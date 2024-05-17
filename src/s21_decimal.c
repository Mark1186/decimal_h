#include "s21_decimal.h"

res_t *s21_constructor() {
  res_t *res = (res_t *)calloc(sizeof(res_t), sizeof(res_t));
  PANIC(res);
  if (res != NULL) {
    res->tmp_str = (char *)calloc(1024, sizeof(char));
    PANIC(res->tmp_str);

    res->des_str = (char *)calloc(1024, sizeof(char));
    PANIC(res->des_str);

    res->dec_part = (char *)calloc(1024, sizeof(char));
    PANIC(res->dec_part);

    res->comma_part = (char *)calloc(1024, sizeof(char));
    PANIC(res->comma_part);
  }
  return res;
}

void s21_destructor(res_t *res) {
  if (res) {
    if (res->tmp_str) {
      free(res->tmp_str);
      res->tmp_str = NULL;
    }
    if (res->des_str) {
      free(res->des_str);
      res->des_str = NULL;
    }
    if (res->dec_part) {
      free(res->dec_part);
      res->dec_part = NULL;
    }
    if (res->comma_part) {
      free(res->comma_part);
      res->comma_part = NULL;
    }
    free(res);
  }
}

int s21_extract_bits_three(s21_decimal src) {
  int result_code = 0;
  int num = src.bits[3];
  unsigned int mask_low = 0xFFFF;
  unsigned int extracted_bits_low = (num & mask_low);
  int mask_high = 0x7F << 24;
  int extracted_bits_high = (num & mask_high) >> 24;
  if (extracted_bits_low || extracted_bits_high) {
    result_code = 1;
  }
  return result_code;
}

int s21_extracting_0_15(s21_decimal src) {
  int num = src.bits[3];
  unsigned int mask = 0xFFFF;
  int extracted_bits = (num & mask);
  return extracted_bits;
}

int s21_get_exponent(s21_decimal src) {
  int num = src.bits[3];
  int mask = 0xFF << 16;
  int extracted_bits = (num & mask) >> 16;
  return extracted_bits;
}

int s21_extracting_24_30(s21_decimal src) {
  int num = src.bits[3];
  int mask = 0x7F << 24;
  int extracted_bits = (num & mask) >> 24;
  return extracted_bits;
}

void s21_reverse_string(char *str) {
  res_t *res = s21_constructor();
  PANIC(str);
  if (str && res) {
    size_t i = 0;
    for (int j = (int)strlen(str) - 1; j >= 0; --j) {
      res->tmp_str[i++] = str[j];
    }
    res->tmp_str[i] = '\0';
    strcpy(str, res->tmp_str);
  }
  s21_destructor(res);
}

void s21_binary_to_string(s21_decimal value, char *str) {
  res_t *tmp = s21_constructor();
  PANIC(str);
  if (str && tmp) {
    int negative = (value.bits[3] >> 31);
    int index = 0;
    if (negative) {
      tmp->tmp_str[index++] = '-';
    }
    for (int i = 2; i >= 0; i--) {
      for (int j = 31; j >= 0; j--) {
        int bit = (value.bits[i] >> j) & 1;
        tmp->tmp_str[index] = bit ? '1' : '0';
        index++;
      }
    }
    tmp->tmp_str[index] = '\0';
    strcpy(str, tmp->tmp_str);
  }
  s21_destructor(tmp);
}

void s21_number_alignment(char *binary_1, char *binary_2) {
  res_t *res = s21_constructor();
  PANIC(binary_1, binary_2);
  if (res && binary_1 && binary_2) {
    int len1 = (int)strlen(binary_1);
    int len2 = (int)strlen(binary_2);
    int diff = abs(len1 - len2);
    while (diff-- > 0) {
      strcat(res->tmp_str, "0");
    }
    if (len1 > len2) {
      strcat(res->tmp_str, binary_2);
      strcpy(binary_2, res->tmp_str);
    } else if (len2 > len1) {
      strcat(res->tmp_str, binary_1);
      strcpy(binary_1, res->tmp_str);
    }
  }
  s21_destructor(res);
}

void s21_del_symbol_handle(char *value, char symbol, size_t *index_des) {
  PANIC(value, index_des);
  if (value && index_des) {
    for (size_t i = 0; value[i] != '\0'; ++i) {
      if (value[i] != symbol) {
        value[(*index_des)++] = value[i];
      }
    }
  }
}

void s21_del_symbol(char *value, deleting_symbol_t symbol) {
  PANIC(value);
  if (value != NULL) {
    char del_symbol = '\0';
    if (symbol == MINUS) {
      del_symbol = '-';
    } else if (symbol == COMMA) {
      del_symbol = '.';
    }
    char *find_comma = strchr(value, del_symbol);
    if (find_comma) {
      size_t index_des = 0;
      s21_del_symbol_handle(value, del_symbol, &index_des);
      value[index_des] = '\0';
    }
  }
}

void s21_del_zero_begin(char *value) {
  PANIC(value);
  if (value) {
    _Bool is_end = FALSE;
    s21_reverse_string(value);
    for (int i = (int)strlen(value) - 1; i >= 0 && !is_end; --i) {
      int digit = value[i] - '0';
      if (digit == 0) {
        value[i] = '\0';
      } else {
        is_end = TRUE;
      }
    }
    s21_reverse_string(value);
  }
}

void s21_set_negative_number(char *des) {
  PANIC(des);
  if (des) {
    s21_reverse_string(des);
    strcat(des, "-");
    s21_reverse_string(des);
  }
}

int s21_binary_cmp(char *binary_1, char *binary_2) {
  int result = IS_EQUAL;
  res_t *val_1 = s21_constructor();
  res_t *val_2 = s21_constructor();
  PANIC(binary_1, binary_2);
  if (val_1 && val_2 && binary_1 && binary_2) {
    strcpy(val_1->tmp_str, binary_1);
    strcpy(val_2->tmp_str, binary_2);
    s21_number_alignment(val_1->tmp_str, val_2->tmp_str);
    for (size_t i = 0; val_1->tmp_str[i] != '\0' && !result; ++i) {
      int bit_1 = val_1->tmp_str[i] - '0';
      int bit_2 = val_2->tmp_str[i] - '0';
      if (bit_1 > bit_2) {
        result = IS_GREATER;
      } else if (bit_1 < bit_2) {
        result = IS_LESS;
      }
    }
  }
  s21_destructor(val_1);
  s21_destructor(val_2);
  return result;
}

int s21_checking_number_for_size(const char *src) {
  int error_code = OK;
  char *tmp_str = (char *)calloc(1024, sizeof(char));
  PANIC(tmp_str, src);
  if (tmp_str != NULL && src != NULL) {
    strcpy(tmp_str, src);
    char *find_minus = strchr(tmp_str, '-');
    s21_del_symbol(tmp_str, COMMA);
    if (find_minus) {
      s21_del_symbol(tmp_str, MINUS);
    }
    int result = s21_binary_cmp(tmp_str, MAX_VALUE);

    if (result > 0) {
      if (!find_minus) {
        error_code = NUMBER_LARGE;
      } else {
        error_code = NUMBER_SMALL;
      }
    }
  }
  free(tmp_str);
  return error_code;
}

void s21_splitting_number(const char *src, char *dec_part, char *comma_part) {
  PANIC(src, dec_part, comma_part);
  if (src && dec_part && comma_part) {
    size_t index = 0;
    if (strchr(src, '.')) {
      while (src[index] != '.') {
        dec_part[index] = src[index];
        index++;
      }
      dec_part[index] = '\0';
      index++;
      size_t index_comma = 0;
      while (src[index] != '\0') {
        comma_part[index_comma++] = src[index];
        index++;
      }
      comma_part[index_comma] = '\0';
    } else {
      strcpy(dec_part, src);
    }
  }
}

int s21_decimal_get_scale(s21_decimal value) {
  char result = (char)(value.bits[3] >> 16);
  return abs(result);
}

