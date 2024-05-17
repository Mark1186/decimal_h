#include "s21_test_other.h"

START_TEST(test_floor_fail1) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  ck_assert_int_eq(S21_ERROR, s21_floor(decimal, NULL));
}
END_TEST

START_TEST(test_floor_fail2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal = {{0, 0, 0, 1000000000}};
  s21_decimal check;
  ck_assert_int_eq(S21_ERROR, s21_floor(decimal, &check));
}
END_TEST

START_TEST(test_floor_fail3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{-1, 0, 0, 0x1D0000}};
  s21_decimal check;
  ck_assert_int_eq(S21_ERROR, s21_floor(decimal, &check));
}
END_TEST

START_TEST(test_floor_fail4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{0, 0, 0, 0x1D0000}};
  s21_decimal check;
  ck_assert_int_eq(S21_ERROR, s21_floor(decimal, &check));
}
END_TEST

START_TEST(test_floor_fail5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C0001}};
  s21_decimal check;
  ck_assert_int_eq(S21_ERROR, s21_floor(decimal, &check));
}
END_TEST

START_TEST(test_floor_fail6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C8000}};
  s21_decimal check;
  ck_assert_int_eq(S21_ERROR, s21_floor(decimal, &check));
}
END_TEST

START_TEST(test_floor_fail7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x11C0000}};
  s21_decimal check;
  ck_assert_int_eq(S21_ERROR, s21_floor(decimal, &check));
}
END_TEST

START_TEST(test_floor_fail8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x401C0000}};
  s21_decimal check;
  ck_assert_int_eq(S21_ERROR, s21_floor(decimal, &check));
}
END_TEST

