#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <math.h>

#define MAX_LEN_BUF 1000
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

typedef enum {MYINT, MYFLOAT, MYCHAR, MYSTRING, MYEXP, PERSENT,} mySprintfTipes;

int s21_sprintf(char *buffer, const char *format, ...);

int isTypeSymbol(Specifiers *specifiers, char c);

const char* makeSpecifires(const char* buffer, Specifiers *specifiers);

char* intToString(int a, char *str, Specifiers *specifiers);

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

int getIntegerPartLength(double num);

char* doubleToFloatString(double num, char* str, Specifiers *specifiers);

char* doubleToExpString(double num, char* str, Specifiers* specifiers);

char* converseByWigthSpecifier(Specifiers *specifiers, char* str, mySprintfTipes typeOption);

char* percentToString();


int main (void) {
    int a = -666;
    int b = 35;
    char company[] = "Umbrella Corp.";
    char status = 'Z';
    unsigned int salary = 5000;
    double coefficient = 0.0023936924;
    
    char text[MAX_LEN_BUF];
    
    int charNumber = s21_sprintf(text, "MAX Code: %d Age: %d Employer: %.5s Status: %c Reward: %u Priority: %e!", a, b, company, status, salary, coefficient);  
    printf ("Mysprintf: %s\n", text);
    printf("text length: %d\n", charNumber);
    printf("\n");
    charNumber = sprintf(text, "MAX Code: %d Age: %d Employer: %.5s Status: %c Reward: %u Priority: %e!", a, b, company, status, salary, coefficient);
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
            
            //printSpecifiers(&specifiers);
                        
            bufferFromVariable = makeStringFromVariable(&specifiers, ap, *format, typeOption);
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
        typeOption = MYINT;        
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
        break;    
    case '%':
        typeOption = PERSENT;        
        result = percentToString();
        break;
    default:
        break;
    }
    if (strlen(result) < specifiers->width) {
        result = converseByWigthSpecifier(specifiers, result, typeOption);
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
    
    if (specifiers->precision) {
        memcpy(buffer, str, specifiers->precision);
    } else {
        memcpy(buffer, str, strlen(str) + 1);
    }
        
    return buffer;
}

//Переводит в строку тип int по заданным спецификаторам включая точность
char* converseIntType(Specifiers *specifiers, va_list ap) {
    char *buffer = malloc(50 * sizeof(char));
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
    intToString(a, p, specifiers);

    return buffer;
}

//Переводит в строку тип unsigned int по заданным спецификаторам включая точность
char* converseUnsignedIntType(Specifiers *specifiers, va_list ap) {
    char *buffer = malloc(50 * sizeof(char));
    char* p = buffer;
    unsigned int a;
    convertTypeByLength(specifiers, ap, &a, unsigned int);

    if (a < 0) {
        perror("Error: The variable must not be negative");
        exit(1);
    }
    intToString(a, p, specifiers);

    return buffer;
}

