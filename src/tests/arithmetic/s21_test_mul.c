#include "s21_test_arithmetic.h"

START_TEST(test_mul_fail1) {
  // 792281625.14264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int code = s21_mul(decimal1, decimal2, NULL);
  ck_assert_int_ne(code, S21_OK);
}
END_TEST

START_TEST(test_mul_fail2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal1 = {{0, 0, 0, 1000000000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(code, S21_OK);
}
END_TEST

START_TEST(test_mul_fail3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1D0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(code, S21_OK);
}
END_TEST

START_TEST(test_mul_fail4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal1 = {{0, 0, 0, 0x1D0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(code, S21_OK);
}
END_TEST

START_TEST(test_mul_fail5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1C0001}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(code, S21_OK);
}
END_TEST

START_TEST(test_mul_fail6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1C8000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(code, S21_OK);
}
END_TEST

START_TEST(test_mul_fail7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x11C0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(code, S21_OK);
}
END_TEST

START_TEST(test_mul_fail8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x401C0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(code, S21_OK);
}
END_TEST

START_TEST(test_mul1) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul2) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul3) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul4) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul5) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul6) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul7) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul8) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul9) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul10) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul11) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul12) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80150000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul13) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul14) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul15) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul16) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul17) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 52818775009509558395695964249
  s21_decimal check = {{0xAAAAA059, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul18) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -52818775009509558395695964249
  s21_decimal check = {{0xAAAAA059, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul19) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // 26409387504754779197847983445
  s21_decimal check = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul20) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -26409387504754779197847983445
  s21_decimal check = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul21) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // 13204693752377389598923991722
  s21_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x2AAAAAAA, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul22) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -13204693752377389598923991722
  s21_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x2AAAAAAA, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul23) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 13204693752377389598923991720
  s21_decimal check = {{0xAAAAAAA8, 0xAAAAAAAA, 0x2AAAAAAA, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul24) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -13204693752377389598923991720
  s21_decimal check = {{0xAAAAAAA8, 0xAAAAAAAA, 0x2AAAAAAA, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul25) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 13204693752377389598923991725
  s21_decimal check = {{0xAAAAAAAD, 0xAAAAAAAA, 0x2AAAAAAA, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul26) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -13204693752377389598923991725
  s21_decimal check = {{0xAAAAAAAD, 0xAAAAAAAA, 0x2AAAAAAA, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul27) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 26409387504754779197847983448
  s21_decimal check = {{0x55555558, 0x55555555, 0x55555555, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul28) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -26409387504754779197847983448
  s21_decimal check = {{0x55555558, 0x55555555, 0x55555555, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul29) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul30) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul31) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 26409387504754779197847983442
  s21_decimal check = {{0x55555552, 0x55555555, 0x55555555, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul32) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -26409387504754779197847983442
  s21_decimal check = {{0x55555552, 0x55555555, 0x55555555, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul33) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul34) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul35) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul36) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul37) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x1C0000}};
  // 20923672451288935879452631411
  s21_decimal check = {{0xADCFA173, 0x67336914, 0x439BA7FC, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul38) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x801C0000}};
  // -20923672451288935879452631411
  s21_decimal check = {{0xADCFA173, 0x67336914, 0x439BA7FC, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul39) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 792281625142643.37593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul40) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -792281625142643.37593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul41) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x100000}};
  // 66023468761886.947994619958612
  s21_decimal check = {{0x55555554, 0x55555555, 0xD5555555, 0xF0000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul42) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x80100000}};
  // -66023468761886.947994619958612
  s21_decimal check = {{0x55555554, 0x55555555, 0xD5555555, 0x800F0000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul43) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.0000000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x100000}};
  // 13204693752377.389598923991722
  s21_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x2AAAAAAA, 0xF0000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul44) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.0000000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80100000}};
  // -13204693752377.389598923991722
  s21_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x2AAAAAAA, 0x800F0000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul45) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul46) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul47) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul48) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul49) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 2.6409387504754779197847983445
  s21_decimal check = {{0x55555555, 0x55555555, 0x55555555, 0x1C0000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul50) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // -2.6409387504754779197847983445
  s21_decimal check = {{0x55555555, 0x55555555, 0x55555555, 0x801C0000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul51) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // 26.409387504754779197847983445
  s21_decimal check = {{0x55555555, 0x55555555, 0x55555555, 0x1B0000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul52) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // -26.409387504754779197847983445
  s21_decimal check = {{0x55555555, 0x55555555, 0x55555555, 0x801B0000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul53) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 400435217312910.10886274103770
  s21_decimal decimal2 = {{0x4F4FB9DA, 0xC076B0FB, 0x8163398E, 0xE0000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul54) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -400435217312910.10886274103770
  s21_decimal decimal2 = {{0x4F4FB9DA, 0xC076B0FB, 0x8163398E, 0x800E0000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul55) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -57476540395758265626.742442133
  s21_decimal decimal2 = {{0xD42B4895, 0x339BF28D, 0xB9B77ADA, 0x80090000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul56) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 57476540395758265626.742442133
  s21_decimal decimal2 = {{0xD42B4895, 0x339BF28D, 0xB9B77ADA, 0x90000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul57) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -7055.820576069728775806815669
  s21_decimal decimal2 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x80180000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul58) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 7055.820576069728775806815669
  s21_decimal decimal2 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul59) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul60) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul61) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul62) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul63) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul64) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul65) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul66) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul67) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul68) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul69) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul70) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80150000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul71) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul72) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul73) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul74) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul75) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -52818775009509558395695964249
  s21_decimal check = {{0xAAAAA059, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul76) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 52818775009509558395695964249
  s21_decimal check = {{0xAAAAA059, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul77) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // -26409387504754779197847983445
  s21_decimal check = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul78) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 26409387504754779197847983445
  s21_decimal check = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul79) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // -13204693752377389598923991722
  s21_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x2AAAAAAA, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul80) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 13204693752377389598923991722
  s21_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x2AAAAAAA, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul81) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -13204693752377389598923991720
  s21_decimal check = {{0xAAAAAAA8, 0xAAAAAAAA, 0x2AAAAAAA, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul82) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 13204693752377389598923991720
  s21_decimal check = {{0xAAAAAAA8, 0xAAAAAAAA, 0x2AAAAAAA, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul83) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -13204693752377389598923991725
  s21_decimal check = {{0xAAAAAAAD, 0xAAAAAAAA, 0x2AAAAAAA, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul84) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 13204693752377389598923991725
  s21_decimal check = {{0xAAAAAAAD, 0xAAAAAAAA, 0x2AAAAAAA, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul85) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -26409387504754779197847983448
  s21_decimal check = {{0x55555558, 0x55555555, 0x55555555, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul86) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 26409387504754779197847983448
  s21_decimal check = {{0x55555558, 0x55555555, 0x55555555, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul87) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul88) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul89) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -26409387504754779197847983442
  s21_decimal check = {{0x55555552, 0x55555555, 0x55555555, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul90) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 26409387504754779197847983442
  s21_decimal check = {{0x55555552, 0x55555555, 0x55555555, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul91) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul92) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul93) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul94) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul95) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x1C0000}};
  // -20923672451288935879452631411
  s21_decimal check = {{0xADCFA173, 0x67336914, 0x439BA7FC, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul96) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x801C0000}};
  // 20923672451288935879452631411
  s21_decimal check = {{0xADCFA173, 0x67336914, 0x439BA7FC, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul97) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 792281625142643.37593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_SMALL, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul98) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -792281625142643.37593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // overflow
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TOO_LARGE, s21_mul(decimal1, decimal2, &check));
}
END_TEST