void s21_binary_comma_part_to_dec_comma_part(const char *binary, char *dec) {
  res_t *tmp = s21_constructor();
  PANIC(binary, dec);
  if (binary && dec && tmp) {
    int index = -1;
    double sum = 0;
    for (size_t i = 0; binary[i] != '\0'; ++i) {
      int bit = binary[i] - '0';
      double digit = bit * (pow(2, index--));
      sum += digit;
    }
    sprintf(tmp->comma_part, "%f", sum);
    s21_reverse_string(tmp->comma_part);
    strncpy(dec, tmp->comma_part, strlen(tmp->comma_part) - 2);
    s21_reverse_string(dec);
  }
  s21_destructor(tmp);
}

void s21_bank_rounding(char *value) {
  res_t *tmp = s21_constructor();
  PANIC(value);
  if (tmp && value) {
    _Bool is_neg = FALSE;
    if (strchr(value, '-')) {
      s21_del_symbol(value, MINUS);
      is_neg = TRUE;
    }
    s21_splitting_number(value, tmp->dec_part, tmp->comma_part);
    s21_binary_comma_part_to_dec_comma_part(tmp->comma_part, tmp->tmp_str);
    int last_digit_dec_part = tmp->dec_part[strlen(tmp->dec_part) - 1] - '0';
    int first_digit_comma_part = tmp->tmp_str[0] - '0';
    if (last_digit_dec_part) {
      if (first_digit_comma_part >= 5) {
        s21_sum_binary_string(tmp->dec_part, "1", tmp->dec_part);
      }
    } else {
      if (first_digit_comma_part > 5) {
        s21_sum_binary_string(tmp->dec_part, "1", tmp->dec_part);
      }
    }
    if (is_neg) {
      s21_reverse_string(tmp->dec_part);
      strcat(tmp->dec_part, "-");
      s21_reverse_string(tmp->dec_part);
    }
    strcpy(value, tmp->dec_part);
  }
  s21_destructor(tmp);
}

int s21_diff_in_zoom_levels(s21_decimal val_1, s21_decimal val_2) {
  int zoom_lvl_1 = s21_decimal_get_scale(val_1);
  int zoom_lvl_2 = s21_decimal_get_scale(val_2);
  int diff = abs(zoom_lvl_1 - zoom_lvl_2);
  return diff;
}

_Bool s21_decimal_is_zero(s21_decimal *value) {
  _Bool is_zero = TRUE;
  if (value->bits[0] != 0 || value->bits[1] != 0 || value->bits[2] != 0) {
    is_zero = FALSE;
  }
  return is_zero;
}

void s21_denominator_handle(char *value, unsigned int diff) {
  res_t *res = s21_constructor();
  PANIC(value, res);
  if (value && res) {
    while (diff > 0) {
      s21_multiply_binary(value, "1010", res->tmp_str);
      strcpy(value, res->tmp_str);
      diff--;
    }
  }
  s21_destructor(res);
}

int s21_common_denominator(s21_decimal val_1, s21_decimal val_2, char *binary_1,
                           char *binary_2) {
  int result = 0;
  PANIC(binary_1, binary_2);
  if (binary_1 && binary_2) {
    int scale_1 = s21_decimal_get_scale(val_1);
    int scale_2 = s21_decimal_get_scale(val_2);
    int diff = 0;
    if (scale_1 == scale_2) {
      result = scale_1;
    } else {
      diff = s21_diff_in_zoom_levels(val_1, val_2);
      if (scale_1 > scale_2) {
        s21_denominator_handle(binary_2, diff);
        result = scale_1;
      } else if (scale_2 > scale_1) {
        s21_denominator_handle(binary_1, diff);
        result = scale_2;
      }
    }
  }
  return result;
}

void s21_opposite_of_denominator(int denominator, char *des_str) {
  if (denominator-- > 0) {
    res_t *res = s21_constructor();
    PANIC(des_str);
    if (res && des_str && denominator >= 0) {
      strcpy(res->dec_part, "1010");
      s21_denominator_handle(res->dec_part, denominator);
      s21_division_binary(des_str, res->dec_part, res->des_str);
      strcpy(des_str, res->des_str);
    }
    s21_destructor(res);
  }
}

void s21_decimal_init(s21_decimal *dec) {
  PANIC(dec);
  if (dec) {
    dec->bits[0] = 0;
    dec->bits[1] = 0;
    dec->bits[2] = 0;
    dec->bits[3] = 0;
  }
}

void s21_binary_string_to_decimal_handle(const char *des, s21_decimal *result,
                                         int *index_result, int *index_bit,
                                         int *count, size_t index) {
  if (des && index_result && index_bit && count) {
    if (*index_result >= 0) {
      int bit = des[index] - '0';
      result->bits[*index_result] |= (bit << *index_bit);
      if (*count == 31) {
        *count = 0;
        *index_bit = 31;
        (*index_result)--;
      } else {
        (*count)++;
        (*index_bit)--;
      }
    }
  }
}

void s21_binary_string_to_decimal_processing(const char *des,
                                             s21_decimal *result,
                                             _Bool num_is_large) {
  PANIC(des);
  if (des) {
    int count = 0;
    int index_bit = 31;
    int index_result = 2;
    for (size_t i = 0; des[i] != '\0' && !num_is_large; i++) {
      s21_binary_string_to_decimal_handle(des, result, &index_result,
                                          &index_bit, &count, i);
    }
  }
}

void s21_binary_string_to_decimal(char *binary, s21_decimal *result) {
  res_t *tmp = s21_constructor();
  PANIC(binary);
  if (tmp && binary) {
    s21_decimal_init(result);
    strcpy(tmp->tmp_str, binary);
    char *comma = strchr(tmp->tmp_str, '.');
    char *negative = strchr(tmp->tmp_str, '-');
    if (negative) {
      s21_del_symbol(tmp->tmp_str, MINUS);
      result->bits[3] |= (1 << 31);
    }
    if (comma) {
      s21_splitting_number(tmp->tmp_str, tmp->dec_part, tmp->comma_part);
      int position_comma = (int)strlen(tmp->comma_part);
      result->bits[3] |= (position_comma << 16);
      s21_del_symbol(tmp->tmp_str, COMMA);
    }

    _Bool num_is_large = FALSE;

    if (s21_binary_cmp(tmp->tmp_str, MAX_VALUE) <= 0) {
      s21_number_alignment(MAX_VALUE, tmp->tmp_str);
    } else {
      num_is_large = TRUE;
    }

    s21_binary_string_to_decimal_processing(tmp->tmp_str, result, num_is_large);
  }
  s21_destructor(tmp);
}

void s21_sum_binary_string(const char *binary_1, const char *binary_2,
                           char *des_str) {
  res_t *res = s21_constructor();
  res_t *val_1 = s21_constructor();
  res_t *val_2 = s21_constructor();
  PANIC(binary_1, binary_2, des_str);
  if (res && val_1 && val_2 && binary_1 && binary_2 && des_str) {
    strcpy(val_1->tmp_str, binary_1);
    strcpy(val_2->tmp_str, binary_2);
    char *negative_val_1 = strchr(val_1->tmp_str, '-');
    char *negative_val_2 = strchr(val_2->tmp_str, '-');
    if (negative_val_1) {
      s21_del_symbol(val_1->tmp_str, MINUS);
    }
    if (negative_val_2) {
      s21_del_symbol(val_2->tmp_str, MINUS);
    }

    int carry = 0;
    size_t index_result = 0;

    s21_number_alignment(val_1->tmp_str, val_2->tmp_str);

    for (int i = (int)strlen(val_1->tmp_str) - 1; i >= 0; --i) {
      int bit1 = val_1->tmp_str[i] - '0';
      int bit2 = val_2->tmp_str[i] - '0';

      int sum = bit1 + bit2 + carry;
      res->des_str[index_result++] = sum % 2 + '0';
      carry = sum / 2;
    }

    if (carry > 0) {
      res->des_str[index_result++] = carry + '0';
    }

    res->des_str[strlen(res->des_str)] = '\0';
    s21_reverse_string(res->des_str);
    strcpy(des_str, res->des_str);
  }
  s21_destructor(res);
  s21_destructor(val_1);
  s21_destructor(val_2);
}

