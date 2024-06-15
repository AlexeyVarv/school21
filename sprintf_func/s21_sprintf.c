#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <math.h>

#define MAX_LEN_BUF 1000
#define MAX_LEN_DOUBLE 400
#define MAX_LEN_INT 50
#define convertTypeByLength(specifiers, ap, a, type) \
    do { \
        if (specifiers->lenght.longIntFlag) { \
            *(type*)(a) = (type)va_arg(ap, long int); \
        } else if (specifiers->lenght.shortFlag) { \
            *(type*)(a) = (type)(short int)va_arg(ap, int); \
        } else { \
            *(type*)(a) = (type)va_arg(ap, int); \
        } \
    } while(0)

typedef struct {
    int letSideFlag;
    int signFlag;
    int spaseFlag;
    int zeroFlag;
    int sharpFlag;
    int precisionFlag;
} Flags;

typedef struct {
    int shortFlag;
    int longIntFlag;
    int longDoubleFlag;
} Lenght;

typedef struct {
    Flags flags;
    unsigned int width;
    unsigned int precision;
    Lenght lenght;
    const char* strFlags;
    const char* strfLengthDescription;
    const char* variantsSpecifiers;
    const char* typeSymbols;
    char specifiersString[50];
    unsigned int maxLenghtResultString;
} Specifiers;

typedef enum {MYINT, MYUINT, MYFLOAT, MYCHAR, MYSTRING, MYEXP, MYHEX, PERSENT,} mySprintfTipes;

int s21_sprintf(char *buffer, const char *format, ...);

int isTypeSymbol(Specifiers *specifiers, char c);

const char* makeSpecifires(const char* buffer, Specifiers *specifiers);

void parseSpecifiers(Specifiers *specifiers);

void printSpecifiers(const Specifiers *specifiers);

void resetSpecifiers(Specifiers *specifiers);

void checkSpecifiersParameters(Specifiers *specifiers, size_t *count);

char* converseIntType(Specifiers *specifiers, va_list ap);

char* makeStringFromVariable(Specifiers *specifiers, va_list ap, int cType, mySprintfTipes typeOption);

char* converseStringType(Specifiers *specifiers, va_list ap);

char* converseCharType(Specifiers *specifiers, va_list ap);

char* converseUnsignedIntType(Specifiers *specifiers, va_list ap);

char* converseFloatType(Specifiers *specifiers, va_list ap, mySprintfTipes typeOption);

int getIntegerPartLength(int num);

int getDoublePartLength(double integerPart);

double roundToNDecimalPlaces(double num, int n);

char* intToString(int num, char *str, int precision);

char* doubleToFloatString(double num, char* str, int precision);

char* doubleToExpString(double num, char* str, int precision);

int getExpLength(double num);

char* converseByFlagsWigthSpecifier(Specifiers *specifiers, char* str, mySprintfTipes typeOption);

char* percentToString();


int main (void) {
    int a = -55;
    int b = 0;
    char company[] = "Umbrella Corp.";
    char status = 'Z';
    unsigned int salary = 0;
    double coefficient = 0.75452635e115;
    int group = 1256;
    
    char text[MAX_LEN_BUF];
    
    int charNumber = s21_sprintf(text, "MAX Code: %08d Age: %-10d Employer: %s Status: %5c Reward: %+05u Priority: % 015.4e!", a, b, company, status, salary, coefficient);  
    printf ("Mysprintf: %s\n", text);
    printf("text length: %d\n", charNumber);
    printf("\n");
    charNumber = sprintf(text, "MAX Code: %08d Age: %-10d Employer: %s Status: %5c Reward: %+05u Priority: % 015.4e Group %010X!", a, b, company, status, salary, coefficient, group);
    printf ("Control: %s\n", text);
    printf("text length: %d\n", charNumber);
    
    return 0;
}


