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
  s21_decimal temp = {0};
  if (src < 0) {
    set_sign(&temp, 1);
    src *= -1;
  }

  // определяем показатель EXP
  int exp = get_exp_length(src);
  char float_str[64];
  // переводим в строку с необходимой точностью, чтобы число поместилось в dec
  sprintf(float_str, "%.*E\n", (exp <= -23 ? exp + 28 : 6), src);
  char *ptr = float_str;
  int number = 0;
  while (*ptr != 'E') {
    ptr++;
  }
  ptr--;
  // убираем конечные нули
  while (*ptr == '0') {
    exp++;
    ptr--;
  }
  ptr++;
  // переводим в int
  int count = 0;
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
  temp.bits[0] = number;
  // для чисел со степенью более 6 производим умножение на 10, пока масштабный
  // коэф не станет равным 0. Или записываем показатель в bits[3]
  if (scale < 0) {
    s21_decimal ten_num = {0};
    ten_num.bits[0] = 10;
    while (scale < 0) {
      s21_mul(temp, ten_num, &temp);
      scale++;
    }
  } else {
    s21_set_scale(&temp, scale);
  }

  *dst = temp;

  return 1;
}

/*int check_float_to_decimal(float src, s21_decimal *dst) {
  int code = S21_CONVERSION_TRUE;
  if (!dst) {
    // Если указатель на decimal является NULL
    code = false;
  } else if (isinf(src) || isnan(src)) {
    // Отдельно обрабатываем +inf, -inf, +nan, и -nan
    code = false;
    *dst = s21_decimal_get_inf();

    if (signbit(src) != 0) {
      // Добавляем знак для -nan и -inf
      s21_decimal_set_sign(dst, S21_NEGATIVE);
    }
  } else if (fabsf(src) > MAX_FLOAT_TO_CONVERT) {
    // MAX_FLOAT_TO_CONVERT - максимальное число, которое можно сконвертировать
    // в decimal
    code = false;
    *dst = s21_decimal_get_inf();
    if (signbit(src) != 0) {
      // Добавляем знак для для отрицательного числа
      s21_decimal_set_sign(dst, S21_NEGATIVE);
    }
  } else if (fabsf(src) < MIN_FLOAT_TO_CONVERT) {
    // MIN_FLOAT_TO_CONVERT - минимальное число, которое можно сконвертировать в
    // decimal
    code = false;
    *dst = s21_decimal_get_zero();
  }

  return code;
}*/

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  dst->bits[0] = abs(src);

  if (src < 0) {
    dst->bits[3] = (1 << 31);
  }

  return 1;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  double number = 0.0f;
  int scale = get_scale(src);
  
  for (int i = 0; i < BITS_3; i++) {
    if (get_bit(src, i)) {
      number += pow(2.0, i);
    }
  }
  
  double powerten = pow(10, scale);
  number /= powerten;

  if (s21_get_sign(src)) {
    number *= -1;
  }
  *dst = (float)number;

  return 1;
}