START_TEST(test_floor1) {
  // 79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor2) {
  // -79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor3) {
  // 7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395033
  s21_decimal check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor4) {
  // -7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -7922816251426433759354395034
  s21_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor5) {
  // 792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  // 792281625142643375935439503
  s21_decimal check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor6) {
  // -792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  // -792281625142643375935439504
  s21_decimal check = {{0x28F5C290, 0xF5C28F5C, 0x28F5C28, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor7) {
  // 79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  // 79228162514264337593543950
  s21_decimal check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor8) {
  // -79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  // -79228162514264337593543951
  s21_decimal check = {{0x9DB22D0F, 0x4BC6A7EF, 0x418937, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor9) {
  // 7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  // 7922816251426433759354395
  s21_decimal check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor10) {
  // -7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  // -7922816251426433759354396
  s21_decimal check = {{0x295E9E1C, 0xBAC710CB, 0x68DB8, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor11) {
  // 792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  // 792281625142643375935439
  s21_decimal check = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor12) {
  // -792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  // -792281625142643375935440
  s21_decimal check = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor13) {
  // 79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  // 79228162514264337593543
  s21_decimal check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor14) {
  // -79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  // -79228162514264337593544
  s21_decimal check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor15) {
  // 7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  // 7922816251426433759354
  s21_decimal check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor16) {
  // -7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  // -7922816251426433759355
  s21_decimal check = {{0xF485787B, 0x7F29ABCA, 0x1AD, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor17) {
  // 792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  // 792281625142643375935
  s21_decimal check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor18) {
  // -792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  // -792281625142643375936
  s21_decimal check = {{0x1873BF40, 0xF31DC461, 0x2A, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor19) {
  // 79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  // 79228162514264337593
  s21_decimal check = {{0xB5A52CB9, 0x4B82FA09, 0x4, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor20) {
  // -79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  // -79228162514264337594
  s21_decimal check = {{0xB5A52CBA, 0x4B82FA09, 0x4, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor21) {
  // 7922816251426433759.3543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};
  // 7922816251426433759
  s21_decimal check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor22) {
  // -7922816251426433759.3543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};
  // -7922816251426433760
  s21_decimal check = {{0x5EF6EAE0, 0x6DF37F67, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor23) {
  // 792281625142643375.93543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};
  // 792281625142643375
  s21_decimal check = {{0xBCB24AAF, 0xAFEBFF0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor24) {
  // -792281625142643375.93543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};
  // -792281625142643376
  s21_decimal check = {{0xBCB24AB0, 0xAFEBFF0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor25) {
  // 79228162514264337.593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};
  // 79228162514264337
  s21_decimal check = {{0x12DEA111, 0x1197998, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor26) {
  // -79228162514264337.593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};
  // -79228162514264338
  s21_decimal check = {{0x12DEA112, 0x1197998, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor27) {
  // 7922816251426433.7593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};
  // 7922816251426433
  s21_decimal check = {{0x68497681, 0x1C25C2, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor28) {
  // -7922816251426433.7593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};
  // -7922816251426434
  s21_decimal check = {{0x68497682, 0x1C25C2, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor29) {
  // 792281625142643.37593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // 792281625142643
  s21_decimal check = {{0x70D42573, 0x2D093, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor30) {
  // -792281625142643.37593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // -792281625142644
  s21_decimal check = {{0x70D42574, 0x2D093, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor31) {
  // 79228162514264.337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};
  // 79228162514264
  s21_decimal check = {{0xBE7B9D58, 0x480E, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor32) {
  // -79228162514264.337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  // -79228162514265
  s21_decimal check = {{0xBE7B9D59, 0x480E, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor33) {
  // 7922816251426.4337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};
  // 7922816251426
  s21_decimal check = {{0xACA5F622, 0x734, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor34) {
  // -7922816251426.4337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  // -7922816251427
  s21_decimal check = {{0xACA5F623, 0x734, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor35) {
  // 792281625142.64337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};
  // 792281625142
  s21_decimal check = {{0x77AA3236, 0xB8, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor36) {
  // -792281625142.64337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};
  // -792281625143
  s21_decimal check = {{0x77AA3237, 0xB8, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor37) {
  // 79228162514.264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};
  // 79228162514
  s21_decimal check = {{0x725DD1D2, 0x12, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor38) {
  // -79228162514.264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};
  // -79228162515
  s21_decimal check = {{0x725DD1D3, 0x12, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor39) {
  // 7922816251.4264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};
  // 7922816251
  s21_decimal check = {{0xD83C94FB, 0x1, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor40) {
  // -7922816251.4264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};
  // -7922816252
  s21_decimal check = {{0xD83C94FC, 0x1, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor41) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  // 792281625
  s21_decimal check = {{0x2F394219, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor42) {
  // -792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  // -792281626
  s21_decimal check = {{0x2F39421A, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor43) {
  // 79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  // 79228162
  s21_decimal check = {{0x4B8ED02, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor44) {
  // -79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  // -79228163
  s21_decimal check = {{0x4B8ED03, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor45) {
  // 7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  // 7922816
  s21_decimal check = {{0x78E480, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor46) {
  // -7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  // -7922817
  s21_decimal check = {{0x78E481, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor47) {
  // 792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  // 792281
  s21_decimal check = {{0xC16D9, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor48) {
  // -792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  // -792282
  s21_decimal check = {{0xC16DA, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor49) {
  // 79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  // 79228
  s21_decimal check = {{0x1357C, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor50) {
  // -79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  // -79229
  s21_decimal check = {{0x1357D, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor51) {
  // 7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  // 7922
  s21_decimal check = {{0x1EF2, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor52) {
  // -7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  // -7923
  s21_decimal check = {{0x1EF3, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor53) {
  // 792.28162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  // 792
  s21_decimal check = {{0x318, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor54) {
  // -792.28162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  // -793
  s21_decimal check = {{0x319, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor55) {
  // 79.228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  // 79
  s21_decimal check = {{0x4F, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor56) {
  // -79.228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  // -80
  s21_decimal check = {{0x50, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor57) {
  // 7.9228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 7
  s21_decimal check = {{0x7, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor58) {
  // -7.9228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -8
  s21_decimal check = {{0x8, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor59) {
  // 79228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor60) {
  // -79228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor61) {
  // 7922816251426433759354395033.4
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395033
  s21_decimal check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor62) {
  // -7922816251426433759354395033.4
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -7922816251426433759354395034
  s21_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor63) {
  // 792281625142643375935439503.34
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  // 792281625142643375935439503
  s21_decimal check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor64) {
  // -792281625142643375935439503.34
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  // -792281625142643375935439504
  s21_decimal check = {{0x28F5C290, 0xF5C28F5C, 0x28F5C28, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor65) {
  // 79228162514264337593543950.334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  // 79228162514264337593543950
  s21_decimal check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor66) {
  // -79228162514264337593543950.334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  // -79228162514264337593543951
  s21_decimal check = {{0x9DB22D0F, 0x4BC6A7EF, 0x418937, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor67) {
  // 7922816251426433759354395.0334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  // 7922816251426433759354395
  s21_decimal check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor68) {
  // -7922816251426433759354395.0334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  // -7922816251426433759354396
  s21_decimal check = {{0x295E9E1C, 0xBAC710CB, 0x68DB8, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor69) {
  // 792281625142643375935439.50334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  // 792281625142643375935439
  s21_decimal check = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor70) {
  // -792281625142643375935439.50334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  // -792281625142643375935440
  s21_decimal check = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor71) {
  // 79228162514264337593543.950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  // 79228162514264337593543
  s21_decimal check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor72) {
  // -79228162514264337593543.950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  // -79228162514264337593544
  s21_decimal check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor73) {
  // 7922816251426433759354.3950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  // 7922816251426433759354
  s21_decimal check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor74) {
  // -7922816251426433759354.3950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  // -7922816251426433759355
  s21_decimal check = {{0xF485787B, 0x7F29ABCA, 0x1AD, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor75) {
  // 792281625142643375935.43950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  // 792281625142643375935
  s21_decimal check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor76) {
  // -792281625142643375935.43950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  // -792281625142643375936
  s21_decimal check = {{0x1873BF40, 0xF31DC461, 0x2A, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor77) {
  // 79228162514264337593.543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  // 79228162514264337593
  s21_decimal check = {{0xB5A52CB9, 0x4B82FA09, 0x4, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor78) {
  // -79228162514264337593.543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  // -79228162514264337594
  s21_decimal check = {{0xB5A52CBA, 0x4B82FA09, 0x4, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor79) {
  // 7922816251426433759.3543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};
  // 7922816251426433759
  s21_decimal check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor80) {
  // -7922816251426433759.3543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};
  // -7922816251426433760
  s21_decimal check = {{0x5EF6EAE0, 0x6DF37F67, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor81) {
  // 792281625142643375.93543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};
  // 792281625142643375
  s21_decimal check = {{0xBCB24AAF, 0xAFEBFF0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor82) {
  // -792281625142643375.93543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};
  // -792281625142643376
  s21_decimal check = {{0xBCB24AB0, 0xAFEBFF0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor83) {
  // 79228162514264337.593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};
  // 79228162514264337
  s21_decimal check = {{0x12DEA111, 0x1197998, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor84) {
  // -79228162514264337.593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};
  // -79228162514264338
  s21_decimal check = {{0x12DEA112, 0x1197998, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor85) {
  // 7922816251426433.7593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};
  // 7922816251426433
  s21_decimal check = {{0x68497681, 0x1C25C2, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor86) {
  // -7922816251426433.7593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};
  // -7922816251426434
  s21_decimal check = {{0x68497682, 0x1C25C2, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor87) {
  // 792281625142643.37593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // 792281625142643
  s21_decimal check = {{0x70D42573, 0x2D093, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor88) {
  // -792281625142643.37593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // -792281625142644
  s21_decimal check = {{0x70D42574, 0x2D093, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor89) {
  // 79228162514264.337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};
  // 79228162514264
  s21_decimal check = {{0xBE7B9D58, 0x480E, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor90) {
  // -79228162514264.337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  // -79228162514265
  s21_decimal check = {{0xBE7B9D59, 0x480E, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor91) {
  // 7922816251426.4337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};
  // 7922816251426
  s21_decimal check = {{0xACA5F622, 0x734, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor92) {
  // -7922816251426.4337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  // -7922816251427
  s21_decimal check = {{0xACA5F623, 0x734, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor93) {
  // 792281625142.64337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};
  // 792281625142
  s21_decimal check = {{0x77AA3236, 0xB8, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor94) {
  // -792281625142.64337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};
  // -792281625143
  s21_decimal check = {{0x77AA3237, 0xB8, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor95) {
  // 79228162514.264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};
  // 79228162514
  s21_decimal check = {{0x725DD1D2, 0x12, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor96) {
  // -79228162514.264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};
  // -79228162515
  s21_decimal check = {{0x725DD1D3, 0x12, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor97) {
  // 7922816251.4264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};
  // 7922816251
  s21_decimal check = {{0xD83C94FB, 0x1, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor98) {
  // -7922816251.4264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};
  // -7922816252
  s21_decimal check = {{0xD83C94FC, 0x1, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor99) {
  // 792281625.14264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  // 792281625
  s21_decimal check = {{0x2F394219, 0x0, 0x0, 0x0}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

START_TEST(test_floor100) {
  // -792281625.14264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  // -792281626
  s21_decimal check = {{0x2F39421A, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = check;
  ck_assert_int_eq(S21_OK, s21_floor(decimal, &check));
  ck_assert_int_eq(S21_TRUE, s21_is_equal(expected, check));
}
END_TEST

Suite *floor_suite(void) {
  Suite *s1 = suite_create("test_floor");
  TCase *tc = tcase_create("test_floor");
  suite_add_tcase(s1, tc);
  tcase_add_test(tc, test_floor_fail1);
  tcase_add_test(tc, test_floor_fail2);
  tcase_add_test(tc, test_floor_fail3);
  tcase_add_test(tc, test_floor_fail4);
  tcase_add_test(tc, test_floor_fail5);
  tcase_add_test(tc, test_floor_fail6);
  tcase_add_test(tc, test_floor_fail7);
  tcase_add_test(tc, test_floor_fail8);
  tcase_add_test(tc, test_floor1);
  tcase_add_test(tc, test_floor2);
  tcase_add_test(tc, test_floor3);
  tcase_add_test(tc, test_floor4);
  tcase_add_test(tc, test_floor5);
  tcase_add_test(tc, test_floor6);
  tcase_add_test(tc, test_floor7);
  tcase_add_test(tc, test_floor8);
  tcase_add_test(tc, test_floor9);
  tcase_add_test(tc, test_floor10);
  tcase_add_test(tc, test_floor11);
  tcase_add_test(tc, test_floor12);
  tcase_add_test(tc, test_floor13);
  tcase_add_test(tc, test_floor14);
  tcase_add_test(tc, test_floor15);
  tcase_add_test(tc, test_floor16);
  tcase_add_test(tc, test_floor17);
  tcase_add_test(tc, test_floor18);
  tcase_add_test(tc, test_floor19);
  tcase_add_test(tc, test_floor20);
  tcase_add_test(tc, test_floor21);
  tcase_add_test(tc, test_floor22);
  tcase_add_test(tc, test_floor23);
  tcase_add_test(tc, test_floor24);
  tcase_add_test(tc, test_floor25);
  tcase_add_test(tc, test_floor26);
  tcase_add_test(tc, test_floor27);
  tcase_add_test(tc, test_floor28);
  tcase_add_test(tc, test_floor29);
  tcase_add_test(tc, test_floor30);
  tcase_add_test(tc, test_floor31);
  tcase_add_test(tc, test_floor32);
  tcase_add_test(tc, test_floor33);
  tcase_add_test(tc, test_floor34);
  tcase_add_test(tc, test_floor35);
  tcase_add_test(tc, test_floor36);
  tcase_add_test(tc, test_floor37);
  tcase_add_test(tc, test_floor38);
  tcase_add_test(tc, test_floor39);
  tcase_add_test(tc, test_floor40);
  tcase_add_test(tc, test_floor41);
  tcase_add_test(tc, test_floor42);
  tcase_add_test(tc, test_floor43);
  tcase_add_test(tc, test_floor44);
  tcase_add_test(tc, test_floor45);
  tcase_add_test(tc, test_floor46);
  tcase_add_test(tc, test_floor47);
  tcase_add_test(tc, test_floor48);
  tcase_add_test(tc, test_floor49);
  tcase_add_test(tc, test_floor50);
  tcase_add_test(tc, test_floor51);
  tcase_add_test(tc, test_floor52);
  tcase_add_test(tc, test_floor53);
  tcase_add_test(tc, test_floor54);
  tcase_add_test(tc, test_floor55);
  tcase_add_test(tc, test_floor56);
  tcase_add_test(tc, test_floor57);
  tcase_add_test(tc, test_floor58);
  tcase_add_test(tc, test_floor59);
  tcase_add_test(tc, test_floor60);
  tcase_add_test(tc, test_floor61);
  tcase_add_test(tc, test_floor62);
  tcase_add_test(tc, test_floor63);
  tcase_add_test(tc, test_floor64);
  tcase_add_test(tc, test_floor65);
  tcase_add_test(tc, test_floor66);
  tcase_add_test(tc, test_floor67);
  tcase_add_test(tc, test_floor68);
  tcase_add_test(tc, test_floor69);
  tcase_add_test(tc, test_floor70);
  tcase_add_test(tc, test_floor71);
  tcase_add_test(tc, test_floor72);
  tcase_add_test(tc, test_floor73);
  tcase_add_test(tc, test_floor74);
  tcase_add_test(tc, test_floor75);
  tcase_add_test(tc, test_floor76);
  tcase_add_test(tc, test_floor77);
  tcase_add_test(tc, test_floor78);
  tcase_add_test(tc, test_floor79);
  tcase_add_test(tc, test_floor80);
  tcase_add_test(tc, test_floor81);
  tcase_add_test(tc, test_floor82);
  tcase_add_test(tc, test_floor83);
  tcase_add_test(tc, test_floor84);
  tcase_add_test(tc, test_floor85);
  tcase_add_test(tc, test_floor86);
  tcase_add_test(tc, test_floor87);
  tcase_add_test(tc, test_floor88);
  tcase_add_test(tc, test_floor89);
  tcase_add_test(tc, test_floor90);
  tcase_add_test(tc, test_floor91);
  tcase_add_test(tc, test_floor92);
  tcase_add_test(tc, test_floor93);
  tcase_add_test(tc, test_floor94);
  tcase_add_test(tc, test_floor95);
  tcase_add_test(tc, test_floor96);
  tcase_add_test(tc, test_floor97);
  tcase_add_test(tc, test_floor98);
  tcase_add_test(tc, test_floor99);
  tcase_add_test(tc, test_floor100);
  return s1;
}