int s21_sprintf(char *buffer, const char *format, ...) {
    char* start = buffer;
    Specifiers specifiers;
    mySprintfTipes typeOption;
    va_list ap;
    
    va_start(ap, format);
    while(*format) {
        resetSpecifiers(&specifiers);
        if (*format == '%') {
            char *bufferFromVariable;
            format++;
            format = makeSpecifires(format, &specifiers);
            parseSpecifiers(&specifiers);
            bufferFromVariable = makeStringFromVariable(&specifiers, ap, *format, typeOption);
            //printSpecifiers(&specifiers);
            memcpy(buffer, bufferFromVariable, strlen(bufferFromVariable) + 1);
            buffer+= strlen(bufferFromVariable);
            format++;
            //free(bufferFromVariable);
        } else {
            *buffer++ = *format++;
        }
    }
    va_end(ap);
    *buffer = '\0';

    return buffer - start;
}

//Проверят тип переменной, возвращает строку из переменной заданного типа
char* makeStringFromVariable(Specifiers *specifiers, va_list ap, int cType, mySprintfTipes typeOption) {
    char* result;
    
    switch (cType)
    {
    case 'd':
        typeOption = MYINT;
        result = converseIntType(specifiers, ap);
        printf("***Number: %s\n", result);
        break;
    case 's':
        typeOption = MYSTRING;
        result = converseStringType(specifiers, ap);
        printf("***Number: %s\n", result);
        break;
    case 'c':
        typeOption = MYCHAR;
        result = converseCharType(specifiers, ap);
        printf("***Number: %s\n", result);
        break;
    case 'u':
        typeOption = MYUINT;        
        result = converseUnsignedIntType(specifiers, ap);
        printf("***Number: %s\n", result);
        break;
    case 'f':
        typeOption = MYFLOAT;    
        result = converseFloatType(specifiers, ap, typeOption);
        printf("***Number: %s\n", result);
        break;
    case 'e':
        typeOption = MYEXP;    
        result = converseFloatType(specifiers, ap, typeOption);
        printf("***Number: %s\n", result);
        break;
    case 'x':
        typeOption = MYHEX;    
        result = converseFloatType(specifiers, ap, typeOption);
        printf("***Number: %s\n", result);
        break;   
    case '%':
        typeOption = PERSENT;        
        result = percentToString();
        break;
    default:
        break;
    }

    if (strlen(result) < specifiers->width) {
        result = converseByFlagsWigthSpecifier(specifiers, result, typeOption);
    }
        
    return result;
}

//Переводит в строку тип char по заданным спецификаторам
char* converseCharType(Specifiers *specifiers, va_list ap) {
    char ch;
    
    if (specifiers->lenght.longIntFlag) {
        ch = va_arg(ap, int);
        ch = (wchar_t)ch;
    } else {
        ch = va_arg(ap, int);
    }
    char *buffer = malloc(2 * sizeof(char));
    memset(buffer, ch, 1);
    
    return buffer;
}

//Возвращает указатель на строку по заданным спецификаторам включая точность
char* converseStringType(Specifiers *specifiers, va_list ap) {
    char *str = va_arg(ap, char*);
    char *buffer = malloc(sizeof(str) * sizeof(char));
    
    if (specifiers->flags.precisionFlag) {
        memcpy(buffer, str, specifiers->precision);
    } else {
        memcpy(buffer, str, strlen(str) + 1);
    }
        
    return buffer;
}

//Переводит в строку тип int по заданным спецификаторам включая точность
char* converseIntType(Specifiers *specifiers, va_list ap) {
    char *buffer = malloc(MAX_LEN_INT * sizeof(char));
    char* p = buffer;
    int a;
    
    if (specifiers->lenght.longIntFlag) {
        a = va_arg(ap, long int);
        a = (long int)a;
    } else {
        a = va_arg(ap, int);
    }
    if (specifiers->flags.signFlag && a >= 0) {
        *p++ = '+';
    }
    if (!specifiers->flags.signFlag && a >= 0 && specifiers->flags.spaseFlag) {
        *p++ = ' ';
    }
    if (a < 0) {
        *p++ = '-';
        a *= -1;
    }
    if (specifiers->precision == 0 && a == 0 && specifiers->flags.precisionFlag) {
        buffer[0] = '\0';
    } else {
        intToString(a, p, specifiers->precision);
    }
    
    return buffer;
}

