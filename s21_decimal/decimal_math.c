#include "decimal.h"

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
        if (bit_field_shift_left(result)) {
            return 1;
        };
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
    int scale_result = get_scale(value_1) + get_scale(value_2);
    //int scale_value_2 = get_scale(value_2);

    while (!null_value_bits_struct_decimal(temp_value_2) && count < 96) {
        if ((temp_value_2.bits[0] & 1) || (temp_value_2.bits[1] & 1) || (temp_value_2.bits[2] & 1)) {
            if (s21_add(temp_result, temp_value_1, &temp_result)) {
                if (scale_result) {
                    scale_result--;
                } else {
                    return 1;
                }
            }
            //s21_add(temp_result, temp_value_1, &temp_result);
        }
               
        bit_field_shift_left(&temp_value_1);
        bit_field_shift_right(&temp_value_2);
        count++;
    }

    *result = temp_result;

    return 0;
}

int bit_field_shift_left(s21_decimal *bf) {
    uint32_t tempA = bf->bits[0];
    uint32_t tempB = bf->bits[1];
    uint32_t tempC = bf->bits[2];
    //uint32_t tempD = bf->bits[3];

    // Сдвигаем каждый int на 1 бит влево
    bf->bits[3] <<= 1;
    if (tempC & 0x80000000) {
        return 1;
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

    return 0;
}

void bit_field_shift_right(s21_decimal *bf) {
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

int null_value_bits_struct_decimal(s21_decimal value) {
    int result = 0;
    if (value.bits[0] == 0 && value.bits[1] == 0 && value.bits[2] == 0) {
        result = 1;
    }

    return result;
}

void print_value_bits_struct_decimal(s21_decimal value) {
    printf("Bits[0]: %d bits[1]: %d bits[2]: %d Scale: %d\n", value.bits[0], value.bits[1], value.bits[2], get_scale(value));

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

int get_scale(s21_decimal dec) {
    int scale = 0;
    for(int i = BITS_3 + 16; i <= BITS_3 + 23; i++) {
        int bit = get_bit(dec, i);
        bit <<= (i - 16);
        scale |= bit;
    }
    return scale;
}

void set_scale(s21_decimal *dec, int scale) {
    for(int i = BITS_3 + 16; i <= BITS_3 + 23; i++) {
        set_bit(dec, scale & 1, i);  
        scale >>= 1;                    
    }
}

void set_bit(s21_decimal *dec, int bit, int pos) {
    int index = pos / 32;    // номер инта
    int position = pos % 32; // номер разряда
    if(bit == 1) {
        dec->bits[index] |= (1 << position); 
    } else {
        dec->bits[index] &= ~(1 << position);
    }
}

int get_bit(s21_decimal dec, int pos) {
  int index = pos / 32;   
  int position = pos % 32;   
  return (dec.bits[index] & (1 << position)) >> position;  
}