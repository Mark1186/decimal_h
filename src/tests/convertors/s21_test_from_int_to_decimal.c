#include "s21_test_convertors.h"

START_TEST(test_from_int_to_decimal_fail1) {
  int number = -2147483648;
  ck_assert_int_eq(s21_from_int_to_decimal(number, NULL), S21_ERROR);
}
END_TEST

START_TEST(test_from_int_to_decimal1) {
  int number = -2147483648;
  // Converted the Int32 value -2147483648 to the Decimal value -2147483648.
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = decimal;
  s21_decimal dfdf;
  ck_assert_int_eq(S21_OK, s21_from_int_to_decimal(number, &dfdf));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, decimal));
}
END_TEST

START_TEST(test_from_int_to_decimal2) {
  int number = -2147483647;
  // Converted the Int32 value -2147483647 to the Decimal value -2147483647.
  s21_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = decimal;
  ck_assert_int_eq(S21_OK, s21_from_int_to_decimal(number, &decimal));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, decimal));
}
END_TEST

START_TEST(test_from_int_to_decimal3) {
  int number = -214748364;
  // Converted the Int32 value -214748364 to the Decimal value -214748364.
  s21_decimal decimal = {{0xCCCCCCC, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = decimal;
  ck_assert_int_eq(S21_OK, s21_from_int_to_decimal(number, &decimal));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, decimal));
}
END_TEST

START_TEST(test_from_int_to_decimal4) {
  int number = -214748;
  // Converted the Int32 value -214748 to the Decimal value -214748.
  s21_decimal decimal = {{0x346DC, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = decimal;
  ck_assert_int_eq(S21_OK, s21_from_int_to_decimal(number, &decimal));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, decimal));
}
END_TEST

START_TEST(test_from_int_to_decimal5) {
  int number = -1000;
  // Converted the Int32 value -1000 to the Decimal value -1000.
  s21_decimal decimal = {{0x3E8, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = decimal;
  ck_assert_int_eq(S21_OK, s21_from_int_to_decimal(number, &decimal));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, decimal));
}
END_TEST

START_TEST(test_from_int_to_decimal6) {
  int number = -1;
  // Converted the Int32 value -1 to the Decimal value -1.
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = decimal;
  ck_assert_int_eq(S21_OK, s21_from_int_to_decimal(number, &decimal));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, decimal));
}
END_TEST

START_TEST(test_from_int_to_decimal7) {
  int number = 0;
  // Converted the Int32 value 0 to the Decimal value 0.
  s21_decimal decimal = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal expected = decimal;
  ck_assert_int_eq(S21_OK, s21_from_int_to_decimal(number, &decimal));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, decimal));
}
END_TEST

START_TEST(test_from_int_to_decimal8) {
  int number = 1;
  // Converted the Int32 value 1 to the Decimal value 1.
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal expected = decimal;
  ck_assert_int_eq(S21_OK, s21_from_int_to_decimal(number, &decimal));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, decimal));
}
END_TEST

START_TEST(test_from_int_to_decimal9) {
  int number = 1000;
  // Converted the Int32 value 1000 to the Decimal value 1000.
  s21_decimal decimal = {{0x3E8, 0x0, 0x0, 0x0}};
  s21_decimal expected = decimal;
  ck_assert_int_eq(S21_OK, s21_from_int_to_decimal(number, &decimal));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, decimal));
}
END_TEST

START_TEST(test_from_int_to_decimal10) {
  int number = 214748;
  // Converted the Int32 value 214748 to the Decimal value 214748.
  s21_decimal decimal = {{0x346DC, 0x0, 0x0, 0x0}};
  s21_decimal expected = decimal;
  ck_assert_int_eq(S21_OK, s21_from_int_to_decimal(number, &decimal));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, decimal));
}
END_TEST

START_TEST(test_from_int_to_decimal11) {
  int number = 214748364;
  // Converted the Int32 value 214748364 to the Decimal value 214748364.
  s21_decimal decimal = {{0xCCCCCCC, 0x0, 0x0, 0x0}};
  s21_decimal expected = decimal;
  ck_assert_int_eq(S21_OK, s21_from_int_to_decimal(number, &decimal));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, decimal));
}
END_TEST

START_TEST(test_from_int_to_decimal12) {
  int number = 2147483646;
  // Converted the Int32 value 2147483646 to the Decimal value 2147483646.
  s21_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x0}};
  s21_decimal expected = decimal;
  ck_assert_int_eq(S21_OK, s21_from_int_to_decimal(number, &decimal));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, decimal));
}
END_TEST

START_TEST(test_from_int_to_decimal13) {
  int number = 2147483647;
  // Converted the Int32 value 2147483647 to the Decimal value 2147483647.
  s21_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};
  s21_decimal expected = decimal;
  ck_assert_int_eq(S21_OK, s21_from_int_to_decimal(number, &decimal));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, decimal));
}
END_TEST

Suite *from_int_to_decimal_suite(void) {
  Suite *s1 = suite_create("test_from_int_to_decimal");
  TCase *tc = tcase_create("test_from_int_to_decimal");
  suite_add_tcase(s1, tc);
  tcase_add_test(tc, test_from_int_to_decimal_fail1);
  tcase_add_test(tc, test_from_int_to_decimal1);
  tcase_add_test(tc, test_from_int_to_decimal2);
  tcase_add_test(tc, test_from_int_to_decimal3);
  tcase_add_test(tc, test_from_int_to_decimal4);
  tcase_add_test(tc, test_from_int_to_decimal5);
  tcase_add_test(tc, test_from_int_to_decimal6);
  tcase_add_test(tc, test_from_int_to_decimal7);
  tcase_add_test(tc, test_from_int_to_decimal8);
  tcase_add_test(tc, test_from_int_to_decimal9);
  tcase_add_test(tc, test_from_int_to_decimal10);
  tcase_add_test(tc, test_from_int_to_decimal11);
  tcase_add_test(tc, test_from_int_to_decimal12);
  tcase_add_test(tc, test_from_int_to_decimal13);
  return s1;
}