//Переводит в строку тип unsigned int по заданным спецификаторам включая точность
char* converseUnsignedIntType(Specifiers *specifiers, va_list ap) {
    char *buffer = malloc(MAX_LEN_INT * sizeof(char));
    char* p = buffer;
    unsigned int a;
    convertTypeByLength(specifiers, ap, &a, unsigned int);

    if (a < 0) {
        perror("Error: The variable must not be negative");
        exit(1);
    }
    if (specifiers->precision == 0 && a == 0 && specifiers->flags.precisionFlag) {
        buffer[0] = '\0';
    } else {
        intToString(a, p, specifiers->precision);
    }

    return buffer;
}

//Переводит в строку с плавающей точко по спецификатору f включая точность
char* converseFloatType(Specifiers *specifiers, va_list ap, mySprintfTipes typeOption) {
    char *buffer = malloc(MAX_LEN_DOUBLE * sizeof(char));
    char* p = buffer;
    double num;
        
    if (specifiers->lenght.longDoubleFlag) {
        num = va_arg(ap, long double);
        num = (long double)num;
    } else {
        num = va_arg(ap, double);
    }
    if (specifiers->flags.signFlag && num >= 0) {
        *p++ = '+';
    }
    if (!specifiers->flags.signFlag && num >= 0 && specifiers->flags.spaseFlag) {
        *p++ = ' ';
    }
    if (num < 0) {
        *p++ = '-';
        num *= -1;
    }
    int currentPrecicion = 6;
    if (specifiers->flags.precisionFlag) {
        currentPrecicion = specifiers->precision;
    }
    
    if (typeOption == MYFLOAT) {
        doubleToFloatString(num, p, currentPrecicion);
    } else if (typeOption == MYEXP) {
        doubleToExpString(num, p, currentPrecicion);
    }
    
    return buffer;
}

//Выводит строку в зависимости от заданной ширины
char* converseByFlagsWigthSpecifier(Specifiers *specifiers, char* str, mySprintfTipes typeOption) {
    size_t spaceCount = specifiers->width;
    char *spaceString = malloc((spaceCount + 1) * sizeof(char));
    memset(spaceString, ' ', spaceCount);
    char *zeroString = malloc((spaceCount + 1) * sizeof(char));
    memset(zeroString, '0', spaceCount);
    char *p;
    
    if(specifiers->flags.zeroFlag && !specifiers->flags.letSideFlag && ((typeOption == MYINT && !specifiers->flags.precisionFlag) || typeOption == MYFLOAT || typeOption == MYEXP || typeOption == MYUINT)) {
        p = zeroString;
        if (specifiers->flags.signFlag && str[0] != '-' && typeOption != MYUINT) {
            *p = '+';
            str[0] = '0';
        }
        if (str[0] == '-') {
            *p = '-';
            str[0] = '0';
        }
        if (!specifiers->flags.signFlag && str[0] != '-' && specifiers->flags.spaseFlag) {
            *p = ' ';
            str[0] = '0';
        }
        p += (spaceCount - strlen(str));
        memcpy(p, str, strlen(str));
        return zeroString;
    } else {
        p = spaceString;
        if (!specifiers->flags.letSideFlag) {
            p += (spaceCount - strlen(str));
        }
        memcpy(p, str, strlen(str));
        return spaceString;
    }
    
}

//Проверка спецификатора на невалидный символ и неверное расположение параметров
void checkSpecifiersParameters(Specifiers *specifiers, size_t *count) {
    const char *p = specifiers->specifiersString;
    while (*p)
    {
        if (!strchr(specifiers->variantsSpecifiers, *p)) {
            perror("Error: Unvalid specifiers");
            exit(1);
        }
        p++;
    }
    if (*count != strlen(specifiers->specifiersString)) {
        perror("Error: Specifiers order");
        exit(1);
    }
    if (specifiers->width > specifiers->maxLenghtResultString) {
        perror("Error: WITHG bigger then buffer");
        exit(1);
    }
}

