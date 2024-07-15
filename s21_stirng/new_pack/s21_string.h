#pragma once

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <math.h>

#define MAX_LEN_BUF 1000
#define MAX_LEN_DOUBLE 400
#define MAX_LEN_INT 50
#define EPS 0.0000000001

typedef struct {
    int leftSideFlag;
    int signFlag;
    int spaseFlag;
    int zeroFlag;
    int sharpFlag;
    int precisionFlag;
    int widthArgumentFlag;
    int precisionArgumentFlag;
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

typedef enum {MYINT, MYUINT, MYFLOAT, MYCHAR, MYSTRING, MYEXP, MYFLOATEXP, MYUPHEX, MYOCT, MYPOINTER, PERSENT,} mySprintfTipes;

size_t s21_strlen(const char *str);
char* s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char* s21_strncat(char *dest, const char *src, size_t n);
char* s21_strncpy(char *dest, const char *src, size_t n);

int s21_sprintf(char *buffer, const char *format, ...);
int isTypeSymbol(Specifiers *specifiers, char c);
const char* makeSpecifires(const char* buffer, Specifiers *specifiers);
void parseSpecifiers(Specifiers *specifiers);
void printSpecifiers(const Specifiers *specifiers);
void resetSpecifiers(Specifiers *specifiers);
void checkSpecifiersParameters(Specifiers *specifiers, size_t *count);
void checkWidhtPresicionArg(Specifiers *specifiers, va_list ap);
char* converseIntType(Specifiers *specifiers, va_list ap);
char* makeStringFromVariable(Specifiers *specifiers, va_list ap, int cType, mySprintfTipes typeOption);
char* converseStringType(Specifiers *specifiers, va_list ap);
char* converseCharType(Specifiers *specifiers, va_list ap);
char* converseUnsignedIntType(Specifiers *specifiers, va_list ap, mySprintfTipes typeOption);
char* converseFloatType(Specifiers *specifiers, va_list ap, mySprintfTipes typeOption);
char* conversePointerType(va_list ap);
int getIntegerPartLength(unsigned long long integerPart, int dividor);
int getDoublePartLength(long double integerPart);
double roundToNDecimalPlaces(long double num, int n);
char* intToString(unsigned long int num, char *str, int precision);
char* hexUpToString(unsigned long long num, char *str, int precision);
char* octToString(unsigned long long num, char *str, int precision);
char* doubleToFloatString(long double num, char* str, int precision);
char* doubleToExpString(long double num, char* str, int precision);
void removeExpZeros(char* str);
void removeTrailingZeros(char* str);
int getExpLength(long double num);
char* converseByFlagsWigthSpecifier(Specifiers *specifiers, char* str, mySprintfTipes typeOption);
char* percentToString();
char *myToLower(char *str);

