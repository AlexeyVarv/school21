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
    if (c == 0) {
        return (char*)(str + s21_strlen(str));
    }
    while(*str) {
        if (*str == c) {
            return (char*)str;
        }
        str++;
    }
    
    return NULL;
}

int s21_strncmp(const char *str1, const char *str2, size_t n) {
    for(size_t i = 0; i < n; i++) {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
    }
    return 0;
}

char* s21_strncat(char *dest, const char *src, size_t n) {
    char *p = dest;
    while(*p) {
        p++;
    }
    size_t i = 0;
    while(*src) {
        if (i >= n) {
            break;
        }
        *p++ = *src++;
        i++;
    }
    *p = '\0';

    return dest;
}

char* s21_strncpy(char *dest, const char *src, size_t n) {
    char *p = dest;
    size_t i = 0;
    do {
        if (i >= n) {
            break;;
        }
        *p++ = *src++;
        i++;
    } while(*src);
    while(*p) {
        p++;
    }
    *p = '\0';

    return dest;
}