//Опеределение всех спецификаторов и запись параметров в структуру
void parseSpecifiers(Specifiers *specifiers) {
    const char *p = specifiers->specifiersString;
    char strWidth[20] = "0";
    int widthIndex = 0;
    char strPrecision[20] = "0";
    int precisionIndex = 0;
    size_t countPrecision = 0;
    while(*p) {
        while (strchr(specifiers->strFlags, *p) && *p != '\0') {
            switch(*p) {
            case '-': 
                specifiers->flags.letSideFlag = 1;
                break;
            case '+':
                specifiers->flags.signFlag = 1;
                break;
            case ' ':
                specifiers->flags.spaseFlag = 1;
                break;
            case '0':
                specifiers->flags.zeroFlag = 1;
                break;
            case '#':
                specifiers->flags.sharpFlag = 1;
                break;
            }
            p++;
            countPrecision++;
        }
        while(isdigit(*p)) {
            strWidth[widthIndex] = *p;
            widthIndex++;
            p++;
            countPrecision++;
        }
        strWidth[widthIndex] = '\0';
        if (*p == '.') {
            specifiers->flags.precisionFlag = 1;
            p++;
            countPrecision++;
        }
        while(isdigit(*p)) {
            strPrecision[precisionIndex] = *p;
            precisionIndex++;
            p++;
            countPrecision++;
        }
        strPrecision[precisionIndex] = '\0';
        if (strchr(specifiers->strfLengthDescription, *p) && *p != '\0') {
            switch(*p) {
            case 'h': 
                specifiers->lenght.shortFlag = 1;
                break;
            case 'l':
                specifiers->lenght.longIntFlag = 1;
                break;
            case 'L':
                specifiers->lenght.longDoubleFlag = 1;
                break;
            }
            countPrecision++;
            p++;
            break;
        }
        if (*p != '\0') {
            p++;
        }
    }
    if (strWidth[0]) {
        specifiers->width = strtol(strWidth, NULL, 10);
    }
    if (strPrecision[0]) {
        specifiers->precision = strtol(strPrecision, NULL, 10);
    }
    checkSpecifiersParameters(specifiers, &countPrecision);
}

//Печать флагов, ширины, точности, длины
void printSpecifiers(const Specifiers *specifiers) {
    printf("Flags:\n");
    printf("LetSideFlag: %d\n", specifiers->flags.letSideFlag);
    printf("SignFlag: %d\n", specifiers->flags.signFlag);
    printf("SpaseFlag: %d\n", specifiers->flags.spaseFlag);
    printf("ZeroFlag: %d\n", specifiers->flags.zeroFlag);
    printf("SharpFlag: %d\n", specifiers->flags.sharpFlag);
    printf("PresicionFlag: %d\n", specifiers->flags.precisionFlag);
    printf("Width: %u\n", specifiers->width);
    printf("Precision: %u\n", specifiers->precision);
    printf("Length:\n");
    printf("ShortFlag: %d\n", specifiers->lenght.shortFlag);
    printf("LongIntFlag: %d\n", specifiers->lenght.longIntFlag);
    printf("LongDoubleFlag: %d\n", specifiers->lenght.longDoubleFlag);
    printf("Buffer lenght: %u\n", specifiers->maxLenghtResultString);
    printf("***Spesifire: %s\n", specifiers->specifiersString);
}

//Сброс структуры спецификатора в ноль, установка параметров
void resetSpecifiers(Specifiers *specifiers) {
    specifiers->flags.letSideFlag = 0;
    specifiers->flags.signFlag = 0;
    specifiers->flags.spaseFlag = 0;
    specifiers->flags.zeroFlag = 0;
    specifiers->flags.sharpFlag = 0;
    specifiers->flags.precisionFlag = 0;
    specifiers->width = 0;
    specifiers->precision = 0;
    specifiers->lenght.shortFlag = 0;
    specifiers->lenght.longIntFlag = 0;
    specifiers->lenght.longDoubleFlag = 0;
    specifiers->strFlags = "-+ 0#";
    specifiers->strfLengthDescription = "hlL";
    specifiers->variantsSpecifiers = ". -+#0123456789hlL";
    specifiers->typeSymbols = "cdieEfgGosuxXpn%";
    specifiers->specifiersString[0] = '\0';
    specifiers->maxLenghtResultString = MAX_LEN_BUF;
}

