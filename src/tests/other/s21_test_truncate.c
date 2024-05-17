#include "s21_test_other.h"

START_TEST(test_truncate_fail1) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  ck_assert_int_eq(S21_ERROR, s21_truncate(decimal, NULL));
}
END_TEST

START_TEST(test_truncate_fail2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal = {{0, 0, 0, 1000000000}};
  s21_decimal check;
  ck_assert_int_eq(S21_ERROR, s21_truncate(decimal, &check));
}
END_TEST

START_TEST(test_truncate_fail3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{-1, 0, 0, 0x1D0000}};
  s21_decimal check;
  ck_assert_int_eq(S21_ERROR, s21_truncate(decimal, &check));
}
END_TEST

START_TEST(test_truncate_fail4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{0, 0, 0, 0x1D0000}};
  s21_decimal check;
  ck_assert_int_eq(S21_ERROR, s21_truncate(decimal, &check));
}
END_TEST

START_TEST(test_truncate_fail5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C0001}};
  s21_decimal check;
  ck_assert_int_eq(S21_ERROR, s21_truncate(decimal, &check));
}
END_TEST

START_TEST(test_truncate_fail6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C8000}};
  s21_decimal check;
  ck_assert_int_eq(S21_ERROR, s21_truncate(decimal, &check));
}
END_TEST

START_TEST(test_truncate_fail7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x11C0000}};
  s21_decimal check;
  ck_assert_int_eq(S21_ERROR, s21_truncate(decimal, &check));
}
END_TEST

START_TEST(test_truncate_fail8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x401C0000}};
  s21_decimal check;
  ck_assert_int_eq(S21_ERROR, s21_truncate(decimal, &check));
}
END_TEST