void s21_subtract_handle(const char *binary_1, const char *binary_2, char *res,
                         size_t *index_result, _Bool is_negative) {
  PANIC(binary_1, binary_2, res);
  if (binary_1 && binary_2 && res) {
    int borrow = 0;
    int bit1 = 0;
    int bit2 = 0;
    for (int i = (int)strlen(binary_1) - 1; i >= 0; --i) {
      if (!is_negative) {
        bit1 = binary_1[i] - '0';
        bit2 = binary_2[i] - '0';
      } else {
        bit1 = binary_2[i] - '0';
        bit2 = binary_1[i] - '0';
      }

      int diff = bit1 - bit2 - borrow;

      if (diff < 0) {
        diff += 2;
        borrow = 1;
      } else {
        borrow = 0;
      }
      res[(*index_result)++] = diff + '0';
    }

    if (borrow > 0) {
      res[(*index_result)++] = borrow + '0';
    }
  }
}

void s21_subtract_binary_string(char *binary_1, char *binary_2, char *des_str) {
  res_t *res = s21_constructor();
  PANIC(binary_1, binary_2, des_str);
  if (res && binary_1 && binary_2 && des_str) {
    size_t index_result = 0;
    _Bool is_negative = FALSE;
    char *neg_binary_1 = strchr(binary_1, '-');
    char *neg_binary_2 = strchr(binary_2, '-');
    if (neg_binary_1) {
      s21_del_symbol(binary_1, MINUS);
    }
    if (neg_binary_2) {
      s21_del_symbol(binary_2, MINUS);
    }

    s21_number_alignment(binary_1, binary_2);

    if (s21_binary_cmp(binary_1, binary_2) < 0) {
      is_negative = TRUE;
    }

    s21_subtract_handle(binary_1, binary_2, res->des_str, &index_result,
                        is_negative);

    if (is_negative) {
      res->des_str[index_result++] = '-';
    }
    res->des_str[index_result] = '\0';
    s21_reverse_string(res->des_str);
    strcpy(des_str, res->des_str);
  }
  s21_destructor(res);
}

void s21_memory_allocation_for_mul_results(char **arr, size_t size) {
  PANIC(arr);
  if (arr) {
    for (size_t i = 0; i < size; ++i) {
      arr[i] = (char *)calloc(1024, sizeof(char));
    }
  }
}

void s21_multiply_handle(char *val_1, char *val_2, char **arr) {
  char *zero_num = (char *)calloc(1024, sizeof(char));
  size_t index_arr = 0;
  PANIC(val_1, val_2, arr);
  if (zero_num && val_1 && val_2 && arr) {
    for (int i = (int)strlen(val_1) - 1; i >= 0; --i) {
      strcat(zero_num, "0");
    }
    for (int i = (int)strlen(val_2) - 1; i >= 0; --i) {
      if (val_2[i] == '1') {
        strcat(arr[index_arr], val_1);
      } else {
        strcat(arr[index_arr], zero_num);
      }
      s21_reverse_string(arr[index_arr]);
      int adding_empty = (int)strlen(val_2) - 1;
      while (adding_empty > (int)index_arr) {
        strcat(arr[index_arr], "0");
        adding_empty--;
      }
      s21_reverse_string(arr[index_arr]);
      int adding_zero = (int)index_arr;
      while (adding_zero > 0) {
        strcat(arr[index_arr], "0");
        adding_zero--;
      }
      index_arr++;
    }
  }
  free(zero_num);
}

void s21_summation_mul_results(char *res, char **arr, size_t size) {
  PANIC(res, arr);
  if (res && arr) {
    if (size > 1) {
      strcpy(res, arr[1]);
      _Bool is_once = TRUE;
      for (size_t i = 0; i < size; ++i) {
        s21_sum_binary_string(arr[i], res, res);
        if (is_once) {
          i++;
          is_once = FALSE;
        }
      }
    } else {
      strcpy(res, arr[0]);
    }
  }
}

void s21_multiply_binary(char *val_1, char *val_2, char *res) {
  PANIC(val_1, val_2, res);
  if (val_1 && val_2 && res) {
    size_t size = strlen(val_2);
    char **arr = (char **)calloc(size, sizeof(char *));
    PANIC(arr);
    if (arr) {
      char *negative_val_1 = strchr(val_1, '-');
      char *negative_val_2 = strchr(val_2, '-');
      s21_memory_allocation_for_mul_results(arr, size);
      s21_multiply_handle(val_1, val_2, arr);
      s21_summation_mul_results(res, arr, size);
      if (s21_binary_cmp(res, "0") != 0) {
        s21_del_zero_begin(res);
      } else {
        strcpy(res, "0");
      }
      if ((negative_val_1 && !negative_val_2) ||
          (!negative_val_1 && negative_val_2)) {
        s21_set_negative_number(res);
      }

      for (size_t i = 0; i < size; ++i) {
        free(arr[i]);
      }
      free(arr);
    }
  }
}

void s21_checking_for_division_completion(char *val_1, char *des, char *res,
                                          _Bool *is_div, size_t index) {
  PANIC(val_1, des, res, is_div);
  if (val_1 && des && res && is_div) {
    size_t val_1_len = strlen(val_1);
    if ((val_1_len == 0) && (s21_binary_cmp(des, "0") == 0)) {
      *is_div = FALSE;
    } else {
      *is_div = TRUE;
      if (index == val_1_len) {
        strcat(res, ".");
      }
    }
  }
}

void s21_writing_division_result(res_t *des, res_t *res, _Bool is_comma_part) {
  PANIC(des, res);
  if (des && res) {
    if (s21_binary_cmp(des->tmp_str, des->des_str) >= 0) {
      s21_subtract_binary_string(des->tmp_str, des->des_str, des->tmp_str);
      strcat(res->tmp_str, "1");
      if (is_comma_part) {
        strcpy(res->comma_part, des->tmp_str);
        s21_del_zero_begin(res->comma_part);
      } else {
        strcpy(des->comma_part, des->tmp_str);
        s21_del_zero_begin(des->comma_part);
      }
    } else {
      strcat(res->tmp_str, "0");
    }
  }
}

void s21_comparing_with_divisor(char *val_1, char *val_2, res_t *des,
                                _Bool *is_comma_part, int *precision,
                                size_t index) {
  PANIC(val_1, val_2, des, is_comma_part, precision);
  if (val_1 && val_2 && des && is_comma_part && precision) {
    if (s21_binary_cmp(des->tmp_str, val_2) >= 0) {
      s21_multiply_binary(val_2, "1", des->des_str);
    } else {
      if (val_1[index] != '\0') {
        int bit = val_1[index] - '0';
        //                bit == 1 ? strcat(des->tmp_str, "1") :
        //                strcat(des->tmp_str, "0");
        des->tmp_str[index] = bit + '0';
      } else {
        strcat(des->tmp_str, "0");
        //                des->tmp_str[index] = '0';
        *is_comma_part = TRUE;
        (*precision)--;
      }
    }
  }
}

void s21_division_handle(char *val_1, char *val_2, res_t *des, res_t *res,
                         _Bool is_div, size_t index, _Bool *is_comma_part,
                         int *precision) {
  PANIC(val_1, val_2, des, res, is_comma_part, precision);
  if (val_1 && val_2 && des && res && is_comma_part && precision) {
    if (is_div) {
      s21_comparing_with_divisor(val_1, val_2, des, is_comma_part, precision,
                                 index);
      s21_writing_division_result(des, res, *is_comma_part);
    }
  }
}

void s21_division_processing(char *val_1, char *val_2, res_t *des, res_t *res) {
  PANIC(val_1, val_2, des, res);
  if (val_1 && val_2 && des && res) {
    int precision = 12;
    _Bool is_div = TRUE;
    _Bool is_comma_part = FALSE;
    for (size_t i = strlen(des->tmp_str) - 1; is_div && precision; i++) {
      s21_checking_for_division_completion(val_1, des->tmp_str, res->tmp_str,
                                           &is_div, i);
      s21_division_handle(val_1, val_2, des, res, is_div, i, &is_comma_part,
                          &precision);
    }
  }
}

