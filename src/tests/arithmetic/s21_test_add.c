#include "s21_test_arithmetic.h"

START_TEST(test_add_fail1) {
  // 792281625.14264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int code = s21_add(decimal1, decimal2, NULL);
  ck_assert_int_ne(code, S21_OK);
}
END_TEST

START_TEST(test_add_fail2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal1 = {{0, 0, 0, 1000000000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  ck_assert_int_ne(s21_add(decimal1, decimal2, &result), S21_OK);
}
END_TEST

START_TEST(test_add_fail3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1D0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  ck_assert_int_ne(s21_add(decimal1, decimal2, &result), S21_OK);
}
END_TEST

START_TEST(test_add_fail4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal1 = {{0, 0, 0, 0x1D0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  ck_assert_int_ne(s21_add(decimal1, decimal2, &result), S21_OK);
}
END_TEST

START_TEST(test_add_fail5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1C0001}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  ck_assert_int_ne(s21_add(decimal1, decimal2, &result), S21_OK);
}
END_TEST

START_TEST(test_add_fail6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1C8000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  ck_assert_int_ne(s21_add(decimal1, decimal2, &result), S21_OK);
}
END_TEST

START_TEST(test_add_fail7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x11C0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  ck_assert_int_ne(s21_add(decimal1, decimal2, &result), S21_OK);
}
END_TEST

START_TEST(test_add_fail8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x401C0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  ck_assert_int_ne(s21_add(decimal1, decimal2, &result), S21_OK);
}
END_TEST

START_TEST(test_add1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add3) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add4) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  s21_decimal check = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add5) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add6) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 71305346262837903834189555302
  s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add7) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add8) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 71305346262837903834189555302
  s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add9) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add10) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // 71305346262837903834189555301
  s21_decimal check = {{0x66666665, 0x66666666, 0xE6666666, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add11) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add12) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // 71305346262837903834189555300
  s21_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add13) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add14) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add15) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add16) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add17) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add18) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add19) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add20) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add21) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add22) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 79228162514264337593543950333
  s21_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add23) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add24) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add25) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add26) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 52818775009509558395695966890
  s21_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add27) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add28) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 52818775015658473085500828330
  s21_decimal check = {{0xAAAAAAAA, 0xFFFFFFFF, 0xAAAAAAAA, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add29) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add30) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 79228162508115422902307433130
  s21_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add31) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add32) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // 79228162508115422903739088895
  s21_decimal check = {{0xFFFFFFFF, 0xAAAAAAAA, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add33) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add34) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // 79228162514264337592112294570
  s21_decimal check = {{0xAAAAAAAA, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add35) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387.704754779197847983445
  s21_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x150000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add36) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387.704754779197847983445
  s21_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x80150000}};
  // 79228162514264337593517540947
  s21_decimal check = {{0xFE6D0653, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add37) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add38) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // 79228162514264337593517540948
  s21_decimal check = {{0xFE6D0654, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add39) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add40) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593517540948
  s21_decimal check = {{0xFE6D0654, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add41) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add42) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 79228162514264337593543950327
  s21_decimal check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add43) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add44) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950327
  s21_decimal check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add45) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add46) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x80100000}};
  // 79228162514264337593543950331
  s21_decimal check = {{0xFFFFFFFB, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add47) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add48) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add49) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add50) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add51) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add52) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add53) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add54) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add55) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -56124981125209321576924.010631
  s21_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x80060000}};
  // 79228106389283212384222373411
  s21_decimal check = {{0x3AC4E623, 0x756BD584, 0xFFFFF41D, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add56) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 56124981125209321576924.010631
  s21_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x60000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add57) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -49704001422.391670881925172831
  s21_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x80120000}};
  // 79228162514264337543839948913
  s21_decimal check = {{0x6D692071, 0xFFFFFFF4, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add58) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 49704001422.391670881925172831
  s21_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add59) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -649244002.20841517182548587502
  s21_decimal decimal2 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 79228162514264337592894706333
  s21_decimal check = {{0xD94D529D, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add60) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 649244002.20841517182548587502
  s21_decimal decimal2 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add61) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add62) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add63) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  s21_decimal check = {{0x1, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add64) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add65) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -71305346262837903834189555302
  s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add66) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add67) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -71305346262837903834189555302
  s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add68) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add69) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // -71305346262837903834189555301
  s21_decimal check = {{0x66666665, 0x66666666, 0xE6666666, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add70) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add71) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // -71305346262837903834189555300
  s21_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add72) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add73) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add74) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add75) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add76) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add77) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add78) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add79) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add80) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add81) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -79228162514264337593543950333
  s21_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add82) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add83) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add84) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add85) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -52818775009509558395695966890
  s21_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add86) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add87) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -52818775015658473085500828330
  s21_decimal check = {{0xAAAAAAAA, 0xFFFFFFFF, 0xAAAAAAAA, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add88) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add89) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -79228162508115422902307433130
  s21_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xFFFFFFFF, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add90) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add91) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -79228162508115422903739088895
  s21_decimal check = {{0xFFFFFFFF, 0xAAAAAAAA, 0xFFFFFFFF, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add92) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add93) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // -79228162514264337592112294570
  s21_decimal check = {{0xAAAAAAAA, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add94) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add95) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387.704754779197847983445
  s21_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x150000}};
  // -79228162514264337593517540947
  s21_decimal check = {{0xFE6D0653, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add96) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387.704754779197847983445
  s21_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x80150000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add97) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // -79228162514264337593517540948
  s21_decimal check = {{0xFE6D0654, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add98) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_add(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_add99) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // -79228162514264337593517540948
  s21_decimal check = {{0xFE6D0654, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_add(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_add100) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_add(decimal1, decimal2, &check));
}
END_TEST

Suite *add_suite(void) {
  Suite *s1 = suite_create("test_add");
  TCase *tc = tcase_create("test_add");
  suite_add_tcase(s1, tc);
  tcase_add_test(tc, test_add_fail1);
  tcase_add_test(tc, test_add_fail2);
  tcase_add_test(tc, test_add_fail3);
  tcase_add_test(tc, test_add_fail4);
  tcase_add_test(tc, test_add_fail5);
  tcase_add_test(tc, test_add_fail6);
  tcase_add_test(tc, test_add_fail7);
  tcase_add_test(tc, test_add_fail8);
  tcase_add_test(tc, test_add1);
  tcase_add_test(tc, test_add2);
  tcase_add_test(tc, test_add3);
  tcase_add_test(tc, test_add4);
  tcase_add_test(tc, test_add5);
  tcase_add_test(tc, test_add6);
  tcase_add_test(tc, test_add7);
  tcase_add_test(tc, test_add8);
  tcase_add_test(tc, test_add9);
  tcase_add_test(tc, test_add10);
  tcase_add_test(tc, test_add11);
  tcase_add_test(tc, test_add12);
  tcase_add_test(tc, test_add13);
  tcase_add_test(tc, test_add14);
  tcase_add_test(tc, test_add15);
  tcase_add_test(tc, test_add16);
  tcase_add_test(tc, test_add17);
  tcase_add_test(tc, test_add18);
  tcase_add_test(tc, test_add19);
  tcase_add_test(tc, test_add20);
  tcase_add_test(tc, test_add21);
  tcase_add_test(tc, test_add22);
  tcase_add_test(tc, test_add23);
  tcase_add_test(tc, test_add24);
  tcase_add_test(tc, test_add25);
  tcase_add_test(tc, test_add26);
  tcase_add_test(tc, test_add27);
  tcase_add_test(tc, test_add28);
  tcase_add_test(tc, test_add29);
  tcase_add_test(tc, test_add30);
  tcase_add_test(tc, test_add31);
  tcase_add_test(tc, test_add32);
  tcase_add_test(tc, test_add33);
  tcase_add_test(tc, test_add34);
  tcase_add_test(tc, test_add35);
  tcase_add_test(tc, test_add36);
  tcase_add_test(tc, test_add37);
  tcase_add_test(tc, test_add38);
  tcase_add_test(tc, test_add39);
  tcase_add_test(tc, test_add40);
  tcase_add_test(tc, test_add41);
  tcase_add_test(tc, test_add42);
  tcase_add_test(tc, test_add43);
  tcase_add_test(tc, test_add44);
  tcase_add_test(tc, test_add45);
  tcase_add_test(tc, test_add46);
  tcase_add_test(tc, test_add47);
  tcase_add_test(tc, test_add48);
  tcase_add_test(tc, test_add49);
  tcase_add_test(tc, test_add50);
  tcase_add_test(tc, test_add51);
  tcase_add_test(tc, test_add52);
  tcase_add_test(tc, test_add53);
  tcase_add_test(tc, test_add54);
  tcase_add_test(tc, test_add55);
  tcase_add_test(tc, test_add56);
  tcase_add_test(tc, test_add57);
  tcase_add_test(tc, test_add58);
  tcase_add_test(tc, test_add59);
  tcase_add_test(tc, test_add60);
  tcase_add_test(tc, test_add61);
  tcase_add_test(tc, test_add62);
  tcase_add_test(tc, test_add63);
  tcase_add_test(tc, test_add64);
  tcase_add_test(tc, test_add65);
  tcase_add_test(tc, test_add66);
  tcase_add_test(tc, test_add67);
  tcase_add_test(tc, test_add68);
  tcase_add_test(tc, test_add69);
  tcase_add_test(tc, test_add70);
  tcase_add_test(tc, test_add71);
  tcase_add_test(tc, test_add72);
  tcase_add_test(tc, test_add73);
  tcase_add_test(tc, test_add74);
  tcase_add_test(tc, test_add75);
  tcase_add_test(tc, test_add76);
  tcase_add_test(tc, test_add77);
  tcase_add_test(tc, test_add78);
  tcase_add_test(tc, test_add79);
  tcase_add_test(tc, test_add80);
  tcase_add_test(tc, test_add81);
  tcase_add_test(tc, test_add82);
  tcase_add_test(tc, test_add83);
  tcase_add_test(tc, test_add84);
  tcase_add_test(tc, test_add85);
  tcase_add_test(tc, test_add86);
  tcase_add_test(tc, test_add87);
  tcase_add_test(tc, test_add88);
  tcase_add_test(tc, test_add89);
  tcase_add_test(tc, test_add90);
  tcase_add_test(tc, test_add91);
  tcase_add_test(tc, test_add92);
  tcase_add_test(tc, test_add93);
  tcase_add_test(tc, test_add94);
  tcase_add_test(tc, test_add95);
  tcase_add_test(tc, test_add96);
  tcase_add_test(tc, test_add97);
  tcase_add_test(tc, test_add98);
  tcase_add_test(tc, test_add99);
  tcase_add_test(tc, test_add100);
  return s1;
}