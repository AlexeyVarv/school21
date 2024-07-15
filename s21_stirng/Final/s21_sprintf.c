#include "s21_string.h"


int s21_sprintf(char *buffer, const char *format, ...) {
    char* start = buffer;
    Specifiers specifiers;
    va_list ap;
    
    va_start(ap, format);
    while(*format) {
        resetSpecifiers(&specifiers);
        if (*format == '%') {
            char *bufferFromVariable = S21_NULL;
            mySprintfTipes typeOption = 0;
            format++;
            format = makeSpecifires(format, &specifiers);
            parseSpecifiers(&specifiers);
            bufferFromVariable = makeStringFromVariable(&specifiers, ap, *format, typeOption);
            s21_memcpy(buffer, bufferFromVariable, s21_strlen(bufferFromVariable) + 1);
            buffer+= s21_strlen(bufferFromVariable);
            format++;
            if (bufferFromVariable != S21_NULL) {
                free(bufferFromVariable);
            }
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
    checkWidhtPresicionArg(specifiers, ap);
    switch (cType)
    {
    case 'd':
        typeOption = MYINT;
        result = converseIntType(specifiers, ap);
        break;
    case 's':
        typeOption = MYSTRING;
        result = converseStringType(specifiers, ap);
        break;
    case 'c':
        typeOption = MYCHAR;
        result = converseCharType(specifiers, ap);
        break;
    case 'u':
        typeOption = MYUINT;
        result = converseUnsignedIntType(specifiers, ap, typeOption);
        break;
    case 'f':
        typeOption = MYFLOAT;
        result = converseFloatType(specifiers, ap, typeOption);
        break;
    case 'E':
        typeOption = MYEXP;
        result = converseFloatType(specifiers, ap, typeOption);
        break;
    case 'e':
        typeOption = MYEXP;
        result = converseFloatType(specifiers, ap, typeOption);
        result = myToLower(result);
        break;
    case 'G':
        typeOption = MYFLOATEXP;
        result = converseFloatType(specifiers, ap, typeOption);
        break;
    case 'g':
        typeOption = MYFLOATEXP;
        result = converseFloatType(specifiers, ap, typeOption);
        result = myToLower(result);
        break;     
    case 'X':
        typeOption = MYUPHEX;
        result = converseUnsignedIntType(specifiers, ap, typeOption);
        break;
    case 'x':
        typeOption = MYUPHEX; //Исправить, использовать функцию перевода строки в нижний регистр
        result = converseUnsignedIntType(specifiers, ap, typeOption);
        result = myToLower(result);
        break;
    case 'o':
        typeOption = MYOCT;
        result = converseUnsignedIntType(specifiers, ap, typeOption);
        break;
    case 'p':
        typeOption = MYPOINTER;
        result = conversePointerType(ap);
        result = myToLower(result);
        break;    
    case '%':
        typeOption = PERSENT;
        result = percentToString();
        break;
    default:
        break;
    }

    if (s21_strlen(result) < specifiers->width) {
        result = converseByFlagsWigthSpecifier(specifiers, result, typeOption);
    }
        
    return result;
}

void checkWidhtPresicionArg(Specifiers *specifiers, va_list ap) {
    if (specifiers->flags.widthArgumentFlag) {
        specifiers->width = va_arg(ap, int);
    } 
    if (specifiers->flags.precisionArgumentFlag) {
        specifiers->precision = va_arg(ap, int);
    } 
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
    buffer[0] = ch;
    buffer[1] = '\0';

    return buffer;
}

//Возвращает указатель на строку по заданным спецификаторам включая точность
char* converseStringType(Specifiers *specifiers, va_list ap) {
    char *str = va_arg(ap, char*);
    s21_size_t lenght = s21_strlen(str);
    char *buffer = malloc((lenght + 1) * sizeof(char));
    
    if (specifiers->flags.precisionFlag) {
        s21_memcpy(buffer, str, specifiers->precision);
        buffer[specifiers->precision] = '\0';
    } else {
        s21_memcpy(buffer, str, lenght + 1);
    }
        
    return buffer;
}

//Переводит в строку тип int по заданным спецификаторам включая точность
char* converseIntType(Specifiers *specifiers, va_list ap) {
    char *buffer = malloc(MAX_LEN_INT * sizeof(char));
    char* p = buffer;
    long int a;
    
    if (specifiers->lenght.longIntFlag) {
        a = va_arg(ap, long int);
        a = (long int)a;
    } else {
        a = va_arg(ap, int);
    }
    if (specifiers->flags.signFlag && a >= 0) {
        *p++ = '+';
    }
    if (!specifiers->flags.signFlag && a >= 0 && specifiers->flags.spaceFlag) {
        *p++ = ' ';
    }
    if (a < 0) {
        if (a == INT_MIN) {
            s21_memcpy(buffer, "-2147483648", 11);
            return buffer;
        } else {
            *p++ = '-';
            a *= -1; 
        }
    }
    if (specifiers->precision == 0 && a == 0 && specifiers->flags.precisionFlag) {
        if (specifiers->flags.spaceFlag) {
            buffer[0] = ' ';
            buffer[1] = '\0';
        } else {
            buffer[0] = '\0';
        }
    } else {
        intToString(a, p, specifiers->precision);
    }
    
    return buffer;
}

//Переводит в строку тип unsigned int по заданным спецификаторам включая точность
char* converseUnsignedIntType(Specifiers *specifiers, va_list ap, mySprintfTipes typeOption) {
    char *buffer = malloc(MAX_LEN_INT * sizeof(char));
    char* p = buffer;
    unsigned long int a;
    if (specifiers->lenght.longIntFlag) {
        a = va_arg(ap, long int);
        a = (unsigned long int)a;
    } else {
        a = va_arg(ap, int);
    }
    if (specifiers->precision == 0 && a == 0 && specifiers->flags.precisionFlag) {
        buffer[0] = '\0';
    } else {
        if (typeOption == MYUINT) {
            intToString(a, p, specifiers->precision);
        }
        else if (typeOption == MYUPHEX) {
            if (specifiers->flags.sharpFlag && a != 0) {
                *p++ = '0';
                *p++ = 'X';
            }
            hexUpToString(a, p, specifiers->precision);
        }
        else if (typeOption == MYOCT) {
            int integerLength = getIntegerPartLength(a, 8);
            if (specifiers->flags.sharpFlag && (int)specifiers->precision <= integerLength && a != 0) {
                *p++ = '0';
            }
            octToString(a, p, specifiers->precision);
        }   
    }

    return buffer;
}

//Переводит в строку с плавающей точко по спецификатору f включая точность
char* converseFloatType(Specifiers *specifiers, va_list ap, mySprintfTipes typeOption) {
    char *buffer = malloc(MAX_LEN_DOUBLE * sizeof(char));
    char* p = buffer;
    long double num;
        
    if (specifiers->lenght.longDoubleFlag) {
        num = va_arg(ap, long double);
        num = (long double)num;
    } else {
        num = va_arg(ap, double);
    }
    if (specifiers->flags.signFlag && num >= 0) {
        *p++ = '+';
    }
    if (!specifiers->flags.signFlag && num >= 0 && specifiers->flags.spaceFlag) {
        *p++ = ' ';
    }
    if (num < 0) {
        *p++ = '-';
        num *= -1;
    }
    
    if (!specifiers->flags.precisionFlag) {
        specifiers->precision = 6;
    }
    
    if (typeOption == MYFLOAT) {
        doubleToFloatString(num, p, specifiers->precision);
        removeTrailingZeros(buffer, specifiers, typeOption);
    } else if (typeOption == MYEXP) {
        doubleToExpString(num, p, specifiers->precision);
        removeExpZeros(buffer, specifiers, typeOption);
    } else if (typeOption == MYFLOATEXP) {
        int lenght = getExpLength(num);
        if ((lenght >= (int)specifiers->precision || lenght < -4) && lenght != 0) {
            if (specifiers->precision == 0) {
                doubleToExpString(num, p, specifiers->precision);
            } else {
                doubleToExpString(num, p, specifiers->precision - 1);
            }
            removeExpZeros(buffer, specifiers, typeOption);
        } else {
            if (specifiers->precision == 0) {
                doubleToFloatString(num, p, specifiers->precision);
            } else {
                doubleToFloatString(num, p, specifiers->precision - (lenght + 1));
            }
            removeTrailingZeros(buffer, specifiers, typeOption);
        }
    }
    
    return buffer;
}

void removeExpZeros(char* str, Specifiers* specifiers, mySprintfTipes typeOption) {
    char* ePos = s21_strchr(str, 'E');

    if (ePos == S21_NULL) {
        return;
    }
    char* currPos = ePos - 1;
    if (!specifiers->flags.sharpFlag && typeOption == MYFLOATEXP) {
        while (currPos && *currPos == '0') {
            memmove(currPos, currPos + 1, s21_strlen(currPos) + 1);
            currPos--;
        }
    } else if (specifiers->flags.sharpFlag) {
        if (specifiers->precision <= 1) {
            memmove(ePos + 1, ePos, s21_strlen(ePos) + 1);
            *(ePos) = '.';
        }
    }
}

void removeTrailingZeros(char* str, Specifiers* specifiers, mySprintfTipes typeOption) {
    int len = s21_strlen(str);
    char* dotPos = s21_strchr(str, '.');
    if (!specifiers->flags.sharpFlag && typeOption == MYFLOATEXP) {
            if (dotPos == S21_NULL) {
            return;
        }
        char* currPos = str + len - 1;
        while (currPos > dotPos && *currPos == '0') {
            *currPos = '\0';
            currPos--;
        }
        if (*currPos == '.') {
            *currPos = '\0';
        }
    } else if (specifiers->flags.sharpFlag) {
        if (dotPos == S21_NULL) {
            str[len] = '.';
            str[len + 1] = '\0';
        }
    }
}


char* conversePointerType(va_list ap) {
    char *buffer = malloc(MAX_LEN_INT * sizeof(char));
    void * ptr = va_arg(ap, void *);
    char* p = buffer;
    *p++ = '0';
    *p++ = 'X';
    hexUpToString((unsigned long long)ptr, p, 0);

    return buffer;
}

//Выводит строку в зависимости от заданной ширины
char* converseByFlagsWigthSpecifier(Specifiers *specifiers, char* str, mySprintfTipes typeOption) {
    s21_size_t spaceCount = specifiers->width;
    char *p;
    
    if(specifiers->flags.zeroFlag && !specifiers->flags.leftSideFlag && ((typeOption == MYINT && !specifiers->flags.precisionFlag) || (typeOption == MYUPHEX && !specifiers->flags.precisionFlag) ||(typeOption == MYOCT && !specifiers->flags.precisionFlag) || typeOption == MYFLOAT || typeOption == MYFLOATEXP || typeOption == MYEXP || typeOption == MYUINT)) {
        char *zeroString = malloc((spaceCount + 1) * sizeof(char));
        s21_memset(zeroString, '0', spaceCount);
        p = zeroString;
        if (typeOption == MYUPHEX && !specifiers->flags.precisionFlag && specifiers->flags.sharpFlag && s21_strncmp("0", str, s21_strlen(str)) != 0) {
            *(p + 1) = str[1];
            str[1] = '0';
            p += (spaceCount - s21_strlen(str));
        } else {
            if (specifiers->flags.signFlag && str[0] != '-' && typeOption != MYUINT && typeOption != MYOCT) {
                *p = '+';
                str[0] = '0';
            }
            if (!specifiers->flags.signFlag && str[0] != '-' && specifiers->flags.spaceFlag) {
                *p = ' ';
                str[0] = '0';
            }
            if (str[0] == '-') {
                *p = '-';
                str[0] = '0';
            }
            p += (spaceCount - s21_strlen(str));
        }
        s21_memcpy(p, str, s21_strlen(str) + 1);
        free(str);
        return zeroString;
    } else {
        char *spaceString = malloc((spaceCount + 1) * sizeof(char));
        s21_memset(spaceString, ' ', spaceCount);
        spaceString[spaceCount] = '\0';
        p = spaceString;
        if (!specifiers->flags.leftSideFlag) {
            p += (spaceCount - s21_strlen(str));
        }
        s21_memcpy(p, str, s21_strlen(str));
        free(str);
        return spaceString;
    }
}

//Проверка спецификатора на невалидный символ и неверное расположение параметров
void checkSpecifiersParameters(Specifiers *specifiers, s21_size_t *count) {
    const char *p = specifiers->specifiersString;
    while (*p)
    {
        if (!s21_strchr(specifiers->variantsSpecifiers, *p)) {
            perror("Error: Unvalid specifiers");
            exit(1);
        }
        p++;
    }
    if (*count != s21_strlen(specifiers->specifiersString)) {
        perror("Error: Specifiers order");
        exit(1);
    }
    if (specifiers->flags.widthArgumentFlag && specifiers->width > 0) {
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
    s21_size_t countPrecision = 0;
    while(*p) {
        while (s21_strchr(specifiers->strFlags, *p) && *p != '\0') {
            switch(*p) {
            case '-': 
                specifiers->flags.leftSideFlag = 1;
                break;
            case '+':
                specifiers->flags.signFlag = 1;
                break;
            case ' ':
                specifiers->flags.spaceFlag = 1;
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
        while (*p >= '0' && *p <= '9') {
            specifiers->width = specifiers->width * 10 + (*p - '0');
            p++;
            countPrecision++;
        }
        if (*p == '*') {
            specifiers->flags.widthArgumentFlag = 1;
            p++;
            countPrecision++;
        }
        if (*p == '.') {
            specifiers->flags.precisionFlag = 1;
            p++;
            countPrecision++;
        }
        while (*p >= '0' && *p <= '9') {
            specifiers->precision = specifiers->precision * 10 + (*p - '0');
            p++;
            countPrecision++;
        }
        if (*p == '*' && *(p - 1) == '.') {
            specifiers->flags.precisionArgumentFlag = 1;
            p++;
            countPrecision++;
        }
        if (s21_strchr(specifiers->strfLengthDescription, *p) && *p != '\0') {
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
    
    checkSpecifiersParameters(specifiers, &countPrecision);
}

//Сброс структуры спецификатора в ноль, установка параметров
void resetSpecifiers(Specifiers *specifiers) {
    specifiers->flags.leftSideFlag = 0;
    specifiers->flags.signFlag = 0;
    specifiers->flags.spaceFlag = 0;
    specifiers->flags.zeroFlag = 0;
    specifiers->flags.sharpFlag = 0;
    specifiers->flags.precisionFlag = 0;
    specifiers->flags.widthArgumentFlag = 0;
    specifiers->flags.precisionArgumentFlag = 0;
    specifiers->width = 0;
    specifiers->precision = 0;
    specifiers->lenght.shortFlag = 0;
    specifiers->lenght.longIntFlag = 0;
    specifiers->lenght.longDoubleFlag = 0;
    specifiers->strFlags = "-+ 0#";
    specifiers->strfLengthDescription = "hlL";
    specifiers->variantsSpecifiers = ". -+#*0123456789hlL";
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
    if (c != '\0' && s21_strchr(specifiers->typeSymbols, c)) {
        return 1;
    }
    return 0;
}

//Переводит int в строку с заданной точностью
char* intToString(unsigned long int num, char *str, int precision){
    long int integerLength = getIntegerPartLength(num, 10);
    if (precision > integerLength) {
        integerLength = precision;
        
    } 
    for (long int i = integerLength - 1; i >= 0; i--) {
        str[i] = '0' + num % 10;
        num /= 10;
    }
    str[integerLength] = '\0';
    
    return str;
}

char* hexUpToString(unsigned long long num, char *str, int precision) {
    int integerLength = getIntegerPartLength(num, 16);
    if (precision > integerLength) {
        integerLength = precision;
    }
    for (int i = integerLength - 1; i >= 0; i--) {
        int digit = (num % 16);
        if (digit < 10) {
            str[i] = '0' + digit;
        } else {
            str[i] = 'A' + (digit - 10);
        }
        num /= 16;
    }
    str[integerLength] = '\0';
    
    return str;
}

char* octToString(unsigned long long num, char *str, int precision) {
    int integerLength = getIntegerPartLength(num, 8);
    if (precision > integerLength) {
        integerLength = precision;
    }
    for (int i = integerLength - 1; i >= 0; i--) {
        str[i] = '0' + num % 8;
        num /= 8;
    }
    str[integerLength] = '\0';
    
    return str;
}

// Расчет целого в числе с плавающей точкой
long int getIntegerPartLength(unsigned long long integerPart, int dividor) {
    long int length = 0;
    do {
        integerPart /= dividor;
        length++;
    } while (integerPart != 0);
    
    return length;
}

int getDoublePartLength(long double integerPart) {
    int length = 0;
    do {
        integerPart /= 10;
        length++;
    } while (integerPart >= 1);
    
    return length;
}

double roundToNDecimalPlaces(long double num, int n) {
    double multiplier = pow(10.0, n);
    return round(num * (multiplier )) / multiplier;
}

// Функция для перевода дробного числа в строку с плавающей точкой
char* doubleToFloatString(long double num, char* str, int precision) {
    if (!precision) {
        num = roundToNDecimalPlaces(num, precision);
    }
    //num = roundToNDecimalPlaces(num, precision);
    double intPart;
    double fracPart = modf(num, &intPart); //Стандартная функция, разделяет число с плавающей точкой на 2 числа double - целую и дробную часть
    int integerLength = getDoublePartLength(num);
    
    for (int i = integerLength - 1; i >= 0; i--) {
        str[i] = '0' + fmod(intPart, 10); //Стандартная функция - вычисляет остаток от деления для чисел с плавающей точкой
        intPart /= 10;
    }
    if (precision) {
        str[integerLength] = '.';
        int count = 1;
        for (int i = integerLength + 1; i < integerLength + precision + 1; i++) {
            fracPart *= 10;
            int digit = (int)(roundToNDecimalPlaces(fracPart, (precision - count)));
            str[i] = '0' + digit;
            fracPart -= digit;
            count++;
        }
        str[integerLength + 1 + precision] = '\0';
    } else {
        str[integerLength + precision] = '\0';
    }
         
    return str;
}

//Возвращает число цифр целого
int getExpLength(long double num) {
    int length = 0;
    if (num == 0) {
        return 0;
    }
    if (num >= 1) {
        num /= 10;
        while (num > 1) {
            num /= 10;
            length++;
        }
    } else {
        while (num < 1) {
            num *= 10;
            length--;
        }
    }
    
    return length;
}

//Функция для перевода дробного числа в строку с экспоненциальной записью
char* doubleToExpString(long double num, char* str, int precision) {
    int expLength = getExpLength(num);
    num = num * pow(10, -expLength);
    if (!precision) {
        num = roundToNDecimalPlaces(num, precision);
    }
    double intPart;
    double fracPart = modf(num, &intPart);   
    str[0] = '0' + fmod(intPart, 10);
    
    if (precision) {
        str[1] = '.';
        for (int i = 2; i < precision + 2; i++) {
            fracPart *= 10;
            int digit = (int)(roundToNDecimalPlaces(fracPart, (precision - i + 1)));
            str[i] = '0' + digit;
            fracPart -= digit;
        }
        str[precision + 2] = '\0';
    } else {
        str[1] = '\0';
    }
        
    char exp[10];
    char *p = exp;
    *p++ = 'E';
    if (expLength >= 0) {
        *p++ = '+';
    } else {
        *p++ = '-';
        expLength *= -1;
    }
    intToString(expLength, p, 2);
    s21_strncat(str, exp, s21_strlen(exp));

    return str;
}

//Возвращает знак %
char* percentToString() {
    char *strPersent = malloc(2);
    strPersent[0] = '%';
    strPersent[1] = '\0';
    return strPersent; 
}

char* myToLower(char *str) {
  s21_size_t length = s21_strlen(str);
  for (s21_size_t i = 0; i < length; i++) {
    if (str[i] >= 65 && str[i] <= 90) {
      str[i] = str[i] + 32;
      continue;
    }
  }

  return str;
}