void s21_begin_setting_for_div(char *val_1, char *val_2, char *des) {
  PANIC(val_1, val_2, des);
  if (val_1 && val_2 && des) {
    strncat(des, val_1, strlen(val_2));
    strcat(des, "\0");
    if (s21_binary_cmp(des, val_2) < 0) {
      memset(des, 0, strlen(des));
      strncat(des, val_1, strlen(val_2) + 1);
      strcat(des, "\0");
    }
  }
}

void s21_normalizing_value(char *val_1, char *val_2, _Bool *is_negative) {
  PANIC(val_1, val_2);
  if (val_1 && val_2 && is_negative) {
    char *neg_val_1 = strchr(val_1, '-');
    char *neg_val_2 = strchr(val_2, '-');
    if (neg_val_1 && !neg_val_2) {
      *is_negative = TRUE;
      s21_del_symbol(val_1, MINUS);
    } else if (!neg_val_1 && neg_val_2) {
      *is_negative = TRUE;
      s21_del_symbol(val_2, MINUS);
    }

    s21_del_zero_begin(val_1);
    s21_del_zero_begin(val_2);

    s21_del_symbol(val_1, COMMA);
    s21_del_symbol(val_2, COMMA);
  }
}

void s21_division_binary(char *val1, char *val2, char *result) {
  res_t *tmp = s21_constructor();
  res_t *res = s21_constructor();
  res_t *val1_tmp = s21_constructor();
  res_t *val2_tmp = s21_constructor();
  PANIC(val1, val2, result);
  if (tmp && res && val1_tmp && val2_tmp && val1 && val2 && result) {
    _Bool is_negative = FALSE;
    strcpy(val1_tmp->tmp_str, val1);
    strcpy(val2_tmp->tmp_str, val2);

    s21_normalizing_value(val1_tmp->tmp_str, val2_tmp->tmp_str, &is_negative);

    size_t len1 = strlen(val1_tmp->tmp_str);
    size_t len2 = strlen(val2_tmp->tmp_str);

    if (len2 > len1) {
      strcpy(tmp->des_str, val2_tmp->tmp_str);
    }

    s21_begin_setting_for_div(val1_tmp->tmp_str, val2_tmp->tmp_str,
                              tmp->tmp_str);
    s21_division_processing(val1_tmp->tmp_str, val2_tmp->tmp_str, tmp, res);

    if (is_negative) {
      s21_set_negative_number(res->tmp_str);
    }

    strcpy(result, res->tmp_str);
  }
  s21_destructor(val1_tmp);
  s21_destructor(val2_tmp);
  s21_destructor(tmp);
  s21_destructor(res);
}

void s21_handle_addition_binary_with_signs(char *val_1, char *val_2, char *res,
                                           const char *negative_1,
                                           const char *negative_2) {
  if (negative_1 && negative_2) {
    s21_sum_binary_string(val_1, val_2, res);
    s21_set_negative_number(res);
  } else if (negative_1 || negative_2) {
    if (negative_1) {
      if (s21_binary_cmp(val_1, val_2) > 0) {
        s21_subtract_binary_string(val_1, val_2, res);
        s21_set_negative_number(res);
      } else {
        s21_subtract_binary_string(val_2, val_1, res);
      }
    } else {
      if (s21_binary_cmp(val_1, val_2) >= 0) {
        s21_subtract_binary_string(val_1, val_2, res);
      } else {
        s21_subtract_binary_string(val_2, val_1, res);
        s21_set_negative_number(res);
      }
    }
  } else {
    s21_sum_binary_string(val_1, val_2, res);
  }
}

void s21_handle_subtraction_binary_with_signs(char *val_1, char *val_2,
                                              char *res, const char *negative_1,
                                              const char *negative_2) {
  if (negative_1 && negative_2) {
    if (s21_binary_cmp(val_2, val_1) > 0) {
      s21_subtract_binary_string(val_2, val_1, res);
    } else {
      s21_subtract_binary_string(val_1, val_2, res);
      s21_set_negative_number(res);
    }
  } else if (negative_1 || negative_2) {
    if (negative_1) {
      s21_sum_binary_string(val_1, val_2, res);
      s21_set_negative_number(res);
    } else {
      s21_sum_binary_string(val_1, val_2, res);
    }
  } else {
    if (s21_binary_cmp(val_1, val_2) >= 0) {
      s21_subtract_binary_string(val_1, val_2, res);
    } else {
      s21_subtract_binary_string(val_2, val_1, res);
      s21_set_negative_number(res);
    }
  }
}

void s21_calculating(char *val_1, char *val_2, char *res,
                     math_operations_t operation) {
  PANIC(val_1, val_2, res);
  if (val_1 && val_2 && res) {
    char *negative_1 = strchr(val_1, '-');
    char *negative_2 = strchr(val_2, '-');
    if (negative_1) {
      s21_del_symbol(val_1, MINUS);
    }
    if (negative_2) {
      s21_del_symbol(val_2, MINUS);
    }
    if (operation == ADD) {
      s21_handle_addition_binary_with_signs(val_1, val_2, res, negative_1,
                                            negative_2);
    } else if (operation == SUB) {
      s21_handle_subtraction_binary_with_signs(val_1, val_2, res, negative_1,
                                               negative_2);
    } else if (operation == MUL) {
      s21_multiply_binary(val_1, val_2, res);
      if (((negative_1 && !negative_2) || (!negative_1 && negative_2)) &&
          strlen(res) > 1) {
        s21_set_negative_number(res);
      }
    } else {
      s21_division_binary(val_1, val_2, res);
      if ((negative_1 && !negative_2) || (!negative_1 && negative_2)) {
        s21_set_negative_number(res);
      }
    }
  }
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error_code = OK;
  res_t *res = s21_constructor();
  res_t *val1 = s21_constructor();
  res_t *val2 = s21_constructor();
  PANIC(result);
  int exponent_val1 = s21_get_exponent(value_1);
  int exponent_val2 = s21_get_exponent(value_2);
  int bits_val1 = s21_extract_bits_three(value_1);
  int bits_val2 = s21_extract_bits_three(value_2);
  if (res && val1 && val2 && result && exponent_val1 < 29 &&
      exponent_val2 < 29 && !bits_val1 && !bits_val2) {
    s21_decimal_init(result);
    s21_binary_to_string(value_1, val1->tmp_str);
    s21_binary_to_string(value_2, val2->tmp_str);

    int denominator =
        s21_common_denominator(value_1, value_2, val1->tmp_str, val2->tmp_str);

    s21_calculating(val1->tmp_str, val2->tmp_str, res->tmp_str, ADD);

    error_code = s21_checking_number_for_size(res->tmp_str);
    if (error_code != OK) {
      s21_opposite_of_denominator(denominator, res->tmp_str);
      s21_bank_rounding(res->tmp_str);
      error_code = s21_checking_number_for_size(res->tmp_str);
      denominator = 0;
    }

    if (error_code == OK) {
      s21_binary_string_to_decimal(res->tmp_str, result);
      result->bits[3] |= (denominator << 16);
    }
  } else {
    error_code = ERROR;
  }
  s21_destructor(val1);
  s21_destructor(val2);
  s21_destructor(res);
  return error_code;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error_code = OK;
  res_t *res = s21_constructor();
  res_t *val1 = s21_constructor();
  res_t *val2 = s21_constructor();
  PANIC(result);
  int exponent_val1 = s21_get_exponent(value_1);
  int exponent_val2 = s21_get_exponent(value_2);
  int bits_val1 = s21_extract_bits_three(value_1);
  int bits_val2 = s21_extract_bits_three(value_2);
  if (res && val1 && val2 && result && exponent_val1 < 29 &&
      exponent_val2 < 29 && !bits_val1 && !bits_val2) {
    s21_decimal_init(result);
    s21_binary_to_string(value_1, val1->tmp_str);
    s21_binary_to_string(value_2, val2->tmp_str);

    int denominator =
        s21_common_denominator(value_1, value_2, val1->tmp_str, val2->tmp_str);

    s21_calculating(val1->tmp_str, val2->tmp_str, res->tmp_str, SUB);

    error_code = s21_checking_number_for_size(res->tmp_str);
    if (error_code != OK) {
      s21_opposite_of_denominator(denominator, res->tmp_str);
      s21_bank_rounding(res->tmp_str);
      error_code = s21_checking_number_for_size(res->tmp_str);
      denominator = 0;
    }

    if (error_code == OK) {
      s21_binary_string_to_decimal(res->tmp_str, result);
      result->bits[3] |= (denominator << 16);
    }
  } else {
    error_code = ERROR;
  }
  s21_destructor(res);
  s21_destructor(val1);
  s21_destructor(val2);
  return error_code;
}