START_TEST(test_truncate1) {
  // 79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate2) {
  // -79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate3) {
  // 7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395033
  s21_decimal check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate4) {
  // -7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -7922816251426433759354395033
  s21_decimal check = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate5) {
  // 792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  // 792281625142643375935439503
  s21_decimal check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate6) {
  // -792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  // -792281625142643375935439503
  s21_decimal check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate7) {
  // 79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  // 79228162514264337593543950
  s21_decimal check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate8) {
  // -79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  // -79228162514264337593543950
  s21_decimal check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate9) {
  // 7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  // 7922816251426433759354395
  s21_decimal check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate10) {
  // -7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  // -7922816251426433759354395
  s21_decimal check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate11) {
  // 792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  // 792281625142643375935439
  s21_decimal check = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate12) {
  // -792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  // -792281625142643375935439
  s21_decimal check = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate13) {
  // 79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  // 79228162514264337593543
  s21_decimal check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate14) {
  // -79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  // -79228162514264337593543
  s21_decimal check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate15) {
  // 7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  // 7922816251426433759354
  s21_decimal check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate16) {
  // -7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  // -7922816251426433759354
  s21_decimal check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate17) {
  // 792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  // 792281625142643375935
  s21_decimal check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate18) {
  // -792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  // -792281625142643375935
  s21_decimal check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate19) {
  // 79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  // 79228162514264337593
  s21_decimal check = {{0xB5A52CB9, 0x4B82FA09, 0x4, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate20) {
  // -79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  // -79228162514264337593
  s21_decimal check = {{0xB5A52CB9, 0x4B82FA09, 0x4, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate21) {
  // 7922816251426433759.3543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};
  // 7922816251426433759
  s21_decimal check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate22) {
  // -7922816251426433759.3543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};
  // -7922816251426433759
  s21_decimal check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate23) {
  // 792281625142643375.93543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};
  // 792281625142643375
  s21_decimal check = {{0xBCB24AAF, 0xAFEBFF0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate24) {
  // -792281625142643375.93543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};
  // -792281625142643375
  s21_decimal check = {{0xBCB24AAF, 0xAFEBFF0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate25) {
  // 79228162514264337.593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};
  // 79228162514264337
  s21_decimal check = {{0x12DEA111, 0x1197998, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate26) {
  // -79228162514264337.593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};
  // -79228162514264337
  s21_decimal check = {{0x12DEA111, 0x1197998, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate27) {
  // 7922816251426433.7593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};
  // 7922816251426433
  s21_decimal check = {{0x68497681, 0x1C25C2, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate28) {
  // -7922816251426433.7593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};
  // -7922816251426433
  s21_decimal check = {{0x68497681, 0x1C25C2, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate29) {
  // 792281625142643.37593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // 792281625142643
  s21_decimal check = {{0x70D42573, 0x2D093, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate30) {
  // -792281625142643.37593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // -792281625142643
  s21_decimal check = {{0x70D42573, 0x2D093, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate31) {
  // 79228162514264.337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};
  // 79228162514264
  s21_decimal check = {{0xBE7B9D58, 0x480E, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate32) {
  // -79228162514264.337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  // -79228162514264
  s21_decimal check = {{0xBE7B9D58, 0x480E, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate33) {
  // 7922816251426.4337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};
  // 7922816251426
  s21_decimal check = {{0xACA5F622, 0x734, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate34) {
  // -7922816251426.4337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  // -7922816251426
  s21_decimal check = {{0xACA5F622, 0x734, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate35) {
  // 792281625142.64337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};
  // 792281625142
  s21_decimal check = {{0x77AA3236, 0xB8, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate36) {
  // -792281625142.64337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};
  // -792281625142
  s21_decimal check = {{0x77AA3236, 0xB8, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate37) {
  // 79228162514.264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};
  // 79228162514
  s21_decimal check = {{0x725DD1D2, 0x12, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate38) {
  // -79228162514.264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};
  // -79228162514
  s21_decimal check = {{0x725DD1D2, 0x12, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate39) {
  // 7922816251.4264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};
  // 7922816251
  s21_decimal check = {{0xD83C94FB, 0x1, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate40) {
  // -7922816251.4264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};
  // -7922816251
  s21_decimal check = {{0xD83C94FB, 0x1, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate41) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  // 792281625
  s21_decimal check = {{0x2F394219, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate42) {
  // -792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  // -792281625
  s21_decimal check = {{0x2F394219, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate43) {
  // 79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  // 79228162
  s21_decimal check = {{0x4B8ED02, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate44) {
  // -79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  // -79228162
  s21_decimal check = {{0x4B8ED02, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate45) {
  // 7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  // 7922816
  s21_decimal check = {{0x78E480, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate46) {
  // -7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  // -7922816
  s21_decimal check = {{0x78E480, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate47) {
  // 792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  // 792281
  s21_decimal check = {{0xC16D9, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate48) {
  // -792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  // -792281
  s21_decimal check = {{0xC16D9, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate49) {
  // 79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  // 79228
  s21_decimal check = {{0x1357C, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate50) {
  // -79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  // -79228
  s21_decimal check = {{0x1357C, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate51) {
  // 7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  // 7922
  s21_decimal check = {{0x1EF2, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate52) {
  // -7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  // -7922
  s21_decimal check = {{0x1EF2, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate53) {
  // 792.28162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  // 792
  s21_decimal check = {{0x318, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate54) {
  // -792.28162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  // -792
  s21_decimal check = {{0x318, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate55) {
  // 79.228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  // 79
  s21_decimal check = {{0x4F, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate56) {
  // -79.228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  // -79
  s21_decimal check = {{0x4F, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate57) {
  // 7.9228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 7
  s21_decimal check = {{0x7, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate58) {
  // -7.9228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -7
  s21_decimal check = {{0x7, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate59) {
  // 79228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate60) {
  // -79228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate61) {
  // 7922816251426433759354395033.4
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395033
  s21_decimal check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate62) {
  // -7922816251426433759354395033.4
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -7922816251426433759354395033
  s21_decimal check = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate63) {
  // 792281625142643375935439503.34
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  // 792281625142643375935439503
  s21_decimal check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate64) {
  // -792281625142643375935439503.34
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  // -792281625142643375935439503
  s21_decimal check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate65) {
  // 79228162514264337593543950.334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  // 79228162514264337593543950
  s21_decimal check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate66) {
  // -79228162514264337593543950.334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  // -79228162514264337593543950
  s21_decimal check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate67) {
  // 7922816251426433759354395.0334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  // 7922816251426433759354395
  s21_decimal check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate68) {
  // -7922816251426433759354395.0334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  // -7922816251426433759354395
  s21_decimal check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate69) {
  // 792281625142643375935439.50334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  // 792281625142643375935439
  s21_decimal check = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate70) {
  // -792281625142643375935439.50334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  // -792281625142643375935439
  s21_decimal check = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate71) {
  // 79228162514264337593543.950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  // 79228162514264337593543
  s21_decimal check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate72) {
  // -79228162514264337593543.950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  // -79228162514264337593543
  s21_decimal check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate73) {
  // 7922816251426433759354.3950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  // 7922816251426433759354
  s21_decimal check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate74) {
  // -7922816251426433759354.3950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  // -7922816251426433759354
  s21_decimal check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate75) {
  // 792281625142643375935.43950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  // 792281625142643375935
  s21_decimal check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate76) {
  // -792281625142643375935.43950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  // -792281625142643375935
  s21_decimal check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate77) {
  // 79228162514264337593.543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  // 79228162514264337593
  s21_decimal check = {{0xB5A52CB9, 0x4B82FA09, 0x4, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate78) {
  // -79228162514264337593.543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  // -79228162514264337593
  s21_decimal check = {{0xB5A52CB9, 0x4B82FA09, 0x4, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate79) {
  // 7922816251426433759.3543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};
  // 7922816251426433759
  s21_decimal check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate80) {
  // -7922816251426433759.3543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};
  // -7922816251426433759
  s21_decimal check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate81) {
  // 792281625142643375.93543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};
  // 792281625142643375
  s21_decimal check = {{0xBCB24AAF, 0xAFEBFF0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate82) {
  // -792281625142643375.93543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};
  // -792281625142643375
  s21_decimal check = {{0xBCB24AAF, 0xAFEBFF0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate83) {
  // 79228162514264337.593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};
  // 79228162514264337
  s21_decimal check = {{0x12DEA111, 0x1197998, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate84) {
  // -79228162514264337.593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};
  // -79228162514264337
  s21_decimal check = {{0x12DEA111, 0x1197998, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate85) {
  // 7922816251426433.7593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};
  // 7922816251426433
  s21_decimal check = {{0x68497681, 0x1C25C2, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate86) {
  // -7922816251426433.7593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};
  // -7922816251426433
  s21_decimal check = {{0x68497681, 0x1C25C2, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate87) {
  // 792281625142643.37593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // 792281625142643
  s21_decimal check = {{0x70D42573, 0x2D093, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate88) {
  // -792281625142643.37593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // -792281625142643
  s21_decimal check = {{0x70D42573, 0x2D093, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate89) {
  // 79228162514264.337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};
  // 79228162514264
  s21_decimal check = {{0xBE7B9D58, 0x480E, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate90) {
  // -79228162514264.337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  // -79228162514264
  s21_decimal check = {{0xBE7B9D58, 0x480E, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate91) {
  // 7922816251426.4337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};
  // 7922816251426
  s21_decimal check = {{0xACA5F622, 0x734, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate92) {
  // -7922816251426.4337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  // -7922816251426
  s21_decimal check = {{0xACA5F622, 0x734, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate93) {
  // 792281625142.64337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};
  // 792281625142
  s21_decimal check = {{0x77AA3236, 0xB8, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate94) {
  // -792281625142.64337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};
  // -792281625142
  s21_decimal check = {{0x77AA3236, 0xB8, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate95) {
  // 79228162514.264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};
  // 79228162514
  s21_decimal check = {{0x725DD1D2, 0x12, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate96) {
  // -79228162514.264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};
  // -79228162514
  s21_decimal check = {{0x725DD1D2, 0x12, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate97) {
  // 7922816251.4264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};
  // 7922816251
  s21_decimal check = {{0xD83C94FB, 0x1, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate98) {
  // -7922816251.4264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};
  // -7922816251
  s21_decimal check = {{0xD83C94FB, 0x1, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate99) {
  // 792281625.14264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  // 792281625
  s21_decimal check = {{0x2F394219, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_truncate100) {
  // -792281625.14264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  // -792281625
  s21_decimal check = {{0x2F394219, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_truncate(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

Suite *truncate_suite(void) {
  Suite *s1 = suite_create("test_truncate");
  TCase *tc = tcase_create("test_truncate");
  suite_add_tcase(s1, tc);
  tcase_add_test(tc, test_truncate_fail1);
  tcase_add_test(tc, test_truncate_fail2);
  tcase_add_test(tc, test_truncate_fail3);
  tcase_add_test(tc, test_truncate_fail4);
  tcase_add_test(tc, test_truncate_fail5);
  tcase_add_test(tc, test_truncate_fail6);
  tcase_add_test(tc, test_truncate_fail7);
  tcase_add_test(tc, test_truncate_fail8);
  tcase_add_test(tc, test_truncate1);
  tcase_add_test(tc, test_truncate2);
  tcase_add_test(tc, test_truncate3);
  tcase_add_test(tc, test_truncate4);
  tcase_add_test(tc, test_truncate5);
  tcase_add_test(tc, test_truncate6);
  tcase_add_test(tc, test_truncate7);
  tcase_add_test(tc, test_truncate8);
  tcase_add_test(tc, test_truncate9);
  tcase_add_test(tc, test_truncate10);
  tcase_add_test(tc, test_truncate11);
  tcase_add_test(tc, test_truncate12);
  tcase_add_test(tc, test_truncate13);
  tcase_add_test(tc, test_truncate14);
  tcase_add_test(tc, test_truncate15);
  tcase_add_test(tc, test_truncate16);
  tcase_add_test(tc, test_truncate17);
  tcase_add_test(tc, test_truncate18);
  tcase_add_test(tc, test_truncate19);
  tcase_add_test(tc, test_truncate20);
  tcase_add_test(tc, test_truncate21);
  tcase_add_test(tc, test_truncate22);
  tcase_add_test(tc, test_truncate23);
  tcase_add_test(tc, test_truncate24);
  tcase_add_test(tc, test_truncate25);
  tcase_add_test(tc, test_truncate26);
  tcase_add_test(tc, test_truncate27);
  tcase_add_test(tc, test_truncate28);
  tcase_add_test(tc, test_truncate29);
  tcase_add_test(tc, test_truncate30);
  tcase_add_test(tc, test_truncate31);
  tcase_add_test(tc, test_truncate32);
  tcase_add_test(tc, test_truncate33);
  tcase_add_test(tc, test_truncate34);
  tcase_add_test(tc, test_truncate35);
  tcase_add_test(tc, test_truncate36);
  tcase_add_test(tc, test_truncate37);
  tcase_add_test(tc, test_truncate38);
  tcase_add_test(tc, test_truncate39);
  tcase_add_test(tc, test_truncate40);
  tcase_add_test(tc, test_truncate41);
  tcase_add_test(tc, test_truncate42);
  tcase_add_test(tc, test_truncate43);
  tcase_add_test(tc, test_truncate44);
  tcase_add_test(tc, test_truncate45);
  tcase_add_test(tc, test_truncate46);
  tcase_add_test(tc, test_truncate47);
  tcase_add_test(tc, test_truncate48);
  tcase_add_test(tc, test_truncate49);
  tcase_add_test(tc, test_truncate50);
  tcase_add_test(tc, test_truncate51);
  tcase_add_test(tc, test_truncate52);
  tcase_add_test(tc, test_truncate53);
  tcase_add_test(tc, test_truncate54);
  tcase_add_test(tc, test_truncate55);
  tcase_add_test(tc, test_truncate56);
  tcase_add_test(tc, test_truncate57);
  tcase_add_test(tc, test_truncate58);
  tcase_add_test(tc, test_truncate59);
  tcase_add_test(tc, test_truncate60);
  tcase_add_test(tc, test_truncate61);
  tcase_add_test(tc, test_truncate62);
  tcase_add_test(tc, test_truncate63);
  tcase_add_test(tc, test_truncate64);
  tcase_add_test(tc, test_truncate65);
  tcase_add_test(tc, test_truncate66);
  tcase_add_test(tc, test_truncate67);
  tcase_add_test(tc, test_truncate68);
  tcase_add_test(tc, test_truncate69);
  tcase_add_test(tc, test_truncate70);
  tcase_add_test(tc, test_truncate71);
  tcase_add_test(tc, test_truncate72);
  tcase_add_test(tc, test_truncate73);
  tcase_add_test(tc, test_truncate74);
  tcase_add_test(tc, test_truncate75);
  tcase_add_test(tc, test_truncate76);
  tcase_add_test(tc, test_truncate77);
  tcase_add_test(tc, test_truncate78);
  tcase_add_test(tc, test_truncate79);
  tcase_add_test(tc, test_truncate80);
  tcase_add_test(tc, test_truncate81);
  tcase_add_test(tc, test_truncate82);
  tcase_add_test(tc, test_truncate83);
  tcase_add_test(tc, test_truncate84);
  tcase_add_test(tc, test_truncate85);
  tcase_add_test(tc, test_truncate86);
  tcase_add_test(tc, test_truncate87);
  tcase_add_test(tc, test_truncate88);
  tcase_add_test(tc, test_truncate89);
  tcase_add_test(tc, test_truncate90);
  tcase_add_test(tc, test_truncate91);
  tcase_add_test(tc, test_truncate92);
  tcase_add_test(tc, test_truncate93);
  tcase_add_test(tc, test_truncate94);
  tcase_add_test(tc, test_truncate95);
  tcase_add_test(tc, test_truncate96);
  tcase_add_test(tc, test_truncate97);
  tcase_add_test(tc, test_truncate98);
  tcase_add_test(tc, test_truncate99);
  tcase_add_test(tc, test_truncate100);
  return s1;
}