START_TEST(test_mul99) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x100000}};
  // -66023468761886.947994619958612
  s21_decimal check = {{0x55555554, 0x55555555, 0xD5555555, 0x800F0000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_mul100) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x80100000}};
  // 66023468761886.947994619958612
  s21_decimal check = {{0x55555554, 0x55555555, 0xD5555555, 0xF0000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_mul(decimal1, decimal2, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

Suite *mul_suite(void) {
  Suite *s1 = suite_create("test_mul");
  TCase *tc = tcase_create("test_mul");
  suite_add_tcase(s1, tc);
  tcase_add_test(tc, test_mul_fail1);
  tcase_add_test(tc, test_mul_fail2);
  tcase_add_test(tc, test_mul_fail3);
  tcase_add_test(tc, test_mul_fail4);
  tcase_add_test(tc, test_mul_fail5);
  tcase_add_test(tc, test_mul_fail6);
  tcase_add_test(tc, test_mul_fail7);
  tcase_add_test(tc, test_mul_fail8);
  tcase_add_test(tc, test_mul1);
  tcase_add_test(tc, test_mul2);
  tcase_add_test(tc, test_mul3);
  tcase_add_test(tc, test_mul4);
  tcase_add_test(tc, test_mul5);
  tcase_add_test(tc, test_mul6);
  tcase_add_test(tc, test_mul7);
  tcase_add_test(tc, test_mul8);
  tcase_add_test(tc, test_mul9);
  tcase_add_test(tc, test_mul10);
  tcase_add_test(tc, test_mul11);
  tcase_add_test(tc, test_mul12);
  tcase_add_test(tc, test_mul13);
  tcase_add_test(tc, test_mul14);
  tcase_add_test(tc, test_mul15);
  tcase_add_test(tc, test_mul16);
  tcase_add_test(tc, test_mul17);
  tcase_add_test(tc, test_mul18);
  tcase_add_test(tc, test_mul19);
  tcase_add_test(tc, test_mul20);
  tcase_add_test(tc, test_mul21);
  tcase_add_test(tc, test_mul22);
  tcase_add_test(tc, test_mul23);
  tcase_add_test(tc, test_mul24);
  tcase_add_test(tc, test_mul25);
  tcase_add_test(tc, test_mul26);
  tcase_add_test(tc, test_mul27);
  tcase_add_test(tc, test_mul28);
  tcase_add_test(tc, test_mul29);
  tcase_add_test(tc, test_mul30);
  tcase_add_test(tc, test_mul31);
  tcase_add_test(tc, test_mul32);
  tcase_add_test(tc, test_mul33);
  tcase_add_test(tc, test_mul34);
  tcase_add_test(tc, test_mul35);
  tcase_add_test(tc, test_mul36);
  tcase_add_test(tc, test_mul37);
  tcase_add_test(tc, test_mul38);
  tcase_add_test(tc, test_mul39);
  tcase_add_test(tc, test_mul40);
  tcase_add_test(tc, test_mul41);
  tcase_add_test(tc, test_mul42);
  tcase_add_test(tc, test_mul43);
  tcase_add_test(tc, test_mul44);
  tcase_add_test(tc, test_mul45);
  tcase_add_test(tc, test_mul46);
  tcase_add_test(tc, test_mul47);
  tcase_add_test(tc, test_mul48);
  tcase_add_test(tc, test_mul49);
  tcase_add_test(tc, test_mul50);
  tcase_add_test(tc, test_mul51);
  tcase_add_test(tc, test_mul52);
  tcase_add_test(tc, test_mul53);
  tcase_add_test(tc, test_mul54);
  tcase_add_test(tc, test_mul55);
  tcase_add_test(tc, test_mul56);
  tcase_add_test(tc, test_mul57);
  tcase_add_test(tc, test_mul58);
  tcase_add_test(tc, test_mul59);
  tcase_add_test(tc, test_mul60);
  tcase_add_test(tc, test_mul61);
  tcase_add_test(tc, test_mul62);
  tcase_add_test(tc, test_mul63);
  tcase_add_test(tc, test_mul64);
  tcase_add_test(tc, test_mul65);
  tcase_add_test(tc, test_mul66);
  tcase_add_test(tc, test_mul67);
  tcase_add_test(tc, test_mul68);
  tcase_add_test(tc, test_mul69);
  tcase_add_test(tc, test_mul70);
  tcase_add_test(tc, test_mul71);
  tcase_add_test(tc, test_mul72);
  tcase_add_test(tc, test_mul73);
  tcase_add_test(tc, test_mul74);
  tcase_add_test(tc, test_mul75);
  tcase_add_test(tc, test_mul76);
  tcase_add_test(tc, test_mul77);
  tcase_add_test(tc, test_mul78);
  tcase_add_test(tc, test_mul79);
  tcase_add_test(tc, test_mul80);
  tcase_add_test(tc, test_mul81);
  tcase_add_test(tc, test_mul82);
  tcase_add_test(tc, test_mul83);
  tcase_add_test(tc, test_mul84);
  tcase_add_test(tc, test_mul85);
  tcase_add_test(tc, test_mul86);
  tcase_add_test(tc, test_mul87);
  tcase_add_test(tc, test_mul88);
  tcase_add_test(tc, test_mul89);
  tcase_add_test(tc, test_mul90);
  tcase_add_test(tc, test_mul91);
  tcase_add_test(tc, test_mul92);
  tcase_add_test(tc, test_mul93);
  tcase_add_test(tc, test_mul94);
  tcase_add_test(tc, test_mul95);
  tcase_add_test(tc, test_mul96);
  tcase_add_test(tc, test_mul97);
  tcase_add_test(tc, test_mul98);
  tcase_add_test(tc, test_mul99);
  tcase_add_test(tc, test_mul100);
  return s1;
}