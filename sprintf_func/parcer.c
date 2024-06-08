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
} Specifiers;


void itoa(int i, char *b);

int s21_sprintf(char *buffer, const char *fmt, ...);

void parseSpecifiers(const char* strSpecifiers, const char* strFlags, const char* strfLengthDescription, Specifiers *specifiers);

void print_specifiers(const Specifiers *specifiers);

int main (void)
{
    const char* strFlags = "-+ 0#";
    const char* strfLengthDescription = "hlL";
    Specifiers specifiers = {0};

    const char* parsedStr = "+11h";
    parseSpecifiers(parsedStr, strFlags, strfLengthDescription, &specifiers);
    print_specifiers(&specifiers);

    printf("-----------\n");

    const char* parsedStr2 = "!12.8l";
    parseSpecifiers(parsedStr2, strFlags, strfLengthDescription, &specifiers);
    print_specifiers(&specifiers);

    return 0;
}

void parseSpecifiers(const char* strSpecifiers, const char* strFlags, const char* strfLengthDescription, Specifiers *specifiers) {
    const char *p = strSpecifiers;
    char strWidth[20] = "0";
    int widthIndex = 0;
    char strPrecision[20] = "0";
    int precisionIndex = 0;
    while(*p) {
        if (strchr(strFlags, *p)) {
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
        }
        while(isdigit(*p)) {
            strWidth[widthIndex] = *p;
            widthIndex++;
            p++;
        }
        strWidth[widthIndex] = '\0';
        if (*p == '.') {
            p++;
        }
        while(isdigit(*p)) {
            strPrecision[precisionIndex] = *p;
            precisionIndex++;
            p++;
        }
        strPrecision[precisionIndex] = '\0';
        if (strchr(strfLengthDescription, *p)) {
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
        }
        p++;
    }
    if (strWidth[0]) {
        specifiers->width = strtol(strWidth, NULL, 10);
    }
    if (strPrecision[0]) {
        specifiers->precision = strtol(strPrecision, NULL, 10);
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