#include <stdint.h>
#include <stdio.h>
#include <math.h>

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
// Общее количество бит основания decimal (целого числа, которое хранит значение decimal)
#define BITS_3 96

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