void alignment_scale(s21_decimal *val1, s21_decimal *val2) {
  int get_scale_val1 = s21_decimal_get_scale(*val1);
  int get_scale_val2 = s21_decimal_get_scale(*val2);
  if (get_scale_val1 > get_scale_val2) {
    val2->bits[3] |= (get_scale_val1 << 16);
  } else if (get_scale_val2 > get_scale_val1) {
    val1->bits[3] |= (get_scale_val2 << 16);
  }
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error_code = OK;
  res_t *res = s21_constructor();
  res_t *val1 = s21_constructor();
  res_t *val2 = s21_constructor();
  res_t *splitting = s21_constructor();
  PANIC(res, val1, val2, result);
  int exponent_val1 = s21_get_exponent(value_1);
  int exponent_val2 = s21_get_exponent(value_2);
  int bits_val1 = s21_extract_bits_three(value_1);
  int bits_val2 = s21_extract_bits_three(value_2);
  if (res && val1 && val2 && result && exponent_val1 < 29 &&
      exponent_val2 < 29 && !bits_val1 && !bits_val2) {
    s21_decimal_init(result);
    alignment_scale(&value_1, &value_2);

    s21_binary_to_string(value_1, val1->tmp_str);
    s21_binary_to_string(value_2, val2->tmp_str);

    //        int denominator = s21_diff_in_zoom_levels(value_1, value_2);

    s21_calculating(val1->tmp_str, val2->tmp_str, res->tmp_str, MUL);
    strcpy(splitting->tmp_str, res->tmp_str);

    int scale_1 = s21_decimal_get_scale(value_1);

    int scale_tmp = scale_1;
    if (scale_tmp && s21_checking_number_for_size(splitting->tmp_str)) {
      strcpy(splitting->des_str, splitting->tmp_str);
      do {
        strcpy(splitting->tmp_str, splitting->des_str);
        s21_division_binary(splitting->des_str, "1010", splitting->des_str);
        scale_1--;
      } while (!strchr(splitting->des_str, '.'));
      scale_1++;
    }

    int denominator = 0;
    while (s21_checking_number_for_size(splitting->tmp_str) && scale_1 != 0) {
      s21_division_binary(splitting->tmp_str, "1010", splitting->tmp_str);
      strcpy(splitting->des_str, splitting->tmp_str);
      s21_splitting_number(splitting->tmp_str, splitting->dec_part,
                           splitting->comma_part);
      strcpy(splitting->tmp_str, splitting->dec_part);
      scale_1--;
      denominator++;
    }

    if (denominator > 0) {
      s21_bank_rounding(splitting->des_str);
      strcpy(splitting->tmp_str, splitting->des_str);
    }

    error_code = s21_checking_number_for_size(splitting->tmp_str);
    if (error_code != OK) {
      //            s21_opposite_of_denominator(scale_1, res->tmp_str);
      s21_bank_rounding(splitting->tmp_str);
      error_code = s21_checking_number_for_size(splitting->tmp_str);
      scale_1 = 0;
    }

    if (error_code == OK) {
      s21_binary_string_to_decimal(splitting->tmp_str, result);
      result->bits[3] |= (scale_1 << 16);
    }
  } else {
    error_code = ERROR;
  }
  s21_destructor(splitting);
  s21_destructor(res);
  s21_destructor(val1);
  s21_destructor(val2);
  return error_code;
}

void s21_decimal_to_binary(int digit, char *binary) {
  PANIC(binary);
  if (binary) {
    if (digit == 0) {
      strcpy(binary, "0");
    } else {
      int bits_count = 0;
      int temp = digit;
      while (temp > 0) {
        bits_count++;
        temp /= 2;
      }

      for (int i = bits_count - 1; i >= 0; i--) {
        binary[i] = (digit % 2 == 0) ? '0' : '1';
        digit /= 2;
      }

      binary[bits_count] = '\0';
    }
  }
}

void s21_from_decimal_to_binary(const char *flt_str, char *dst_str) {
  res_t *tmp = s21_constructor();
  res_t *res = s21_constructor();
  PANIC(flt_str, dst_str);
  if (tmp && res && flt_str && dst_str) {
    _Bool is_first = 1;
    size_t index_flt = 0;
    while (flt_str[index_flt] != '\0') {
      tmp->tmp_str[0] = flt_str[index_flt];
      int digit = tmp->tmp_str[0] - '0';
      s21_decimal_to_binary(digit, res->tmp_str);
      int diff = (int)((strlen(flt_str) - 1) - index_flt);
      strcpy(tmp->tmp_str, "1");
      s21_denominator_handle(tmp->tmp_str, diff);
      s21_multiply_binary(res->tmp_str, tmp->tmp_str, tmp->des_str);
      if (is_first) {
        strcpy(res->des_str, "0");
        is_first = 0;
      }
      s21_sum_binary_string(res->des_str, tmp->des_str, res->des_str);

      index_flt++;
      memset(tmp->tmp_str, 0, strlen(tmp->tmp_str));
    }
    strcpy(dst_str, res->des_str);
  }
  s21_destructor(tmp);
  s21_destructor(res);
}

void s21_convert_from_binary_to_float(const char *binary, char *dec) {
  res_t *tmp = s21_constructor();
  res_t *res = s21_constructor();
  PANIC(binary, dec);
  if (binary && dec && tmp && res) {
    s21_splitting_number(binary, tmp->dec_part, tmp->comma_part);
    int index_dec = 0;
    double sum_dec = 0.0;
    for (int i = (int)strlen(tmp->dec_part) - 1; i >= 0; --i) {
      double bit = tmp->dec_part[i] - '0';
      double digit = bit * (pow(2.0, index_dec++));
      sum_dec += digit;
    }
    sprintf(res->dec_part, "%f", sum_dec);
    int index_comma = -1;
    double sum_comma = 0;
    for (size_t i = 0; tmp->comma_part[i] != '\0'; ++i) {
      int bit = tmp->comma_part[i] - '0';
      double digit = bit * (pow(2, index_comma--));
      sum_comma += digit;
    }
    sprintf(tmp->comma_part, "%f", sum_comma);
    s21_reverse_string(tmp->comma_part);
    strncpy(res->comma_part, tmp->comma_part, strlen(tmp->comma_part) - 2);
    s21_reverse_string(res->comma_part);

    s21_reverse_string(res->dec_part);
    s21_del_zero_begin(res->dec_part);
    s21_reverse_string(res->dec_part);
    strcat(res->dec_part, res->comma_part);

    strcpy(dec, res->dec_part);
  }
  s21_destructor(tmp);
  s21_destructor(res);
}

void s21_convert_from_binary_to_decimal_remaining_part(res_t *res,
                                                       res_t *split) {
  PANIC(res, split);
  if (res && split) {
    if (split->dec_part[0] - '0' > 0) {
      s21_reverse_string(split->comma_part);
      strcat(split->comma_part, ".0");
      s21_reverse_string(split->comma_part);
    } else {
      strcpy(split->comma_part, res->tmp_str);
    }

    s21_convert_from_binary_to_float(split->comma_part, res->comma_part);
    s21_reverse_string(res->comma_part);
    s21_del_zero_begin(res->comma_part);
    strncpy(split->tmp_str, res->comma_part, strlen(res->comma_part) - 2);
    s21_reverse_string(split->tmp_str);
  }
}

void s21_set_scale_for_div(res_t *res, res_t *split, int *scale_tmp) {
  PANIC(res, split, scale_tmp);
  if (res && split && scale_tmp) {
    strcpy(res->dec_part, "1");
    *scale_tmp = (int)strlen(split->tmp_str);
    int diff = *scale_tmp;
    if (split->dec_part[0] - '0' > 0) {
      s21_denominator_handle(res->dec_part, diff);
    }
    s21_multiply_binary(split->dec_part, res->dec_part, split->des_str);
    s21_from_decimal_to_binary(split->tmp_str, split->comma_part);
    s21_sum_binary_string(split->des_str, split->comma_part, res->des_str);
  }
}

