#include "decimal.h"

int main() {
  s21_decimal num1 = {0};
  s21_decimal num2 = {0};
  s21_decimal result = {0};
  num1.bits[0] = -1316487168;
  num2.bits[0] = -1316487168;
  num1.bits[1] = -1243369706;
  num2.bits[1] = -1243369706;
  num1.bits[2] = 2;
  num2.bits[2] = 2;

  int sum = s21_add(num1, num2, &result);
  print_value_bits_struct_decimal(result);
  printf("result: %d\n", sum);

  s21_decimal num1_1 = {0};
  s21_decimal num2_1 = {0};
  s21_decimal result_1 = {0};
  num1_1.bits[0] = 0;
  num2_1.bits[0] = 0;
  num1_1.bits[1] = 1;
  num2_1.bits[1] = 1;
  num1_1.bits[2] = 0;
  num2_1.bits[2] = 0;

  int sum_1 = s21_mul(num1_1, num2_1, &result_1);
  print_value_bits_struct_decimal(result_1);
  printf("result: %d\n", sum_1);

  float number1 = 255689.7894e20f;

  // Выводим результаты
  printf("\n---CONVERSION---\n");
  s21_decimal result_2 = {0};
  s21_from_float_to_decimal(number1, &result_2);
  printf("%.6E\n", number1);
  print_value_bits_struct_decimal(result_2);
  float conversed_dec = 0;
  s21_from_decimal_to_float(result_2, &conversed_dec);
  printf("%.6E\n", conversed_dec);

  return 0;
}
