#pragma once

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>

size_t s21_strlen(const char *str);
char* s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char* s21_strncat(char *dest, const char *src, size_t n);
