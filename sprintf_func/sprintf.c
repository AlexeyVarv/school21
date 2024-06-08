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
} Specifiers;


int s21_sprintf(char *buffer, const char *format, ...);

int isTypeSymbol(Specifiers *specifiers, char c);

const char* makeSpecifires(const char* buffer, Specifiers *specifiers, char* dest);

void itoa(int i, char *b);

void parseSpecifiers(const char* strSpecifiers, Specifiers *specifiers);

void print_specifiers(const Specifiers *specifiers);

void reset_specifiers(Specifiers *specifiers);

void checkSpecifiersParameters(const char* strSpec, Specifiers *specifiers);

int main (void) {
    Specifiers specifiers;
    reset_specifiers(&specifiers);

    const char* parsedStr = "+11.2L";
    checkSpecifiersParameters(parsedStr, &specifiers);
    parseSpecifiers(parsedStr, &specifiers);
    print_specifiers(&specifiers);

    printf("-----------\n");
    
    int age = 308;
    int age1 = 418;
    char text[50];
    
    int charNumber = s21_sprintf (text, "MAX Name: Age: %20d %d!\n", age, age1);  
    printf ("%s\n", text);  // Name: Tom  Age: 38
    printf("text length: %d\n", charNumber);  // text length: 19


    return 0;
}

int s21_sprintf(char *buffer, const char *format, ...) {
    Specifiers specifiers;
    va_list ap;
    va_start(ap, format);
    char parsedString[50] = "0";
    while(*format) {
        reset_specifiers(&specifiers);
        char int_buffer[33];
        if (*format != '%') {
            *buffer = *format;
        }
        if (*format == '%') {
            format++;
            format = makeSpecifires(format, &specifiers, parsedString);
            printf("+++%s+++\n", parsedString);
            switch (*format)
            {
            case 'd':
                int a = va_arg(ap, int);
                //char int_buffer[33];
                
                itoa(a, int_buffer);
                *buffer = '\0';
                strncat(buffer, int_buffer, 33);
                buffer += 2;
                printf("---%s---", int_buffer);
                
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

    return (int)(strlen(buffer));
}

void checkSpecifiersParameters(const char* strSpec, Specifiers *specifiers) {
    const char *p = strSpec;
    while (*p)
    {
        if (!strchr(specifiers->variantsSpecifiers, *p)) {
            perror("Unvalid specifiers");
            exit(1);
        }
        p++;
    }
}

void parseSpecifiers(const char* strSpecifiers, Specifiers *specifiers) {
    const char *p = strSpecifiers;
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
    }
    if (strWidth[0]) {
        specifiers->width = strtol(strWidth, NULL, 10);
    }
    if (strPrecision[0]) {
        specifiers->precision = strtol(strPrecision, NULL, 10);
    }
    printf("+++%ld+++\n", countPrecision);
    if (countPrecision != strlen(strSpecifiers)) {
        perror("Error specifiers");
        exit(1);
    }
}

void print_specifiers(const Specifiers *specifiers) {
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

//Сброс структуры спецификатора в ноль
void reset_specifiers(Specifiers *specifiers) {
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
}

const char* makeSpecifires(const char* buffer, Specifiers *specifiers, char* dest) {
    const char* p = buffer;
    while(*p) {
        if (isTypeSymbol(specifiers, *p)) {
            break;
        }
        *dest++ = *p++; 
    }
    return p;
}

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