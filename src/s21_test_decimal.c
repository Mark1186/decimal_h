#include <check.h>

#include "s21_decimal.h"

START_TEST(s21_test_reverse_string) {
  char string_for_reverse[] = "Hello World!\0";
  const char *expected = "!dlroW olleH\0";

  s21_reverse_string(string_for_reverse);
  ck_assert_str_eq(string_for_reverse, expected);
}
END_TEST

START_TEST(s21_test_binary_to_string) {
  s21_decimal decimal;
  decimal.bits[0] = 0b00000000000000000000000000000001;
  decimal.bits[1] = 0b00000000000000000000000000000001;
  decimal.bits[2] = 0b00000000000000000000000000000001;
  decimal.bits[3] = 0b00000000000000000000000000000000;
  char binary_string[96];
  const char *expected =
      "000000000000000000000000000000010000000000000000000000000000000100000000"
      "000000000000000000000001\0";

  s21_binary_to_string(decimal, binary_string);
  ck_assert_str_eq(binary_string, expected);
}
END_TEST

START_TEST(s21_test_number_alignment) {
  char value_1[4] = "101\0";
  char value_2[4] = "11\0";
  const char *expected = "011\0";

  s21_number_alignment(value_1, value_2);
  ck_assert_uint_eq(strlen(value_1), strlen(value_2));
  ck_assert_str_eq(value_2, expected);
}
END_TEST

START_TEST(s21_test_del_symbol_minus) {
  char value[20] = "-111110101010\0";
  const char *expected = "111110101010\0";

  s21_del_symbol(value, MINUS);
  ck_assert_str_eq(value, expected);
}
END_TEST

START_TEST(s21_test_del_symbol_comma) {
  char value[20] = "1.11110101010\0";
  const char *expected = "111110101010\0";

  s21_del_symbol(value, COMMA);
  ck_assert_str_eq(value, expected);
}
END_TEST

START_TEST(s21_test_del_zero_begin) {
  char value[20] = "000101\0";
  const char *expected = "101\0";

  s21_del_zero_begin(value);
  ck_assert_str_eq(value, expected);
}
END_TEST

START_TEST(s21_test_set_negative_number) {
  char value[20] = "101\0";
  const char *expected = "-101\0";

  s21_set_negative_number(value);
  ck_assert_str_eq(value, expected);
}
END_TEST

START_TEST(s21_test_binary_cmp_is_compare) {
  char value_1[20] = "100101011101011\0";
  char value_2[20] = "100101011101011\0";

  int result_cmp = s21_binary_cmp(value_1, value_2);
  int expected = 0;
  ck_assert_int_eq(result_cmp, expected);
}
END_TEST

START_TEST(s21_test_binary_cmp_is_less) {
  char value_1[20] = "111101011101011\0";
  char value_2[20] = "100101011101011\0";

  int result_cmp = s21_binary_cmp(value_1, value_2);
  int expected = 1;
  ck_assert_int_eq(result_cmp, expected);
}
END_TEST

START_TEST(s21_test_binary_cmp_is_greater) {
  char value_1[20] = "100101011101011\0";
  char value_2[20] = "111101011101011\0";

  int result_cmp = s21_binary_cmp(value_1, value_2);
  int expected = -1;
  ck_assert_int_eq(result_cmp, expected);
}
END_TEST

START_TEST(s21_test_checking_number_for_size_number_ok) {
  char value_1[20] = "1001010111101011\0";
  char value_2[97] =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111\0";

  int result_1 = s21_checking_number_for_size(value_1);
  int result_2 = s21_checking_number_for_size(value_2);
  ck_assert_int_eq(result_1, OK);
  ck_assert_int_eq(result_2, OK);
}
END_TEST

START_TEST(s21_test_checking_number_for_size_number_large) {
  char value[98] =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "1111111111111111111111110\0";

  int result = s21_checking_number_for_size(value);
  ck_assert_int_eq(result, NUMBER_LARGE);
}
END_TEST

START_TEST(s21_test_checking_number_for_size_number_small) {
  char value[99] =
      "-11111111111111111111111111111111111111111111111111111111111111111111111"
      "11111111111111111111111110\0";

  int result = s21_checking_number_for_size(value);
  ck_assert_int_eq(result, NUMBER_SMALL);
}
END_TEST

START_TEST(s21_test_splitting_number) {
  char value[20] = "111100110011.1100\0";
  char value_dec_part[20];
  char value_comma_part[20];
  const char *expected_dec_part = "111100110011\0";
  const char *expected_comma_part = "1100\0";

  s21_splitting_number(value, value_dec_part, value_comma_part);
  ck_assert_str_eq(value_dec_part, expected_dec_part);
  ck_assert_str_eq(value_comma_part, expected_comma_part);
}

START_TEST(s21_test_get_zoomlvl) {
  s21_decimal dec;
  dec.bits[0] = 0b00000000000000000000000000000000;
  dec.bits[1] = 0b00000000000000000000000000000000;
  dec.bits[2] = 0b00000000000000000000000000000000;
  dec.bits[3] = 0b00000000000001110000000000000000;

  int zoom_lvl = s21_decimal_get_scale(dec);
  ck_assert_int_eq(zoom_lvl, 7);
}
END_TEST

START_TEST(s21_test_bank_rounding_used_default_method) {
  char value_1[21] = "111110000100.1100110\0";
  const char *expected_1 = "111110000101\0";

  char value_2[20] = "111110000100.0011\0";
  const char *expected_2 = "111110000100\0";

  s21_bank_rounding(value_1);
  s21_bank_rounding(value_2);
  ck_assert_str_eq(value_1, expected_1);
  ck_assert_str_eq(value_2, expected_2);
}
END_TEST

START_TEST(s21_test_bank_rounding_used_bank_method) {
  char value_1[50] = "111110000100.1000011110101110000101000111101\0";
  const char *expected_1 = "111110000100\0";

  char value_2[50] = "111110000101.1000011110101110000101000111101\0";
  const char *expected_2 = "111110000110\0";

  s21_bank_rounding(value_1);
  s21_bank_rounding(value_2);
  ck_assert_str_eq(value_1, expected_1);
  ck_assert_str_eq(value_2, expected_2);
}