void s21_bank_rounding_for_div(const char *comma_part, char *dec_part) {
  PANIC(comma_part, dec_part);
  if (comma_part && dec_part) {
    int last_digit_dec_part = dec_part[strlen(dec_part) - 1] - '0';
    int first_digit_comma_part = comma_part[0] - '0';
    if (last_digit_dec_part) {
      if (first_digit_comma_part >= 5) {
        s21_sum_binary_string(dec_part, "1", dec_part);
      }
    } else {
      if (first_digit_comma_part > 5) {
        s21_sum_binary_string(dec_part, "1", dec_part);
      }
    }
  }
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error_code = OK;
  res_t *res = s21_constructor();
  res_t *val1 = s21_constructor();
  res_t *val2 = s21_constructor();
  res_t *split = s21_constructor();
  PANIC(res, val1, val2, split, result);
  _Bool divisor_is_zero = s21_decimal_is_zero(&value_2);
  s21_decimal_init(result);
  int exponent_val1 = s21_get_exponent(value_1);
  int exponent_val2 = s21_get_exponent(value_2);
  int bits_val1 = s21_extract_bits_three(value_1);
  int bits_val2 = s21_extract_bits_three(value_2);
  if (res && val1 && val2 && split && result && !divisor_is_zero &&
      exponent_val1 < 29 && exponent_val2 < 29 && !bits_val1 && !bits_val2) {
    _Bool is_negative = FALSE;
    s21_binary_to_string(value_1, val1->tmp_str);
    s21_binary_to_string(value_2, val2->tmp_str);
    s21_normalizing_value(val1->tmp_str, val2->tmp_str, &is_negative);

    //        if (s21_binary_cmp(val1->tmp_str, "0") > 0) {
    s21_common_denominator(value_1, value_2, val1->tmp_str, val2->tmp_str);
    s21_calculating(val1->tmp_str, val2->tmp_str, res->tmp_str, DIV);

    s21_splitting_number(res->tmp_str, split->dec_part, split->comma_part);
    s21_convert_from_binary_to_decimal_remaining_part(res, split);
    //        }

    int scale_tmp = 0;
    s21_set_scale_for_div(res, split, &scale_tmp);

    error_code = s21_checking_number_for_size(res->des_str);
    if (error_code != OK) {
      s21_bank_rounding_for_div(split->tmp_str, split->dec_part);

      error_code = s21_checking_number_for_size(split->dec_part);
      strcpy(res->des_str, split->dec_part);
      scale_tmp = 0;
    }

    if (error_code == OK) {
      s21_binary_string_to_decimal(res->des_str, result);
      result->bits[3] |= scale_tmp << 16;
      if (is_negative) {
        result->bits[3] |= 1 << 31;
      }
    } else {
      if (is_negative) {
        error_code = NUMBER_SMALL;
      }
    }
  } else if (divisor_is_zero) {
    error_code = DIVISION_BY_ZERO;
  } else {
    error_code = ERROR;
  }
  s21_destructor(res);
  s21_destructor(val1);
  s21_destructor(val2);
  s21_destructor(split);
  return error_code;
}

void s21_int_to_string(int src, char *result_32) {
  PANIC(result_32);
  if (result_32) {
    int index = 0;
    for (int j = 31; j >= 0; j--) {
      int bit = (src >> j) & 1;
      result_32[index] = bit ? '1' : '0';
      index++;
    }
    result_32[index] = '\0';
  }
}

void s21create_full_decimal_string_from_int(int src, char *result_32,
                                            s21_decimal *dst) {
  PANIC(result_32, dst);
  if (result_32) {
    _Bool is_neg = FALSE;
    if (src < 0) {
      src *= -1;
      is_neg = TRUE;
    }
    s21_int_to_string(src, result_32);
    s21_binary_string_to_decimal(result_32, dst);
    if (is_neg) {
      dst->bits[3] |= 1 << 31;
    }
  }
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int flag = 0;
  PANIC(dst);
  if (dst) {
    s21_decimal_init(dst);
    int get_exponent = s21_get_exponent(*dst);
    if (get_exponent < 0 || get_exponent > 28) {
      flag = 1;
    } else {
      char *result_32 = (char *)calloc(1024, sizeof(char));
      if (result_32 != NULL) {
        s21create_full_decimal_string_from_int(src, result_32, dst);
        free(result_32);
      }
    }
  } else {
    flag = 1;
  }

  return flag;
}

void s21_decimal_to_float(s21_decimal src, float *dst) {
  double mantissa = 0.0;
  char *str = (char *)calloc(1024, sizeof(char));
  if (str != NULL) {
    int index = 0;
    for (int i = 3; i >= 0; i--) {
      for (int j = 31; j >= 0; j--) {
        int bit = (src.bits[i] >> j) & 1;
        str[index] = bit ? '1' : '0';
        index++;
      }
    }
    index = 0;
    for (int i = 127; i >= 32; i--) {
      if (str[i] == '1') {
        mantissa += pow(2.0, index);
      }
      index++;
    }
    int exponent = s21_get_exponent(src);
    double powerten = pow(10, exponent);
    mantissa /= powerten;
    if (str[0] == '1') {
      mantissa = -mantissa;
    }
    *dst = (float)mantissa;
    free(str);
  }
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int flag = 0;
  PANIC(dst);
  if (dst) {
    if (s21_get_exponent(src) < 0 || s21_get_exponent(src) > 28) {
      flag = 1;
      *dst = 0;
    } else if (s21_extracting_0_15(src) != 0) {
      flag = 1;
    } else if (s21_extracting_24_30(src) != 0) {
      flag = 1;
    } else {
      s21_decimal_to_float(src, dst);
    }
  } else {
    flag = 1;
  }

  return flag;
}

void s21_decimal_to_int(s21_decimal src, int *dst, int *flag) {
  char *str = (char *)calloc(1024, sizeof(char));
  PANIC(dst, flag, str);
  if (dst && flag && str) {
    int exponent = s21_get_exponent(src);
    s21_decimal result = {{0, 0, 0, 0}};
    if (exponent != 0) {
      s21_truncate(src, &result);
      src = result;
    }
    double mantissa = 0.0;
    int index = 0;
    for (int i = 3; i >= 0; i--) {
      for (int j = 31; j >= 0; j--) {
        int bit = (src.bits[i] >> j) & 1;
        str[index] = bit ? '1' : '0';
        index++;
      }
    }
    index = 0;
    for (int i = 127; i >= 97; i--) {
      if (str[i] == '1') {
        mantissa += pow(2.0, index);
      }
      index++;
    }
    if (mantissa > -2147483648 && mantissa <= 2147483647) {
      int mantissa_int_part = (int)mantissa;
      *dst = mantissa_int_part;
      if (str[0] == '1') {
        *dst = -(*dst);
      }
    } else {
      *flag = 1;
    }
  }
  if (str != NULL) {
    free(str);
  }
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int flag = 0;
  PANIC(dst);
  if (dst) {
    if (s21_get_exponent(src) < 0 || s21_get_exponent(src) > 28) {
      flag = 1;
    } else if (s21_extracting_0_15(src) != 0) {
      flag = 1;
    } else if (s21_extracting_24_30(src) != 0) {
      flag = 1;
    } else {
      s21_decimal_to_int(src, dst, &flag);
    }
  } else {
    flag = 1;
  }

  return flag;
}

int s21_get_float_sign(float src) {
  int sign = 0;
  if (src != 0.0) {
    unsigned char *ptr = (unsigned char *)&src;
    sign = ((ptr[3] >> 7) & 1);
  }
  return sign;
}

int s21_get_number_flt(char *flt, char *number_flt) {
  int index = 0;
  while (flt[index] != 'E') {
    number_flt[index] = flt[index];
    index++;
  }
  number_flt[index] = '\0';
  return index;
}

