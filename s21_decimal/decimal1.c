#include <stdint.h>
#include <stdio.h>
#include <math.h>

typedef struct s21_decimal {
    int bits[4];
} s21_decimal;


#define MAX_BLOCK_BITS 32
// Общее количество бит основания decimal (целого числа, которое хранит значение decimal)
#define MAX_BLOCK_NUMBER 96

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int findFirstSetBitPosition(long int num);

int findMostSignificantSetBitPosition(int number);

void bitFieldShiftLeft(s21_decimal *bf);

int setBitAtPosition(int num, int position);

int setBitToZero(unsigned int num, int position);

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int nullValueBitsStructDecimal(s21_decimal value);

void bitFieldShiftRight(s21_decimal *bf);

void printValueBitsStructDecimal(s21_decimal value);



int main() {
    int x_0 = 4000000000;
    int y_0 = 2000000000;
    int x_1 = 0;
    int y_1 = 0;
    
    s21_decimal num1 = {0};
    s21_decimal num2 = {0};
    s21_decimal result = {0};
    num1.bits[0] = x_0;
    num2.bits[0] = y_0;
    num1.bits[1] = x_1;
    num2.bits[1] = y_1;

    int sum = s21_add(num1, num2, &result);

    printf("%d %d %d\n", result.bits[0], result.bits[1], result.bits[2]);
    printf("%d\n", sum);

    s21_decimal num1_1 = {0};
    s21_decimal num2_1 = {0};
    s21_decimal result_1 = {0};
    num1_1.bits[0] = 150125;
    num2_1.bits[0] = 755624;
    num1_1.bits[1] = 0;
    num2_1.bits[1] = 0;

    int sum_1 = s21_mul(num1_1, num2_1, &result_1);
    printf("%d %d %d\n", result_1.bits[0], result_1.bits[1], result_1.bits[2]);

    return 0;
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int temp_a_0 = value_1.bits[0];
    int temp_b_0 = value_2.bits[0];
    int temp_a_1 = value_1.bits[1];
    int temp_b_1 = value_2.bits[1];
    int temp_a_2 = value_1.bits[2];
    int temp_b_2 = value_2.bits[2];

    int count = 0;
        
    while (temp_b_0 + temp_b_1 + temp_b_2 != 0) {
        result->bits[0] = temp_a_0 & temp_b_0;
        result->bits[1] = temp_a_1 & temp_b_1;
        result->bits[2] = temp_a_2 & temp_b_2;
        temp_a_0 = temp_a_0 ^ temp_b_0;
        temp_a_1 = temp_a_1 ^ temp_b_1;
        temp_a_2 = temp_a_2 ^ temp_b_2;
        bitFieldShiftLeft(result);
        temp_b_0 = result->bits[0];
        temp_b_1 = result->bits[1];
        temp_b_2 = result->bits[2];
        count++; 
    }

    result->bits[0] = temp_a_0;
    result->bits[1] = temp_a_1;
    result->bits[2] = temp_a_2;

    return 0;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    s21_decimal temp_result = {0};
    s21_decimal temp_value_1 = value_1;
    s21_decimal temp_value_2 = value_2;
    int count = 0;

    while (!nullValueBitsStructDecimal(temp_value_2) && count < 96) {
        //printValueBitsStructDecimal(temp_value_2);
        if ((temp_value_2.bits[0] & 1) || (temp_value_2.bits[1] & 1) || (temp_value_2.bits[2] & 1)) {
            s21_add(temp_result, temp_value_1, &temp_result);
        }
        //printValueBitsStructDecimal(temp_result);  
        bitFieldShiftLeft(&temp_value_1);
        bitFieldShiftRight(&temp_value_2);
        count++;
    }

    *result = temp_result;

    return 0;
}

void bitFieldShiftLeft(s21_decimal *bf) {
    uint32_t tempA = bf->bits[0];
    uint32_t tempB = bf->bits[1];
    uint32_t tempC = bf->bits[2];
    //uint32_t tempD = bf->bits[3];

    // Сдвигаем каждый int на 1 бит влево
    bf->bits[3] <<= 1;
    if (tempC & 0x80000000) {
        printf("Overflow!\n");
    }
    bf->bits[2] <<= 1;
    if (tempB & 0x80000000) {
        bf->bits[2] |= 0x01;
    }
    bf->bits[1] <<= 1;
    if (tempA & 0x80000000) {
        bf->bits[1] |= 0x01;
    }
    bf->bits[0] <<= 1;
}

void bitFieldShiftRight(s21_decimal *bf) {
    uint32_t tempB = bf->bits[1];
    uint32_t tempC = bf->bits[2];
    
    // Сдвигаем каждый int на 1 бит вправо
    bf->bits[0] >>= 1;
    if (tempB & 0x01) {
        bf->bits[0] |= 0x80000000;
    } else {
        bf->bits[0] &= ~(1 << 31);
    }
    bf->bits[1] >>= 1;
    if (tempC & 0x01) {
        bf->bits[1] |= 0x80000000;
    } else {
        bf->bits[1] &= ~(1 << 31);
    }
    bf->bits[2] >>= 1;
}

int nullValueBitsStructDecimal(s21_decimal value) {
    int result = 0;
    if (value.bits[0] == 0 && value.bits[1] == 0 && value.bits[2] == 0) {
        result = 1;
    }

    return result;
}

void printValueBitsStructDecimal(s21_decimal value) {
    printf("***%d %d %d***\n", value.bits[0], value.bits[1], value.bits[2]);
}




int setBitAtPosition(int num, int position) {
    int mask = 1 << position;
    return num | mask;
}

int findMostSignificantSetBitPosition(int num) {
    int position = 0;
    while (num != 0) {
        num = num >> 1;
        position++;
    }
    
    return position - 1;
}

int findFirstSetBitPosition(long int num) {
    int position = 0;
    
    while ((num & 1) == 0) {
        num = num >> 1;
        position++;
    }
    
    return position;
}

int setBitToZero(unsigned int num, int position) {
    unsigned int mask = ~(1 << position);  // Создаем маску с установленным битом в позиции position
    return num & mask;  // Устанавливаем 0 бит в позиции position и возвращаем результат
}
