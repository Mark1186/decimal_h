#include "s21_test_other.h"

START_TEST(test_round_fail1) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  ck_assert_int_eq(S21_ERROR, s21_round(decimal, NULL));
}
END_TEST

START_TEST(test_round_fail2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal = {{0, 0, 0, 1000000000}};
  s21_decimal check;
  ck_assert_int_eq(S21_ERROR, s21_round(decimal, &check));
}
END_TEST

START_TEST(test_round_fail3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{-1, 0, 0, 0x1D0000}};
  s21_decimal check;
  ck_assert_int_eq(S21_ERROR, s21_round(decimal, &check));
}
END_TEST

START_TEST(test_round_fail4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{0, 0, 0, 0x1D0000}};
  s21_decimal check;
  ck_assert_int_eq(S21_ERROR, s21_round(decimal, &check));
}
END_TEST

START_TEST(test_round_fail5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C0001}};
  s21_decimal check;
  ck_assert_int_eq(S21_ERROR, s21_round(decimal, &check));
}
END_TEST

START_TEST(test_round_fail6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C8000}};
  s21_decimal check;
  ck_assert_int_eq(S21_ERROR, s21_round(decimal, &check));
}
END_TEST

START_TEST(test_round_fail7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x11C0000}};
  s21_decimal check;
  ck_assert_int_eq(S21_ERROR, s21_round(decimal, &check));
}
END_TEST

START_TEST(test_round_fail8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x401C0000}};
  s21_decimal check;
  ck_assert_int_eq(S21_ERROR, s21_round(decimal, &check));
}
END_TEST