int s21_get_copy_number_flt(char *number_flt, char *copy_number_flt) {
  int number_index = 0;
  int copy_index = 0;
  int breakpoint = 0;
  int number_exp_counter = 0;
  while (number_flt[number_index] != '\0') {
    if (number_flt[number_index] != '.') {
      copy_number_flt[copy_index] = number_flt[number_index];
      copy_index++;
      if (breakpoint) {
        number_exp_counter++;
      }
    } else {
      breakpoint = 1;
    }
    number_index++;
  }
  copy_number_flt[copy_index] = '\0';
  return number_exp_counter;
}

void s21_get_exp_flt(char *flt, char *exp_flt, int index) {
  index++;
  int exp_index = 0;
  while (flt[index] != '\0') {
    exp_flt[exp_index] = flt[index];
    index++;
    exp_index++;
  }

  exp_flt[exp_index] = '\0';
}

int s21_set_exponent(char *exp_flt, int number_exp_counter) {
  int exponent;
  exponent = strtof(exp_flt, NULL);
  exponent = -exponent;
  if (exponent != 0) {
    exponent += number_exp_counter;
  }
  return exponent;
}

void s21_exponent_over_zero(char *mantissa_string, char *exponent_string,
                            char *result_string, s21_decimal *dst,
                            long src_copy, int exponent, int sign) {
  s21_int_to_string(src_copy, mantissa_string);
  s21_int_to_string(exponent, exponent_string);

  int mantissa_index = 31;
  int exponent_index = 31;
  for (int i = 127; i >= 0; i--) {
    if (i <= 127 && i >= 96) {
      result_string[i] = mantissa_string[mantissa_index];
      mantissa_index--;
    } else if (i <= 15 && i >= 8) {
      result_string[i] = exponent_string[exponent_index];
      exponent_index--;
    } else if (i == 0) {
      result_string[i] = sign + 48;
    } else {
      result_string[i] = '0';
    }
  }
  result_string[128] = '\0';
  for (int i = 127; i >= 0; i--) {
    int bit_index = 31 - (i % 32);
    int int_index = 3 - (i / 32);
    if (result_string[i] == '1') {
      dst->bits[int_index] |= (1 << bit_index);
    }
  }
}

void s21_exponent_over_18(char *exponent_buffer_string,
                          char *mantissa_x_exponent_x_buffer_string,
                          char *mantissa_x_exponent_string,
                          char *mantissa_string, char *exponent_string,
                          int exponent, int index) {
  int exponent_buffer = exponent - 18;
  exponent -= exponent_buffer;
  long long power = pow(10, exponent);
  long long buffer_power = pow(10, exponent_buffer);
  index = 0;
  for (int j = 63; j >= 0; j--) {
    int bit = (power >> j) & 1;
    exponent_string[index] = bit ? '1' : '0';
    index++;
  }
  index = 0;
  for (int j = 63; j >= 0; j--) {
    int bit = (buffer_power >> j) & 1;
    exponent_buffer_string[index] = bit ? '1' : '0';
    index++;
  }
  s21_multiply_binary(mantissa_string, exponent_string,
                      mantissa_x_exponent_string);
  s21_multiply_binary(mantissa_x_exponent_string, exponent_buffer_string,
                      mantissa_x_exponent_x_buffer_string);
}

void s21_exponent_under_18(char *mantissa_x_exponent_x_buffer_string,
                           char *mantissa_x_exponent_string,
                           char *mantissa_string, char *exponent_string,
                           int exponent, int index) {
  long long power = pow(10, exponent);
  index = 0;
  for (int j = 63; j >= 0; j--) {
    int bit = (power >> j) & 1;
    exponent_string[index] = bit ? '1' : '0';
    index++;
  }
  s21_multiply_binary(mantissa_string, exponent_string,
                      mantissa_x_exponent_string);
  strcpy(mantissa_x_exponent_x_buffer_string, mantissa_x_exponent_string);
}

void s21_set_float_value_to_decimal(char *mantissa_x_exponent_x_buffer_string,
                                    char *result_string, int sign,
                                    s21_decimal *dst) {
  int mantissa_index = strlen(mantissa_x_exponent_x_buffer_string) - 1;
  for (int i = 127; i >= 0; i--) {
    if (mantissa_index != -1) {
      result_string[i] = mantissa_x_exponent_x_buffer_string[mantissa_index];
      mantissa_index--;
    } else if (i == 0) {
      result_string[i] = sign + 48;
    } else {
      result_string[i] = '0';
    }
  }
  for (int i = 127; i >= 0; i--) {
    int bit_index = 31 - (i % 32);
    int int_index = 3 - (i / 32);
    if (result_string[i] == '1') {
      dst->bits[int_index] |= (1 << bit_index);
    }
  }
}

void s21_functions_packed(s21_decimal *dst, float src, char *mantissa_string,
                          char *exponent_string, char *result_string, char *flt,
                          char *exp_flt, char *number_flt,
                          char *copy_number_flt, char *exponent_buffer_string,
                          char *mantissa_x_exponent_x_buffer_string,
                          char *mantissa_x_exponent_string) {
  s21_decimal_init(dst);
  int sign = s21_get_float_sign(src);
  sprintf(flt, "%.6E", fabsf(src));
  int index = s21_get_number_flt(flt, number_flt);
  int number_exp_counter = s21_get_copy_number_flt(number_flt, copy_number_flt);
  long src_copy = strtol(copy_number_flt, NULL, 10);
  s21_get_exp_flt(flt, exp_flt, index);
  int exponent = s21_set_exponent(exp_flt, number_exp_counter);
  if (exponent > 0) {
    s21_exponent_over_zero(mantissa_string, exponent_string, result_string, dst,
                           src_copy, exponent, sign);
  } else {
    exponent = abs(exponent);
    s21_int_to_string(src_copy, mantissa_string);
    if (exponent > 18) {
      s21_exponent_over_18(exponent_buffer_string,
                           mantissa_x_exponent_x_buffer_string,
                           mantissa_x_exponent_string, mantissa_string,
                           exponent_string, exponent, index);
    } else {
      s21_exponent_under_18(mantissa_x_exponent_x_buffer_string,
                            mantissa_x_exponent_string, mantissa_string,
                            exponent_string, exponent, index);
    }
    s21_set_float_value_to_decimal(mantissa_x_exponent_x_buffer_string,
                                   result_string, sign, dst);
  }
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int conditon = 0;
  char *flt = (char *)calloc(1024, sizeof(char));
  char *number_flt = (char *)calloc(1024, sizeof(char));
  char *copy_number_flt = (char *)calloc(1024, sizeof(char));
  char *exp_flt = (char *)calloc(1024, sizeof(char));
  char *exponent_string = (char *)calloc(1024, sizeof(char));
  char *exponent_buffer_string = (char *)calloc(1024, sizeof(char));
  char *mantissa_string = (char *)calloc(1024, sizeof(char));
  char *result_string = (char *)calloc(1024, sizeof(char));
  char *mantissa_x_exponent_string = (char *)calloc(1024, sizeof(char));
  char *mantissa_x_exponent_x_buffer_string =
      (char *)calloc(1024, sizeof(char));
  if (flt && number_flt && copy_number_flt && exp_flt && exponent_string &&
      exponent_buffer_string && mantissa_string && result_string &&
      mantissa_x_exponent_string && mantissa_x_exponent_x_buffer_string) {
    if ((fabs(src) < 79228162514264337593543950335.0F && fabs(src) > 1E-28F &&
         !isinf(src) && dst != NULL) ||
        fabs(src) == 0.0) {
      s21_functions_packed(
          dst, src, mantissa_string, exponent_string, result_string, flt,
          exp_flt, number_flt, copy_number_flt, exponent_buffer_string,
          mantissa_x_exponent_x_buffer_string, mantissa_x_exponent_string);
    } else {
      conditon = 1;
      s21_decimal_init(dst);
    }
  } else {
    conditon = 1;
  }
  free(flt);
  free(number_flt);
  free(copy_number_flt);
  free(exp_flt);
  free(exponent_string);
  free(exponent_buffer_string);
  free(mantissa_string);
  free(result_string);
  free(mantissa_x_exponent_string);
  free(mantissa_x_exponent_x_buffer_string);
  return conditon;
}

