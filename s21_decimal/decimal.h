#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s21_decimal {
  int bits[4];
} s21_decimal;

typedef union decimal_bit3 {
  int i;
  struct {
    uint32_t empty2 : 16;
    uint32_t power : 8;
    uint32_t empty1 : 7;
    uint32_t sign : 1;
  } parts;
} decimal_bit3;

#define MAX_BLOCK_BITS 32
// Общее количество бит основания decimal (целого числа, которое хранит значение
// decimal)
#define BITS_3 96

typedef enum s21_decimal_sign {
  S21_POSITIVE = 0,
  S21_NEGATIVE = 1
} s21_decimal_sign;

typedef enum s21_arithmetic_result {
  S21_ARITHMETIC_OK = 0,
  S21_ARITHMETIC_BIG = 1,
  S21_ARITHMETIC_SMALL = 2,
  S21_ARITHMETIC_ZERO_DIV = 3,
  S21_ARITHMETIC_ERROR = 4
} s21_arithmetic_result;

typedef enum s21_comparison_result {
  S21_COMPARISON_FALSE = 0,
  S21_COMPARISON_TRUE = 1,
} s21_comparison_result;

typedef enum s21_conversion_result {
  S21_CONVERSION_FALSE = 0,
  S21_CONVERSION_TRUE = 1,
} s21_conversion_result;


int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int findFirstSetBitPosition(long int num);

int findMostSignificantSetBitPosition(int number);

int bit_field_shift_left(s21_decimal *bf);

int setBitAtPosition(int num, int position);

int setBitToZero(unsigned int num, int position);

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int null_value_bits_struct_decimal(s21_decimal value);

void bit_field_shift_right(s21_decimal *bf);

void print_value_bits_struct_decimal(s21_decimal value);

int get_scale(s21_decimal dec);

void set_scale(s21_decimal *dec, int scale);

int get_bit(s21_decimal dec, int pos);

void set_bit(s21_decimal *dec, int bit, int pos);

int get_exp_length(long double num);

int s21_from_float_to_decimal(float src, s21_decimal *dst);

void set_sign(s21_decimal *decimal, int sign);

void s21_set_scale(s21_decimal *decimal, int scale);

int s21_from_int_to_decimal(int src, s21_decimal *dst);

int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_get_sign(s21_decimal decimal);