//Переводит в строку с плавающей точко по спецификатору f включая точность
char* converseFloatType(Specifiers *specifiers, va_list ap, mySprintfTipes typeOption) {
    char *buffer = malloc(50 * sizeof(char));
    char* p = buffer;
    double num;
    
    if (specifiers->lenght.longDoubleFlag) {
        num = va_arg(ap, long double);
        //printf("Size = %zd\n", sizeof(num));
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
    
    if (typeOption == MYFLOAT) {
        doubleToFloatString(num, p, specifiers);
    } else if (typeOption == MYEXP) {
        doubleToExpString(num, p, specifiers);
    }
    
    return buffer;
}

//Выводит строку в зависимости от заданной ширины
char* converseByWigthSpecifier(Specifiers *specifiers, char* str, mySprintfTipes typeOption) {
    size_t spaceCount = specifiers->width;
    char *spaceString = malloc((spaceCount + 1) * sizeof(char));
    memset(spaceString, ' ', spaceCount);
    char *p = spaceString;
    
    if (!specifiers->flags.letSideFlag) {
        p += (spaceCount - strlen(str));
    }
    switch (typeOption)
    {
    case MYINT:
        memcpy(p, str, strlen(str));
        break;    
    case MYCHAR:
        memcpy(p, str, strlen(str));
        break;
    case MYSTRING:
        memcpy(p, str, strlen(str));
        break;
    case MYFLOAT:
    case MYEXP:
        memcpy(p, str, strlen(str));
        break;    
    default:
        break;
    }

    return spaceString;
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
    //printf("+++%ld+++\n", countPrecision);
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
char* intToString(int a, char *str, Specifiers *specifiers){
    char const digit[] = "0123456789";
    char* p = str;
    int numDigit = a;
    int zeroCount = 0;
    
    while(numDigit) {
        zeroCount++;
        numDigit = numDigit / 10;
    }
    while((int)specifiers->precision - zeroCount > 0) {
        *p++ = '0';
        zeroCount++;
    }
    int shifter = a;
    do { //Move to where representation ends
        ++p;
        shifter = shifter / 10;
    } while(shifter);
    *p = '\0';
    do { //Move back, inserting digits as u go
        *--p = digit[a % 10];
        a = a / 10;
    } while(a);
    
    return str;
}

//Расчет целого в числе с плавающей точкой
int getIntegerPartLength(double num) {
    int length = 0;
    int integerPart = (int)num;
    while (integerPart != 0) {
        integerPart /= 10;
        length++;
    }
    
    return length;
}

// Функция для перевода числа типа float в строку
char* doubleToFloatString(double num, char* str, Specifiers* specifiers) {
    int integerPart = (int)num;
    double decimalPart = num - integerPart;
    int precision = 6;
    if (specifiers->precision) {
        precision = specifiers->precision;
    }
    
    int integerLength = getIntegerPartLength(num);
    for (int i = integerLength - 1; i >= 0; i--) {
        str[i] = '0' + integerPart % 10;
        integerPart /= 10;
    }
    str[integerLength] = '.';
    
    long int decimalInteger = decimalPart * pow(10, precision + 1);
    int rest = decimalInteger % 10;
    if (rest >= 5) {
        decimalInteger = decimalInteger / 10 + 1;
    } else {
        decimalInteger /= 10;
    }
    for (int i = integerLength + precision; i > integerLength; i--) {
        str[i] = '0' + decimalInteger % 10;
        decimalInteger /= 10;
    }
    str[integerLength + 1 + precision] = '\0';

    return str;
}

int getExpLength(double num) {
    int length = 0;
    if (num > 1) {
    
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

char* doubleToExpString(double num, char* str, Specifiers* specifiers) {
    int precision = 6;
    if (specifiers->precision) {
        precision = specifiers->precision;
    }
    
    int expLength = getExpLength(num);
    printf("$$$%d\n", expLength);
    num = num * pow(10, -expLength);
    int integerPart = (int)num;
    double decimalPart = num - integerPart;
    
    str[0] = '0' + integerPart % 10;
    integerPart /= 10;
    
    str[1] = '.';
    
    long int decimalInteger = decimalPart * pow(10, precision + 1);
    int rest = decimalInteger % 10;
    if (rest >= 5) {
        decimalInteger = decimalInteger / 10 + 1;
    } else {
        decimalInteger /= 10;
    }
    for (int i = precision + 1; i > 1; i--) {
        str[i] = '0' + decimalInteger % 10;
        decimalInteger /= 10;
    }
    str[precision + 2] = 'e';
    if (expLength > 0) {
        str[precision + 3] = '+';
    } else {
        str[precision + 3] = '-';
    }
    str[precision + 4] = '\0';

    return str;
}

//Возвращает знак %
char* percentToString() {
    char *strPersent = "%";
    
    return strPersent; 
}
