#include "s21_string.h"

size_t s21_strlen(const char *str) {
    const char *p = str;
    while (*str) {
        str++;
    }
    return str - p;
}