int s21_get_bit(s21_decimal num, int indexbit) {
  int sign = 0;
  int num_int = indexbit / 32;
  int num_bit = indexbit % 32;
  unsigned int n = (1u << num_bit);
  if ((num.bits[num_int] & n) == 0) {
    sign = 0;
  } else {
    sign = 1;
  }
  return sign;
}

int s21_get_sign(s21_decimal num) { return s21_get_bit(num, 127); }

int s21_is_less(s21_decimal num1, s21_decimal num2) {
  return s21_is_greater(num2, num1);
}

int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2) {
  return s21_is_less(num1, num2) || s21_is_equal(num1, num2);
}

void set_comma_part(char *dst) {
  PANIC(dst);
  if (dst != NULL) {
    s21_reverse_string(dst);
    strcat(dst, ".0");
    s21_reverse_string(dst);
  }
}

void remove_comma_part(char *src, char *dst) {
  PANIC(src, dst);
  if (src != NULL && dst != NULL) {
    s21_reverse_string(src);
    memset(dst, 0, strlen(dst));
    strncpy(dst, src, strlen(src) - 2);
    s21_reverse_string(dst);
  }
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int result = FALSE;
  res_t *val_1 = s21_constructor();
  res_t *val_2 = s21_constructor();
  int bits_val1 = s21_extract_bits_three(value_1);
  int bits_val2 = s21_extract_bits_three(value_2);
  if (!val_1 || !val_2) {
    result = 0;
  } else if (s21_get_exponent(value_1) > 28 || s21_get_exponent(value_2) > 28 ||
             bits_val1 || bits_val2) {
    result = FALSE;
  } else if (s21_get_sign(value_1) < s21_get_sign(value_2)) {
    result = TRUE;
  } else if (s21_get_sign(value_1) > s21_get_sign(value_2)) {
    result = FALSE;
  } else {
    s21_binary_to_string(value_1, val_1->tmp_str);
    s21_binary_to_string(value_2, val_2->tmp_str);
    int scale_1 = s21_decimal_get_scale(value_1);
    int scale_2 = s21_decimal_get_scale(value_2);
    strcpy(val_1->des_str, "1");
    strcpy(val_2->des_str, "1");
    s21_denominator_handle(val_1->des_str, scale_1);
    s21_denominator_handle(val_2->des_str, scale_2);
    s21_division_binary(val_1->tmp_str, val_1->des_str, val_1->tmp_str);
    s21_division_binary(val_2->tmp_str, val_2->des_str, val_2->tmp_str);
    s21_splitting_number(val_1->tmp_str, val_1->dec_part, val_1->comma_part);
    s21_splitting_number(val_2->tmp_str, val_2->dec_part, val_2->comma_part);
    int cmp_dec_part = s21_binary_cmp(val_1->dec_part, val_2->dec_part);
    if (cmp_dec_part == 0 &&
        (strlen(val_1->comma_part) > 0 || strlen(val_2->comma_part) > 0)) {
      set_comma_part(val_1->comma_part);
      s21_convert_from_binary_to_float(val_1->comma_part, val_1->des_str);
      remove_comma_part(val_1->des_str, val_1->comma_part);
      set_comma_part(val_2->comma_part);
      s21_convert_from_binary_to_float(val_2->comma_part, val_2->des_str);
      remove_comma_part(val_2->des_str, val_2->comma_part);
      s21_from_decimal_to_binary(val_1->comma_part, val_1->des_str);
      s21_from_decimal_to_binary(val_2->comma_part, val_2->des_str);
      int cmp_comma_part = s21_binary_cmp(val_1->des_str, val_2->des_str);
      if (cmp_comma_part > 0) {
        result = TRUE;
      } else {
        result = FALSE;
      }
    } else if (cmp_dec_part > 0) {
      result = TRUE;
    } else {
      result = FALSE;
    }
  }
  s21_destructor(val_1);
  s21_destructor(val_2);
  return result;
}

int s21_is_greater_or_equal(s21_decimal num1, s21_decimal num2) {
  return s21_is_greater(num1, num2) || s21_is_equal(num1, num2);
}

int s21_is_equal(s21_decimal num1, s21_decimal num2) {
  int flag = 1;
  int sign_num1 = s21_get_sign(num1);
  int sign_num2 = s21_get_sign(num2);
  int is_zero_num1 = s21_decimal_is_zero(&num1);
  int is_zero_num2 = s21_decimal_is_zero(&num2);
  if (is_zero_num1 == 1 && is_zero_num2 == 1) {
    flag = 1;
  } else if ((s21_extracting_0_15(num1) != 0 ||
              s21_extracting_0_15(num2) != 0) &&
             (s21_extracting_24_30(num1) != 0 ||
              s21_extracting_24_30(num2) != 0) &&
             (sign_num1 != sign_num2)) {
    flag = 0;
  } else {
    for (int i = 0; i < 4 && flag; i++) {
      if (num1.bits[i] != num2.bits[i]) {
        flag = 0;
      }
    }
  }
  return flag;
}

int s21_is_not_equal(s21_decimal num1, s21_decimal num2) {
  return !s21_is_equal(num1, num2);
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  int result_code = 0;
  s21_decimal value_floor = {0};
  s21_decimal balance = {0};
  s21_decimal equal = {0};
  s21_decimal floor = {0};
  floor.bits[0] = 1;
  PANIC(result);
  if (result) {
    s21_decimal_init(result);
    s21_truncate(value, &value_floor);
    int sign = s21_get_sign(value);
    if (sign == 0) {
      *result = value_floor;
    } else {
      s21_sub(value, value_floor, &balance);
      if (s21_is_equal(balance, equal) == 1) {
        *result = value_floor;
      } else
        s21_sub(value_floor, floor, result);
      result->bits[3] |= (sign << 31);
    }
  } else {
    result_code = 1;
  }
  return result_code;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  int result_code = 0;
  s21_decimal value_round = {0};
  s21_decimal equal1 = {{5, 0, 0, 65536}};
  s21_decimal balance = {0};
  s21_decimal round = {{1, 0, 0, 0}};
  PANIC(result);
  if (result) {
    s21_decimal_init(result);
    int sign = s21_get_sign(value);
    s21_set_bit(&value, 127, 0);
    s21_truncate(value, &value_round);
    s21_sub(value, value_round, &balance);
    if (s21_is_greater_or_equal(balance, equal1) == 0) {
      *result = value_round;
    } else
      s21_add(value_round, round, result);
    if (sign == 1) {
      s21_set_bit(result, 127, 1);
    }
  } else {
    result_code = 1;
  }
  return result_code;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  int result_code = 0;
  PANIC(result);
  if (result) {
    s21_decimal_init(result);
    *result = value;
    int sign = s21_get_sign(value);
    if (sign == 1) {
      s21_set_bit(result, 127, 0);
    } else
      s21_set_bit(result, 127, 1);
  } else {
    result_code = 1;
  }
  return result_code;
}

void s21_set_bit(s21_decimal *num, int index, int bit) {
  PANIC(num);
  if (num) {
    int num_int = index / 32;
    int num_bit = index % 32;
    if (bit == 1)
      num->bits[num_int] = num->bits[num_int] | (1 << num_bit);
    else if (bit == 0)
      num->bits[num_int] = num->bits[num_int] & ~(1 << num_bit);
  }
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int result_code = 0;
  int scale = s21_decimal_get_scale(value);
  int sign = s21_get_sign(value);
  res_t *val = s21_constructor();
  PANIC(result);
  if (val && result) {
    s21_decimal_init(result);
    s21_binary_to_string(value, val->tmp_str);
    s21_del_symbol(val->tmp_str, MINUS);
    char *delim = "1010\0";
    while (scale > 0) {
      s21_division_binary(val->tmp_str, delim, val->tmp_str);
      s21_splitting_number(val->tmp_str, val->dec_part, val->comma_part);
      strcpy(val->tmp_str, val->dec_part);
      scale--;
    }
    s21_binary_string_to_decimal(val->dec_part, result);
    result->bits[3] |= (sign << 31);
  } else {
    result_code = 1;
  }
  s21_destructor(val);
  return result_code;
}