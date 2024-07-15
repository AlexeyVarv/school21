#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>

typedef struct s21_decimal {
    int bits[4];
} s21_decimal;

typedef struct s21_int256 {
    s21_decimal decimals[2];
} s21_int256;

// Общее количество бит в decimal
#define MAX_BITS 128
// Общее количество бит в одном элементе массива
#define MAX_BLOCK_BITS 32
// Общее количество бит основания decimal (целого числа, которое хранит значение decimal)
#define MAX_BLOCK_NUMBER 96

/**
 * @brief объединение для получения доступа к данным bits[3] decimal
 * 16 бит: Биты от 0 до 15, младшее слово, не используются и должны быть равны нулю.
 * 8 бит: Биты с 16 по 23 должны содержать показатель степени от 0 до 28.
 * 7 бит: Биты с 24 по 30 не используются и должны быть равны нулю.
 * 1 бит: Бит 31 содержит знак; 0 означает положительный, а 1 означает отрицательный.
 * Итого 32 бита
 * @author Hubert Furr (hubertfu@student.21-school.ru)
 */
typedef union decimal_bit3 {
    int i;
    struct {
        uint32_t empty2 : 16;
        uint32_t power : 8;
        uint32_t empty1 : 7;
        uint32_t sign : 1;
    } parts;
} decimal_bit3;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int findFirstSetBitPosition(long int num);

int findMostSignificantSetBitPosition(long int num);

void putLongIntToDecimal(s21_decimal *num, long int a);

int setBitAtPosition(int num, int position);