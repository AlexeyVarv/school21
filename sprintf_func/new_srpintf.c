#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

#define _CRT_SECURE_NO_WARNINGS 1

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
    int width;
    int precision;
    Lenght lenght;
    const char* strFlags;
    const char* strfLengthDescription;
    const char* variantsSpecifiers;
    const char* typeSymbols;
    char specifiersString[50];
} Specifiers;


int s21_sprintf(char *buffer, const char *format, ...);

int isTypeSymbol(Specifiers *specifiers, char c);

const char* makeSpecifires(const char* buffer, Specifiers *specifiers);

void itoa(int i, char *b);

void parseSpecifiers(Specifiers *specifiers);

void printSpecifiers(const Specifiers *specifiers);

void resetSpecifiers(Specifiers *specifiers);

void checkSpecifiersParameters(Specifiers *specifiers, size_t *count);

void converseIntType(Specifiers *specifiers, char* buffer, va_list ap);


int main (void) {
    long int a = 308;
    long int b = 418;
    char text[50];
    
    int charNumber = s21_sprintf(text, "MAX Name: Age: %li %li!\n", a, b);  
    printf ("Mysprintf: %s\n", text);
    printf("text length: %d\n", charNumber);
    
    charNumber = sprintf(text, "MAX Name: Age: %d %ld!\n", a, b);
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
        resetSpecifiers(&specifiers);
        char int_buffer[33];
        if (*format != '%') {
            *buffer = *format;
        }
        if (*format == '%') {
            format++;
            format = makeSpecifires(format, &specifiers);
            parseSpecifiers(&specifiers);
            printSpecifiers(&specifiers);
            printf("***Spesifire: %s\n", specifiers.specifiersString);
            switch (*format)
            {
            case 'd':
                int a = va_arg(ap, int);
                //char int_buffer[33];
                itoa(a, int_buffer);
                *buffer = '\0';
                strncat(buffer, int_buffer, 33);
                buffer += 2;
                printf("***Number: %s\n", int_buffer);
                break;
            case 'i':
                char hex_buffer[33];
                converseIntType(&specifiers, hex_buffer, ap);
                *buffer = '\0';
                strncat(buffer, hex_buffer, 33);
                buffer += 2;
                printf("***Number: %s\n", hex_buffer);
                break;
            default:
                break;
            }
        }
        buffer++;
        format++;
    }
    va_end(ap);
    *buffer = '\0';
    return buffer - start;
}

void converseIntType(Specifiers *specifiers, char* buffer, va_list ap) {
    int a;
    if (specifiers->lenght.longIntFlag) {
        a = va_arg(ap, long int);
        a = (long int)a;
    } else {
        a = va_arg(ap, int);
    }
    
    const char digit[] = "0123456789";
    char* p = buffer;
    if(a < 0){
        *p++ = '-';
        a *= -1;
    }
    int shifter = a;
    do{ //Move to where representation ends
        ++p;
        shifter = shifter / 10;
    }while(shifter);
    *p = '\0';
    do{ //Move back, inserting digits as u go
        *--p = digit[a % 10];
        a = a / 10;
    }while(a);
    
    
}

//Проверка спецификатора на невалидный символ и неверное расположение параметров
void checkSpecifiersParameters(Specifiers *specifiers, size_t *count) {
    const char *p = specifiers->specifiersString;
    while (*p)
    {
        if (!strchr(specifiers->variantsSpecifiers, *p)) {
            perror("Unvalid specifiers");
            exit(1);
        }
        p++;
    }
    if (*count != strlen(specifiers->specifiersString)) {
        perror("Error specifiers order");
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
        if (strchr(specifiers->strFlags, *p)) {
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
        if (*p != '\0' && strchr(specifiers->strfLengthDescription, *p)) {
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
        p++;
    }
    if (strWidth[0]) {
        specifiers->width = strtol(strWidth, NULL, 10);
    }
    if (strPrecision[0]) {
        specifiers->precision = strtol(strPrecision, NULL, 10);
    }

    checkSpecifiersParameters(specifiers, &countPrecision);
    //printf("+++%ld+++\n", countPrecision);
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