//Запись спецификаторов в строку, останавливается на определителе типа
const char* makeSpecifires(const char* buffer, Specifiers *specifiers) {
    const char* p = buffer;
    int i = 0;
    while(*p) {
        if (isTypeSymbol(specifiers, *p)) {
            break;
        }
        specifiers->specifiersString[i] = *p;
        i++;
        p++;
    }
    specifiers->specifiersString[i] = '\0';
    return p;
}

//Определение символа типа переменной
int isTypeSymbol(Specifiers *specifiers, char c) {
    if (c != '\0' && strchr(specifiers->typeSymbols, c)) {
        return 1;
    }
    return 0;
}

//Переводит int в строку с заданной точностью
char* intToString(int num, char *str, int precision){
    int integerLength = getIntegerPartLength(num);
    if (precision > integerLength) {
        for (int i = precision - 1; i >= 0; i--) {
            str[i] = '0' + num % 10;
            num /= 10;
        }
        str[precision] = '\0';
    } else {
        for (int i = integerLength - 1; i >= 0; i--) {
            str[i] = '0' + num % 10;
            num /= 10;
        }
        str[integerLength] = '\0';
    }
    return str;
}

//Расчет целого в числе с плавающей точкой
int getIntegerPartLength(int integerPart) {
    int length = 0;
    do {
        integerPart /= 10;
        length++;
    } while (integerPart != 0);
    
    return length;
}

int getDoublePartLength(double integerPart) {
    int length = 0;
    do {
        integerPart /= 10;
        length++;
    } while (integerPart > 1);
    
    return length;
}

double roundToNDecimalPlaces(double num, int n) {
    double multiplier = pow(10.0, n);
    return round(num * (multiplier )) / multiplier;
}

// Функция для перевода дробного числа в строку с плавающей точкой
char* doubleToFloatString(double num, char* str, int precision) {
    num = roundToNDecimalPlaces(num, precision);
    double intPart;
    double fracPart = modf(num, &intPart); //Стандартная функция, разделяет число с плавающей точкой на 2 числа double - целую и дробную часть
    int integerLength = getDoublePartLength(num);
    
    for (int i = integerLength - 1; i >= 0; i--) {
        str[i] = '0' + fmod(intPart, 10); //Стандартная функция - вычисляет остаток от деления для чисел с плавающей точкой
        intPart /= 10;
    }
    if (precision) {
        str[integerLength] = '.';
        for (int i = integerLength + 1; i < integerLength + precision + 1; i++) {
            fracPart *= 10;
            int digit = (int)fracPart;
            str[i] = '0' + digit;
            fracPart -= digit;
        }
        str[integerLength + 1 + precision] = '\0';
    } else {
        str[integerLength + precision] = '\0';
    }
         
    return str;
}

//Возвращает число цифр целого
int getExpLength(double num) {
    int length = 0;
    if (num > 1) {
        num /= 10;
        while (num > 1) {
            num /= 10;
            length++;
        }
    } else {
        while (num <= 1) {
            num *= 10;
            length--;
        }
    }
    
    return length;
}

//Функция для перевода дробного числа в строку с экспоненциальной записью
char* doubleToExpString(double num, char* str, int precision) {
    int expLength = getExpLength(num);
    num = num * pow(10, -expLength);
    num = roundToNDecimalPlaces(num, precision);
    double intPart;
    double fracPart = modf(num, &intPart);   
    str[0] = '0' + fmod(intPart, 10);
        
    if (precision) {
        str[1] = '.';
        for (int i = 2; i < precision + 2; i++) {
            fracPart *= 10;
            int digit = (int)fracPart;
            str[i] = '0' + digit;
            fracPart -= digit;
        }
        str[precision + 2] = '\0';
    } else {
        str[1] = '\0';
    }
        
    char exp[10];
    char *p = exp;
    *p++ = 'e';
    if (expLength >= 0) {
        *p++ = '+';
    } else {
        *p++ = '-';
        expLength *= -1;
    }
    intToString(expLength, p, 2);
    strncat(str, exp, strlen(exp));

    return str;
}

//Возвращает знак %
char* percentToString() {
    char *strPersent = "%";
    
    return strPersent; 
}
