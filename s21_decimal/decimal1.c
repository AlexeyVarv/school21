#include "decimal.h"


int main() {
    s21_decimal num1 = {0};
    s21_decimal num2 = {0};
    s21_decimal result = {0};
    num1.bits[0] = 100;
    num2.bits[0] = 11;
    num1.bits[1] = 0;
    num2.bits[1] = 0;
    num1.bits[2] = 0;
    num2.bits[2] = 0;

    int sum = s21_add(num1, num2, &result);
    print_value_bits_struct_decimal(result);
    printf("result: %d\n", sum);
    
    s21_decimal num1_1 = {0};
    s21_decimal num2_1 = {0};
    s21_decimal result_1 = {0};
    num1_1.bits[0] = 3555365;
    num2_1.bits[0] = 5524127;
    num1_1.bits[1] = 15;
    num2_1.bits[1] = 23;
    num1_1.bits[2] = 0;
    num2_1.bits[2] = 0;

    int sum_1 = s21_mul(num1_1, num2_1, &result_1);
    print_value_bits_struct_decimal(result_1);
    printf("result: %d\n", sum_1);

    float number1 = 0.0f;
    
    // Выводим результаты
    printf("\n---CONVERSION---\n");
    s21_decimal result_2 = {0};
    s21_from_float_to_decimal(number1, &result_2);
    printf("%.6E\n", number1);
    print_value_bits_struct_decimal(result_2);
    return 0;
}
