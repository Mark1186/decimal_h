#ifndef DECIMAL_S21_DECIMAL_H
#define DECIMAL_S21_DECIMAL_H

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct {
  char *tmp_str;
  char *des_str;
  char *dec_part;
  char *comma_part;
} res_t;

typedef enum {
  OK,
  NUMBER_LARGE,
  NUMBER_SMALL,
  DIVISION_BY_ZERO,
  ERROR
} error_code_t;

typedef enum { ADD, SUB, MUL, DIV } math_operations_t;

typedef enum { MINUS, COMMA } deleting_symbol_t;

typedef enum { IS_LESS = -1, IS_EQUAL, IS_GREATER } comparing_numbers_t;

typedef enum { FALSE, TRUE } bool_t;

#define PANIC(...)                                                      \
  do {                                                                  \
    const void *pointers[] = {(const void *)__VA_ARGS__};               \
    const char *names[] = {#__VA_ARGS__};                               \
    const size_t count = sizeof(pointers) / sizeof(pointers[0]);        \
    for (size_t i = 0; i < count; ++i) {                                \
      if (pointers[i] == NULL) {                                        \
        fprintf(stderr, "Memory allocated for %s is fail\n", names[i]); \
      }                                                                 \
    }                                                                   \
  } while (0)

#define MAX_VALUE                                                              \
  "11111111111111111111111111111111111111111111111111111111111111111111111111" \
  "1111111111111111111111"

res_t *s21_constructor();
void s21_destructor(res_t *res);

void s21_reverse_string(char *str);
void s21_binary_to_string(s21_decimal value, char *str);
void s21_number_alignment(char *binary_1, char *binary_2);
void s21_del_symbol_handle(char *value, char symbol, size_t *index_des);
void s21_del_symbol(char *value, deleting_symbol_t symbol);
void s21_del_zero_begin(char *value);
void s21_set_negative_number(char *des);
int s21_binary_cmp(char *binary_1, char *binary_2);
int s21_checking_number_for_size(const char *src);
void s21_splitting_number(const char *src, char *dec_part, char *comma_part);
int s21_decimal_get_scale(s21_decimal value);
void s21_binary_comma_part_to_dec_comma_part(const char *binary, char *dec);
void s21_bank_rounding(char *value);
int s21_diff_in_zoom_levels(s21_decimal val_1, s21_decimal val_2);
_Bool s21_decimal_is_zero(s21_decimal *value);
void s21_denominator_handle(char *value, unsigned int diff);
int s21_common_denominator(s21_decimal val_1, s21_decimal val_2, char *binary_1,
                           char *binary_2);
void s21_opposite_of_denominator(int denominator, char *des_str);

void s21_decimal_init(s21_decimal *dec);
void s21_binary_string_to_decimal_handle(const char *des, s21_decimal *result,
                                         int *index_result, int *index_bit,
                                         int *count, size_t index);
void s21_binary_string_to_decimal_processing(const char *des,
                                             s21_decimal *result,
                                             _Bool num_is_large);
void s21_binary_string_to_decimal(char *binary, s21_decimal *result);

void s21_sum_binary_string(const char *binary_1, const char *binary_2,
                           char *des_str);
void s21_subtract_handle(const char *binary_1, const char *binary_2, char *res,
                         size_t *index_result, _Bool is_negative);
void s21_subtract_binary_string(char *binary_1, char *binary_2, char *des_str);

void s21_memory_allocation_for_mul_results(char **arr, size_t size);
void s21_multiply_handle(char *val_1, char *val_2, char **arr);
void s21_summation_mul_results(char *res, char **arr, size_t size);
void s21_multiply_binary(char *val_1, char *val_2, char *res);

void s21_checking_for_division_completion(char *val_1, char *des, char *res,
                                          _Bool *is_div, size_t index);
void s21_writing_division_result(res_t *des, res_t *res, _Bool is_comma_part);
void s21_comparing_with_divisor(char *val_1, char *val_2, res_t *des,
                                _Bool *is_comma_part, int *precision,
                                size_t index);
void s21_division_handle(char *val_1, char *val_2, res_t *des, res_t *res,
                         _Bool is_div, size_t index, _Bool *is_comma_part,
                         int *precision);
void s21_division_processing(char *val_1, char *val_2, res_t *des, res_t *res);
void s21_begin_setting_for_div(char *val_1, char *val_2, char *des);
void s21_normalizing_value(char *val_1, char *val_2, _Bool *is_negative);
void s21_division_binary(char *val1, char *val2, char *result);

void s21_handle_addition_binary_with_signs(char *val_1, char *val_2, char *res,
                                           const char *negative_1,
                                           const char *negative_2);
void s21_handle_subtraction_binary_with_signs(char *val_1, char *val_2,
                                              char *res, const char *negative_1,
                                              const char *negative_2);
void s21_calculating(char *val_1, char *val_2, char *res,
                     math_operations_t operation);

void s21_convert_from_binary_to_decimal_remaining_part(res_t *res,
                                                       res_t *split);
void s21_set_scale_for_div(res_t *res, res_t *split, int *scale_tmp);
void s21_bank_rounding_for_div(const char *comma_part, char *dec_part);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

void s21_int_to_string(int src, char *result_32);
void s21create_full_decimal_string_from_int(int src, char *result_32,
                                            s21_decimal *dst);
int s21_get_exponent(s21_decimal src);
void s21_decimal_to_float(s21_decimal src, float *dst);
void s21_convert_from_binary_to_float(const char *binary, char *dec);

void s21_decimal_to_int(s21_decimal src, int *dst, int *flag);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
void s21_from_decimal_to_binary(const char *flt_str, char *dst_str);
int s21_get_bit(s21_decimal num, int indexbit);
int s21_get_sign(s21_decimal num);
int s21_is_less(s21_decimal num1, s21_decimal num2);
int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2);
int s21_is_greater(s21_decimal num1, s21_decimal num2);
int s21_is_greater_or_equal(s21_decimal num1, s21_decimal num2);
int s21_is_equal(s21_decimal num1, s21_decimal num2);
int s21_is_not_equal(s21_decimal num1, s21_decimal num2);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
void s21_set_bit(s21_decimal *num, int index, int bit);
int s21_truncate(s21_decimal value, s21_decimal *result);

#endif  // DECIMAL_S21_DECIMAL_H
