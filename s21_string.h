#pragma once

#include "check/src/check.h"
#include "check/check_stdint.h"
#include "check/config.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>

size_t s21_strlen(const char *str);
char* s21_strchr(const char *str, int c);
char *s21_strchr_2(const char *str, int c);