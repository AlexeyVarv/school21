#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_LEN_BUF 100

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
    size_t maxLenghtResultString;
} Specifiers;


int s21_sprintf(char *buffer, const char *format, ...);

int isTypeSymbol(Specifiers *specifiers, char c);

const char* makeSpecifires(const char* buffer, Specifiers *specifiers);

void itoa(int i, char *b);

void parseSpecifiers(Specifiers *specifiers);

void printSpecifiers(const Specifiers *specifiers);

void resetSpecifiers(Specifiers *specifiers, char* text);

void checkSpecifiersParameters(Specifiers *specifiers, size_t *count);

char* converseIntType(Specifiers *specifiers, va_list ap);

char* makeStringFromVariable(Specifiers *specifiers, va_list ap, int cType);

char* converseStringType(Specifiers *specifiers, va_list ap);

char* converseCharType(Specifiers *specifiers, va_list ap);

int main (void) {
    int a = -666;
    int b = 15508;
    char company[] = "Umbrella Corp.";
    char status = 'Z';

    char text[MAX_LEN_BUF];
    
    int charNumber = s21_sprintf(text, "MAX Name: %d Age: %d Employer: %s Status: %-c!", a, b, company, status);  
    printf ("Mysprintf: %s\n", text);
    printf("text length: %d\n", charNumber);
    printf("\n");
    charNumber = sprintf(text, "MAX Name: %d Age: %d Employer: %s Status: %-c!", a, b, company, status);
    printf ("Control: %s\n", text);
    printf("text length: %d\n", charNumber);

    return 0;
}


int s21_sprintf(char *buffer, const char *format, ...) {
    char* start = buffer;
    Specifiers specifiers;
    va_list ap;

    va_start(ap, format);
    while(*format) {
        resetSpecifiers(&specifiers, buffer);
        if (*format == '%') {
            char *bufferFromVariable;
            format++;
            format = makeSpecifires(format, &specifiers);
            parseSpecifiers(&specifiers);
            
            printSpecifiers(&specifiers);
                        
            bufferFromVariable = makeStringFromVariable(&specifiers, ap, *format);
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
char* makeStringFromVariable(Specifiers *specifiers, va_list ap, int cType) {
    char* result;
    switch (cType)
    {
    case 'd':
        result = converseIntType(specifiers, ap);
        printf("***Number: %s\n", result);
        break;
    case 's':
        result = converseStringType(specifiers, ap);
        printf("***Number: %s\n", result);
        break;
    case 'c':
        result = converseCharType(specifiers, ap);
        printf("***Number: %s\n", result);
        break;
    default:
        break;
    }
    return result;
}

char* converseCharType(Specifiers *specifiers, va_list ap) {
    char ch = va_arg(ap, int);
    char *buffer = malloc((specifiers->width + 2) * sizeof(char));
    memset(buffer, ch, 1);
    
    return buffer;
}


char* converseStringType(Specifiers *specifiers, va_list ap) {
    char *str = va_arg(ap, char*);
    char *buffer = malloc((sizeof(str) + 1) * sizeof(char));
    memcpy(buffer, str, strlen(str) + 1);
    
    return buffer;
}

//Переводит в строку тип int по заданным спецификаторам
char* converseIntType(Specifiers *specifiers, va_list ap) {
    char *buffer = malloc(50 * sizeof(char));
    char* p = buffer;
    int a;
    const char digit[] = "0123456789";
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
    
    return buffer;
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
    if (specifiers->width > (unsigned int)specifiers->maxLenghtResultString) {
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
    printf("Width: %d\n", specifiers->width);
    printf("Precision: %d\n", specifiers->precision);
    printf("Length:\n");
    printf("ShortFlag: %d\n", specifiers->lenght.shortFlag);
    printf("LongIntFlag: %d\n", specifiers->lenght.longIntFlag);
    printf("LongDoubleFlag: %d\n", specifiers->lenght.longDoubleFlag);
    printf("***Spesifire: %s\n", specifiers->specifiersString);
}

//Сброс структуры спецификатора в ноль, установка параметров
void resetSpecifiers(Specifiers *specifiers, char* text) {
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
    specifiers->maxLenghtResultString = strlen(text);
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

void itoa(int i, char *b){
    char const digit[] = "0123456789";
    char* p = b;
    if(i<0){
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do{ //Move to where representation ends
        ++p;
        shifter = shifter/10;
    }while(shifter);
    *p = '\0';
    do{ //Move back, inserting digits as u go
        *--p = digit[i%10];
        i = i/10;
    }while(i);
    //return b;
}