START_TEST(s21_test_diff_in_zoom_levels_equals) {
  s21_decimal val_1;
  val_1.bits[0] = 0b00000000000000000000000000000000;
  val_1.bits[1] = 0b00000000000000000000000000000000;
  val_1.bits[2] = 0b00000000000000000000000000000000;
  val_1.bits[3] = 0b00000000000001110000000000000000;
  s21_decimal val_2;
  val_2.bits[0] = 0b00000000000000000000000000000000;
  val_2.bits[1] = 0b00000000000000000000000000000000;
  val_2.bits[2] = 0b00000000000000000000000000000000;
  val_2.bits[3] = 0b00000000000001110000000000000000;

  int result = s21_diff_in_zoom_levels(val_1, val_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_test_diff_in_zoom_levels_not_equals) {
  s21_decimal val_1;
  val_1.bits[0] = 0b00000000000000000000000000000000;
  val_1.bits[1] = 0b00000000000000000000000000000000;
  val_1.bits[2] = 0b00000000000000000000000000000000;
  val_1.bits[3] = 0b00000000000001110000000000000000;
  s21_decimal val_2;
  val_2.bits[0] = 0b00000000000000000000000000000000;
  val_2.bits[1] = 0b00000000000000000000000000000000;
  val_2.bits[2] = 0b00000000000000000000000000000000;
  val_2.bits[3] = 0b00000000000011110000000000000000;

  int result = s21_diff_in_zoom_levels(val_1, val_2);
  int expected =
      abs(s21_decimal_get_scale(val_1) - s21_decimal_get_scale(val_2));
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(s21_test_decimal_is_zero_true) {
  s21_decimal value;
  value.bits[0] = 0b00000000000000000000000000000000;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000000000000000000000;

  _Bool result = s21_decimal_is_zero(&value);
  _Bool expected = TRUE;

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(s21_test_decimal_is_zero_false) {
  s21_decimal value;
  value.bits[0] = 0b00000000000000000000000000000001;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000000000000000000000;

  _Bool result = s21_decimal_is_zero(&value);
  _Bool expected = FALSE;

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(s21_test_common_denominator) {
  s21_decimal value_1;
  value_1.bits[0] = 0b00000000000000000000000000000001;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000000001;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  char binary_1[150];
  char binary_2[150];

  s21_binary_to_string(value_1, binary_1);
  s21_binary_to_string(value_2, binary_2);
  s21_common_denominator(value_1, value_2, binary_1, binary_2);
  const char *expected_binary_2 = "1010";
  ck_assert_str_eq(binary_2, expected_binary_2);
}
END_TEST

START_TEST(s21_test_opposite_of_denominator) {
  char value[20] = "1111011\0";
  char result[20];
  char *expected = "1111011.000000000000\0";

  s21_multiply_binary(value, "1010\0", result);
  s21_opposite_of_denominator(1, result);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(s21_test_binary_string_to_decimal) {
  char binary[20] = "-1111011\0";
  char binary_result[150];
  s21_decimal result;

  s21_binary_string_to_decimal(binary, &result);
  s21_binary_to_string(result, binary_result);
  const char *expected =
      "-00000000000000000000000000000000000000000000000000000000000000000000000"
      "0000000000000000001111011\0";
  ck_assert_str_eq(binary_result, expected);
}
END_TEST

START_TEST(s21_test_sum_binary_string) {
  char binary_1[20] = "11001110100\0";
  char binary_2[20] = "00101101100\0";
  char result[20];
  const char *expected = "11111100000\0";

  s21_sum_binary_string(binary_1, binary_2, result);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(s21_test_subtract_binary_string) {
  char binary_1[20] = "11001110100\0";
  char binary_2[20] = "00101101100\0";
  char result[20];
  const char *expected = "10100001000\0";

  s21_subtract_binary_string(binary_1, binary_2, result);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(s21_test_multiply_binary) {
  char binary_1[20] = "11001110100\0";
  char binary_2[20] = "00101101100\0";
  char result[21];
  const char *expected = "10010010110011110000\0";

  s21_multiply_binary(binary_1, binary_2, result);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(s21_test_division_binary) {
  char binary_1[20] = "11001110100\0";
  char binary_2[20] = "00101101100\0";
  char result[21];
  const char *expected = "100.100010011101\0";

  s21_division_binary(binary_1, binary_2, result);
  ck_assert_str_eq(result, expected);
}

START_TEST(s21_test_calculating_add) {
  char binary_1[20] = "11001110100\0";
  char binary_2[20] = "00101101100\0";
  char result[20];
  const char *expected = "11111100000\0";

  s21_calculating(binary_1, binary_2, result, ADD);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(s21_test_calculating_sub) {
  char binary_1[20] = "11001110100\0";
  char binary_2[20] = "00101101100\0";
  char result[20];
  const char *expected = "10100001000\0";

  s21_calculating(binary_1, binary_2, result, SUB);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(s21_test_calculating_mul) {
  char binary_1[20] = "11001110100\0";
  char binary_2[20] = "00101101100\0";
  char result[21];
  const char *expected = "10010010110011110000\0";

  s21_calculating(binary_1, binary_2, result, MUL);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(s21_test_calculating_div) {
  char binary_1[20] = "11001110100\0";
  char binary_2[20] = "00101101100\0";
  char result[21];
  const char *expected = "100.100010011101\0";

  s21_calculating(binary_1, binary_2, result, DIV);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(s21_test_s21_add_is_normal_positive_both_value_without_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b00000000000000000000000000000101;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000001111;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result;
  char result_binary[96];
  int expected_code = 0;
  const char *expected_binary =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000010100\0";

  int result_code = s21_add(value_1, value_2, &result);
  s21_binary_to_string(result, result_binary);

  ck_assert_int_eq(result_code, expected_code);
  ck_assert_str_eq(result_binary, expected_binary);
}
END_TEST

START_TEST(s21_test_s21_add_is_normal_negative_left_value_without_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b00000000000000000000000000000101;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b10000000000000000000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000001111;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result;
  char result_binary[96];
  int expected_code = 0;
  const char *expected_binary =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000001010\0";

  int result_code = s21_add(value_1, value_2, &result);
  s21_binary_to_string(result, result_binary);

  ck_assert_int_eq(result_code, expected_code);
  ck_assert_str_eq(result_binary, expected_binary);
}
END_TEST

START_TEST(s21_test_s21_add_is_normal_negative_right_value_without_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b00000000000000000000000000000101;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000001111;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result;
  char result_binary[96];
  int expected_code = 0;
  const char *expected_binary =
      "-00000000000000000000000000000000000000000000000000000000000000000000000"
      "0000000000000000000001010\0";

  int result_code = s21_add(value_1, value_2, &result);
  s21_binary_to_string(result, result_binary);

  ck_assert_int_eq(result_code, expected_code);
  ck_assert_str_eq(result_binary, expected_binary);
}
END_TEST

START_TEST(s21_test_s21_add_is_normal_negative_both_value_without_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b00000000000000000000000000000101;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b10000000000000000000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000001111;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result;
  char result_binary[96];
  int expected_code = 0;
  const char *expected_binary =
      "-00000000000000000000000000000000000000000000000000000000000000000000000"
      "0000000000000000000010100\0";

  int result_code = s21_add(value_1, value_2, &result);
  s21_binary_to_string(result, result_binary);

  ck_assert_int_eq(result_code, expected_code);
  ck_assert_str_eq(result_binary, expected_binary);
}
END_TEST

START_TEST(s21_test_s21_add_is_normal_positive_both_value_with_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b00000000000000000000000000000101;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000010000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000001111;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result;
  char result_binary[96];
  int expected_code = 0;
  int expected_scale = 1;
  const char *expected_binary =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000010011011\0";

  int result_code = s21_add(value_1, value_2, &result);
  int result_zoom_level = s21_decimal_get_scale(result);
  s21_binary_to_string(result, result_binary);

  ck_assert_int_eq(result_code, expected_code);
  ck_assert_int_eq(result_zoom_level, expected_scale);
  ck_assert_str_eq(result_binary, expected_binary);
}
END_TEST

START_TEST(s21_test_s21_add_is_normal_negative_both_value_with_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b00000000000000000000000000000101;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b10000000000000010000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000001111;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result;
  char result_binary[96];
  int expected_code = 0;
  int expected_scale = 1;
  const char *expected_binary =
      "-00000000000000000000000000000000000000000000000000000000000000000000000"
      "0000000000000000010011011\0";

  int result_code = s21_add(value_1, value_2, &result);
  int result_scale = s21_decimal_get_scale(result);
  s21_binary_to_string(result, result_binary);

  ck_assert_int_eq(result_code, expected_code);
  ck_assert_int_eq(result_scale, expected_scale);
  ck_assert_str_eq(result_binary, expected_binary);
}
END_TEST

START_TEST(s21_test_s21_sub_is_normal_positive_both_value_without_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b00000000000000000000000000000101;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000001111;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result;
  char result_binary[96];
  int expected_code = 0;
  const char *expected_binary =
      "-00000000000000000000000000000000000000000000000000000000000000000000000"
      "0000000000000000000001010\0";

  int result_code = s21_sub(value_1, value_2, &result);
  s21_binary_to_string(result, result_binary);

  ck_assert_int_eq(result_code, expected_code);
  ck_assert_str_eq(result_binary, expected_binary);
}
END_TEST

START_TEST(s21_test_s21_sub_is_normal_negative_left_value_without_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b00000000000000000000000000000101;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b10000000000000000000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000001111;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result;
  char result_binary[96];
  int expected_code = 0;
  const char *expected_binary =
      "-00000000000000000000000000000000000000000000000000000000000000000000000"
      "0000000000000000000010100\0";

  int result_code = s21_sub(value_1, value_2, &result);
  s21_binary_to_string(result, result_binary);

  ck_assert_int_eq(result_code, expected_code);
  ck_assert_str_eq(result_binary, expected_binary);
}
END_TEST

START_TEST(s21_test_s21_sub_is_normal_negative_right_value_without_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b00000000000000000000000000000101;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000001111;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result;
  char result_binary[96];
  int expected_code = 0;
  const char *expected_binary =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000010100\0";

  int result_code = s21_sub(value_1, value_2, &result);
  s21_binary_to_string(result, result_binary);

  ck_assert_int_eq(result_code, expected_code);
  ck_assert_str_eq(result_binary, expected_binary);
}
END_TEST

START_TEST(s21_test_s21_sub_is_normal_negative_both_value_without_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b00000000000000000000000000000101;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b10000000000000000000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000001111;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result;
  char result_binary[96];
  int expected_code = 0;
  const char *expected_binary =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000001010\0";

  int result_code = s21_sub(value_1, value_2, &result);
  s21_binary_to_string(result, result_binary);

  ck_assert_int_eq(result_code, expected_code);
  ck_assert_str_eq(result_binary, expected_binary);
}
END_TEST

START_TEST(s21_test_s21_sub_is_normal_positive_both_value_with_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b00000000000000000000000000000101;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000010000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000001111;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result;
  char result_binary[96];
  int expected_code = 0;
  int expected_scale = 1;
  const char *expected_binary =
      "-00000000000000000000000000000000000000000000000000000000000000000000000"
      "0000000000000000010010001\0";

  int result_code = s21_sub(value_1, value_2, &result);
  int result_scale = s21_decimal_get_scale(result);
  s21_binary_to_string(result, result_binary);

  ck_assert_int_eq(result_code, expected_code);
  ck_assert_int_eq(result_scale, expected_scale);
  ck_assert_str_eq(result_binary, expected_binary);
}
END_TEST

START_TEST(s21_test_s21_sub_is_normal_negative_both_value_with_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b00000000000000000000000000000101;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b10000000000000010000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000001111;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result;
  char result_binary[96];
  int expected_code = 0;
  int expected_scale = 1;
  const char *expected_binary =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000010010001\0";

  int result_code = s21_sub(value_1, value_2, &result);
  int result_scale = s21_decimal_get_scale(result);
  s21_binary_to_string(result, result_binary);

  ck_assert_int_eq(result_code, expected_code);
  ck_assert_int_eq(result_scale, expected_scale);
  ck_assert_str_eq(result_binary, expected_binary);
}
END_TEST

START_TEST(s21_test_s21_mul_is_normal_positive_both_value_without_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b00000000000000000000000000000101;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000001111;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result;
  char result_binary[96];
  int expected_code = 0;
  const char *expected_binary =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000001001011\0";

  int result_code = s21_mul(value_1, value_2, &result);
  s21_binary_to_string(result, result_binary);

  ck_assert_int_eq(result_code, expected_code);
  ck_assert_str_eq(result_binary, expected_binary);
}
END_TEST

START_TEST(s21_test_s21_mul_is_normal_negative_left_value_without_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b00000000000000000000000000000101;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b10000000000000000000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000001111;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result;
  char result_binary[96];
  int expected_code = 0;
  const char *expected_binary =
      "-00000000000000000000000000000000000000000000000000000000000000000000000"
      "0000000000000000001001011\0";

  int result_code = s21_mul(value_1, value_2, &result);
  s21_binary_to_string(result, result_binary);

  ck_assert_int_eq(result_code, expected_code);
  ck_assert_str_eq(result_binary, expected_binary);
}
END_TEST

START_TEST(s21_test_s21_mul_is_normal_negative_both_value_without_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b00000000000000000000000000000101;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b10000000000000000000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000001111;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result;
  char result_binary[96];
  int expected_code = 0;
  const char *expected_binary =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000001001011\0";

  int result_code = s21_mul(value_1, value_2, &result);
  s21_binary_to_string(result, result_binary);

  ck_assert_int_eq(result_code, expected_code);
  ck_assert_str_eq(result_binary, expected_binary);
}
END_TEST

START_TEST(s21_test_s21_mul_is_normal_positive_both_value_with_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b00000000000000000000000000000101;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000010000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000001111;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result;
  char result_binary[96];
  int expected_code = 0;
  int expected_scale = 1;
  const char *expected_binary =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000001001011\0";

  int result_code = s21_mul(value_1, value_2, &result);
  int result_scale = s21_decimal_get_scale(result);
  s21_binary_to_string(result, result_binary);

  ck_assert_int_eq(result_code, expected_code);
  ck_assert_int_eq(result_scale, expected_scale);
  ck_assert_str_eq(result_binary, expected_binary);
}
END_TEST

START_TEST(s21_test_s21_mul_is_normal_negative_both_value_with_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b00000000000000000000000000000101;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b10000000000000010000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000001111;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result;
  char result_binary[96];
  int expected_code = 0;
  int expected_scale = 1;
  const char *expected_binary =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000001001011\0";

  int result_code = s21_mul(value_1, value_2, &result);
  int result_scale = s21_decimal_get_scale(result);
  s21_binary_to_string(result, result_binary);

  ck_assert_int_eq(result_code, expected_code);
  ck_assert_int_eq(result_scale, expected_scale);
  ck_assert_str_eq(result_binary, expected_binary);
}
END_TEST

START_TEST(s21_test_s21_div_is_normal_positive_both_value_without_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b00000000000000000000000011111111;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000001111;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result;
  char result_binary[96];
  int expected_code = 0;
  int expected_scale = 0;
  const char *expected_binary =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000010001\0";

  int result_code = s21_div(value_1, value_2, &result);
  int result_scale = s21_decimal_get_scale(result);
  s21_binary_to_string(result, result_binary);

  ck_assert_int_eq(result_code, expected_code);
  ck_assert_int_eq(result_scale, expected_scale);
  ck_assert_str_eq(result_binary, expected_binary);
}
END_TEST

START_TEST(s21_test_s21_div_is_normal_positive_both_value_with_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b00000000000000000000000011111111;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000100000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000001111;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result;
  char result_binary[96];
  int expected_code = 0;
  int expected_zoom_level = 6;
  const char *expected_binary =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000101001011111000010\0";

  int result_code = s21_div(value_1, value_2, &result);
  int result_zoom_level = s21_decimal_get_scale(result);
  s21_binary_to_string(result, result_binary);

  ck_assert_int_eq(result_code, expected_code);
  ck_assert_int_eq(result_zoom_level, expected_zoom_level);
  ck_assert_str_eq(result_binary, expected_binary);
}
END_TEST

START_TEST(s21_test_s21_div_is_normal_negative_both_value_with_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b00000000000000000000000011111111;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b10000000000000100000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000001111;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b10000000000000010000000000000000;
  s21_decimal result;
  char result_binary[96];
  int expected_code = 0;
  int expected_zoom_level = 6;
  const char *expected_binary =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000110011111000001101111\0";

  int result_code = s21_div(value_1, value_2, &result);
  int result_zoom_level = s21_decimal_get_scale(result);
  s21_binary_to_string(result, result_binary);

  ck_assert_int_eq(result_code, expected_code);
  ck_assert_int_eq(result_zoom_level, expected_zoom_level);
  ck_assert_str_eq(result_binary, expected_binary);
}
END_TEST

START_TEST(s21_test_s21_add_is_unnormal_positive_both_value_without_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b11111111111111111111111111111111;
  value_1.bits[1] = 0b11111111111111111111111111111111;
  value_1.bits[2] = 0b11111111111111111111111111111111;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000000001;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result;
  int expected_code = 1;

  int result_code = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(result_code, expected_code);
}
END_TEST

START_TEST(s21_test_s21_add_is_unnormal_negative_both_value_without_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b11111111111111111111111111111111;
  value_1.bits[1] = 0b11111111111111111111111111111111;
  value_1.bits[2] = 0b11111111111111111111111111111111;
  value_1.bits[3] = 0b10000000000000000000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000000001;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result;
  int expected_code = 2;

  int result_code = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(result_code, expected_code);
}
END_TEST

START_TEST(s21_test_s21_sub_is_unnormal_positive_both_value_without_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b11111111111111111111111111111111;
  value_1.bits[1] = 0b11111111111111111111111111111111;
  value_1.bits[2] = 0b11111111111111111111111111111111;
  value_1.bits[3] = 0b10000000000000000000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000000001;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result;
  int expected_code = 2;

  int result_code = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(result_code, expected_code);
}
END_TEST

START_TEST(s21_test_s21_sub_is_unnormal_negative_both_value_without_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b11111111111111111111111111111111;
  value_1.bits[1] = 0b11111111111111111111111111111111;
  value_1.bits[2] = 0b11111111111111111111111111111111;
  value_1.bits[3] = 0b10000000000000000000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000000001;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result;
  int expected_code = 0;

  int result_code = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(result_code, expected_code);
}
END_TEST

START_TEST(s21_test_s21_mul_is_unnormal_positive_both_value_without_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b11111111111111111111111111111111;
  value_1.bits[1] = 0b11111111111111111111111111111111;
  value_1.bits[2] = 0b11111111111111111111111111111111;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000000010;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result;
  int expected_code = 1;

  int result_code = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(result_code, expected_code);
}
END_TEST

START_TEST(s21_test_s21_mul_is_unnormal_negative_both_value_without_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b11111111111111111111111111111111;
  value_1.bits[1] = 0b11111111111111111111111111111111;
  value_1.bits[2] = 0b11111111111111111111111111111111;
  value_1.bits[3] = 0b10000000000000000000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000000010;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result;
  int expected_code = 2;

  int result_code = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(result_code, expected_code);
}
END_TEST

START_TEST(s21_test_s21_div_is_unnormal_positive_both_value_without_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b11111111111111111111111111111111;
  value_1.bits[1] = 0b11111111111111111111111111111111;
  value_1.bits[2] = 0b11111111111111111111111111111111;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000000010;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result;
  int expected_code = 0;

  int result_code = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(result_code, expected_code);
}
END_TEST

START_TEST(s21_test_s21_div_is_unnormal_negative_both_value_without_comma) {
  s21_decimal value_1;
  value_1.bits[0] = 0b11111111111111111111111111111111;
  value_1.bits[1] = 0b11111111111111111111111111111111;
  value_1.bits[2] = 0b11111111111111111111111111111111;
  value_1.bits[3] = 0b10000000000000000000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000000010;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result;
  int expected_code = 0;

  int result_code = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(result_code, expected_code);
}
END_TEST

START_TEST(s21_test_s21_div_by_zero) {
  s21_decimal value_1;
  value_1.bits[0] = 0b11111111111111111111111111111111;
  value_1.bits[1] = 0b11111111111111111111111111111111;
  value_1.bits[2] = 0b11111111111111111111111111111111;
  value_1.bits[3] = 0b10000000000000000000000000000000;

  s21_decimal value_2;
  value_2.bits[0] = 0b00000000000000000000000000000000;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result;
  int expected_code = 3;

  int result_code = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(result_code, expected_code);
}
END_TEST

START_TEST(s21_test_int_to_string) {
  int number = 155;
  char src[33];
  char *expected = "00000000000000000000000010011011\0";
  s21_int_to_string(number, src);
  ck_assert_str_eq(src, expected);
}

START_TEST(s21_create_full_decimal_string_from_int) {
  s21_decimal dec;
  s21_decimal exp_dec;
  exp_dec.bits[0] = 0b00000000000000000000000010011011;
  int number = 155;
  char src[33];
  s21create_full_decimal_string_from_int(number, src, &dec);
  ck_assert_int_eq(dec.bits[0], exp_dec.bits[0]);
}

START_TEST(s21_test_get_exponent) {
  s21_decimal dec;
  dec.bits[3] = 0b00000000000001010000000000000000;
  int expected = 5;
  int result = s21_get_exponent(dec);
  ck_assert_int_eq(result, expected);
}

START_TEST(s21_test_from_int_to_decimal) {
  s21_decimal src;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  int number = 155;
  int expected = 0;
  int result = s21_from_int_to_decimal(number, &src);
  ck_assert_int_eq(result, expected);
}

START_TEST(s21_test_decimal_to_float) {
  float dst = 0.0F;
  s21_decimal src;
  src.bits[0] = 0b00000000000000000000010001010111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000001000000000000000000;
  float expected = 0.1111F;
  s21_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, expected);
}

START_TEST(s21_test_from_decimal_to_float) {
  float dst = 0.0F;
  s21_decimal src;
  src.bits[0] = 0b00000000000000000000010001010111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  int expected = 0;
  int result = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(result, expected);
}

START_TEST(s21_test_decimal_to_int) {
  int dst = 0;
  s21_decimal src;
  src.bits[0] = 0b00000000000000000000010001010111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  int expected = 1111;
  int flag = 0;
  s21_decimal_to_int(src, &dst, &flag);
  ck_assert_int_eq(dst, expected);
}

START_TEST(s21_test_from_decimal_to_int) {
  int dst = 0;
  s21_decimal src;
  src.bits[0] = 0b00000000000000000000010001010111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  int expected = 0;
  int result = s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(result, expected);
}

START_TEST(s21_test_from_float_to_decimal) {
  float src = 0.111F;
  s21_decimal dst;
  int result = s21_from_float_to_decimal(src, &dst);
  int expected = 0;
  ck_assert_int_eq(result, expected);
}

START_TEST(test_different_scales) {
  s21_decimal num, num1;
  num.bits[0] = 356;
  num.bits[1] = 0b00000000000000000000000000000000;
  num.bits[2] = 0b00000000000000000000000000000000;
  num.bits[3] = 0b00000000000000100000000000000000;

  num1.bits[0] = 99;
  num1.bits[1] = 0b00000000000000000000000000000000;
  num1.bits[2] = 0b00000000000000000000000000000000;
  num1.bits[3] = 0b00000000000000010000000000000000;

  ck_assert_int_eq(0, s21_is_greater(num, num1));
  ck_assert_int_eq(1, s21_is_less(num, num1));
  ck_assert_int_eq(0, s21_is_equal(num, num1));
  ck_assert_int_eq(0, s21_is_greater_or_equal(num, num1));
  ck_assert_int_eq(1, s21_is_less_or_equal(num, num1));
  ck_assert_int_eq(1, s21_is_not_equal(num, num1));
}
END_TEST

START_TEST(s21_is_less_test_1) {
  s21_decimal num1, num2;
  num1.bits[0] = 0b00000000000000000000000001000000;
  num1.bits[1] = 0b00000000000000000000000000000000;
  num1.bits[2] = 0b00000000000000000000000000000000;
  num1.bits[3] = 0b00000000000000000000000000000000;

  num2.bits[0] = 0b00000000000000000000000000000100;
  num2.bits[1] = 0b00000000000000000000000000000000;
  num2.bits[2] = 0b00000000000000000000000000000000;
  num2.bits[3] = 0b10000000000000000000000000000000;

  ck_assert_int_eq(s21_is_less(num1, num2), 0);
}
END_TEST

START_TEST(s21_is_less_test_3) {
  s21_decimal num = {{100, 0, 0, 0}};
  s21_decimal num1 = {{120, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(num, num1), 1);
}
END_TEST

START_TEST(s21_is_less_test_4) {
  s21_decimal num = {{39999, 0, 0, 0}};
  s21_decimal num1 = {{40000, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(num, num1), 1);
}
END_TEST

START_TEST(s21_is_less_test_5) {
  s21_decimal num = {{26000, 0, 0, 0}};
  s21_decimal num1 = {{25999, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(num, num1), 0);
}
END_TEST

START_TEST(s21_is_less_test_7) {
  s21_decimal num1 = {{19993, 1, 0, 2147483647}};
  s21_decimal num2 = {{19993, 1, 0, 0}};
  ck_assert_int_eq(s21_is_less(num1, num2), 0);
}
END_TEST

START_TEST(s21_is_less_test_9) {
  s21_decimal num = {{0, 10, 0, 0}};
  s21_decimal num1 = {{40000, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(num, num1), 0);
}
END_TEST

START_TEST(s21_is_less_test_10) {
  s21_decimal num = {{40000, 1, 0, 0b10000000111111110000000000000000}};
  s21_decimal num1 = {{40000, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(num, num1), 0);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_1) {
  s21_decimal num = {{0, 0, 0, 0}};
  s21_decimal num1 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(num, num1), 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_2) {
  s21_decimal num = {{99999, 0, 0, 0}};
  s21_decimal num1 = {{100000, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(num, num1), 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_5) {
  s21_decimal num = {{0, 99, 0, 0}};
  s21_decimal num1 = {{0, 99, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(num, num1), 1);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_1) {
  s21_decimal num1 = {{0, 0, 0, 0}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater_or_equal(num1, num2), 1);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_2) {
  s21_decimal num1 = {{20000, 0, 0, 0}};
  s21_decimal num2 = {{20001, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater_or_equal(num1, num2), 0);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_5) {
  s21_decimal num1 = {{20000, 0, 0, 0}};
  s21_decimal num2 = {{20000, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater_or_equal(num1, num2), 1);
}
END_TEST

START_TEST(test_s21_is_equal_1) {
  s21_decimal num1 = {{0, 0, 0, 0}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_equal(num1, num2), 1);
}
END_TEST

START_TEST(test_s21_is_equal_2) {
  s21_decimal num1 = {{20000, 0, 0, 0}};
  s21_decimal num2 = {{20001, 0, 0, 0}};
  ck_assert_int_eq(s21_is_equal(num1, num2), 0);
}
END_TEST

START_TEST(test_s21_is_equal_3) {
  s21_decimal num1 = {{4999, 0, 0, 0}};
  s21_decimal num2 = {{4999, 0, 0, 2147483647}};
  ck_assert_int_eq(s21_is_equal(num1, num2), 0);
}
END_TEST

START_TEST(test_s21_is_equal_4) {
  s21_decimal num1 = {{20000, 0, 0, 0}};
  s21_decimal num2 = {{20000, 0, 0, 300000}};
  ck_assert_int_eq(s21_is_equal(num1, num2), 0);
}
END_TEST

START_TEST(test_s21_is_equal_5) {
  s21_decimal num1 = {{20000, 1, 0, 0}};
  s21_decimal num2 = {{20000, 0, 2, 0}};
  ck_assert_int_eq(s21_is_equal(num1, num2), 0);
}
END_TEST

START_TEST(test_s21_is_equal_6) {
  s21_decimal num1 = {{-20000, 0, 0, 0}};
  s21_decimal num2 = {{20001, 0, 0, 0}};
  ck_assert_int_eq(s21_is_equal(num1, num2), 0);
}
END_TEST

START_TEST(test_s21_is_equal_7) {
  s21_decimal num1 = {{-20000, 0, 0, 0}};
  s21_decimal num2 = {{-20001, 0, 0, 0}};
  ck_assert_int_eq(s21_is_equal(num1, num2), 0);
}
END_TEST

START_TEST(test_s21_is_not_equal_1) {
  s21_decimal num1 = {{0, 0, 0, 0}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_not_equal(num1, num2), 0);
}
END_TEST

START_TEST(test_s21_is_not_equal_2) {
  s21_decimal num1 = {{20000, 0, 0, 0}};
  s21_decimal num2 = {{20001, 0, 0, 0}};
  ck_assert_int_eq(s21_is_not_equal(num1, num2), 1);
}
END_TEST

START_TEST(test_s21_is_not_equal_3) {
  s21_decimal num1 = {{5000, 0, 0, 0}};
  s21_decimal num2 = {{5000, 0, 0, 2147483647}};
  ck_assert_int_eq(s21_is_not_equal(num1, num2), 1);
}
END_TEST

START_TEST(test_s21_is_not_equal_4) {
  s21_decimal num1 = {{20000, 0, 0, 0}};
  s21_decimal num2 = {{20000, 0, 0, 300000}};
  ck_assert_int_eq(s21_is_not_equal(num1, num2), 1);
}
END_TEST

START_TEST(test_s21_is_not_equal_5) {
  s21_decimal num1 = {{20000, 1, 0, 0}};
  s21_decimal num2 = {{20000, 0, 2, 0}};
  ck_assert_int_eq(s21_is_not_equal(num1, num2), 1);
}
END_TEST

START_TEST(test_s21_is_not_equal_6) {
  s21_decimal num1 = {{-20000, 0, 0, 0}};
  s21_decimal num2 = {{20000, 0, 0, 0}};
  ck_assert_int_eq(s21_is_not_equal(num1, num2), 1);
}
END_TEST

START_TEST(test_s21_negate_1) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b00000110100010010001001110000000;
  value.bits[1] = 0b01100000000000001100101100000000;
  value.bits[2] = 0b00001000100100010000000010000000;
  value.bits[3] = 0b00000000000000000000000000000000;
  //
  origin.bits[0] = 0b00000110100010010001001110000000;
  origin.bits[1] = 0b01100000000000001100101100000000;
  origin.bits[2] = 0b00001000100100010000000010000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_negate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_negate_2) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b00010001000100011100000001100001;
  value.bits[1] = 0b10010001000100111001001101100011;
  value.bits[2] = 0b00010001011001100110001111011110;
  value.bits[3] = 0b00000000000000000000000000000000;
  //
  origin.bits[0] = 0b00010001000100011100000001100001;
  origin.bits[1] = 0b10010001000100111001001101100011;
  origin.bits[2] = 0b00010001011001100110001111011110;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_negate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_negate_3) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b01100101010010101010101010100000;
  value.bits[1] = 0b00010001101110100101011111100001;
  value.bits[2] = 0b00001100100010010010101011100000;
  value.bits[3] = 0b10000000000000000000000000000000;
  //
  origin.bits[0] = 0b01100101010010101010101010100000;
  origin.bits[1] = 0b00010001101110100101011111100001;
  origin.bits[2] = 0b00001100100010010010101011100000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_negate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_negate_4) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b00000000101101011001000101011011;
  value.bits[1] = 0b00100101010001011011011100010010;
  value.bits[2] = 0b01001001010010100001111001110000;
  value.bits[3] = 0b10000000000000000000000000000000;
  //
  origin.bits[0] = 0b00000000101101011001000101011011;
  origin.bits[1] = 0b00100101010001011011011100010010;
  origin.bits[2] = 0b01001001010010100001111001110000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_negate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_negate_5) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b01110010100010010010101010111100;
  value.bits[1] = 0b01110000101001000101101001010111;
  value.bits[2] = 0b00011001000101000100010011001110;
  value.bits[3] = 0b00000000000001110000000000000000;
  //
  origin.bits[0] = 0b01110010100010010010101010111100;
  origin.bits[1] = 0b01110000101001000101101001010111;
  origin.bits[2] = 0b00011001000101000100010011001110;
  origin.bits[3] = 0b10000000000001110000000000000000;
  s21_output = s21_negate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_negate_6) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b00110010110000001010000100010110;
  value.bits[1] = 0b01101001010110101011100000001111;
  value.bits[2] = 0b01001001000010010011110010100011;
  value.bits[3] = 0b00000000000100100000000000000000;
  //
  origin.bits[0] = 0b00110010110000001010000100010110;
  origin.bits[1] = 0b01101001010110101011100000001111;
  origin.bits[2] = 0b01001001000010010011110010100011;
  origin.bits[3] = 0b10000000000100100000000000000000;
  s21_output = s21_negate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_negate_7) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b00010010010111110000111011001110;
  value.bits[1] = 0b01111100000111000110010011001000;
  value.bits[2] = 0b00010010010010000110000011100000;
  value.bits[3] = 0b10000000000110010000000000000000;
  //
  origin.bits[0] = 0b00010010010111110000111011001110;
  origin.bits[1] = 0b01111100000111000110010011001000;
  origin.bits[2] = 0b00010010010010000110000011100000;
  origin.bits[3] = 0b00000000000110010000000000000000;
  s21_output = s21_negate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_negate_8) {
  // null
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b00000000000000000000000000000000;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000000000000000000000;
  //
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_negate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_negate_9) {
  // negate null
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b00000000000000000000000000000000;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000000000000000000000000;
  //
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_negate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_negate_10) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b00000000000110010010000100000000;
  value.bits[1] = 0b00010000000100010001010100000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000011110000000000000000;
  //
  origin.bits[0] = 0b00000000000110010010000100000000;
  origin.bits[1] = 0b00010000000100010001010100000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000011110000000000000000;
  s21_output = s21_negate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_negate_11) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b00110001000110010010000100000000;
  value.bits[1] = 0b00010000000100010001010100000000;
  value.bits[2] = 0b00001111100100010000100000000000;
  value.bits[3] = 0b00000000000110100000000000000000;
  //
  origin.bits[0] = 0b00110001000110010010000100000000;
  origin.bits[1] = 0b00010000000100010001010100000000;
  origin.bits[2] = 0b00001111100100010000100000000000;
  origin.bits[3] = 0b10000000000110100000000000000000;
  s21_output = s21_negate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_negate_12) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b00110001000110010010000100000000;
  value.bits[1] = 0b00010000000100010001010100000000;
  value.bits[2] = 0b00001111100100010000100000000000;
  value.bits[3] = 0b00000000000110100000000000000000;
  //
  origin.bits[0] = 0b00110001000110010010000100000000;
  origin.bits[1] = 0b00010000000100010001010100000000;
  origin.bits[2] = 0b00001111100100010000100000000000;
  origin.bits[3] = 0b10000000000110100000000000000000;
  s21_output = s21_negate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_truncate_1) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // 264107318112051817.4866968866
  value.bits[0] = 0b00000000010000001001000100100010;
  value.bits[1] = 0b00001000100000000000010010010000;
  value.bits[2] = 0b00001000100010001010010100000000;
  value.bits[3] = 0b00000000000010100000000000000000;
  // 264107318112051817
  origin.bits[0] = 0b11011110101001100110001001101001;
  origin.bits[1] = 0b00000011101010100100110000110100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_truncate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_truncate_2) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // 975909603428014204144180.7086
  value.bits[0] = 0b00001001000100101010101011101110;
  value.bits[1] = 0b00010111110100101100100001110000;
  value.bits[2] = 0b00011111100010001000100011111000;
  value.bits[3] = 0b00000000000001000000000000000000;
  // 975909603428014204144180
  origin.bits[0] = 0b00110011100111000100101000110100;
  origin.bits[1] = 0b00101010011001010101111100011001;
  origin.bits[2] = 0b00000000000000001100111010101000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_truncate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_truncate_3) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // 35127093725958791885374.000000
  value.bits[0] = 0b01010010100100101000101110000000;
  value.bits[1] = 0b10001010000100010000111000000101;
  value.bits[2] = 0b01110001100000000111001101101110;
  value.bits[3] = 0b00000000000001100000000000000000;
  // 35127093725958791885374
  origin.bits[0] = 0b11001010100000011111001000111110;
  origin.bits[1] = 0b00111110010110100110000001110000;
  origin.bits[2] = 0b00000000000000000000011101110000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_truncate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_truncate_4) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // 11301643024.744584584724317966
  value.bits[0] = 0b00111111111110011000011100001110;
  value.bits[1] = 0b00000001000100100101101010010110;
  value.bits[2] = 0b00100100100001001000000000000000;
  value.bits[3] = 0b00000000000100100000000000000000;
  // 11301643024
  origin.bits[0] = 0b10100001101000010110001100010000;
  origin.bits[1] = 0b00000000000000000000000000000010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_truncate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_truncate_5) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // 5947153396147561.664
  value.bits[0] = 0b00100010001000100010010011000000;
  value.bits[1] = 0b01010010100010001000100010000001;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000110000000000000000;
  // 5947153396147561
  origin.bits[0] = 0b10001101100110100010010101101001;
  origin.bits[1] = 0b00000000000101010010000011100111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_truncate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_truncate_6) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // -919639.1385315400060
  value.bits[0] = 0b10001001001011111101100101111100;
  value.bits[1] = 0b01111111101000000010010100111101;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000011010000000000000000;
  // -919639
  origin.bits[0] = 0b00000000000011100000100001010111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_truncate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_truncate_7) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // -9876.540164283795735
  value.bits[0] = 0b10000110000000111000100100010111;
  value.bits[1] = 0b10001001000100001000010011110011;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000011110000000000000000;
  // -9876
  origin.bits[0] = 0b00000000000000000010011010010100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_truncate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_truncate_8) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // -3031287.3475492500523254791
  value.bits[0] = 0b11111000000100010000010000000111;
  value.bits[1] = 0b00101001111100000010000110001110;
  value.bits[2] = 0b00000000000110010001001100000000;
  value.bits[3] = 0b10000000000100110000000000000000;
  // -3031287
  origin.bits[0] = 0b00000000001011100100000011110111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_truncate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_truncate_10) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // 7777777.7777777
  value.bits[0] = 0b00001100110100001101110001110001;
  value.bits[1] = 0b00000000000000000100011010111101;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000001110000000000000000;
  // 7777777
  origin.bits[0] = 0b00000000011101101010110111110001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_truncate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_truncate_13) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // -3.1957442962838464
  value.bits[0] = 0b00000011101110101101001111000000;
  value.bits[1] = 0b00000000011100011000100100100000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000100000000000000000000;
  // 3
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;

  s21_output = s21_truncate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_5) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // 39697459361519.128505637404963
  value.bits[0] = 0b00000001001100000000000100100011;
  value.bits[1] = 0b00011000100000000000001000000000;
  value.bits[2] = 0b10000000010001001111100000000000;
  value.bits[3] = 0b00000000000011110000000000000000;
  // 39697459361519
  origin.bits[0] = 0b11001000111101101011011011101111;
  origin.bits[1] = 0b00000000000000000010010000011010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;

  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_6) {
  // null test
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b00000000000000000000000000000000;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000000000000000000000;
  //
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_8) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // -330034358.000060563
  value.bits[0] = 0b00000000010001001000100010010011;
  value.bits[1] = 0b00000100100101001000010010000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000010010000000000000000;
  // -330034359
  origin.bits[0] = 0b00010011101010111110110010110111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_10) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // -25332308.1000455680
  value.bits[0] = 0b00000000011100001000111000000000;
  value.bits[1] = 0b00000011100000111111110000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000010100000000000000000;
  // -25332309
  origin.bits[0] = 0b00000001100000101000101001010101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_11) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // -0.00000000003452810109649558
  value.bits[0] = 0b00000000000100000000001010010110;
  value.bits[1] = 0b00000000000011000100010001010000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000110100000000000000000;
  // -1
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_12) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // -0.000000000004959928320
  value.bits[0] = 0b00100111101000101000000000000000;
  value.bits[1] = 0b00000000000000000000000000000001;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000101010000000000000000;
  // -1
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_13) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // 27149251.7085128960
  value.bits[0] = 0b10000000000010010010100100000000;
  value.bits[1] = 0b00000011110001001000100100000001;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000010100000000000000000;
  // 27149251
  origin.bits[0] = 0b00000001100111100100001111000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_14) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // 9904296572294616.931377348608
  value.bits[0] = 0b11100000000000000000000000000000;
  value.bits[1] = 0b00000111111110000000000000000001;
  value.bits[2] = 0b00100000000000001010010001100001;
  value.bits[3] = 0b00000000000011000000000000000000;
  // 9904296572294616
  origin.bits[0] = 0b10111110111100010001010111011000;
  origin.bits[1] = 0b00000000001000110010111111100111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_15) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // 22337854.19752363009
  value.bits[0] = 0b00010000110010010101010000000001;
  value.bits[1] = 0b00011111000000000000000000000001;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000010110000000000000000;
  // 22337854
  origin.bits[0] = 0b00000001010101001101100100111110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_16) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  //  -8196555174.425465492
  value.bits[0] = 0b00000001100001010001001010010100;
  value.bits[1] = 0b01110001110000000000001110000001;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000010010000000000000000;
  // -8196555175
  origin.bits[0] = 0b11101000100011011000000110100111;
  origin.bits[1] = 0b00000000000000000000000000000001;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_17) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // 7777777.7777777
  value.bits[0] = 0b00001100110100001101110001110001;
  value.bits[1] = 0b00000000000000000100011010111101;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000001110000000000000000;
  // 7777777
  origin.bits[0] = 0b00000000011101101010110111110001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_18) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // 1080921880.458340136
  value.bits[0] = 0b00101010101010101010011100101000;
  value.bits[1] = 0b00001111000000000011010010111001;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000010010000000000000000;
  // 1080921880
  origin.bits[0] = 0b01000000011011011000111100011000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_19) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // -3.1957442962838464
  value.bits[0] = 0b00000011101110101101001111000000;
  value.bits[1] = 0b00000000011100011000100100100000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000100000000000000000000;
  // -4
  origin.bits[0] = 0b00000000000000000000000000000100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_20) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // -1.28502129019350168
  value.bits[0] = 0b01101001000101000110110010011000;
  value.bits[1] = 0b00000001110010001000100000000001;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000100010000000000000000;
  // -2
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_21) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // 1089644363795118168909.145790
  value.bits[0] = 0b01010010100101011110011010111110;
  value.bits[1] = 0b01010010101110101100100100011111;
  value.bits[2] = 0b00000011100001010101010100101011;
  value.bits[3] = 0b00000000000001100000000000000000;
  // 1089644363795118168909
  origin.bits[0] = 0b00111010100010000001101101001101;
  origin.bits[1] = 0b00010001110110100110111110110000;
  origin.bits[2] = 0b00000000000000000000000000111011;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_22) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // -3965175934092449816848.5532975
  value.bits[0] = 0b11000000010001000101010100101111;
  value.bits[1] = 0b00000011111000000000000000000000;
  value.bits[2] = 0b10000000000111110010101010100101;
  value.bits[3] = 0b10000000000001110000000000000000;
  // -3965175934092449816849
  origin.bits[0] = 0b10010100001011100010000100010001;
  origin.bits[1] = 0b11110011110111101100011110100111;
  origin.bits[2] = 0b00000000000000000000000011010110;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_23) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // 26745264258900957313380.20864
  value.bits[0] = 0b00001110010000101000100000000000;
  value.bits[1] = 0b00010000111001010010100001000110;
  value.bits[2] = 0b00001000101001000101000100000000;
  value.bits[3] = 0b00000000000001010000000000000000;
  // 26745264258900957313380
  origin.bits[0] = 0b10111110100011111011100101100100;
  origin.bits[1] = 0b11011101000110100010110011111100;
  origin.bits[2] = 0b00000000000000000000010110101001;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_24) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // 1551543454561865943408.9728595
  value.bits[0] = 0b10000000000000001100101001010011;
  value.bits[1] = 0b00010010001000010011111100000001;
  value.bits[2] = 0b00110010001000100001000100010000;
  value.bits[3] = 0b00000000000001110000000000000000;
  // 1551543454561865943408
  origin.bits[0] = 0b10010110011100011100100101110000;
  origin.bits[1] = 0b00011011111111011010011101111110;
  origin.bits[2] = 0b00000000000000000000000001010100;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_round_6) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // 18446744073709551615
  // 349738609805692.312931738872
  value.bits[0] = 0b01001001101100110010010011111000;
  value.bits[1] = 0b00000111000101010101101010100101;
  value.bits[2] = 0b00000001001000010100110000001000;
  value.bits[3] = 0b00000000000011000000000000000000;
  // 349738609805692
  // 349738609805693
  //  11011101100110100000100101111101
  origin.bits[0] = 0b11011101100110100000100101111100;
  origin.bits[1] = 0b00000000000000010011111000010101;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_round(value, &result);
  // ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_round_7) {
  // null
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b00000000000000000000000000000000;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000000000000000000000;
  //
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_round(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_round_8) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // 330121751632009242242.714390
  value.bits[0] = 0b01111100101000000000101100010110;
  value.bits[1] = 0b00000011111001001001111011101110;
  value.bits[2] = 0b00000001000100010001001000000000;
  value.bits[3] = 0b00000000000001100000000000000000;
  // 330121751632009242243
  origin.bits[0] = 0b10011111101001000010011010000011;
  origin.bits[1] = 0b11100101010111000001000000001100;
  origin.bits[2] = 0b00000000000000000000000000010001;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_round(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_round_9) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // 4247984203.5
  value.bits[0] = 0b11100011111111101111001011110011;
  value.bits[1] = 0b00000000000000000000000000001001;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000010000000000000000;
  // 4247984204
  origin.bits[0] = 0b11111101001100110001100001001100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_round(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_round_15) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // 0.465
  value.bits[0] = 0b00000000000000000000000111010001;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000110000000000000000;
  // 0
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_round(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_round_16) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // -908745357.386764378
  value.bits[0] = 0b01111010010100101101000001011010;
  value.bits[1] = 0b00001100100111001000001100010110;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000010010000000000000000;
  // -908745357
  origin.bits[0] = 0b00110110001010100101101010001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_round(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_round_17) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // -832381902.74234
  value.bits[0] = 0b01100110110000110101011010111010;
  value.bits[1] = 0b00000000000000000100101110110100;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000001010000000000000000;
  // -832381903
  origin.bits[0] = 0b00110001100111010010001111001111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_round(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_round_22) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // -4262362461.5
  value.bits[0] = 0b11101100100100001110010110100111;
  value.bits[1] = 0b00000000000000000000000000001001;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000000010000000000000000;
  // -4262362462
  origin.bits[0] = 0b11111110000011100111110101011110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_round(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_round_25) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // -213521353245.3125
  value.bits[0] = 0b00100100000111110001100100000101;
  value.bits[1] = 0b00000000000001111001010111110111;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000001000000000000000000;
  // -213521353245
  // 10110110110111010100101000011101
  origin.bits[0] = 0b10110110110111010100101000011101;
  origin.bits[1] = 0b00000000000000000000000000110001;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_round(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_round_26) {
  s21_decimal value;
  s21_decimal_init(&value);
  s21_decimal origin;
  s21_decimal_init(&origin);
  s21_decimal result;
  s21_decimal_init(&result);
  int s21_output = 0;
  int origin_output = 0;
  // -0.1554324
  value.bits[0] = 0b00000000000101111011011110010100;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000001110000000000000000;
  // -0
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_round(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

Suite *s21_decimal_suite(void) {
  Suite *suite;
  TCase *tc_reverse_string, *tc_binary_to_string, *tc_number_alignment,
      *tc_del_symbol_minus, *tc_del_symbol_comma, *tc_set_negative_number,
      *tc_del_zero_begin, *tc_binary_cmp_is_compare, *tc_binary_cmp_is_less,
      *tc_binary_cmp_is_greater, *tc_checking_number_for_size_number_ok,
      *tc_checking_number_for_size_number_large,
      *tc_checking_number_for_size_number_small, *tc_splitting_number,
      *tc_get_zoomlvl, *tc_bank_rounding_used_default_method,
      *tc_bank_rounding_used_bank_method, *tc_diff_in_zoom_levels_equals,
      *tc_diff_in_zoom_levels_not_equals, *tc_decimal_is_zero_true,
      *tc_decimal_is_zero_false, *tc_common_denominator,
      *tc_opposite_of_denominator, *tc_binary_string_to_decimal,
      *tc_sum_binary_string, *tc_subtract_binary_string, *tc_multiply_binary,
      *tc_division_binary, *tc_calculating_add, *tc_calculating_sub,
      *tc_calculating_mul, *tc_calculating_div,
      *tc_s21_add_is_normal_positive_both_value_without_comma,
      *tc_s21_add_is_normal_negative_left_value_without_comma,
      *tc_s21_add_is_normal_negative_right_value_without_comma,
      *tc_s21_add_is_normal_negative_both_value_without_comma,
      *tc_s21_add_is_normal_positive_both_value_with_comma,
      *tc_s21_add_is_normal_negative_both_value_with_comma,
      *tc_s21_sub_is_normal_positive_both_value_without_comma,
      *tc_s21_sub_is_normal_negative_left_value_without_comma,
      *tc_s21_sub_is_normal_negative_right_value_without_comma,
      *tc_s21_sub_is_normal_negative_both_value_without_comma,
      *tc_s21_sub_is_normal_positive_both_value_with_comma,
      *tc_s21_sub_is_normal_negative_both_value_with_comma,
      *tc_s21_mul_is_normal_positive_both_value_without_comma,
      *tc_s21_mul_is_normal_negative_left_value_without_comma,
      *tc_s21_mul_is_normal_negative_both_value_without_comma,
      *tc_s21_mul_is_normal_positive_both_value_with_comma,
      *tc_s21_mul_is_normal_negative_both_value_with_comma,
      *tc_s21_div_is_normal_positive_both_value_without_comma,
      *tc_s21_div_is_normal_positive_both_value_with_comma,
      *tc_s21_div_is_normal_negative_both_value_with_comma,
      *tc_s21_add_is_unnormal_positive_both_value_without_comma,
      *tc_s21_add_is_unnormal_negative_both_value_without_comma,
      *tc_s21_sub_is_unnormal_positive_both_value_without_comma,
      *tc_s21_sub_is_unnormal_negative_both_value_without_comma,
      *tc_s21_mul_is_unnormal_positive_both_value_without_comma,
      *tc_s21_mul_is_unnormal_negative_both_value_without_comma,
      *tc_s21_div_is_unnormal_positive_both_value_without_comma,
      *tc_s21_div_is_unnormal_negative_both_value_without_comma,
      *tc_s21_div_by_zero, *tc_test_int_to_string,
      *tc_create_full_decimal_string_from_int, *tc_test_get_exponent,
      *tc_test_from_int_to_decimal, *tc_test_decimal_to_float,
      *tc_test_from_decimal_to_float, *tc_test_decimal_to_int,
      *tc_test_from_decimal_to_int, *tc_test_from_float_to_decimal;

  suite = suite_create("s21_decimal");

  tc_reverse_string = tcase_create("s21_test_reverse_string");
  tcase_add_test(tc_reverse_string, s21_test_reverse_string);
  suite_add_tcase(suite, tc_reverse_string);

  tc_binary_to_string = tcase_create("s21_test_binary_to_string");
  tcase_add_test(tc_binary_to_string, s21_test_binary_to_string);
  suite_add_tcase(suite, tc_binary_to_string);

  tc_number_alignment = tcase_create("s21_test_number_alignment");
  tcase_add_test(tc_number_alignment, s21_test_number_alignment);
  suite_add_tcase(suite, tc_number_alignment);

  tc_del_symbol_minus = tcase_create("s21_test_del_symbol_minus");
  tcase_add_test(tc_del_symbol_minus, s21_test_del_symbol_minus);
  suite_add_tcase(suite, tc_del_symbol_minus);

  tc_del_symbol_comma = tcase_create("s21_test_del_symbol_comma");
  tcase_add_test(tc_del_symbol_comma, s21_test_del_symbol_comma);
  suite_add_tcase(suite, tc_del_symbol_comma);

  tc_del_zero_begin = tcase_create("s21_test_del_zero_begin");
  tcase_add_test(tc_del_zero_begin, s21_test_del_zero_begin);
  suite_add_tcase(suite, tc_del_zero_begin);

  tc_set_negative_number = tcase_create("s21_test_set_negative_number");
  tcase_add_test(tc_set_negative_number, s21_test_set_negative_number);
  suite_add_tcase(suite, tc_set_negative_number);

  tc_binary_cmp_is_compare = tcase_create("s21_test_binary_cmp_is_compare");
  tcase_add_test(tc_binary_cmp_is_compare, s21_test_binary_cmp_is_compare);
  suite_add_tcase(suite, tc_binary_cmp_is_compare);

  tc_binary_cmp_is_less = tcase_create("s21_test_binary_cmp_is_less");
  tcase_add_test(tc_binary_cmp_is_less, s21_test_binary_cmp_is_less);
  suite_add_tcase(suite, tc_binary_cmp_is_less);

  tc_binary_cmp_is_greater = tcase_create("s21_test_binary_cmp_is_greater");
  tcase_add_test(tc_binary_cmp_is_greater, s21_test_binary_cmp_is_greater);
  suite_add_tcase(suite, tc_binary_cmp_is_greater);

  tc_checking_number_for_size_number_ok =
      tcase_create("s21_test_checking_number_for_size_number_ok");
  tcase_add_test(tc_checking_number_for_size_number_ok,
                 s21_test_checking_number_for_size_number_ok);
  suite_add_tcase(suite, tc_checking_number_for_size_number_ok);

  tc_checking_number_for_size_number_large =
      tcase_create("s21_test_checking_number_for_size_number_large");
  tcase_add_test(tc_checking_number_for_size_number_large,
                 s21_test_checking_number_for_size_number_large);
  suite_add_tcase(suite, tc_checking_number_for_size_number_large);

  tc_checking_number_for_size_number_small =
      tcase_create("s21_test_checking_number_for_size_number_small");
  tcase_add_test(tc_checking_number_for_size_number_small,
                 s21_test_checking_number_for_size_number_small);
  suite_add_tcase(suite, tc_checking_number_for_size_number_small);

  tc_splitting_number = tcase_create("s21_test_splitting_number");
  tcase_add_test(tc_splitting_number, s21_test_splitting_number);
  suite_add_tcase(suite, tc_splitting_number);

  tc_get_zoomlvl = tcase_create("s21_test_get_zoomlvl");
  tcase_add_test(tc_get_zoomlvl, s21_test_get_zoomlvl);
  suite_add_tcase(suite, tc_get_zoomlvl);

  tc_bank_rounding_used_default_method =
      tcase_create("s21_test_bank_rounding_used_default_method");
  tcase_add_test(tc_bank_rounding_used_default_method,
                 s21_test_bank_rounding_used_default_method);
  suite_add_tcase(suite, tc_bank_rounding_used_default_method);

  tc_bank_rounding_used_bank_method =
      tcase_create("s21_test_bank_rounding_used_bank_method");
  tcase_add_test(tc_bank_rounding_used_bank_method,
                 s21_test_bank_rounding_used_bank_method);
  suite_add_tcase(suite, tc_bank_rounding_used_bank_method);

  tc_diff_in_zoom_levels_equals =
      tcase_create("s21_test_diff_in_zoom_levels_equals");
  tcase_add_test(tc_diff_in_zoom_levels_equals,
                 s21_test_diff_in_zoom_levels_equals);
  suite_add_tcase(suite, tc_diff_in_zoom_levels_equals);

  tc_diff_in_zoom_levels_not_equals =
      tcase_create("s21_test_diff_in_zoom_levels_not_equals");
  tcase_add_test(tc_diff_in_zoom_levels_not_equals,
                 s21_test_diff_in_zoom_levels_not_equals);
  suite_add_tcase(suite, tc_diff_in_zoom_levels_not_equals);

  tc_decimal_is_zero_true = tcase_create("s21_test_decimal_is_zero_true");
  tcase_add_test(tc_decimal_is_zero_true, s21_test_decimal_is_zero_true);
  suite_add_tcase(suite, tc_decimal_is_zero_true);

  tc_decimal_is_zero_false = tcase_create("s21_test_decimal_is_zero_false");
  tcase_add_test(tc_decimal_is_zero_false, s21_test_decimal_is_zero_false);
  suite_add_tcase(suite, tc_decimal_is_zero_false);

  tc_common_denominator = tcase_create("s21_test_common_denominator");
  tcase_add_test(tc_common_denominator, s21_test_common_denominator);
  suite_add_tcase(suite, tc_common_denominator);

  tc_opposite_of_denominator = tcase_create("s21_test_opposite_of_denominator");
  tcase_add_test(tc_opposite_of_denominator, s21_test_opposite_of_denominator);
  suite_add_tcase(suite, tc_opposite_of_denominator);

  tc_binary_string_to_decimal =
      tcase_create("s21_test_binary_string_to_decimal");
  tcase_add_test(tc_binary_string_to_decimal,
                 s21_test_binary_string_to_decimal);
  suite_add_tcase(suite, tc_binary_string_to_decimal);

  tc_sum_binary_string = tcase_create("s21_test_sum_binary_string");
  tcase_add_test(tc_sum_binary_string, s21_test_sum_binary_string);
  suite_add_tcase(suite, tc_sum_binary_string);

  tc_subtract_binary_string = tcase_create("s21_test_subtract_binary_string");
  tcase_add_test(tc_subtract_binary_string, s21_test_subtract_binary_string);
  suite_add_tcase(suite, tc_subtract_binary_string);

  tc_multiply_binary = tcase_create("s21_test_multiply_binary");
  tcase_add_test(tc_multiply_binary, s21_test_multiply_binary);
  suite_add_tcase(suite, tc_multiply_binary);

  tc_division_binary = tcase_create("s21_test_division_binary");
  tcase_add_test(tc_division_binary, s21_test_division_binary);
  suite_add_tcase(suite, tc_division_binary);

  tc_calculating_add = tcase_create("s21_test_calculating_add");
  tcase_add_test(tc_calculating_add, s21_test_calculating_add);
  suite_add_tcase(suite, tc_calculating_add);

  tc_calculating_sub = tcase_create("s21_test_calculating_sub");
  tcase_add_test(tc_calculating_sub, s21_test_calculating_sub);
  suite_add_tcase(suite, tc_calculating_sub);

  tc_calculating_mul = tcase_create("s21_test_calculating_mul");
  tcase_add_test(tc_calculating_mul, s21_test_calculating_mul);
  suite_add_tcase(suite, tc_calculating_mul);

  tc_calculating_div = tcase_create("s21_test_calculating_div");
  tcase_add_test(tc_calculating_div, s21_test_calculating_div);
  suite_add_tcase(suite, tc_calculating_div);

  tc_s21_add_is_normal_positive_both_value_without_comma = tcase_create(
      "s21_test_s21_add_is_normal_positive_both_value_without_comma");
  tcase_add_test(tc_s21_add_is_normal_positive_both_value_without_comma,
                 s21_test_s21_add_is_normal_positive_both_value_without_comma);
  suite_add_tcase(suite,
                  tc_s21_add_is_normal_positive_both_value_without_comma);

  tc_s21_add_is_normal_negative_left_value_without_comma = tcase_create(
      "s21_test_s21_add_is_normal_negative_left_value_without_comma");
  tcase_add_test(tc_s21_add_is_normal_negative_left_value_without_comma,
                 s21_test_s21_add_is_normal_negative_left_value_without_comma);
  suite_add_tcase(suite,
                  tc_s21_add_is_normal_negative_left_value_without_comma);

  tc_s21_add_is_normal_negative_right_value_without_comma = tcase_create(
      "s21_test_s21_add_is_normal_negative_right_value_without_comma");
  tcase_add_test(tc_s21_add_is_normal_negative_right_value_without_comma,
                 s21_test_s21_add_is_normal_negative_right_value_without_comma);
  suite_add_tcase(suite,
                  tc_s21_add_is_normal_negative_right_value_without_comma);

  tc_s21_add_is_normal_negative_both_value_without_comma = tcase_create(
      "s21_test_s21_add_is_normal_negative_both_value_without_comma");
  tcase_add_test(tc_s21_add_is_normal_negative_both_value_without_comma,
                 s21_test_s21_add_is_normal_negative_both_value_without_comma);
  suite_add_tcase(suite,
                  tc_s21_add_is_normal_negative_both_value_without_comma);

  tc_s21_add_is_normal_positive_both_value_with_comma =
      tcase_create("s21_test_s21_add_is_normal_positive_both_value_with_comma");
  tcase_add_test(tc_s21_add_is_normal_positive_both_value_with_comma,
                 s21_test_s21_add_is_normal_positive_both_value_with_comma);
  suite_add_tcase(suite, tc_s21_add_is_normal_positive_both_value_with_comma);

  tc_s21_add_is_normal_negative_both_value_with_comma =
      tcase_create("s21_test_s21_add_is_normal_negative_both_value_with_comma");
  tcase_add_test(tc_s21_add_is_normal_negative_both_value_with_comma,
                 s21_test_s21_add_is_normal_negative_both_value_with_comma);
  suite_add_tcase(suite, tc_s21_add_is_normal_negative_both_value_with_comma);

  tc_s21_sub_is_normal_positive_both_value_without_comma = tcase_create(
      "s21_test_s21_sub_is_normal_positive_both_value_without_comma");
  tcase_add_test(tc_s21_sub_is_normal_positive_both_value_without_comma,
                 s21_test_s21_sub_is_normal_positive_both_value_without_comma);
  suite_add_tcase(suite,
                  tc_s21_sub_is_normal_positive_both_value_without_comma);

  tc_s21_sub_is_normal_negative_left_value_without_comma = tcase_create(
      "s21_test_s21_sub_is_normal_negative_left_value_without_comma");
  tcase_add_test(tc_s21_sub_is_normal_negative_left_value_without_comma,
                 s21_test_s21_sub_is_normal_negative_left_value_without_comma);
  suite_add_tcase(suite,
                  tc_s21_sub_is_normal_negative_left_value_without_comma);

  tc_s21_sub_is_normal_negative_right_value_without_comma = tcase_create(
      "s21_test_s21_sub_is_normal_negative_right_value_without_comma");
  tcase_add_test(tc_s21_sub_is_normal_negative_right_value_without_comma,
                 s21_test_s21_sub_is_normal_negative_right_value_without_comma);
  suite_add_tcase(suite,
                  tc_s21_sub_is_normal_negative_right_value_without_comma);

  tc_s21_sub_is_normal_negative_both_value_without_comma = tcase_create(
      "s21_test_s21_sub_is_normal_negative_both_value_without_comma");
  tcase_add_test(tc_s21_sub_is_normal_negative_both_value_without_comma,
                 s21_test_s21_sub_is_normal_negative_both_value_without_comma);
  suite_add_tcase(suite,
                  tc_s21_sub_is_normal_negative_both_value_without_comma);

  tc_s21_sub_is_normal_positive_both_value_with_comma =
      tcase_create("s21_test_s21_sub_is_normal_positive_both_value_with_comma");
  tcase_add_test(tc_s21_sub_is_normal_positive_both_value_with_comma,
                 s21_test_s21_sub_is_normal_positive_both_value_with_comma);
  suite_add_tcase(suite, tc_s21_sub_is_normal_positive_both_value_with_comma);

  tc_s21_sub_is_normal_negative_both_value_with_comma =
      tcase_create("s21_test_s21_sub_is_normal_negative_both_value_with_comma");
  tcase_add_test(tc_s21_sub_is_normal_negative_both_value_with_comma,
                 s21_test_s21_sub_is_normal_negative_both_value_with_comma);
  suite_add_tcase(suite, tc_s21_sub_is_normal_negative_both_value_with_comma);

  tc_s21_mul_is_normal_positive_both_value_without_comma = tcase_create(
      "s21_test_s21_mul_is_normal_positive_both_value_without_comma");
  tcase_add_test(tc_s21_mul_is_normal_positive_both_value_without_comma,
                 s21_test_s21_mul_is_normal_positive_both_value_without_comma);
  suite_add_tcase(suite,
                  tc_s21_mul_is_normal_positive_both_value_without_comma);

  tc_s21_mul_is_normal_negative_left_value_without_comma = tcase_create(
      "s21_test_s21_mul_is_normal_negative_left_value_without_comma");
  tcase_add_test(tc_s21_mul_is_normal_negative_left_value_without_comma,
                 s21_test_s21_mul_is_normal_negative_left_value_without_comma);
  suite_add_tcase(suite,
                  tc_s21_mul_is_normal_negative_left_value_without_comma);

  tc_s21_mul_is_normal_negative_both_value_without_comma = tcase_create(
      "s21_test_s21_mul_is_normal_negative_both_value_without_comma");
  tcase_add_test(tc_s21_mul_is_normal_negative_both_value_without_comma,
                 s21_test_s21_mul_is_normal_negative_both_value_without_comma);
  suite_add_tcase(suite,
                  tc_s21_mul_is_normal_negative_both_value_without_comma);

  tc_s21_mul_is_normal_positive_both_value_with_comma =
      tcase_create("s21_test_s21_mul_is_normal_positive_both_value_with_comma");
  tcase_add_test(tc_s21_mul_is_normal_positive_both_value_with_comma,
                 s21_test_s21_mul_is_normal_positive_both_value_with_comma);
  suite_add_tcase(suite, tc_s21_mul_is_normal_positive_both_value_with_comma);

  tc_s21_mul_is_normal_negative_both_value_with_comma =
      tcase_create("s21_test_s21_mul_is_normal_negative_both_value_with_comma");
  tcase_add_test(tc_s21_mul_is_normal_negative_both_value_with_comma,
                 s21_test_s21_mul_is_normal_negative_both_value_with_comma);
  suite_add_tcase(suite, tc_s21_mul_is_normal_negative_both_value_with_comma);

  tc_s21_div_is_normal_positive_both_value_without_comma = tcase_create(
      "s21_test_s21_div_is_normal_positive_both_value_without_comma");
  tcase_add_test(tc_s21_div_is_normal_positive_both_value_without_comma,
                 s21_test_s21_div_is_normal_positive_both_value_without_comma);
  suite_add_tcase(suite,
                  tc_s21_div_is_normal_positive_both_value_without_comma);

  tc_s21_div_is_normal_positive_both_value_with_comma =
      tcase_create("s21_test_s21_div_is_normal_positive_both_value_with_comma");
  tcase_add_test(tc_s21_div_is_normal_positive_both_value_with_comma,
                 s21_test_s21_div_is_normal_positive_both_value_with_comma);
  suite_add_tcase(suite, tc_s21_div_is_normal_positive_both_value_with_comma);

  tc_s21_div_is_normal_negative_both_value_with_comma =
      tcase_create("s21_test_s21_div_is_normal_negative_both_value_with_comma");
  tcase_add_test(tc_s21_div_is_normal_negative_both_value_with_comma,
                 s21_test_s21_div_is_normal_negative_both_value_with_comma);
  suite_add_tcase(suite, tc_s21_div_is_normal_negative_both_value_with_comma);

  tc_s21_add_is_unnormal_positive_both_value_without_comma = tcase_create(
      "s21_test_s21_add_is_unnormal_positive_both_value_without_comma");
  tcase_add_test(
      tc_s21_add_is_unnormal_positive_both_value_without_comma,
      s21_test_s21_add_is_unnormal_positive_both_value_without_comma);
  suite_add_tcase(suite,
                  tc_s21_add_is_unnormal_positive_both_value_without_comma);

  tc_s21_add_is_unnormal_negative_both_value_without_comma = tcase_create(
      "s21_test_s21_add_is_unnormal_negative_both_value_without_comma");
  tcase_add_test(
      tc_s21_add_is_unnormal_negative_both_value_without_comma,
      s21_test_s21_add_is_unnormal_negative_both_value_without_comma);
  suite_add_tcase(suite,
                  tc_s21_add_is_unnormal_negative_both_value_without_comma);

  tc_s21_sub_is_unnormal_positive_both_value_without_comma = tcase_create(
      "s21_test_s21_sub_is_unnormal_positive_both_value_without_comma");
  tcase_add_test(
      tc_s21_sub_is_unnormal_positive_both_value_without_comma,
      s21_test_s21_sub_is_unnormal_positive_both_value_without_comma);
  suite_add_tcase(suite,
                  tc_s21_sub_is_unnormal_positive_both_value_without_comma);

  tc_s21_sub_is_unnormal_negative_both_value_without_comma = tcase_create(
      "s21_test_s21_sub_is_unnormal_negative_both_value_without_comma");
  tcase_add_test(
      tc_s21_sub_is_unnormal_negative_both_value_without_comma,
      s21_test_s21_sub_is_unnormal_negative_both_value_without_comma);
  suite_add_tcase(suite,
                  tc_s21_sub_is_unnormal_negative_both_value_without_comma);

  tc_s21_mul_is_unnormal_positive_both_value_without_comma = tcase_create(
      "s21_test_s21_mul_is_unnormal_positive_both_value_without_comma");
  tcase_add_test(
      tc_s21_mul_is_unnormal_positive_both_value_without_comma,
      s21_test_s21_mul_is_unnormal_positive_both_value_without_comma);
  suite_add_tcase(suite,
                  tc_s21_mul_is_unnormal_positive_both_value_without_comma);

  tc_s21_mul_is_unnormal_negative_both_value_without_comma = tcase_create(
      "s21_test_s21_mul_is_unnormal_negative_both_value_without_comma");
  tcase_add_test(
      tc_s21_mul_is_unnormal_negative_both_value_without_comma,
      s21_test_s21_mul_is_unnormal_negative_both_value_without_comma);
  suite_add_tcase(suite,
                  tc_s21_mul_is_unnormal_negative_both_value_without_comma);

  tc_s21_div_is_unnormal_positive_both_value_without_comma = tcase_create(
      "s21_test_s21_div_is_unnormal_positive_both_value_without_comma");
  tcase_add_test(
      tc_s21_div_is_unnormal_positive_both_value_without_comma,
      s21_test_s21_div_is_unnormal_positive_both_value_without_comma);
  suite_add_tcase(suite,
                  tc_s21_div_is_unnormal_positive_both_value_without_comma);

  tc_s21_div_is_unnormal_negative_both_value_without_comma = tcase_create(
      "s21_test_s21_div_is_unnormal_negative_both_value_without_comma");
  tcase_add_test(
      tc_s21_div_is_unnormal_negative_both_value_without_comma,
      s21_test_s21_div_is_unnormal_negative_both_value_without_comma);
  suite_add_tcase(suite,
                  tc_s21_div_is_unnormal_negative_both_value_without_comma);

  tc_s21_div_by_zero = tcase_create("s21_test_s21_div_by_zero");
  tcase_add_test(tc_s21_div_by_zero, s21_test_s21_div_by_zero);
  suite_add_tcase(suite, tc_s21_div_by_zero);

  tc_test_int_to_string = tcase_create("s21_test_int_to_string");
  tcase_add_test(tc_test_int_to_string, s21_test_int_to_string);
  suite_add_tcase(suite, tc_test_int_to_string);

  tc_create_full_decimal_string_from_int =
      tcase_create("s21_create_full_decimal_string_from_int");
  tcase_add_test(tc_create_full_decimal_string_from_int,
                 s21_create_full_decimal_string_from_int);
  suite_add_tcase(suite, tc_create_full_decimal_string_from_int);

  tc_test_get_exponent = tcase_create("s21_test_get_exponent");
  tcase_add_test(tc_test_get_exponent, s21_test_get_exponent);
  suite_add_tcase(suite, tc_test_get_exponent);

  tc_test_from_int_to_decimal = tcase_create("s21_test_from_int_to_decimal");
  tcase_add_test(tc_test_from_int_to_decimal, s21_test_from_int_to_decimal);
  suite_add_tcase(suite, tc_test_from_int_to_decimal);

  tc_test_decimal_to_float = tcase_create("s21_test_decimal_to_float");
  tcase_add_test(tc_test_decimal_to_float, s21_test_decimal_to_float);
  suite_add_tcase(suite, tc_test_decimal_to_float);

  tc_test_from_decimal_to_float =
      tcase_create("s21_test_from_decimal_to_float");
  tcase_add_test(tc_test_from_decimal_to_float, s21_test_from_decimal_to_float);
  suite_add_tcase(suite, tc_test_from_decimal_to_float);

  tc_test_decimal_to_int = tcase_create("s21_test_decimal_to_int");
  tcase_add_test(tc_test_decimal_to_int, s21_test_decimal_to_int);
  suite_add_tcase(suite, tc_test_decimal_to_int);

  tc_test_from_decimal_to_int = tcase_create("s21_test_from_decimal_to_int");
  tcase_add_test(tc_test_from_decimal_to_int, s21_test_from_decimal_to_int);
  suite_add_tcase(suite, tc_test_from_decimal_to_int);

  tc_test_from_float_to_decimal =
      tcase_create("s21_test_from_float_to_decimal");
  tcase_add_test(tc_test_from_float_to_decimal, s21_test_from_float_to_decimal);
  suite_add_tcase(suite, tc_test_from_float_to_decimal);

  return suite;
}

Suite *melaniad_operators(void) {
  Suite *s = suite_create("\033[45m-=OPERATORS=-\033[0m");
  TCase *tc = tcase_create("OPERATORS");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_different_scales);
  tcase_add_test(tc, s21_is_less_test_1);
  tcase_add_test(tc, s21_is_less_test_3);
  tcase_add_test(tc, s21_is_less_test_4);
  tcase_add_test(tc, s21_is_less_test_5);
  tcase_add_test(tc, s21_is_less_test_7);
  tcase_add_test(tc, s21_is_less_test_9);
  tcase_add_test(tc, s21_is_less_test_10);
  tcase_add_test(tc, s21_is_less_or_equal_test_1);
  tcase_add_test(tc, s21_is_less_or_equal_test_2);
  tcase_add_test(tc, s21_is_less_or_equal_test_5);
  tcase_add_test(tc, test_s21_is_greater_or_equal_1);
  tcase_add_test(tc, test_s21_is_greater_or_equal_2);
  tcase_add_test(tc, test_s21_is_greater_or_equal_5);
  tcase_add_test(tc, test_s21_is_equal_1);
  tcase_add_test(tc, test_s21_is_equal_2);
  tcase_add_test(tc, test_s21_is_equal_3);
  tcase_add_test(tc, test_s21_is_equal_4);
  tcase_add_test(tc, test_s21_is_equal_5);
  tcase_add_test(tc, test_s21_is_equal_6);
  tcase_add_test(tc, test_s21_is_equal_7);
  tcase_add_test(tc, test_s21_is_not_equal_1);
  tcase_add_test(tc, test_s21_is_not_equal_2);
  tcase_add_test(tc, test_s21_is_not_equal_3);
  tcase_add_test(tc, test_s21_is_not_equal_4);
  tcase_add_test(tc, test_s21_is_not_equal_5);
  tcase_add_test(tc, test_s21_is_not_equal_6);

  suite_add_tcase(s, tc);
  return s;
}

Suite *other_test(void) {
  Suite *s = suite_create("\033[45m-=OTHER=-\033[0m");
  TCase *tc1_1 = tcase_create("s21_decimal: ");

  suite_add_tcase(s, tc1_1);

  tcase_add_test(tc1_1, test_s21_floor_5);
  tcase_add_test(tc1_1, test_s21_floor_6);
  tcase_add_test(tc1_1, test_s21_floor_8);
  tcase_add_test(tc1_1, test_s21_floor_10);
  tcase_add_test(tc1_1, test_s21_floor_11);
  tcase_add_test(tc1_1, test_s21_floor_12);
  tcase_add_test(tc1_1, test_s21_floor_13);
  tcase_add_test(tc1_1, test_s21_floor_14);
  tcase_add_test(tc1_1, test_s21_floor_15);
  tcase_add_test(tc1_1, test_s21_floor_16);
  tcase_add_test(tc1_1, test_s21_floor_17);
  tcase_add_test(tc1_1, test_s21_floor_18);
  tcase_add_test(tc1_1, test_s21_floor_19);
  tcase_add_test(tc1_1, test_s21_floor_20);
  tcase_add_test(tc1_1, test_s21_floor_21);
  tcase_add_test(tc1_1, test_s21_floor_22);
  tcase_add_test(tc1_1, test_s21_floor_23);
  tcase_add_test(tc1_1, test_s21_floor_24);
  //  tests_round
  tcase_add_test(tc1_1, test_round_6);
  tcase_add_test(tc1_1, test_round_7);
  tcase_add_test(tc1_1, test_round_8);
  tcase_add_test(tc1_1, test_round_9);
  tcase_add_test(tc1_1, test_round_15);
  tcase_add_test(tc1_1, test_round_16);
  tcase_add_test(tc1_1, test_round_17);
  tcase_add_test(tc1_1, test_round_22);
  tcase_add_test(tc1_1, test_round_25);
  tcase_add_test(tc1_1, test_round_26);

  //  tests_negate
  tcase_add_test(tc1_1, test_s21_negate_1);
  tcase_add_test(tc1_1, test_s21_negate_2);
  tcase_add_test(tc1_1, test_s21_negate_3);
  tcase_add_test(tc1_1, test_s21_negate_4);
  tcase_add_test(tc1_1, test_s21_negate_5);
  tcase_add_test(tc1_1, test_s21_negate_6);
  tcase_add_test(tc1_1, test_s21_negate_7);
  tcase_add_test(tc1_1, test_s21_negate_8);
  tcase_add_test(tc1_1, test_s21_negate_9);
  tcase_add_test(tc1_1, test_s21_negate_10);
  tcase_add_test(tc1_1, test_s21_negate_11);
  tcase_add_test(tc1_1, test_s21_negate_12);

  //    tests_truncate
  tcase_add_test(tc1_1, test_s21_truncate_1);
  tcase_add_test(tc1_1, test_s21_truncate_2);
  tcase_add_test(tc1_1, test_s21_truncate_3);
  tcase_add_test(tc1_1, test_s21_truncate_4);
  tcase_add_test(tc1_1, test_s21_truncate_5);
  tcase_add_test(tc1_1, test_s21_truncate_6);
  tcase_add_test(tc1_1, test_s21_truncate_7);
  tcase_add_test(tc1_1, test_s21_truncate_8);
  tcase_add_test(tc1_1, test_s21_truncate_10);
  tcase_add_test(tc1_1, test_s21_truncate_13);
  return s;
}

void test_fail(Suite *s, int *fail) {
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

void suite_melaniad_operators(Suite *s, int *fail) {
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  *fail = srunner_ntests_run(sr);
  srunner_free(sr);
}

void suite_other_operators(Suite *s, int *fail) {
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  *fail = srunner_ntests_run(sr);
  srunner_free(sr);
}

int main() {
  int fail_1 = 0;
  test_fail(s21_decimal_suite(), &fail_1);
  int fail_2 = 0;
  suite_melaniad_operators(melaniad_operators(), &fail_2);
  int fail_3 = 0;
  suite_other_operators(other_test(), &fail_3);
  return 0;
}