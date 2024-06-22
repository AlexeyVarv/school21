#include "test_s21.h"

START_TEST(Case_G_g_spec_null_value) {
  // Простой случай, форматирование строки с одной переменной
  double x = 0.0;
  char testString1[500];
  char testString2[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testString1, "Output with noFlags: %G signFlag: %+G sharpFlag: %#G nullFlag: %01G spaceFlag: % G leftSideFlag: %-G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with noFlags: %G signFlag: %+G sharpFlag: %#G nullFlag: %01G spaceFlag: % G leftSideFlag: %-G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with WIGTH + noFlags: %10G signFlag: %+10G sharpFlag: %#10G zeroFlag: %010G spaceFlag: % 10G leftSideFlag: %-10G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with WIGTH + noFlags: %10G signFlag: %+10G sharpFlag: %#10G zeroFlag: %010G spaceFlag: % 10G leftSideFlag: %-10G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with Zero_PRECISION + noFlags: %.G signFlag: %+.G sharpFlag: %#.G zeroFlag: %0.G spaceFlag: % .G leftSideFlag: %-.G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with Zero_PRECISION + noFlags: %.G signFlag: %+.G sharpFlag: %#.G zeroFlag: %0.G spaceFlag: % .G leftSideFlag: %-.G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 3_decimal_PRECISION + noFlags: %.3G signFlag: %+.3G sharpFlag: %#.3G zeroFlag: %0.3G spaceFlag: % .3G leftSideFlag: %-.3G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 3_decimal_PRECISION + noFlags: %.3G signFlag: %+.3G sharpFlag: %#.3G zeroFlag: %0.3G spaceFlag: % .3G leftSideFlag: %-.3G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 10_decimal_PRECISION + noFlags: %.10G signFlag: %+.10G sharpFlag: %#.10G zeroFlag: %0.10G spaceFlag: % .10G leftSideFlag: %-.10G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 10_decimal_PRECISION + noFlags: %.10G signFlag: %+.10G sharpFlag: %#.10G zeroFlag: %0.10G spaceFlag: % .10G leftSideFlag: %-.10G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 14_decimal_PRECISION + noFlags: %.14G signFlag: %+.14G sharpFlag: %#.14G zeroFlag: %0.14G spaceFlag: % .14G leftSideFlag: %-.14G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 14_decimal_PRECISION + noFlags: %.14G signFlag: %+.14G sharpFlag: %#.14G zeroFlag: %0.14G spaceFlag: % .14G leftSideFlag: %-.14G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10G signFlag: %+20.10G sharpFlag: %#20.10G zeroFlag: %020.10G spaceFlag: % 20.10G leftSideFlag: %-20.10G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10G signFlag: %+20.10G sharpFlag: %#20.10G zeroFlag: %020.10G spaceFlag: % 20.10G leftSideFlag: %-20.10G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5G signFlag + leftSideFlag: %-+20.5G sharpFlag + zeroFlag: %#020.5G spaceFlag + zeroFlag: % 020.5G zeroFlag + signFlag: %0+20.5G leftSideFlag + spaceFlag: %- 20.5G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5G signFlag + leftSideFlag: %-+20.5G sharpFlag + zeroFlag: %#020.5G spaceFlag + zeroFlag: % 020.5G zeroFlag + signFlag: %0+20.5G leftSideFlag + spaceFlag: %- 20.5G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5g signFlag + leftSideFlag: %-+20.5g sharpFlag + zeroFlag: %#020.5g spaceFlag + zeroFlag: % 20.5g zroFlag + signFlag: %0+20.5g leftSideFlag + spaceFlag: %- 20.5g", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5g signFlag + leftSideFlag: %-+20.5g sharpFlag + zeroFlag: %#020.5g spaceFlag + zeroFlag: % 20.5g zroFlag + signFlag: %0+20.5g leftSideFlag + spaceFlag: %- 20.5g", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_G_g_spec_random_value) {
  // Простой случай, форматирование строки с одной переменной
  double x = 1523697.70157826369542569;
  char testString1[500];
  char testString2[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testString1, "Output with noFlags: %G signFlag: %+G sharpFlag: %#G nullFlag: %01G spaceFlag: % G leftSideFlag: %-G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with noFlags: %G signFlag: %+G sharpFlag: %#G nullFlag: %01G spaceFlag: % G leftSideFlag: %-G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with WIGTH + noFlags: %10G signFlag: %+10G sharpFlag: %#10G zeroFlag: %010G spaceFlag: % 10G leftSideFlag: %-10G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with WIGTH + noFlags: %10G signFlag: %+10G sharpFlag: %#10G zeroFlag: %010G spaceFlag: % 10G leftSideFlag: %-10G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with Zero_PRECISION + noFlags: %.G signFlag: %+.G sharpFlag: %#.G zeroFlag: %0.G spaceFlag: % .G leftSideFlag: %-.G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with Zero_PRECISION + noFlags: %.G signFlag: %+.G sharpFlag: %#.G zeroFlag: %0.G spaceFlag: % .G leftSideFlag: %-.G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 3_decimal_PRECISION + noFlags: %.3G signFlag: %+.3G sharpFlag: %#.3G zeroFlag: %0.3G spaceFlag: % .3G leftSideFlag: %-.3G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 3_decimal_PRECISION + noFlags: %.3G signFlag: %+.3G sharpFlag: %#.3G zeroFlag: %0.3G spaceFlag: % .3G leftSideFlag: %-.3G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 10_decimal_PRECISION + noFlags: %.10G signFlag: %+.10G sharpFlag: %#.10G zeroFlag: %0.10G spaceFlag: % .10G leftSideFlag: %-.10G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 10_decimal_PRECISION + noFlags: %.10G signFlag: %+.10G sharpFlag: %#.10G zeroFlag: %0.10G spaceFlag: % .10G leftSideFlag: %-.10G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 14_decimal_PRECISION + noFlags: %.14G signFlag: %+.14G sharpFlag: %#.14G zeroFlag: %0.14G spaceFlag: % .14G leftSideFlag: %-.14G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 14_decimal_PRECISION + noFlags: %.14G signFlag: %+.14G sharpFlag: %#.14G zeroFlag: %0.14G spaceFlag: % .14G leftSideFlag: %-.14G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10G signFlag: %+20.10G sharpFlag: %#20.10G zeroFlag: %020.10G spaceFlag: % 20.10G leftSideFlag: %-20.10G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10G signFlag: %+20.10G sharpFlag: %#20.10G zeroFlag: %020.10G spaceFlag: % 20.10G leftSideFlag: %-20.10G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5G signFlag + leftSideFlag: %-+20.5G sharpFlag + zeroFlag: %#020.5G spaceFlag + zeroFlag: % 020.5G zeroFlag + signFlag: %0+20.5G leftSideFlag + spaceFlag: %- 20.5G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5G signFlag + leftSideFlag: %-+20.5G sharpFlag + zeroFlag: %#020.5G spaceFlag + zeroFlag: % 020.5G zeroFlag + signFlag: %0+20.5G leftSideFlag + spaceFlag: %- 20.5G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5g signFlag + leftSideFlag: %-+20.5g sharpFlag + zeroFlag: %#020.5g spaceFlag + zeroFlag: % 20.5g zroFlag + signFlag: %0+20.5g leftSideFlag + spaceFlag: %- 20.5g", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5g signFlag + leftSideFlag: %-+20.5g sharpFlag + zeroFlag: %#020.5g spaceFlag + zeroFlag: % 20.5g zroFlag + signFlag: %0+20.5g leftSideFlag + spaceFlag: %- 20.5g", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_G_g_spec_random_small_value) {
  // Простой случай, форматирование строки с одной переменной
  double x = 0.000000070157826369542569;
  char testString1[500];
  char testString2[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testString1, "Output with noFlags: %G signFlag: %+G sharpFlag: %#G nullFlag: %01G spaceFlag: % G leftSideFlag: %-G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with noFlags: %G signFlag: %+G sharpFlag: %#G nullFlag: %01G spaceFlag: % G leftSideFlag: %-G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with WIGTH + noFlags: %10G signFlag: %+10G sharpFlag: %#10G zeroFlag: %010G spaceFlag: % 10G leftSideFlag: %-10G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with WIGTH + noFlags: %10G signFlag: %+10G sharpFlag: %#10G zeroFlag: %010G spaceFlag: % 10G leftSideFlag: %-10G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with Zero_PRECISION + noFlags: %.G signFlag: %+.G sharpFlag: %#.G zeroFlag: %0.G spaceFlag: % .G leftSideFlag: %-.G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with Zero_PRECISION + noFlags: %.G signFlag: %+.G sharpFlag: %#.G zeroFlag: %0.G spaceFlag: % .G leftSideFlag: %-.G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 3_decimal_PRECISION + noFlags: %.3G signFlag: %+.3G sharpFlag: %#.3G zeroFlag: %0.3G spaceFlag: % .3G leftSideFlag: %-.3G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 3_decimal_PRECISION + noFlags: %.3G signFlag: %+.3G sharpFlag: %#.3G zeroFlag: %0.3G spaceFlag: % .3G leftSideFlag: %-.3G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 10_decimal_PRECISION + noFlags: %.10G signFlag: %+.10G sharpFlag: %#.10G zeroFlag: %0.10G spaceFlag: % .10G leftSideFlag: %-.10G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 10_decimal_PRECISION + noFlags: %.10G signFlag: %+.10G sharpFlag: %#.10G zeroFlag: %0.10G spaceFlag: % .10G leftSideFlag: %-.10G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 14_decimal_PRECISION + noFlags: %.14G signFlag: %+.14G sharpFlag: %#.14G zeroFlag: %0.14G spaceFlag: % .14G leftSideFlag: %-.14G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 14_decimal_PRECISION + noFlags: %.14G signFlag: %+.14G sharpFlag: %#.14G zeroFlag: %0.14G spaceFlag: % .14G leftSideFlag: %-.14G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10G signFlag: %+20.10G sharpFlag: %#20.10G zeroFlag: %020.10G spaceFlag: % 20.10G leftSideFlag: %-20.10G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10G signFlag: %+20.10G sharpFlag: %#20.10G zeroFlag: %020.10G spaceFlag: % 20.10G leftSideFlag: %-20.10G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5G signFlag + leftSideFlag: %-+20.5G sharpFlag + zeroFlag: %#020.5G spaceFlag + zeroFlag: % 020.5G zeroFlag + signFlag: %0+20.5G leftSideFlag + spaceFlag: %- 20.5G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5G signFlag + leftSideFlag: %-+20.5G sharpFlag + zeroFlag: %#020.5G spaceFlag + zeroFlag: % 020.5G zeroFlag + signFlag: %0+20.5G leftSideFlag + spaceFlag: %- 20.5G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5g signFlag + leftSideFlag: %-+20.5g sharpFlag + zeroFlag: %#020.5g spaceFlag + zeroFlag: % 20.5g zroFlag + signFlag: %0+20.5g leftSideFlag + spaceFlag: %- 20.5g", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5g signFlag + leftSideFlag: %-+20.5g sharpFlag + zeroFlag: %#020.5g spaceFlag + zeroFlag: % 20.5g zroFlag + signFlag: %0+20.5g leftSideFlag + spaceFlag: %- 20.5g", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST


START_TEST(Case_G_g_spec_random_big_value) {
  // Простой случай, форматирование строки с одной переменной
  double x = 170157826369542569e150;
  char testString1[500];
  char testString2[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testString1, "Output with noFlags: %G signFlag: %+G sharpFlag: %#G nullFlag: %01G spaceFlag: % G leftSideFlag: %-G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with noFlags: %G signFlag: %+G sharpFlag: %#G nullFlag: %01G spaceFlag: % G leftSideFlag: %-G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with WIGTH + noFlags: %10G signFlag: %+10G sharpFlag: %#10G zeroFlag: %010G spaceFlag: % 10G leftSideFlag: %-10G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with WIGTH + noFlags: %10G signFlag: %+10G sharpFlag: %#10G zeroFlag: %010G spaceFlag: % 10G leftSideFlag: %-10G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with Zero_PRECISION + noFlags: %.G signFlag: %+.G sharpFlag: %#.G zeroFlag: %0.G spaceFlag: % .G leftSideFlag: %-.G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with Zero_PRECISION + noFlags: %.G signFlag: %+.G sharpFlag: %#.G zeroFlag: %0.G spaceFlag: % .G leftSideFlag: %-.G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 3_decimal_PRECISION + noFlags: %.3G signFlag: %+.3G sharpFlag: %#.3G zeroFlag: %0.3G spaceFlag: % .3G leftSideFlag: %-.3G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 3_decimal_PRECISION + noFlags: %.3G signFlag: %+.3G sharpFlag: %#.3G zeroFlag: %0.3G spaceFlag: % .3G leftSideFlag: %-.3G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 10_decimal_PRECISION + noFlags: %.10G signFlag: %+.10G sharpFlag: %#.10G zeroFlag: %0.10G spaceFlag: % .10G leftSideFlag: %-.10G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 10_decimal_PRECISION + noFlags: %.10G signFlag: %+.10G sharpFlag: %#.10G zeroFlag: %0.10G spaceFlag: % .10G leftSideFlag: %-.10G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 14_decimal_PRECISION + noFlags: %.14G signFlag: %+.14G sharpFlag: %#.14G zeroFlag: %0.14G spaceFlag: % .14G leftSideFlag: %-.14G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 14_decimal_PRECISION + noFlags: %.14G signFlag: %+.14G sharpFlag: %#.14G zeroFlag: %0.14G spaceFlag: % .14G leftSideFlag: %-.14G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10G signFlag: %+20.10G sharpFlag: %#20.10G zeroFlag: %020.10G spaceFlag: % 20.10G leftSideFlag: %-20.10G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10G signFlag: %+20.10G sharpFlag: %#20.10G zeroFlag: %020.10G spaceFlag: % 20.10G leftSideFlag: %-20.10G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5G signFlag + leftSideFlag: %-+20.5G sharpFlag + zeroFlag: %#020.5G spaceFlag + zeroFlag: % 020.5G zeroFlag + signFlag: %0+20.5G leftSideFlag + spaceFlag: %- 20.5G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5G signFlag + leftSideFlag: %-+20.5G sharpFlag + zeroFlag: %#020.5G spaceFlag + zeroFlag: % 020.5G zeroFlag + signFlag: %0+20.5G leftSideFlag + spaceFlag: %- 20.5G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5g signFlag + leftSideFlag: %-+20.5g sharpFlag + zeroFlag: %#020.5g spaceFlag + zeroFlag: % 20.5g zroFlag + signFlag: %0+20.5g leftSideFlag + spaceFlag: %- 20.5g", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5g signFlag + leftSideFlag: %-+20.5g sharpFlag + zeroFlag: %#020.5g spaceFlag + zeroFlag: % 20.5g zroFlag + signFlag: %0+20.5g leftSideFlag + spaceFlag: %- 20.5g", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_G_g_spec_negative_value) {
  // Простой случай, форматирование строки с одной переменной
  double x = -170157826369.542569e30;
  char testString1[500];
  char testString2[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testString1, "Output with noFlags: %G signFlag: %+G sharpFlag: %#G nullFlag: %01G spaceFlag: % G leftSideFlag: %-G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with noFlags: %G signFlag: %+G sharpFlag: %#G nullFlag: %01G spaceFlag: % G leftSideFlag: %-G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with WIGTH + noFlags: %10G signFlag: %+10G sharpFlag: %#10G zeroFlag: %010G spaceFlag: % 10G leftSideFlag: %-10G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with WIGTH + noFlags: %10G signFlag: %+10G sharpFlag: %#10G zeroFlag: %010G spaceFlag: % 10G leftSideFlag: %-10G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with Zero_PRECISION + noFlags: %.G signFlag: %+.G sharpFlag: %#.G zeroFlag: %0.G spaceFlag: % .G leftSideFlag: %-.G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with Zero_PRECISION + noFlags: %.G signFlag: %+.G sharpFlag: %#.G zeroFlag: %0.G spaceFlag: % .G leftSideFlag: %-.G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 3_decimal_PRECISION + noFlags: %.3G signFlag: %+.3G sharpFlag: %#.3G zeroFlag: %0.3G spaceFlag: % .3G leftSideFlag: %-.3G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 3_decimal_PRECISION + noFlags: %.3G signFlag: %+.3G sharpFlag: %#.3G zeroFlag: %0.3G spaceFlag: % .3G leftSideFlag: %-.3G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 10_decimal_PRECISION + noFlags: %.10G signFlag: %+.10G sharpFlag: %#.10G zeroFlag: %0.10G spaceFlag: % .10G leftSideFlag: %-.10G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 10_decimal_PRECISION + noFlags: %.10G signFlag: %+.10G sharpFlag: %#.10G zeroFlag: %0.10G spaceFlag: % .10G leftSideFlag: %-.10G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 14_decimal_PRECISION + noFlags: %.14G signFlag: %+.14G sharpFlag: %#.14G zeroFlag: %0.14G spaceFlag: % .14G leftSideFlag: %-.14G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 14_decimal_PRECISION + noFlags: %.14G signFlag: %+.14G sharpFlag: %#.14G zeroFlag: %0.14G spaceFlag: % .14G leftSideFlag: %-.14G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10G signFlag: %+20.10G sharpFlag: %#20.10G zeroFlag: %020.10G spaceFlag: % 20.10G leftSideFlag: %-20.10G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10G signFlag: %+20.10G sharpFlag: %#20.10G zeroFlag: %020.10G spaceFlag: % 20.10G leftSideFlag: %-20.10G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5G signFlag + leftSideFlag: %-+20.5G sharpFlag + zeroFlag: %#020.5G spaceFlag + zeroFlag: % 020.5G zeroFlag + signFlag: %0+20.5G leftSideFlag + spaceFlag: %- 20.5G", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5G signFlag + leftSideFlag: %-+20.5G sharpFlag + zeroFlag: %#020.5G spaceFlag + zeroFlag: % 020.5G zeroFlag + signFlag: %0+20.5G leftSideFlag + spaceFlag: %- 20.5G", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5g signFlag + leftSideFlag: %-+20.5g sharpFlag + zeroFlag: %#020.5g spaceFlag + zeroFlag: % 20.5g zroFlag + signFlag: %0+20.5g leftSideFlag + spaceFlag: %- 20.5g", x, x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5g signFlag + leftSideFlag: %-+20.5g sharpFlag + zeroFlag: %#020.5g spaceFlag + zeroFlag: % 20.5g zroFlag + signFlag: %0+20.5g leftSideFlag + spaceFlag: %- 20.5g", x, x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_f_spec_null_value) {
  // Простой случай, форматирование строки с одной переменной
  double x = 0.0;
  char testStrinf1[500];
  char testStrinf2[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testStrinf1, "Output with noflags: %f signflag: %+f sharpflag: %#f nullflag: %01f spaceflag: % f leftSideflag: %-f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with noflags: %f signflag: %+f sharpflag: %#f nullflag: %01f spaceflag: % f leftSideflag: %-f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with WIfTH + noflags: %10f signflag: %+10f sharpflag: %#10f zeroflag: %010f spaceflag: % 10f leftSideflag: %-10f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with WIfTH + noflags: %10f signflag: %+10f sharpflag: %#10f zeroflag: %010f spaceflag: % 10f leftSideflag: %-10f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with Zero_PRECISION + noflags: %.f signflag: %+.f sharpflag: %#.f zeroflag: %0.f spaceflag: % .f leftSideflag: %-.f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with Zero_PRECISION + noflags: %.f signflag: %+.f sharpflag: %#.f zeroflag: %0.f spaceflag: % .f leftSideflag: %-.f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 3_decimal_PRECISION + noflags: %.3f signflag: %+.3f sharpflag: %#.3f zeroflag: %0.3f spaceflag: % .3f leftSideflag: %-.3f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 3_decimal_PRECISION + noflags: %.3f signflag: %+.3f sharpflag: %#.3f zeroflag: %0.3f spaceflag: % .3f leftSideflag: %-.3f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 15_decimal_PRECISION + noflags: %.10f signflag: %+.10f sharpflag: %#.10f zeroflag: %0.10f spaceflag: % .10f leftSideflag: %-.10f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 15_decimal_PRECISION + noflags: %.10f signflag: %+.10f sharpflag: %#.10f zeroflag: %0.10f spaceflag: % .10f leftSideflag: %-.10f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 15_decimal_PRECISION + noflags: %.15f", x);
  controlNum = sprintf(testStrinf2, "Output with 15_decimal_PRECISION + noflags: %.15f", x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 30_characters_WIDTH and 10_decimal_PRECISION + noflags: %30.10f signflag: %+30.10f sharpflag: %#30.10f zeroflag: %030.10f spaceflag: % 30.10f leftSideflag: %-30.10f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 30_characters_WIDTH and 10_decimal_PRECISION + noflags: %30.10f signflag: %+30.10f sharpflag: %#30.10f zeroflag: %030.10f spaceflag: % 30.10f leftSideflag: %-30.10f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noflags: %20.5f signflag + leftSideflag: %-+20.5f sharpflag + zeroflag: %#020.5f spaceflag + zeroflag: % 020.5f zeroflag + signflag: %0+20.5f leftSideflag + spaceflag: %- 20.5f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noflags: %20.5f signflag + leftSideflag: %-+20.5f sharpflag + zeroflag: %#020.5f spaceflag + zeroflag: % 020.5f zeroflag + signflag: %0+20.5f leftSideflag + spaceflag: %- 20.5f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_f_spec_random_small_value) {
  // Простой случай, форматирование строки с одной переменной
  double x = 0.1285970157826369542569;
  char testStrinf1[500];
  char testStrinf2[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testStrinf1, "Output with noflags: %f signflag: %+f sharpflag: %#f nullflag: %01f spaceflag: % f leftSideflag: %-f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with noflags: %f signflag: %+f sharpflag: %#f nullflag: %01f spaceflag: % f leftSideflag: %-f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with WIfTH + noflags: %10f signflag: %+10f sharpflag: %#10f zeroflag: %010f spaceflag: % 10f leftSideflag: %-10f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with WIfTH + noflags: %10f signflag: %+10f sharpflag: %#10f zeroflag: %010f spaceflag: % 10f leftSideflag: %-10f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with Zero_PRECISION + noflags: %.f signflag: %+.f sharpflag: %#.f zeroflag: %0.f spaceflag: % .f leftSideflag: %-.f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with Zero_PRECISION + noflags: %.f signflag: %+.f sharpflag: %#.f zeroflag: %0.f spaceflag: % .f leftSideflag: %-.f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 3_decimal_PRECISION + noflags: %.3f signflag: %+.3f sharpflag: %#.3f zeroflag: %0.3f spaceflag: % .3f leftSideflag: %-.3f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 3_decimal_PRECISION + noflags: %.3f signflag: %+.3f sharpflag: %#.3f zeroflag: %0.3f spaceflag: % .3f leftSideflag: %-.3f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 15_decimal_PRECISION + noflags: %.10f signflag: %+.10f sharpflag: %#.10f zeroflag: %0.10f spaceflag: % .10f leftSideflag: %-.10f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 15_decimal_PRECISION + noflags: %.10f signflag: %+.10f sharpflag: %#.10f zeroflag: %0.10f spaceflag: % .10f leftSideflag: %-.10f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 15_decimal_PRECISION + noflags: %.15f", x);
  controlNum = sprintf(testStrinf2, "Output with 15_decimal_PRECISION + noflags: %.15f", x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 30_characters_WIDTH and 10_decimal_PRECISION + noflags: %30.10f signflag: %+30.10f sharpflag: %#30.10f zeroflag: %030.10f spaceflag: % 30.10f leftSideflag: %-30.10f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 30_characters_WIDTH and 10_decimal_PRECISION + noflags: %30.10f signflag: %+30.10f sharpflag: %#30.10f zeroflag: %030.10f spaceflag: % 30.10f leftSideflag: %-30.10f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noflags: %20.5f signflag + leftSideflag: %-+20.5f sharpflag + zeroflag: %#020.5f spaceflag + zeroflag: % 020.5f zeroflag + signflag: %0+20.5f leftSideflag + spaceflag: %- 20.5f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noflags: %20.5f signflag + leftSideflag: %-+20.5f sharpflag + zeroflag: %#020.5f spaceflag + zeroflag: % 020.5f zeroflag + signflag: %0+20.5f leftSideflag + spaceflag: %- 20.5f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST


START_TEST(Case_f_spec_random_very_small_value) {
  // Простой случай, форматирование строки с одной переменной
  double x = 0.000000070157826369542569e-100;
  char testStrinf1[500];
  char testStrinf2[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testStrinf1, "Output with noflags: %f signflag: %+f sharpflag: %#f nullflag: %01f spaceflag: % f leftSideflag: %-f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with noflags: %f signflag: %+f sharpflag: %#f nullflag: %01f spaceflag: % f leftSideflag: %-f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with WIfTH + noflags: %10f signflag: %+10f sharpflag: %#10f zeroflag: %010f spaceflag: % 10f leftSideflag: %-10f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with WIfTH + noflags: %10f signflag: %+10f sharpflag: %#10f zeroflag: %010f spaceflag: % 10f leftSideflag: %-10f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with Zero_PRECISION + noflags: %.f signflag: %+.f sharpflag: %#.f zeroflag: %0.f spaceflag: % .f leftSideflag: %-.f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with Zero_PRECISION + noflags: %.f signflag: %+.f sharpflag: %#.f zeroflag: %0.f spaceflag: % .f leftSideflag: %-.f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 3_decimal_PRECISION + noflags: %.3f signflag: %+.3f sharpflag: %#.3f zeroflag: %0.3f spaceflag: % .3f leftSideflag: %-.3f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 3_decimal_PRECISION + noflags: %.3f signflag: %+.3f sharpflag: %#.3f zeroflag: %0.3f spaceflag: % .3f leftSideflag: %-.3f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 15_decimal_PRECISION + noflags: %.10f signflag: %+.10f sharpflag: %#.10f zeroflag: %0.10f spaceflag: % .10f leftSideflag: %-.10f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 15_decimal_PRECISION + noflags: %.10f signflag: %+.10f sharpflag: %#.10f zeroflag: %0.10f spaceflag: % .10f leftSideflag: %-.10f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 15_decimal_PRECISION + noflags: %.15f", x);
  controlNum = sprintf(testStrinf2, "Output with 15_decimal_PRECISION + noflags: %.15f", x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 30_characters_WIDTH and 10_decimal_PRECISION + noflags: %30.10f signflag: %+30.10f sharpflag: %#30.10f zeroflag: %030.10f spaceflag: % 30.10f leftSideflag: %-30.10f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 30_characters_WIDTH and 10_decimal_PRECISION + noflags: %30.10f signflag: %+30.10f sharpflag: %#30.10f zeroflag: %030.10f spaceflag: % 30.10f leftSideflag: %-30.10f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noflags: %20.5f signflag + leftSideflag: %-+20.5f sharpflag + zeroflag: %#020.5f spaceflag + zeroflag: % 020.5f zeroflag + signflag: %0+20.5f leftSideflag + spaceflag: %- 20.5f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noflags: %20.5f signflag + leftSideflag: %-+20.5f sharpflag + zeroflag: %#020.5f spaceflag + zeroflag: % 020.5f zeroflag + signflag: %0+20.5f leftSideflag + spaceflag: %- 20.5f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_f_spec_random_big_value) {
  // Простой случай, форматирование строки с одной переменной
  double x = 7015.782636589e10;
  char testStrinf1[500];
  char testStrinf2[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testStrinf1, "Output with noflags: %f signflag: %+f sharpflag: %#f nullflag: %01f spaceflag: % f leftSideflag: %-f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with noflags: %f signflag: %+f sharpflag: %#f nullflag: %01f spaceflag: % f leftSideflag: %-f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with WIfTH + noflags: %10f signflag: %+10f sharpflag: %#10f zeroflag: %010f spaceflag: % 10f leftSideflag: %-10f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with WIfTH + noflags: %10f signflag: %+10f sharpflag: %#10f zeroflag: %010f spaceflag: % 10f leftSideflag: %-10f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with Zero_PRECISION + noflags: %.f signflag: %+.f sharpflag: %#.f zeroflag: %0.f spaceflag: % .f leftSideflag: %-.f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with Zero_PRECISION + noflags: %.f signflag: %+.f sharpflag: %#.f zeroflag: %0.f spaceflag: % .f leftSideflag: %-.f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 3_decimal_PRECISION + noflags: %.3f signflag: %+.3f sharpflag: %#.3f zeroflag: %0.3f spaceflag: % .3f leftSideflag: %-.3f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 3_decimal_PRECISION + noflags: %.3f signflag: %+.3f sharpflag: %#.3f zeroflag: %0.3f spaceflag: % .3f leftSideflag: %-.3f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 15_decimal_PRECISION + noflags: %.10f signflag: %+.10f sharpflag: %#.10f zeroflag: %0.10f spaceflag: % .10f leftSideflag: %-.10f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 15_decimal_PRECISION + noflags: %.10f signflag: %+.10f sharpflag: %#.10f zeroflag: %0.10f spaceflag: % .10f leftSideflag: %-.10f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 15_decimal_PRECISION + noflags: %.15f", x);
  controlNum = sprintf(testStrinf2, "Output with 15_decimal_PRECISION + noflags: %.15f", x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 30_characters_WIDTH and 10_decimal_PRECISION + noflags: %30.10f signflag: %+30.10f sharpflag: %#30.10f zeroflag: %030.10f spaceflag: % 30.10f leftSideflag: %-30.10f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 30_characters_WIDTH and 10_decimal_PRECISION + noflags: %30.10f signflag: %+30.10f sharpflag: %#30.10f zeroflag: %030.10f spaceflag: % 30.10f leftSideflag: %-30.10f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noflags: %20.5f signflag + leftSideflag: %-+20.5f sharpflag + zeroflag: %#020.5f spaceflag + zeroflag: % 020.5f zeroflag + signflag: %0+20.5f leftSideflag + spaceflag: %- 20.5f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noflags: %20.5f signflag + leftSideflag: %-+20.5f sharpflag + zeroflag: %#020.5f spaceflag + zeroflag: % 020.5f zeroflag + signflag: %0+20.5f leftSideflag + spaceflag: %- 20.5f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_f_spec_random_negative_value) {
  // Простой случай, форматирование строки с одной переменной
  double x = -360157826369556.12658952691;
  char testStrinf1[500];
  char testStrinf2[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testStrinf1, "Output with noflags: %f signflag: %+f sharpflag: %#f nullflag: %01f spaceflag: % f leftSideflag: %-f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with noflags: %f signflag: %+f sharpflag: %#f nullflag: %01f spaceflag: % f leftSideflag: %-f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with WIfTH + noflags: %10f signflag: %+10f sharpflag: %#10f zeroflag: %010f spaceflag: % 10f leftSideflag: %-10f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with WIfTH + noflags: %10f signflag: %+10f sharpflag: %#10f zeroflag: %010f spaceflag: % 10f leftSideflag: %-10f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with Zero_PRECISION + noflags: %.f signflag: %+.f sharpflag: %#.f zeroflag: %0.f spaceflag: % .f leftSideflag: %-.f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with Zero_PRECISION + noflags: %.f signflag: %+.f sharpflag: %#.f zeroflag: %0.f spaceflag: % .f leftSideflag: %-.f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 3_decimal_PRECISION + noflags: %.3f signflag: %+.3f sharpflag: %#.3f zeroflag: %0.3f spaceflag: % .3f leftSideflag: %-.3f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 3_decimal_PRECISION + noflags: %.3f signflag: %+.3f sharpflag: %#.3f zeroflag: %0.3f spaceflag: % .3f leftSideflag: %-.3f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 10_decimal_PRECISION + noflags: %.10f signflag: %+.10f sharpflag: %#.10f zeroflag: %0.10f spaceflag: % .10f leftSideflag: %-.10f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 10_decimal_PRECISION + noflags: %.10f signflag: %+.10f sharpflag: %#.10f zeroflag: %0.10f spaceflag: % .10f leftSideflag: %-.10f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 15_decimal_PRECISION + noflags: %.15f", x);
  controlNum = sprintf(testStrinf2, "Output with 15_decimal_PRECISION + noflags: %.15f", x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 30_characters_WIDTH and 10_decimal_PRECISION + noflags: %30.10f signflag: %+30.10f sharpflag: %#30.10f zeroflag: %030.10f spaceflag: % 30.10f leftSideflag: %-30.10f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 30_characters_WIDTH and 10_decimal_PRECISION + noflags: %30.10f signflag: %+30.10f sharpflag: %#30.10f zeroflag: %030.10f spaceflag: % 30.10f leftSideflag: %-30.10f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noflags: %20.5f signflag + leftSideflag: %-+20.5f sharpflag + zeroflag: %#020.5f spaceflag + zeroflag: % 020.5f zeroflag + signflag: %0+20.5f leftSideflag + spaceflag: %- 20.5f", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noflags: %20.5f signflag + leftSideflag: %-+20.5f sharpflag + zeroflag: %#020.5f spaceflag + zeroflag: % 020.5f zeroflag + signflag: %0+20.5f leftSideflag + spaceflag: %- 20.5f", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST


START_TEST(Case_E_e_spec_null_value) {
  // Простой случай, форматирование строки с одной переменной
  double x = 0.0;
  char testStrinf1[500];
  char testStrinf2[500];
  char testStrinf3[500];
  char testStrinf4[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testStrinf1, "Output with noflags: %E signflag: %+E sharpflag: %#E nullflag: %01E spaceflag: % E leftSideflag: %-E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with noflags: %E signflag: %+E sharpflag: %#E nullflag: %01E spaceflag: % E leftSideflag: %-E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with WIfTH + noflags: %10E signflag: %+10E sharpflag: %#10E zeroflag: %010E spaceflag: % 10E leftSideflag: %-10E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with WIfTH + noflags: %10E signflag: %+10E sharpflag: %#10E zeroflag: %010E spaceflag: % 10E leftSideflag: %-10E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with Zero_PRECISION + noflags: %.E signflag: %+.E sharpflag: %#.E zeroflag: %0.E spaceflag: % .E leftSideflag: %-.E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with Zero_PRECISION + noflags: %.E signflag: %+.E sharpflag: %#.E zeroflag: %0.E spaceflag: % .E leftSideflag: %-.E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 3_decimal_PRECISION + noflags: %.3E signflag: %+.3E sharpflag: %#.3E zeroflag: %0.3E spaceflag: % .3E leftSideflag: %-.3E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 3_decimal_PRECISION + noflags: %.3E signflag: %+.3E sharpflag: %#.3E zeroflag: %0.3E spaceflag: % .3E leftSideflag: %-.3E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 10_decimal_PRECISION + noflags: %.10E signflag: %+.10E sharpflag: %#.10E zeroflag: %0.10E spaceflag: % .10E leftSideflag: %-.10E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 10_decimal_PRECISION + noflags: %.10E signflag: %+.10E sharpflag: %#.10E zeroflag: %0.10E spaceflag: % .10E leftSideflag: %-.10E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 15_decimal_PRECISION + noflags: %.15E", x);
  controlNum = sprintf(testStrinf2, "Output with 15_decimal_PRECISION + noflags: %.15E", x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 30_characters_WIDTH and 10_decimal_PRECISION + noflags: %30.10E signflag: %+30.10E sharpflag: %#30.10E zeroflag: %030.10E spaceflag: % 30.10E leftSideflag: %-30.10E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 30_characters_WIDTH and 10_decimal_PRECISION + noflags: %30.10E signflag: %+30.10E sharpflag: %#30.10E zeroflag: %030.10E spaceflag: % 30.10E leftSideflag: %-30.10E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noflags: %20.5E signflag + leftSideflag: %-+20.5E sharpflag + zeroflag: %#020.5E spaceflag + zeroflag: % 020.5E zeroflag + signflag: %0+20.5E leftSideflag + spaceflag: %- 20.5E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noflags: %20.5E signflag + leftSideflag: %-+20.5E sharpflag + zeroflag: %#020.5E spaceflag + zeroflag: % 020.5E zeroflag + signflag: %0+20.5E leftSideflag + spaceflag: %- 20.5E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf3, "Output with 20_characters_WIDTH and 0_decimal_PRECISION + noflags: %20.0e signflag + leftSideflag: %-+20.0e sharpflag + zeroflag: %#020.0e spaceflag + zeroflag: % 020.0e zeroflag + signflag: %0+20.0e leftSideflag + spaceflag: %- 20.5e", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf4, "Output with 20_characters_WIDTH and 0_decimal_PRECISION + noflags: %20.0e signflag + leftSideflag: %-+20.0e sharpflag + zeroflag: %#020.0e spaceflag + zeroflag: % 020.0e zeroflag + signflag: %0+20.0e leftSideflag + spaceflag: %- 20.5e", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_E_e_spec_random_value) {
  // Простой случай, форматирование строки с одной переменной
  double x = 32.01526e56;
  char testStrinf1[500];
  char testStrinf2[500];
  char testStrinf3[500];
  char testStrinf4[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testStrinf1, "Output with noflags: %E signflag: %+E sharpflag: %#E nullflag: %01E spaceflag: % E leftSideflag: %-E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with noflags: %E signflag: %+E sharpflag: %#E nullflag: %01E spaceflag: % E leftSideflag: %-E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with WIfTH + noflags: %10E signflag: %+10E sharpflag: %#10E zeroflag: %010E spaceflag: % 10E leftSideflag: %-10E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with WIfTH + noflags: %10E signflag: %+10E sharpflag: %#10E zeroflag: %010E spaceflag: % 10E leftSideflag: %-10E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with Zero_PRECISION + noflags: %.E signflag: %+.E sharpflag: %#.E zeroflag: %0.E spaceflag: % .E leftSideflag: %-.E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with Zero_PRECISION + noflags: %.E signflag: %+.E sharpflag: %#.E zeroflag: %0.E spaceflag: % .E leftSideflag: %-.E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 3_decimal_PRECISION + noflags: %.3E signflag: %+.3E sharpflag: %#.3E zeroflag: %0.3E spaceflag: % .3E leftSideflag: %-.3E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 3_decimal_PRECISION + noflags: %.3E signflag: %+.3E sharpflag: %#.3E zeroflag: %0.3E spaceflag: % .3E leftSideflag: %-.3E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 10_decimal_PRECISION + noflags: %.10E signflag: %+.10E sharpflag: %#.10E zeroflag: %0.10E spaceflag: % .10E leftSideflag: %-.10E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 10_decimal_PRECISION + noflags: %.10E signflag: %+.10E sharpflag: %#.10E zeroflag: %0.10E spaceflag: % .10E leftSideflag: %-.10E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 15_decimal_PRECISION + noflags: %.15E", x);
  controlNum = sprintf(testStrinf2, "Output with 15_decimal_PRECISION + noflags: %.15E", x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 30_characters_WIDTH and 10_decimal_PRECISION + noflags: %30.10E signflag: %+30.10E sharpflag: %#30.10E zeroflag: %030.10E spaceflag: % 30.10E leftSideflag: %-30.10E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 30_characters_WIDTH and 10_decimal_PRECISION + noflags: %30.10E signflag: %+30.10E sharpflag: %#30.10E zeroflag: %030.10E spaceflag: % 30.10E leftSideflag: %-30.10E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noflags: %20.5E signflag + leftSideflag: %-+20.5E sharpflag + zeroflag: %#020.5E spaceflag + zeroflag: % 020.5E zeroflag + signflag: %0+20.5E leftSideflag + spaceflag: %- 20.5E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noflags: %20.5E signflag + leftSideflag: %-+20.5E sharpflag + zeroflag: %#020.5E spaceflag + zeroflag: % 020.5E zeroflag + signflag: %0+20.5E leftSideflag + spaceflag: %- 20.5E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf3, "Output with 20_characters_WIDTH and 0_decimal_PRECISION + noflags: %20.0e signflag + leftSideflag: %-+20.0e sharpflag + zeroflag: %#020.0e spaceflag + zeroflag: % 020.0e zeroflag + signflag: %0+20.0e leftSideflag + spaceflag: %- 20.5e", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf4, "Output with 20_characters_WIDTH and 0_decimal_PRECISION + noflags: %20.0e signflag + leftSideflag: %-+20.0e sharpflag + zeroflag: %#020.0e spaceflag + zeroflag: % 020.0e zeroflag + signflag: %0+20.0e leftSideflag + spaceflag: %- 20.5e", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_E_e_spec_random_small_value) {
  // Простой случай, форматирование строки с одной переменной
  double x = 0.000003201526e-73;
  char testStrinf1[500];
  char testStrinf2[500];
  char testStrinf3[500];
  char testStrinf4[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testStrinf1, "Output with noflags: %E signflag: %+E sharpflag: %#E nullflag: %01E spaceflag: % E leftSideflag: %-E", x, x, x, x, x, x);
  testNum = s21_sprintf(testStrinf1, "Output with noflags: %E signflag: %+E sharpflag: %#E nullflag: %01E spaceflag: % E leftSideflag: %-E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with noflags: %E signflag: %+E sharpflag: %#E nullflag: %01E spaceflag: % E leftSideflag: %-E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with WIfTH + noflags: %10E signflag: %+10E sharpflag: %#10E zeroflag: %010E spaceflag: % 10E leftSideflag: %-10E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with WIfTH + noflags: %10E signflag: %+10E sharpflag: %#10E zeroflag: %010E spaceflag: % 10E leftSideflag: %-10E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with Zero_PRECISION + noflags: %.E signflag: %+.E sharpflag: %#.E zeroflag: %0.E spaceflag: % .E leftSideflag: %-.E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with Zero_PRECISION + noflags: %.E signflag: %+.E sharpflag: %#.E zeroflag: %0.E spaceflag: % .E leftSideflag: %-.E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 3_decimal_PRECISION + noflags: %.3E signflag: %+.3E sharpflag: %#.3E zeroflag: %0.3E spaceflag: % .3E leftSideflag: %-.3E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 3_decimal_PRECISION + noflags: %.3E signflag: %+.3E sharpflag: %#.3E zeroflag: %0.3E spaceflag: % .3E leftSideflag: %-.3E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 10_decimal_PRECISION + noflags: %.10E signflag: %+.10E sharpflag: %#.10E zeroflag: %0.10E spaceflag: % .10E leftSideflag: %-.10E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 10_decimal_PRECISION + noflags: %.10E signflag: %+.10E sharpflag: %#.10E zeroflag: %0.10E spaceflag: % .10E leftSideflag: %-.10E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 15_decimal_PRECISION + noflags: %.15E", x);
  controlNum = sprintf(testStrinf2, "Output with 15_decimal_PRECISION + noflags: %.15E", x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 30_characters_WIDTH and 10_decimal_PRECISION + noflags: %30.10E signflag: %+30.10E sharpflag: %#30.10E zeroflag: %030.10E spaceflag: % 30.10E leftSideflag: %-30.10E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 30_characters_WIDTH and 10_decimal_PRECISION + noflags: %30.10E signflag: %+30.10E sharpflag: %#30.10E zeroflag: %030.10E spaceflag: % 30.10E leftSideflag: %-30.10E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noflags: %20.5E signflag + leftSideflag: %-+20.5E sharpflag + zeroflag: %#020.5E spaceflag + zeroflag: % 020.5E zeroflag + signflag: %0+20.5E leftSideflag + spaceflag: %- 20.5E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noflags: %20.5E signflag + leftSideflag: %-+20.5E sharpflag + zeroflag: %#020.5E spaceflag + zeroflag: % 020.5E zeroflag + signflag: %0+20.5E leftSideflag + spaceflag: %- 20.5E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf3, "Output with 20_characters_WIDTH and 0_decimal_PRECISION + noflags: %20.0e signflag + leftSideflag: %-+20.0e sharpflag + zeroflag: %#020.0e spaceflag + zeroflag: % 020.0e zeroflag + signflag: %0+20.0e leftSideflag + spaceflag: %- 20.5e", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf4, "Output with 20_characters_WIDTH and 0_decimal_PRECISION + noflags: %20.0e signflag + leftSideflag: %-+20.0e sharpflag + zeroflag: %#020.0e spaceflag + zeroflag: % 020.0e zeroflag + signflag: %0+20.0e leftSideflag + spaceflag: %- 20.5e", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_E_e_spec_max_value) {
  // Простой случай, форматирование строки с одной переменной
  double x = 1.7976931348623158e+308;
  char testStrinf1[500];
  char testStrinf2[500];
  char testStrinf3[500];
  char testStrinf4[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testStrinf1, "Output with noflags: %E signflag: %+E sharpflag: %#E nullflag: %01E spaceflag: % E leftSideflag: %-E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with noflags: %E signflag: %+E sharpflag: %#E nullflag: %01E spaceflag: % E leftSideflag: %-E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with WIfTH + noflags: %10E signflag: %+10E sharpflag: %#10E zeroflag: %010E spaceflag: % 10E leftSideflag: %-10E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with WIfTH + noflags: %10E signflag: %+10E sharpflag: %#10E zeroflag: %010E spaceflag: % 10E leftSideflag: %-10E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with Zero_PRECISION + noflags: %.E signflag: %+.E sharpflag: %#.E zeroflag: %0.E spaceflag: % .E leftSideflag: %-.E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with Zero_PRECISION + noflags: %.E signflag: %+.E sharpflag: %#.E zeroflag: %0.E spaceflag: % .E leftSideflag: %-.E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 3_decimal_PRECISION + noflags: %.3E signflag: %+.3E sharpflag: %#.3E zeroflag: %0.3E spaceflag: % .3E leftSideflag: %-.3E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 3_decimal_PRECISION + noflags: %.3E signflag: %+.3E sharpflag: %#.3E zeroflag: %0.3E spaceflag: % .3E leftSideflag: %-.3E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 10_decimal_PRECISION + noflags: %.10E signflag: %+.10E sharpflag: %#.10E zeroflag: %0.10E spaceflag: % .10E leftSideflag: %-.10E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 10_decimal_PRECISION + noflags: %.10E signflag: %+.10E sharpflag: %#.10E zeroflag: %0.10E spaceflag: % .10E leftSideflag: %-.10E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 15_decimal_PRECISION + noflags: %.15E", x);
  controlNum = sprintf(testStrinf2, "Output with 15_decimal_PRECISION + noflags: %.15E", x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 30_characters_WIDTH and 10_decimal_PRECISION + noflags: %30.10E signflag: %+30.10E sharpflag: %#30.10E zeroflag: %030.10E spaceflag: % 30.10E leftSideflag: %-30.10E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 30_characters_WIDTH and 10_decimal_PRECISION + noflags: %30.10E signflag: %+30.10E sharpflag: %#30.10E zeroflag: %030.10E spaceflag: % 30.10E leftSideflag: %-30.10E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noflags: %20.5E signflag + leftSideflag: %-+20.5E sharpflag + zeroflag: %#020.5E spaceflag + zeroflag: % 020.5E zeroflag + signflag: %0+20.5E leftSideflag + spaceflag: %- 20.5E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noflags: %20.5E signflag + leftSideflag: %-+20.5E sharpflag + zeroflag: %#020.5E spaceflag + zeroflag: % 020.5E zeroflag + signflag: %0+20.5E leftSideflag + spaceflag: %- 20.5E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf3, "Output with 20_characters_WIDTH and 0_decimal_PRECISION + noflags: %20.0e signflag + leftSideflag: %-+20.0e sharpflag + zeroflag: %#020.0e spaceflag + zeroflag: % 020.0e zeroflag + signflag: %0+20.0e leftSideflag + spaceflag: %- 20.5e", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf4, "Output with 20_characters_WIDTH and 0_decimal_PRECISION + noflags: %20.0e signflag + leftSideflag: %-+20.0e sharpflag + zeroflag: %#020.0e spaceflag + zeroflag: % 020.0e zeroflag + signflag: %0+20.0e leftSideflag + spaceflag: %- 20.5e", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_E_e_spec_min_value) {
  // Простой случай, форматирование строки с одной переменной
  double x = 2.2250738585072014e-308;
  char testStrinf1[500];
  char testStrinf2[500];
  char testStrinf3[500];
  char testStrinf4[500];
  int testNum = 0;
  int controlNum = 0;
         
    testNum = s21_sprintf(testStrinf1, "Output with noflags: %E signflag: %+E sharpflag: %#E nullflag: %01E spaceflag: % E leftSideflag: %-E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with noflags: %E signflag: %+E sharpflag: %#E nullflag: %01E spaceflag: % E leftSideflag: %-E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with WIfTH + noflags: %10E signflag: %+10E sharpflag: %#10E zeroflag: %010E spaceflag: % 10E leftSideflag: %-10E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with WIfTH + noflags: %10E signflag: %+10E sharpflag: %#10E zeroflag: %010E spaceflag: % 10E leftSideflag: %-10E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with Zero_PRECISION + noflags: %.E signflag: %+.E sharpflag: %#.E zeroflag: %0.E spaceflag: % .E leftSideflag: %-.E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with Zero_PRECISION + noflags: %.E signflag: %+.E sharpflag: %#.E zeroflag: %0.E spaceflag: % .E leftSideflag: %-.E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 3_decimal_PRECISION + noflags: %.3E signflag: %+.3E sharpflag: %#.3E zeroflag: %0.3E spaceflag: % .3E leftSideflag: %-.3E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 3_decimal_PRECISION + noflags: %.3E signflag: %+.3E sharpflag: %#.3E zeroflag: %0.3E spaceflag: % .3E leftSideflag: %-.3E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 10_decimal_PRECISION + noflags: %.10E signflag: %+.10E sharpflag: %#.10E zeroflag: %0.10E spaceflag: % .10E leftSideflag: %-.10E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 10_decimal_PRECISION + noflags: %.10E signflag: %+.10E sharpflag: %#.10E zeroflag: %0.10E spaceflag: % .10E leftSideflag: %-.10E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 15_decimal_PRECISION + noflags: %.15E", x);
  controlNum = sprintf(testStrinf2, "Output with 15_decimal_PRECISION + noflags: %.15E", x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 30_characters_WIDTH and 10_decimal_PRECISION + noflags: %30.10E signflag: %+30.10E sharpflag: %#30.10E zeroflag: %030.10E spaceflag: % 30.10E leftSideflag: %-30.10E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 30_characters_WIDTH and 10_decimal_PRECISION + noflags: %30.10E signflag: %+30.10E sharpflag: %#30.10E zeroflag: %030.10E spaceflag: % 30.10E leftSideflag: %-30.10E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noflags: %20.5E signflag + leftSideflag: %-+20.5E sharpflag + zeroflag: %#020.5E spaceflag + zeroflag: % 020.5E zeroflag + signflag: %0+20.5E leftSideflag + spaceflag: %- 20.5E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noflags: %20.5E signflag + leftSideflag: %-+20.5E sharpflag + zeroflag: %#020.5E spaceflag + zeroflag: % 020.5E zeroflag + signflag: %0+20.5E leftSideflag + spaceflag: %- 20.5E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf3, "Output with 20_characters_WIDTH and 0_decimal_PRECISION + noflags: %20.0e signflag + leftSideflag: %-+20.0e sharpflag + zeroflag: %#020.0e spaceflag + zeroflag: % 020.0e zeroflag + signflag: %0+20.0e leftSideflag + spaceflag: %- 20.5e", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf4, "Output with 20_characters_WIDTH and 0_decimal_PRECISION + noflags: %20.0e signflag + leftSideflag: %-+20.0e sharpflag + zeroflag: %#020.0e spaceflag + zeroflag: % 020.0e zeroflag + signflag: %0+20.0e leftSideflag + spaceflag: %- 20.5e", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_E_e_spec_min_negative_value) {
  // Простой случай, форматирование строки с одной переменной
  double x = -1.7976931348623158e+307;
  char testStrinf1[500];
  char testStrinf2[500];
  char testStrinf3[500];
  char testStrinf4[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testStrinf1, "Output with noflags: %E signflag: %+E sharpflag: %#E nullflag: %01E spaceflag: % E leftSideflag: %-E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with noflags: %E signflag: %+E sharpflag: %#E nullflag: %01E spaceflag: % E leftSideflag: %-E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with WIfTH + noflags: %10E signflag: %+10E sharpflag: %#10E zeroflag: %010E spaceflag: % 10E leftSideflag: %-10E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with WIfTH + noflags: %10E signflag: %+10E sharpflag: %#10E zeroflag: %010E spaceflag: % 10E leftSideflag: %-10E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with Zero_PRECISION + noflags: %.E signflag: %+.E sharpflag: %#.E zeroflag: %0.E spaceflag: % .E leftSideflag: %-.E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with Zero_PRECISION + noflags: %.E signflag: %+.E sharpflag: %#.E zeroflag: %0.E spaceflag: % .E leftSideflag: %-.E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 3_decimal_PRECISION + noflags: %.3E signflag: %+.3E sharpflag: %#.3E zeroflag: %0.3E spaceflag: % .3E leftSideflag: %-.3E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 3_decimal_PRECISION + noflags: %.3E signflag: %+.3E sharpflag: %#.3E zeroflag: %0.3E spaceflag: % .3E leftSideflag: %-.3E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 10_decimal_PRECISION + noflags: %.10E signflag: %+.10E sharpflag: %#.10E zeroflag: %0.10E spaceflag: % .10E leftSideflag: %-.10E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 10_decimal_PRECISION + noflags: %.10E signflag: %+.10E sharpflag: %#.10E zeroflag: %0.10E spaceflag: % .10E leftSideflag: %-.10E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 15_decimal_PRECISION + noflags: %.15E", x);
  controlNum = sprintf(testStrinf2, "Output with 15_decimal_PRECISION + noflags: %.15E", x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 30_characters_WIDTH and 10_decimal_PRECISION + noflags: %30.10E signflag: %+30.10E sharpflag: %#30.10E zeroflag: %030.10E spaceflag: % 30.10E leftSideflag: %-30.10E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 30_characters_WIDTH and 10_decimal_PRECISION + noflags: %30.10E signflag: %+30.10E sharpflag: %#30.10E zeroflag: %030.10E spaceflag: % 30.10E leftSideflag: %-30.10E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noflags: %20.5E signflag + leftSideflag: %-+20.5E sharpflag + zeroflag: %#020.5E spaceflag + zeroflag: % 020.5E zeroflag + signflag: %0+20.5E leftSideflag + spaceflag: %- 20.5E", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noflags: %20.5E signflag + leftSideflag: %-+20.5E sharpflag + zeroflag: %#020.5E spaceflag + zeroflag: % 020.5E zeroflag + signflag: %0+20.5E leftSideflag + spaceflag: %- 20.5E", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testStrinf3, "Output with 20_characters_WIDTH and 0_decimal_PRECISION + noflags: %20.0e signflag + leftSideflag: %-+20.0e sharpflag + zeroflag: %#020.0e spaceflag + zeroflag: % 020.0e zeroflag + signflag: %0+20.0e leftSideflag + spaceflag: %- 20.5e", x, x, x, x, x, x);
  controlNum = sprintf(testStrinf4, "Output with 20_characters_WIDTH and 0_decimal_PRECISION + noflags: %20.0e signflag + leftSideflag: %-+20.0e sharpflag + zeroflag: %#020.0e spaceflag + zeroflag: % 020.0e zeroflag + signflag: %0+20.0e leftSideflag + spaceflag: %- 20.5e", x, x, x, x, x, x);
  ck_assert_str_eq(testStrinf1, testStrinf2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_d_spec_null_value) {
  // Простой случай, форматирование строки с одной переменной
  int x = 0;
  char testString1[500];
  char testString2[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testString1, "Output with noFlags: %d signFlag: %+d nullFlag: %01d spaceFlag: % d leftSideFlag: %-d", x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with noFlags: %d signFlag: %+d nullFlag: %01d spaceFlag: % d leftSideFlag: %-d", x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with WIdTH + noFlags: %10d signFlag: %+10d zeroFlag: %010d spaceFlag: % 10d leftSideFlag: %-10d", x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with WIdTH + noFlags: %10d signFlag: %+10d zeroFlag: %010d spaceFlag: % 10d leftSideFlag: %-10d", x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with Zero_PRECISION + noFlags: %.d signFlag: %.d spaceFlag: % .d leftSideFlag: %-.d", x, x, x, x);
  controlNum = sprintf(testString2, "Output with Zero_PRECISION + noFlags: %.d signFlag: %.d spaceFlag: % .d leftSideFlag: %-.d", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 3_decimal_PRECISION + noFlags: %.3d signFlag: %+.3d spaceFlag: % .3d leftSideFlag: %-.3d", x, x, x, x);
  controlNum = sprintf(testString2, "Output with 3_decimal_PRECISION + noFlags: %.3d signFlag: %+.3d spaceFlag: % .3d leftSideFlag: %-.3d", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 10_decimal_PRECISION + noFlags: %.10d signFlag: %+.10d spaceFlag: % .10d leftSideFlag: %-.10d", x, x, x, x);
  controlNum = sprintf(testString2, "Output with 10_decimal_PRECISION + noFlags: %.10d signFlag: %+.10d spaceFlag: % .10d leftSideFlag: %-.10d", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10d signFlag: %+20.10d spaceFlag: % 20.10d leftSideFlag: %-20.10d", x, x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10d signFlag: %+20.10d spaceFlag: % 20.10d leftSideFlag: %-20.10d", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5d signFlag + leftSideFlag: %-+20.5d spaceFlag + zeroFlag: % 020d zeroFlag + signFlag: %0+20d leftSideFlag + spaceFlag: %- 20.5d", x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5d signFlag + leftSideFlag: %-+20.5d spaceFlag + zeroFlag: % 020d zeroFlag + signFlag: %0+20d leftSideFlag + spaceFlag: %- 20.5d", x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_d_spec_max_value) {
  // Простой случай, форматирование строки с одной переменной
  int x = 2147483647;
  char testString1[500];
  char testString2[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testString1, "Output with noFlags: %d signFlag: %+d nullFlag: %01d spaceFlag: % d leftSideFlag: %-d", x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with noFlags: %d signFlag: %+d nullFlag: %01d spaceFlag: % d leftSideFlag: %-d", x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with WIdTH + noFlags: %10d signFlag: %+10d zeroFlag: %010d spaceFlag: % 10d leftSideFlag: %-10d", x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with WIdTH + noFlags: %10d signFlag: %+10d zeroFlag: %010d spaceFlag: % 10d leftSideFlag: %-10d", x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with Zero_PRECISION + noFlags: %.d signFlag: %.d spaceFlag: % .d leftSideFlag: %-.d", x, x, x, x);
  controlNum = sprintf(testString2, "Output with Zero_PRECISION + noFlags: %.d signFlag: %.d spaceFlag: % .d leftSideFlag: %-.d", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 3_decimal_PRECISION + noFlags: %.3d signFlag: %+.3d spaceFlag: % .3d leftSideFlag: %-.3d", x, x, x, x);
  controlNum = sprintf(testString2, "Output with 3_decimal_PRECISION + noFlags: %.3d signFlag: %+.3d spaceFlag: % .3d leftSideFlag: %-.3d", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 10_decimal_PRECISION + noFlags: %.10d signFlag: %+.10d spaceFlag: % .10d leftSideFlag: %-.10d", x, x, x, x);
  controlNum = sprintf(testString2, "Output with 10_decimal_PRECISION + noFlags: %.10d signFlag: %+.10d spaceFlag: % .10d leftSideFlag: %-.10d", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10d signFlag: %+20.10d spaceFlag: % 20.10d leftSideFlag: %-20.10d", x, x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10d signFlag: %+20.10d spaceFlag: % 20.10d leftSideFlag: %-20.10d", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5d signFlag + leftSideFlag: %-+20.5d spaceFlag + zeroFlag: % 020d zeroFlag + signFlag: %0+20d leftSideFlag + spaceFlag: %- 20.5d", x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5d signFlag + leftSideFlag: %-+20.5d spaceFlag + zeroFlag: % 020d zeroFlag + signFlag: %0+20d leftSideFlag + spaceFlag: %- 20.5d", x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_d_spec_max_long_value) {
  // Простой случай, форматирование строки с одной переменной
  long int x = 92233720368547758;
  char testString1[500];
  char testString2[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testString1, "Output with noFlags: %ld signFlag: %+ld nullFlag: %0ld spaceFlag: % ld leftSideFlag: %-ld", x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with noFlags: %ld signFlag: %+ld nullFlag: %0ld spaceFlag: % ld leftSideFlag: %-ld", x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5ld signFlag + leftSideFlag: %-+20.5ld spaceFlag + zeroFlag: % 020ld zeroFlag + signFlag: %0+20ld leftSideFlag + spaceFlag: %- 20.5ld", x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5ld signFlag + leftSideFlag: %-+20.5ld spaceFlag + zeroFlag: % 020ld zeroFlag + signFlag: %0+20ld leftSideFlag + spaceFlag: %- 20.5ld", x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_d_spec_negative_value) {
  // Простой случай, форматирование строки с одной переменной
  int x = -47483647;
  char testString1[500];
  char testString2[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testString1, "Output with noFlags: %d signFlag: %+d nullFlag: %01d spaceFlag: % d leftSideFlag: %-d", x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with noFlags: %d signFlag: %+d nullFlag: %01d spaceFlag: % d leftSideFlag: %-d", x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with WIdTH + noFlags: %10d signFlag: %+10d zeroFlag: %010d spaceFlag: % 10d leftSideFlag: %-10d", x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with WIdTH + noFlags: %10d signFlag: %+10d zeroFlag: %010d spaceFlag: % 10d leftSideFlag: %-10d", x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with Zero_PRECISION + noFlags: %.d signFlag: %.d spaceFlag: % .d leftSideFlag: %-.d", x, x, x, x);
  controlNum = sprintf(testString2, "Output with Zero_PRECISION + noFlags: %.d signFlag: %.d spaceFlag: % .d leftSideFlag: %-.d", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 3_decimal_PRECISION + noFlags: %.3d signFlag: %+.3d spaceFlag: % .3d leftSideFlag: %-.3d", x, x, x, x);
  controlNum = sprintf(testString2, "Output with 3_decimal_PRECISION + noFlags: %.3d signFlag: %+.3d spaceFlag: % .3d leftSideFlag: %-.3d", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 10_decimal_PRECISION + noFlags: %.10d signFlag: %+.10d spaceFlag: % .10d leftSideFlag: %-.10d", x, x, x, x);
  controlNum = sprintf(testString2, "Output with 10_decimal_PRECISION + noFlags: %.10d signFlag: %+.10d spaceFlag: % .10d leftSideFlag: %-.10d", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10d signFlag: %+20.10d spaceFlag: % 20.10d leftSideFlag: %-20.10d", x, x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10d signFlag: %+20.10d spaceFlag: % 20.10d leftSideFlag: %-20.10d", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5d signFlag + leftSideFlag: %-+20.5d spaceFlag + zeroFlag: % 020d zeroFlag + signFlag: %0+20d leftSideFlag + spaceFlag: %- 20.5d", x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5d signFlag + leftSideFlag: %-+20.5d spaceFlag + zeroFlag: % 020d zeroFlag + signFlag: %0+20d leftSideFlag + spaceFlag: %- 20.5d", x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_d_spec_min_value) {
  // Простой случай, форматирование строки с одной переменной
  int x = -2147483648;
  char testString1[500];
  char testString2[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testString1, "Output with noFlags: %d signFlag: %+d nullFlag: %01d spaceFlag: % d leftSideFlag: %-d", x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with noFlags: %d signFlag: %+d nullFlag: %01d spaceFlag: % d leftSideFlag: %-d", x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with WIdTH + noFlags: %10d signFlag: %+10d zeroFlag: %010d spaceFlag: % 10d leftSideFlag: %-10d", x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with WIdTH + noFlags: %10d signFlag: %+10d zeroFlag: %010d spaceFlag: % 10d leftSideFlag: %-10d", x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with Zero_PRECISION + noFlags: %.d signFlag: %.d spaceFlag: % .d leftSideFlag: %-.d", x, x, x, x);
  controlNum = sprintf(testString2, "Output with Zero_PRECISION + noFlags: %.d signFlag: %.d spaceFlag: % .d leftSideFlag: %-.d", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 3_decimal_PRECISION + noFlags: %.3d signFlag: %+.3d spaceFlag: % .3d leftSideFlag: %-.3d", x, x, x, x);
  controlNum = sprintf(testString2, "Output with 3_decimal_PRECISION + noFlags: %.3d signFlag: %+.3d spaceFlag: % .3d leftSideFlag: %-.3d", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 10_decimal_PRECISION + noFlags: %.10d signFlag: %+.10d spaceFlag: % .10d leftSideFlag: %-.10d", x, x, x, x);
  controlNum = sprintf(testString2, "Output with 10_decimal_PRECISION + noFlags: %.10d signFlag: %+.10d spaceFlag: % .10d leftSideFlag: %-.10d", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10d signFlag: %+20.10d spaceFlag: % 20.10d leftSideFlag: %-20.10d", x, x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10d signFlag: %+20.10d spaceFlag: % 20.10d leftSideFlag: %-20.10d", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5d signFlag + leftSideFlag: %-+20.5d spaceFlag + zeroFlag: % 020d zeroFlag + signFlag: %0+20d leftSideFlag + spaceFlag: %- 20.5d", x, x, x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5d signFlag + leftSideFlag: %-+20.5d spaceFlag + zeroFlag: % 020d zeroFlag + signFlag: %0+20d leftSideFlag + spaceFlag: %- 20.5d", x, x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_X_x_spec_null_value) {
  // Простой случай, форматирование строки с одной переменной
  int x = 0;
  char testString1[500];
  char testString2[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testString1, "Output with noFlags: %X sharpFlag: %#X nullFlag: %01X leftSideFlag: %-X", x, x, x, x);
  controlNum = sprintf(testString2, "Output with noFlags: %X sharpFlag: %#X nullFlag: %01X leftSideFlag: %-X", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with WIXTH + noFlags: %10X sharpFlag: %#10X zeroFlag: %010X leftSideFlag: %-10X", x, x, x, x);
  controlNum = sprintf(testString2, "Output with WIXTH + noFlags: %10X sharpFlag: %#10X zeroFlag: %010X leftSideFlag: %-10X", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with Zero_PRECISION + noFlags: %.X sharpFlag: %#.X leftSideFlag: %-.X", x, x, x);
  controlNum = sprintf(testString2, "Output with Zero_PRECISION + noFlags: %.X sharpFlag: %#.X leftSideFlag: %-.X", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 3_decimal_PRECISION + noFlags: %.3X sharpFlag: %#.3X leftSideFlag: %-.3X", x, x, x);
  controlNum = sprintf(testString2, "Output with 3_decimal_PRECISION + noFlags: %.3X sharpFlag: %#.3X leftSideFlag: %-.3X", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 10_decimal_PRECISION + noFlags: %.10X sharpFlag: %#.10X leftSideFlag: %-.10X", x, x, x);
  controlNum = sprintf(testString2, "Output with 10_decimal_PRECISION + noFlags: %.10X sharpFlag: %#.10X leftSideFlag: %-.10X", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10X sharpFlag: %#20.10X leftSideFlag: %-20.10X", x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10X sharpFlag: %#20.10X leftSideFlag: %-20.10X", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5X sharpFlag + zeroFlag: %#020X leftSideFlag + sharpFlag: %-#20.5X", x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5X sharpFlag + zeroFlag: %#020X leftSideFlag + sharpFlag: %-#20.5X", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5x sharpFlag + zeroFlag: %#020x leftSideFlag + sharpFlag: %-#20.5x", x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5x sharpFlag + zeroFlag: %#020x leftSideFlag + sharpFlag: %-#20.5x", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_X_x_spec_max_value) {
  // Простой случай, форматирование строки с одной переменной
  int x = 2147483647;
  char testString1[500];
  char testString2[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testString1, "Output with noFlags: %X sharpFlag: %#X nullFlag: %01X leftSideFlag: %-X", x, x, x, x);
  controlNum = sprintf(testString2, "Output with noFlags: %X sharpFlag: %#X nullFlag: %01X leftSideFlag: %-X", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with WIXTH + noFlags: %10X sharpFlag: %#10X zeroFlag: %010X leftSideFlag: %-10X", x, x, x, x);
  controlNum = sprintf(testString2, "Output with WIXTH + noFlags: %10X sharpFlag: %#10X zeroFlag: %010X leftSideFlag: %-10X", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with Zero_PRECISION + noFlags: %.X sharpFlag: %#.X leftSideFlag: %-.X", x, x, x);
  controlNum = sprintf(testString2, "Output with Zero_PRECISION + noFlags: %.X sharpFlag: %#.X leftSideFlag: %-.X", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 3_decimal_PRECISION + noFlags: %.3X sharpFlag: %#.3X leftSideFlag: %-.3X", x, x, x);
  controlNum = sprintf(testString2, "Output with 3_decimal_PRECISION + noFlags: %.3X sharpFlag: %#.3X leftSideFlag: %-.3X", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 10_decimal_PRECISION + noFlags: %.10X sharpFlag: %#.10X leftSideFlag: %-.10X", x, x, x);
  controlNum = sprintf(testString2, "Output with 10_decimal_PRECISION + noFlags: %.10X sharpFlag: %#.10X leftSideFlag: %-.10X", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10X sharpFlag: %#20.10X leftSideFlag: %-20.10X", x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10X sharpFlag: %#20.10X leftSideFlag: %-20.10X", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 30_characters_WIDTH and 5_decimal_PRECISION + noFlags: %30.5X sharpFlag + zeroFlag: %#030X leftSideFlag + sharpFlag: %-#30.5X", x, x, x);
  controlNum = sprintf(testString2, "Output with 30_characters_WIDTH and 5_decimal_PRECISION + noFlags: %30.5X sharpFlag + zeroFlag: %#030X leftSideFlag + sharpFlag: %-#30.5X", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5x sharpFlag + zeroFlag: %#020x leftSideFlag + sharpFlag: %-#20.5x", x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5x sharpFlag + zeroFlag: %#020x leftSideFlag + sharpFlag: %-#20.5x", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_X_x_spec_random_value) {
  // Простой случай, форматирование строки с одной переменной
  int x = 586234747;
  char testString1[500];
  char testString2[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testString1, "Output with noFlags: %X sharpFlag: %#X nullFlag: %01X leftSideFlag: %-X", x, x, x, x);
  controlNum = sprintf(testString2, "Output with noFlags: %X sharpFlag: %#X nullFlag: %01X leftSideFlag: %-X", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with WIXTH + noFlags: %10X sharpFlag: %#10X zeroFlag: %010X leftSideFlag: %-10X", x, x, x, x);
  controlNum = sprintf(testString2, "Output with WIXTH + noFlags: %10X sharpFlag: %#10X zeroFlag: %010X leftSideFlag: %-10X", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with Zero_PRECISION + noFlags: %.X sharpFlag: %#.X leftSideFlag: %-.X", x, x, x);
  controlNum = sprintf(testString2, "Output with Zero_PRECISION + noFlags: %.X sharpFlag: %#.X leftSideFlag: %-.X", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 3_decimal_PRECISION + noFlags: %.3X sharpFlag: %#.3X leftSideFlag: %-.3X", x, x, x);
  controlNum = sprintf(testString2, "Output with 3_decimal_PRECISION + noFlags: %.3X sharpFlag: %#.3X leftSideFlag: %-.3X", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 10_decimal_PRECISION + noFlags: %.10X sharpFlag: %#.10X leftSideFlag: %-.10X", x, x, x);
  controlNum = sprintf(testString2, "Output with 10_decimal_PRECISION + noFlags: %.10X sharpFlag: %#.10X leftSideFlag: %-.10X", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10X sharpFlag: %#20.10X leftSideFlag: %-20.10X", x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10X sharpFlag: %#20.10X leftSideFlag: %-20.10X", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5X sharpFlag + zeroFlag: %#020X leftSideFlag + sharpFlag: %-#20.5X", x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5X sharpFlag + zeroFlag: %#020X leftSideFlag + sharpFlag: %-#20.5X", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5x sharpFlag + zeroFlag: %#020x leftSideFlag + sharpFlag: %-#20.5x", x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5x sharpFlag + zeroFlag: %#020x leftSideFlag + sharpFlag: %-#20.5x", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_o_spec_null_value) {
  // Простой случай, форматирование строки с одной переменной
  int x = 1;
  char testString1[500];
  char testString2[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testString1, "Output with noFlags: %o sharpFlag: %#o nullFlag: %01o leftSideFlag: %-o", x, x, x, x);
  controlNum = sprintf(testString2, "Output with noFlags: %o sharpFlag: %#o nullFlag: %01o leftSideFlag: %-o", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with WIoTH + noFlags: %10o sharpFlag: %#10o zeroFlag: %010o leftSideFlag: %-10o", x, x, x, x);
  controlNum = sprintf(testString2, "Output with WIoTH + noFlags: %10o sharpFlag: %#10o zeroFlag: %010o leftSideFlag: %-10o", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with Zero_PRECISION + noFlags: %.o sharpFlag: %#.o leftSideFlag: %-.o", x, x, x);
  controlNum = sprintf(testString2, "Output with Zero_PRECISION + noFlags: %.o sharpFlag: %#.o leftSideFlag: %-.o", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 3_decimal_PRECISION + noFlags: %.3o sharpFlag: %#.3o leftSideFlag: %-.3o", x, x, x);
  controlNum = sprintf(testString2, "Output with 3_decimal_PRECISION + noFlags: %.3o sharpFlag: %#.3o leftSideFlag: %-.3o", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 10_decimal_PRECISION + noFlags: %.10o sharpFlag: %#.10o leftSideFlag: %-.10o", x, x, x);
  controlNum = sprintf(testString2, "Output with 10_decimal_PRECISION + noFlags: %.10o sharpFlag: %#.10o leftSideFlag: %-.10o", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10o sharpFlag: %#20.10o leftSideFlag: %-20.10o", x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10o sharpFlag: %#20.10o leftSideFlag: %-20.10o", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5o sharpFlag + zeroFlag: %#020o leftSideFlag + sharpFlag: %-#20.5o", x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5o sharpFlag + zeroFlag: %#020o leftSideFlag + sharpFlag: %-#20.5o", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_o_spec_max_value) {
  int x = 2147483647;
  char testString1[500];
  char testString2[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testString1, "Output with noFlags: %o sharpFlag: %#o nullFlag: %01o leftSideFlag: %-o", x, x, x, x);
  controlNum = sprintf(testString2, "Output with noFlags: %o sharpFlag: %#o nullFlag: %01o leftSideFlag: %-o", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with WIoTH + noFlags: %10o sharpFlag: %#10o zeroFlag: %010o leftSideFlag: %-10o", x, x, x, x);
  controlNum = sprintf(testString2, "Output with WIoTH + noFlags: %10o sharpFlag: %#10o zeroFlag: %010o leftSideFlag: %-10o", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with Zero_PRECISION + noFlags: %.o sharpFlag: %#.o leftSideFlag: %-.o", x, x, x);
  controlNum = sprintf(testString2, "Output with Zero_PRECISION + noFlags: %.o sharpFlag: %#.o leftSideFlag: %-.o", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 3_decimal_PRECISION + noFlags: %.3o sharpFlag: %#.3o leftSideFlag: %-.3o", x, x, x);
  controlNum = sprintf(testString2, "Output with 3_decimal_PRECISION + noFlags: %.3o sharpFlag: %#.3o leftSideFlag: %-.3o", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 10_decimal_PRECISION + noFlags: %.10o sharpFlag: %#.10o leftSideFlag: %-.10o", x, x, x);
  controlNum = sprintf(testString2, "Output with 10_decimal_PRECISION + noFlags: %.10o sharpFlag: %#.10o leftSideFlag: %-.10o", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10o sharpFlag: %#20.10o leftSideFlag: %-20.10o", x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10o sharpFlag: %#20.10o leftSideFlag: %-20.10o", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5o sharpFlag + zeroFlag: %#020o leftSideFlag + sharpFlag: %-#20.5o", x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5o sharpFlag + zeroFlag: %#020o leftSideFlag + sharpFlag: %-#20.5o", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_o_spec_random_value) {
  // Простой случай, форматирование строки с одной переменной
  int x = 586234747;
  char testString1[500];
  char testString2[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testString1, "Output with noFlags: %o sharpFlag: %#o nullFlag: %01o leftSideFlag: %-o", x, x, x, x);
  controlNum = sprintf(testString2, "Output with noFlags: %o sharpFlag: %#o nullFlag: %01o leftSideFlag: %-o", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with WIoTH + noFlags: %10o sharpFlag: %#10o zeroFlag: %010o leftSideFlag: %-10o", x, x, x, x);
  controlNum = sprintf(testString2, "Output with WIoTH + noFlags: %10o sharpFlag: %#10o zeroFlag: %010o leftSideFlag: %-10o", x, x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with Zero_PRECISION + noFlags: %.o sharpFlag: %#.o leftSideFlag: %-.o", x, x, x);
  controlNum = sprintf(testString2, "Output with Zero_PRECISION + noFlags: %.o sharpFlag: %#.o leftSideFlag: %-.o", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 3_decimal_PRECISION + noFlags: %.3o sharpFlag: %#.3o leftSideFlag: %-.3o", x, x, x);
  controlNum = sprintf(testString2, "Output with 3_decimal_PRECISION + noFlags: %.3o sharpFlag: %#.3o leftSideFlag: %-.3o", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 10_decimal_PRECISION + noFlags: %.10o sharpFlag: %#.10o leftSideFlag: %-.10o", x, x, x);
  controlNum = sprintf(testString2, "Output with 10_decimal_PRECISION + noFlags: %.10o sharpFlag: %#.10o leftSideFlag: %-.10o", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10o sharpFlag: %#20.10o leftSideFlag: %-20.10o", x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10o sharpFlag: %#20.10o leftSideFlag: %-20.10o", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5o sharpFlag + zeroFlag: %#020o leftSideFlag + sharpFlag: %-#20.5o", x, x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 5_decimal_PRECISION + noFlags: %20.5o sharpFlag + zeroFlag: %#020o leftSideFlag + sharpFlag: %-#20.5o", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_u_spec_null_value) {
  // Простой случай, форматирование строки с одной переменной
  unsigned int x = 0;
  char testString1[500];
  char testString2[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testString1, "Output with noFlags: %u nullFlag: %0u leftSideFlag: %-u", x, x, x);
  controlNum = sprintf(testString2, "Output with noFlags: %u nullFlag: %0u leftSideFlag: %-u", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with WIoTH + noFlags: %10u zeroFlag: %010u leftSideFlag: %-10u", x, x, x);
  controlNum = sprintf(testString2, "Output with WIoTH + noFlags: %10u zeroFlag: %010u leftSideFlag: %-10u", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with Zero_PRECISION + noFlags: %.u leftSideFlag: %-.u", x, x);
  controlNum = sprintf(testString2, "Output with Zero_PRECISION + noFlags: %.u leftSideFlag: %-.u", x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 3_decimal_PRECISION + noFlags: %.3u leftSideFlag: %-.3u", x, x);
  controlNum = sprintf(testString2, "Output with 3_decimal_PRECISION + noFlags: %.3u leftSideFlag: %-.3u", x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 10_decimal_PRECISION + noFlags: %.10u leftSideFlag: %-.10u", x, x);
  controlNum = sprintf(testString2, "Output with 10_decimal_PRECISION + noFlags: %.10u leftSideFlag: %-.10u", x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10u leftSideFlag: %-20.10u", x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10u leftSideFlag: %-20.10u", x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);  
}
END_TEST

START_TEST(Case_u_spec_max_value) {
  unsigned int x = 2147483647;
  char testString1[500];
  char testString2[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testString1, "Output with noFlags: %u nullFlag: %0u leftSideFlag: %-u", x, x, x);
  controlNum = sprintf(testString2, "Output with noFlags: %u nullFlag: %0u leftSideFlag: %-u", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with WIDTH + noFlags: %10u zeroFlag: %010u leftSideFlag: %-10u", x, x, x);
  controlNum = sprintf(testString2, "Output with WIDTH + noFlags: %10u zeroFlag: %010u leftSideFlag: %-10u", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with Zero_PRECISION + noFlags: %.u leftSideFlag: %-.u", x, x);
  controlNum = sprintf(testString2, "Output with Zero_PRECISION + noFlags: %.u leftSideFlag: %-.u", x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 3_decimal_PRECISION + noFlags: %.3u leftSideFlag: %-.3u", x, x);
  controlNum = sprintf(testString2, "Output with 3_decimal_PRECISION + noFlags: %.3u leftSideFlag: %-.3u", x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 10_decimal_PRECISION + noFlags: %.10u leftSideFlag: %-.10u", x, x);
  controlNum = sprintf(testString2, "Output with 10_decimal_PRECISION + noFlags: %.10u leftSideFlag: %-.10u", x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10u leftSideFlag: %-20.10u", x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10u leftSideFlag: %-20.10u", x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_u_spec_long_max_value) {
  unsigned long int x = 1844674407370955161;
  char testString1[500];
  char testString2[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testString1, "Output with noFlags: %lu nullFlag: %0lu leftSideFlag: %-lu", x, x, x);
  controlNum = sprintf(testString2, "Output with noFlags: %lu nullFlag: %0lu leftSideFlag: %-lu", x, x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10lu leftSideFlag: %-20.10lu", x, x);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 10_decimal_PRECISION + noFlags: %20.10lu leftSideFlag: %-20.10lu", x, x);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_s_c_spec) {
  char c = 'Z';
  char s1[] = "";
  char s2[] = "Hello world";
  char testString1[500];
  char testString2[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testString1, "Output with noFlags: %% %c %s %s", c, s1, s2);
  controlNum = sprintf(testString2, "Output with noFlags: %% %c %s %s", c, s1, s2);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with WIDTH: %10c %10s %10s", c, s1, s2);
  controlNum = sprintf(testString2, "Output with WIDTH: %10c %10s %10s", c, s1, s2);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with Zero_PRECISION: %.s %.s", s1, s2);
  controlNum = sprintf(testString2, "Output with Zero_PRECISION: %.s %.s", s1, s2);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 3_decimal_PRECISION: %.3s %.3s", s1, s2);
  controlNum = sprintf(testString2, "Output with 3_decimal_PRECISION: %.3s %.3s", s1, s2);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_decimal_PRECISION: %.20s %.20s", s1, s2);
  controlNum = sprintf(testString2, "Output with 20_decimal_PRECISION: %.20s %.20s", s1, s2);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 10_decimal_PRECISION: %20.10s %20.10s", s1, s2);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 10_decimal_PRECISION: %20.10s %20.10s", s1, s2);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 10_decimal_PRECISION and leftsideFlag: %-20.10s %-20.10s", s1, s2);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 10_decimal_PRECISION and leftsideFlag: %-20.10s %-20.10s", s1, s2);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH and 10_decimal_PRECISION and leftsideFlag: %-*.*s %-20.10s", 20, 10, s1, s2);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH and 10_decimal_PRECISION and leftsideFlag: %-*.*s %-20.10s", 20, 10, s1, s2);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);
}
END_TEST

START_TEST(Case_p_spec) {
  int x = 15;
  char s1[] = "";
  char s2[] = "Hello world";
  int *ptr = &x;
  char testString1[500];
  char testString2[500];
  int testNum = 0;
  int controlNum = 0;
         
  testNum = s21_sprintf(testString1, "Output with noFlags: %p %p %p", ptr, s1, s2);
  controlNum = sprintf(testString2, "Output with noFlags: %p %p %p", ptr, s1, s2);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

  testNum = s21_sprintf(testString1, "Output with 20_characters_WIDTH: %20p %20p %20p", ptr, s1, s2);
  controlNum = sprintf(testString2, "Output with 20_characters_WIDTH: %20p %20p %20p", ptr, s1, s2);
  ck_assert_str_eq(testString1, testString2);
  ck_assert_int_eq(testNum, controlNum);

}
END_TEST

Suite *s21_sprintf_suite(void) {
  Suite *s;
  TCase *tc_core_G_g_spec;
  TCase *tc_core_f_spec;
  TCase *tc_core_E_e_spec;
  TCase *tc_core_d_spec;
  TCase *tc_core_X_x_spec;
  TCase *tc_core_o_spec;
  TCase *tc_core_u_spec;
  TCase *tc_core_s_c_spec;
  TCase *tc_core_p_spec;

  s = suite_create("s21_sprintf");
  tc_core_G_g_spec = tcase_create("Core of sprintf");
  tc_core_f_spec = tcase_create("Core of sprintf");
  tc_core_E_e_spec = tcase_create("Core of sprintf");
  tc_core_d_spec  = tcase_create("Core of sprintf");
  tc_core_X_x_spec  = tcase_create("Core of sprintf");
  tc_core_o_spec  = tcase_create("Core of sprintf");
  tc_core_u_spec  = tcase_create("Core of sprintf");
  tc_core_s_c_spec  = tcase_create("Core of sprintf");
  tc_core_p_spec  = tcase_create("Core of sprintf");

  tcase_add_test(tc_core_G_g_spec, Case_G_g_spec_null_value);
  tcase_add_test(tc_core_G_g_spec, Case_G_g_spec_random_small_value);
  tcase_add_test(tc_core_G_g_spec, Case_G_g_spec_random_value);
  tcase_add_test(tc_core_G_g_spec, Case_G_g_spec_random_big_value);
  tcase_add_test(tc_core_G_g_spec, Case_G_g_spec_negative_value);
  tcase_add_test(tc_core_f_spec, Case_f_spec_null_value);
  tcase_add_test(tc_core_f_spec, Case_f_spec_random_small_value);
  tcase_add_test(tc_core_f_spec, Case_f_spec_random_very_small_value);
  tcase_add_test(tc_core_f_spec, Case_f_spec_random_big_value);
  tcase_add_test(tc_core_f_spec, Case_f_spec_random_negative_value);
  tcase_add_test(tc_core_E_e_spec, Case_E_e_spec_null_value);
  tcase_add_test(tc_core_E_e_spec, Case_E_e_spec_random_value);
  tcase_add_test(tc_core_E_e_spec, Case_E_e_spec_random_small_value);
  tcase_add_test(tc_core_E_e_spec, Case_E_e_spec_max_value);
  tcase_add_test(tc_core_E_e_spec, Case_E_e_spec_min_value);
  tcase_add_test(tc_core_E_e_spec, Case_E_e_spec_min_negative_value);
  tcase_add_test(tc_core_d_spec, Case_d_spec_null_value);
  tcase_add_test(tc_core_d_spec, Case_d_spec_max_value);
  tcase_add_test(tc_core_d_spec, Case_d_spec_min_value);
  tcase_add_test(tc_core_d_spec, Case_d_spec_negative_value);
  tcase_add_test(tc_core_d_spec, Case_d_spec_max_long_value);
  tcase_add_test(tc_core_X_x_spec, Case_X_x_spec_null_value);
  tcase_add_test(tc_core_X_x_spec, Case_X_x_spec_max_value);
  tcase_add_test(tc_core_X_x_spec, Case_X_x_spec_random_value);
  tcase_add_test(tc_core_o_spec, Case_o_spec_null_value);
  tcase_add_test(tc_core_o_spec, Case_o_spec_max_value);
  tcase_add_test(tc_core_o_spec, Case_o_spec_random_value);
  tcase_add_test(tc_core_u_spec, Case_u_spec_null_value);
  tcase_add_test(tc_core_u_spec, Case_u_spec_max_value);
  tcase_add_test(tc_core_u_spec, Case_u_spec_long_max_value);
  tcase_add_test(tc_core_s_c_spec, Case_s_c_spec);
  tcase_add_test(tc_core_p_spec, Case_p_spec);


  suite_add_tcase(s, tc_core_f_spec);
  suite_add_tcase(s, tc_core_G_g_spec);
  suite_add_tcase(s, tc_core_E_e_spec);
  suite_add_tcase(s, tc_core_d_spec);
  suite_add_tcase(s, tc_core_o_spec);
  suite_add_tcase(s, tc_core_X_x_spec);
  suite_add_tcase(s, tc_core_u_spec);
  suite_add_tcase(s, tc_core_s_c_spec);
  suite_add_tcase(s, tc_core_p_spec);
  
  return s;
}
