#include "decimal.h"

int get_exp_length(long double num) {
  int length = 0;
  if (num == 0) {
    return 0;
  }
  if (num >= 1) {
    num /= 10;
    while (num > 1) {
      num /= 10;
      length++;
    }
  } else {
    while (num < 1) {
      num *= 10;
      length--;
    }
  }

  return length;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  // определяем показатель EXP
  int exp = get_exp_length(src);
  char float_str[64]; 
  // переводим в строку с необходимой точностью, чтобы число поместилось в dec
  sprintf(float_str, "%.*E\n",(exp <= -23 ? exp + 28 : 6), src);
  char *ptr = float_str;
  int number = 0;
  while (*ptr != 'E') {
    ptr++;
  }
  int count = 0;
  ptr--;
  // убираем конечные нули
  while (*ptr == '0') {
      exp++;
      ptr--;
    }
  ptr++;
  // переводим в int 
  while (ptr != float_str) {
    ptr--;
    if (*ptr >= '0' && *ptr <= '9') {
      number += (*ptr - '0') * pow(10, count);
      count++;
    }
  }
  // считаем значение масштабного коэффициента
  int scale = 6 - exp;
  //записываем число в структуру decimal
  s21_decimal temp = {0};
  temp.bits[0] = number;
  // для чисел со степенью более 6 производим умножение на 10, пока масштабный коэф не станет равным 0. Или записываем показатель в bits[3]
  if (scale < 0) {
    s21_decimal ten_num = {0};
    ten_num.bits[0] = 10;
    while (scale < 0) {
      s21_mul(temp, ten_num, &temp);
      scale++;
    }
  } else {
    set_scale(&temp, scale);
  }
  
  *dst = temp;

  return 1;
}