START_TEST(test_round1) {
  // 79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round2) {
  // -79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round3) {
  // 7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395034
  s21_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round4) {
  // -7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -7922816251426433759354395034
  s21_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round5) {
  // 792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  // 792281625142643375935439503
  s21_decimal check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round6) {
  // -792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  // -792281625142643375935439503
  s21_decimal check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round7) {
  // 79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  // 79228162514264337593543950
  s21_decimal check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round8) {
  // -79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  // -79228162514264337593543950
  s21_decimal check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round9) {
  // 7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  // 7922816251426433759354395
  s21_decimal check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round10) {
  // -7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  // -7922816251426433759354395
  s21_decimal check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round11) {
  // 792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  // 792281625142643375935440
  s21_decimal check = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round12) {
  // -792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  // -792281625142643375935440
  s21_decimal check = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round13) {
  // 79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  // 79228162514264337593544
  s21_decimal check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round14) {
  // -79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  // -79228162514264337593544
  s21_decimal check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round15) {
  // 7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  // 7922816251426433759354
  s21_decimal check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round16) {
  // -7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  // -7922816251426433759354
  s21_decimal check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round17) {
  // 792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  // 792281625142643375935
  s21_decimal check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round18) {
  // -792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  // -792281625142643375935
  s21_decimal check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round19) {
  // 79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  // 79228162514264337594
  s21_decimal check = {{0xB5A52CBA, 0x4B82FA09, 0x4, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round20) {
  // -79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  // -79228162514264337594
  s21_decimal check = {{0xB5A52CBA, 0x4B82FA09, 0x4, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round21) {
  // 7922816251426433759.3543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};
  // 7922816251426433759
  s21_decimal check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round22) {
  // -7922816251426433759.3543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};
  // -7922816251426433759
  s21_decimal check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round23) {
  // 792281625142643375.93543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};
  // 792281625142643376
  s21_decimal check = {{0xBCB24AB0, 0xAFEBFF0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round24) {
  // -792281625142643375.93543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};
  // -792281625142643376
  s21_decimal check = {{0xBCB24AB0, 0xAFEBFF0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round25) {
  // 79228162514264337.593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};
  // 79228162514264338
  s21_decimal check = {{0x12DEA112, 0x1197998, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round26) {
  // -79228162514264337.593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};
  // -79228162514264338
  s21_decimal check = {{0x12DEA112, 0x1197998, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round27) {
  // 7922816251426433.7593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};
  // 7922816251426434
  s21_decimal check = {{0x68497682, 0x1C25C2, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round28) {
  // -7922816251426433.7593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};
  // -7922816251426434
  s21_decimal check = {{0x68497682, 0x1C25C2, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round29) {
  // 792281625142643.37593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // 792281625142643
  s21_decimal check = {{0x70D42573, 0x2D093, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round30) {
  // -792281625142643.37593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // -792281625142643
  s21_decimal check = {{0x70D42573, 0x2D093, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round31) {
  // 79228162514264.337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};
  // 79228162514264
  s21_decimal check = {{0xBE7B9D58, 0x480E, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round32) {
  // -79228162514264.337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  // -79228162514264
  s21_decimal check = {{0xBE7B9D58, 0x480E, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round33) {
  // 7922816251426.4337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};
  // 7922816251426
  s21_decimal check = {{0xACA5F622, 0x734, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round34) {
  // -7922816251426.4337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  // -7922816251426
  s21_decimal check = {{0xACA5F622, 0x734, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round35) {
  // 792281625142.64337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};
  // 792281625143
  s21_decimal check = {{0x77AA3237, 0xB8, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round36) {
  // -792281625142.64337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};
  // -792281625143
  s21_decimal check = {{0x77AA3237, 0xB8, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round37) {
  // 79228162514.264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};
  // 79228162514
  s21_decimal check = {{0x725DD1D2, 0x12, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round38) {
  // -79228162514.264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};
  // -79228162514
  s21_decimal check = {{0x725DD1D2, 0x12, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round39) {
  // 7922816251.4264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};
  // 7922816251
  s21_decimal check = {{0xD83C94FB, 0x1, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round40) {
  // -7922816251.4264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};
  // -7922816251
  s21_decimal check = {{0xD83C94FB, 0x1, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round41) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  // 792281625
  s21_decimal check = {{0x2F394219, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round42) {
  // -792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  // -792281625
  s21_decimal check = {{0x2F394219, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round43) {
  // 79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  // 79228163
  s21_decimal check = {{0x4B8ED03, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round44) {
  // -79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  // -79228163
  s21_decimal check = {{0x4B8ED03, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round45) {
  // 7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  // 7922816
  s21_decimal check = {{0x78E480, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round46) {
  // -7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  // -7922816
  s21_decimal check = {{0x78E480, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round47) {
  // 792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  // 792282
  s21_decimal check = {{0xC16DA, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round48) {
  // -792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  // -792282
  s21_decimal check = {{0xC16DA, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round49) {
  // 79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  // 79228
  s21_decimal check = {{0x1357C, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round50) {
  // -79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  // -79228
  s21_decimal check = {{0x1357C, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round51) {
  // 7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  // 7923
  s21_decimal check = {{0x1EF3, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round52) {
  // -7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  // -7923
  s21_decimal check = {{0x1EF3, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round53) {
  // 792.28162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  // 792
  s21_decimal check = {{0x318, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round54) {
  // -792.28162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  // -792
  s21_decimal check = {{0x318, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round55) {
  // 79.228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  // 79
  s21_decimal check = {{0x4F, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round56) {
  // -79.228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  // -79
  s21_decimal check = {{0x4F, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round57) {
  // 7.9228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 8
  s21_decimal check = {{0x8, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round58) {
  // -7.9228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -8
  s21_decimal check = {{0x8, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round59) {
  // 79228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round60) {
  // -79228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round61) {
  // 7922816251426433759354395033.4
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395033
  s21_decimal check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round62) {
  // -7922816251426433759354395033.4
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -7922816251426433759354395033
  s21_decimal check = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round63) {
  // 792281625142643375935439503.34
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  // 792281625142643375935439503
  s21_decimal check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round64) {
  // -792281625142643375935439503.34
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  // -792281625142643375935439503
  s21_decimal check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round65) {
  // 79228162514264337593543950.334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  // 79228162514264337593543950
  s21_decimal check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round66) {
  // -79228162514264337593543950.334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  // -79228162514264337593543950
  s21_decimal check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round67) {
  // 7922816251426433759354395.0334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  // 7922816251426433759354395
  s21_decimal check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round68) {
  // -7922816251426433759354395.0334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  // -7922816251426433759354395
  s21_decimal check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round69) {
  // 792281625142643375935439.50334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  // 792281625142643375935440
  s21_decimal check = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round70) {
  // -792281625142643375935439.50334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  // -792281625142643375935440
  s21_decimal check = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round71) {
  // 79228162514264337593543.950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  // 79228162514264337593544
  s21_decimal check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round72) {
  // -79228162514264337593543.950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  // -79228162514264337593544
  s21_decimal check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round73) {
  // 7922816251426433759354.3950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  // 7922816251426433759354
  s21_decimal check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round74) {
  // -7922816251426433759354.3950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  // -7922816251426433759354
  s21_decimal check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round75) {
  // 792281625142643375935.43950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  // 792281625142643375935
  s21_decimal check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round76) {
  // -792281625142643375935.43950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  // -792281625142643375935
  s21_decimal check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round77) {
  // 79228162514264337593.543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  // 79228162514264337594
  s21_decimal check = {{0xB5A52CBA, 0x4B82FA09, 0x4, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round78) {
  // -79228162514264337593.543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  // -79228162514264337594
  s21_decimal check = {{0xB5A52CBA, 0x4B82FA09, 0x4, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round79) {
  // 7922816251426433759.3543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};
  // 7922816251426433759
  s21_decimal check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round80) {
  // -7922816251426433759.3543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};
  // -7922816251426433759
  s21_decimal check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round81) {
  // 792281625142643375.93543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};
  // 792281625142643376
  s21_decimal check = {{0xBCB24AB0, 0xAFEBFF0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round82) {
  // -792281625142643375.93543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};
  // -792281625142643376
  s21_decimal check = {{0xBCB24AB0, 0xAFEBFF0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round83) {
  // 79228162514264337.593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};
  // 79228162514264338
  s21_decimal check = {{0x12DEA112, 0x1197998, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round84) {
  // -79228162514264337.593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};
  // -79228162514264338
  s21_decimal check = {{0x12DEA112, 0x1197998, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round85) {
  // 7922816251426433.7593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};
  // 7922816251426434
  s21_decimal check = {{0x68497682, 0x1C25C2, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round86) {
  // -7922816251426433.7593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};
  // -7922816251426434
  s21_decimal check = {{0x68497682, 0x1C25C2, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round87) {
  // 792281625142643.37593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // 792281625142643
  s21_decimal check = {{0x70D42573, 0x2D093, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round88) {
  // -792281625142643.37593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // -792281625142643
  s21_decimal check = {{0x70D42573, 0x2D093, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round89) {
  // 79228162514264.337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};
  // 79228162514264
  s21_decimal check = {{0xBE7B9D58, 0x480E, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round90) {
  // -79228162514264.337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  // -79228162514264
  s21_decimal check = {{0xBE7B9D58, 0x480E, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round91) {
  // 7922816251426.4337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};
  // 7922816251426
  s21_decimal check = {{0xACA5F622, 0x734, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round92) {
  // -7922816251426.4337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  // -7922816251426
  s21_decimal check = {{0xACA5F622, 0x734, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round93) {
  // 792281625142.64337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};
  // 792281625143
  s21_decimal check = {{0x77AA3237, 0xB8, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round94) {
  // -792281625142.64337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};
  // -792281625143
  s21_decimal check = {{0x77AA3237, 0xB8, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round95) {
  // 79228162514.264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};
  // 79228162514
  s21_decimal check = {{0x725DD1D2, 0x12, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round96) {
  // -79228162514.264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};
  // -79228162514
  s21_decimal check = {{0x725DD1D2, 0x12, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round97) {
  // 7922816251.4264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};
  // 7922816251
  s21_decimal check = {{0xD83C94FB, 0x1, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round98) {
  // -7922816251.4264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};
  // -7922816251
  s21_decimal check = {{0xD83C94FB, 0x1, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round99) {
  // 792281625.14264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  // 792281625
  s21_decimal check = {{0x2F394219, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_round100) {
  // -792281625.14264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  // -792281625
  s21_decimal check = {{0x2F394219, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_round(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

Suite *round_suite(void) {
  Suite *s1 = suite_create("test_round");
  TCase *tc = tcase_create("test_round");
  suite_add_tcase(s1, tc);
  tcase_add_test(tc, test_round_fail1);
  tcase_add_test(tc, test_round_fail2);
  tcase_add_test(tc, test_round_fail3);
  tcase_add_test(tc, test_round_fail4);
  tcase_add_test(tc, test_round_fail5);
  tcase_add_test(tc, test_round_fail6);
  tcase_add_test(tc, test_round_fail7);
  tcase_add_test(tc, test_round_fail8);
  tcase_add_test(tc, test_round1);
  tcase_add_test(tc, test_round2);
  tcase_add_test(tc, test_round3);
  tcase_add_test(tc, test_round4);
  tcase_add_test(tc, test_round5);
  tcase_add_test(tc, test_round6);
  tcase_add_test(tc, test_round7);
  tcase_add_test(tc, test_round8);
  tcase_add_test(tc, test_round9);
  tcase_add_test(tc, test_round10);
  tcase_add_test(tc, test_round11);
  tcase_add_test(tc, test_round12);
  tcase_add_test(tc, test_round13);
  tcase_add_test(tc, test_round14);
  tcase_add_test(tc, test_round15);
  tcase_add_test(tc, test_round16);
  tcase_add_test(tc, test_round17);
  tcase_add_test(tc, test_round18);
  tcase_add_test(tc, test_round19);
  tcase_add_test(tc, test_round20);
  tcase_add_test(tc, test_round21);
  tcase_add_test(tc, test_round22);
  tcase_add_test(tc, test_round23);
  tcase_add_test(tc, test_round24);
  tcase_add_test(tc, test_round25);
  tcase_add_test(tc, test_round26);
  tcase_add_test(tc, test_round27);
  tcase_add_test(tc, test_round28);
  tcase_add_test(tc, test_round29);
  tcase_add_test(tc, test_round30);
  tcase_add_test(tc, test_round31);
  tcase_add_test(tc, test_round32);
  tcase_add_test(tc, test_round33);
  tcase_add_test(tc, test_round34);
  tcase_add_test(tc, test_round35);
  tcase_add_test(tc, test_round36);
  tcase_add_test(tc, test_round37);
  tcase_add_test(tc, test_round38);
  tcase_add_test(tc, test_round39);
  tcase_add_test(tc, test_round40);
  tcase_add_test(tc, test_round41);
  tcase_add_test(tc, test_round42);
  tcase_add_test(tc, test_round43);
  tcase_add_test(tc, test_round44);
  tcase_add_test(tc, test_round45);
  tcase_add_test(tc, test_round46);
  tcase_add_test(tc, test_round47);
  tcase_add_test(tc, test_round48);
  tcase_add_test(tc, test_round49);
  tcase_add_test(tc, test_round50);
  tcase_add_test(tc, test_round51);
  tcase_add_test(tc, test_round52);
  tcase_add_test(tc, test_round53);
  tcase_add_test(tc, test_round54);
  tcase_add_test(tc, test_round55);
  tcase_add_test(tc, test_round56);
  tcase_add_test(tc, test_round57);
  tcase_add_test(tc, test_round58);
  tcase_add_test(tc, test_round59);
  tcase_add_test(tc, test_round60);
  tcase_add_test(tc, test_round61);
  tcase_add_test(tc, test_round62);
  tcase_add_test(tc, test_round63);
  tcase_add_test(tc, test_round64);
  tcase_add_test(tc, test_round65);
  tcase_add_test(tc, test_round66);
  tcase_add_test(tc, test_round67);
  tcase_add_test(tc, test_round68);
  tcase_add_test(tc, test_round69);
  tcase_add_test(tc, test_round70);
  tcase_add_test(tc, test_round71);
  tcase_add_test(tc, test_round72);
  tcase_add_test(tc, test_round73);
  tcase_add_test(tc, test_round74);
  tcase_add_test(tc, test_round75);
  tcase_add_test(tc, test_round76);
  tcase_add_test(tc, test_round77);
  tcase_add_test(tc, test_round78);
  tcase_add_test(tc, test_round79);
  tcase_add_test(tc, test_round80);
  tcase_add_test(tc, test_round81);
  tcase_add_test(tc, test_round82);
  tcase_add_test(tc, test_round83);
  tcase_add_test(tc, test_round84);
  tcase_add_test(tc, test_round85);
  tcase_add_test(tc, test_round86);
  tcase_add_test(tc, test_round87);
  tcase_add_test(tc, test_round88);
  tcase_add_test(tc, test_round89);
  tcase_add_test(tc, test_round90);
  tcase_add_test(tc, test_round91);
  tcase_add_test(tc, test_round92);
  tcase_add_test(tc, test_round93);
  tcase_add_test(tc, test_round94);
  tcase_add_test(tc, test_round95);
  tcase_add_test(tc, test_round96);
  tcase_add_test(tc, test_round97);
  tcase_add_test(tc, test_round98);
  tcase_add_test(tc, test_round99);
  tcase_add_test(tc, test_round100);
  return s1;
}