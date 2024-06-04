#include "s21_string.h"

size_t s21_strlen(const char *str) {
    const char *p = str;
    while (*str) {
        str++;
    }
    return str - p;
}

char *s21_strchr(const char *str, int c) {
    if (str == NULL) {
        return NULL;
    }
    
    while(*str) {
        if (*str == c) {
            return (char*)str; // Возвращаем указатель на найденный символ
        }
        str++;
    }
    
    return NULL; // Символ не найден
}
