#include "s21_test_convertors.h"

START_TEST(test_from_decimal_to_int_manual1) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  ck_assert_int_eq(s21_from_decimal_to_int(decimal, NULL), S21_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_manual2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal = {{0, 0, 0, 1000000000}};
  int result;
  ck_assert_int_eq(s21_from_decimal_to_int(decimal, &result), S21_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_manual3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{-1, 0, 0, 0x1D0000}};
  int result;
  ck_assert_int_eq(s21_from_decimal_to_int(decimal, &result), S21_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_manual4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{0, 0, 0, 0x1D0000}};
  int result;
  ck_assert_int_eq(s21_from_decimal_to_int(decimal, &result), S21_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_manual5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C0001}};
  int result;
  ck_assert_int_eq(s21_from_decimal_to_int(decimal, &result), S21_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_manual6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C8000}};
  int result;
  ck_assert_int_eq(s21_from_decimal_to_int(decimal, &result), S21_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_manual7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x11C0000}};
  int result;
  ck_assert_int_eq(s21_from_decimal_to_int(decimal, &result), S21_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_manual8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x401C0000}};
  int result;
  ck_assert_int_eq(s21_from_decimal_to_int(decimal, &result), S21_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int1) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int check = 792281625;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int2) {
  // -792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  int check = -792281625;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int3) {
  // 79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  int check = 79228162;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int4) {
  // -79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  int check = -79228162;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int5) {
  // 7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  int check = 7922816;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int6) {
  // -7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  int check = -7922816;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int7) {
  // 792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  int check = 792281;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int8) {
  // -792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  int check = -792281;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int9) {
  // 79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  int check = 79228;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int10) {
  // -79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  int check = -79228;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int11) {
  // 7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  int check = 7922;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int12) {
  // -7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  int check = -7922;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int13) {
  // 792.28162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  int check = 792;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int14) {
  // -792.28162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  int check = -792;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int15) {
  // 79.228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  int check = 79;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int16) {
  // -79.228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  int check = -79;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int17) {
  // 7.9228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  int check = 7;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int18) {
  // -7.9228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  int check = -7;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int19) {
  // 792281625.14264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int check = 792281625;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int20) {
  // -792281625.14264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  int check = -792281625;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int21) {
  // 79228162.514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  int check = 79228162;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int22) {
  // -79228162.514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  int check = -79228162;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int23) {
  // 7922816.2514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  int check = 7922816;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int24) {
  // -7922816.2514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  int check = -7922816;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int25) {
  // 792281.62514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  int check = 792281;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int26) {
  // -792281.62514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  int check = -792281;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int27) {
  // 79228.162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  int check = 79228;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int28) {
  // -79228.162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  int check = -79228;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int29) {
  // 7922.8162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  int check = 7922;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int30) {
  // -7922.8162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  int check = -7922;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int31) {
  // 792.28162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  int check = 792;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int32) {
  // -792.28162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  int check = -792;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int33) {
  // 79.228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  int check = 79;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int34) {
  // -79.228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  int check = -79;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int35) {
  // 7.9228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  int check = 7;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int36) {
  // -7.9228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  int check = -7;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int37) {
  // 528187750.09509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x140000}};
  int check = 528187750;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int38) {
  // -528187750.09509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80140000}};
  int check = -528187750;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int39) {
  // 5.2818775009509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
  int check = 5;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int40) {
  // -5.2818775009509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
  int check = -5;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int41) {
  // 528187750.09509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x140000}};
  int check = 528187750;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int42) {
  // -528187750.09509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80140000}};
  int check = -528187750;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int43) {
  // 5.2818775009509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
  int check = 5;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int44) {
  // -5.2818775009509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
  int check = -5;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int45) {
  // 528187749.97211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x140000}};
  int check = 528187749;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int46) {
  // -528187749.97211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80140000}};
  int check = -528187749;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int47) {
  // 5.2818774997211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x1C0000}};
  int check = 5;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int48) {
  // -5.2818774997211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x801C0000}};
  int check = -5;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int49) {
  // 528187749.97211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x140000}};
  int check = 528187749;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int50) {
  // -528187749.97211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80140000}};
  int check = -528187749;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int51) {
  // 5.2818774997211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x1C0000}};
  int check = 5;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int52) {
  // -5.2818774997211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x801C0000}};
  int check = -5;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int53) {
  // 122978293.82473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0xB0000}};
  int check = 122978293;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int54) {
  // -122978293.82473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x800B0000}};
  int check = -122978293;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int55) {
  // 1.2297829382473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = 1;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int56) {
  // -1.2297829382473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = -1;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int57) {
  // 122978293.79609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0xB0000}};
  int check = 122978293;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int58) {
  // -122978293.79609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x800B0000}};
  int check = -122978293;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int59) {
  // 1.2297829379609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = 1;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int60) {
  // -1.2297829379609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = -1;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int61) {
  // 286331153.0
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x10000}};
  int check = 286331153;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int62) {
  // -286331153.0
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80010000}};
  int check = -286331153;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int63) {
  // 286331.1530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x40000}};
  int check = 286331;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int64) {
  // -286331.1530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80040000}};
  int check = -286331;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int65) {
  // 2.863311530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x90000}};
  int check = 2;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int66) {
  // -2.863311530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80090000}};
  int check = -2;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int67) {
  // 264093875.04754779197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x140000}};
  int check = 264093875;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int68) {
  // -264093875.04754779197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80140000}};
  int check = -264093875;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int69) {
  // 2.6409387504754779197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x1C0000}};
  int check = 2;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int70) {
  // -2.6409387504754779197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x801C0000}};
  int check = -2;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int71) {
  // 264093875.04754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x140000}};
  int check = 264093875;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int72) {
  // -264093875.04754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80140000}};
  int check = -264093875;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int73) {
  // 2.6409387504754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x1C0000}};
  int check = 2;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int74) {
  // -2.6409387504754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x801C0000}};
  int check = -2;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int75) {
  // 264093874.98605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x140000}};
  int check = 264093874;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int76) {
  // -264093874.98605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80140000}};
  int check = -264093874;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int77) {
  // 2.6409387498605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x1C0000}};
  int check = 2;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int78) {
  // -2.6409387498605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x801C0000}};
  int check = -2;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int79) {
  // 264093874.98605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x140000}};
  int check = 264093874;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int80) {
  // -264093874.98605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80140000}};
  int check = -264093874;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int81) {
  // 2.6409387498605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x1C0000}};
  int check = 2;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int82) {
  // -2.6409387498605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x801C0000}};
  int check = -2;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int83) {
  // 6148914.691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0xC0000}};
  int check = 6148914;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int84) {
  // -6148914.691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x800C0000}};
  int check = -6148914;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int85) {
  // 6.148914691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x120000}};
  int check = 6;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int86) {
  // -6.148914691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80120000}};
  int check = -6;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int87) {
  // 6148914.689804861440
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0xC0000}};
  int check = 6148914;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int88) {
  // -6148914.689804861440
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x800C0000}};
  int check = -6148914;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int89) {
  // 6.148914689804861440
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x120000}};
  int check = 6;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int90) {
  // -6.148914689804861440
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80120000}};
  int check = -6;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int91) {
  // 1431655765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x0}};
  int check = 1431655765;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int92) {
  // -1431655765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80000000}};
  int check = -1431655765;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int93) {
  // 143165576.5
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x10000}};
  int check = 143165576;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int94) {
  // -143165576.5
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80010000}};
  int check = -143165576;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int95) {
  // 143165.5765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x40000}};
  int check = 143165;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int96) {
  // -143165.5765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80040000}};
  int check = -143165;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int97) {
  // 1.431655765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x90000}};
  int check = 1;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int98) {
  // -1.431655765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80090000}};
  int check = -1;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int99) {
  // 184467440.78004518913
  s21_decimal decimal = {{0x1, 0x1, 0x1, 0xB0000}};
  int check = 184467440;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(test_from_decimal_to_int100) {
  // -184467440.78004518913
  s21_decimal decimal = {{0x1, 0x1, 0x1, 0x800B0000}};
  int check = -184467440;
  int result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_int(decimal, &result));
  ck_assert_int_eq(check, result);
}
END_TEST

Suite *from_decimal_to_int_suite(void) {
  Suite *s1 = suite_create("test_from_decimal_to_int");
  TCase *tc = tcase_create("test_from_decimal_to_int");
  suite_add_tcase(s1, tc);
  tcase_add_test(tc, test_from_decimal_to_int_manual1);
  tcase_add_test(tc, test_from_decimal_to_int_manual2);
  tcase_add_test(tc, test_from_decimal_to_int_manual3);
  tcase_add_test(tc, test_from_decimal_to_int_manual4);
  tcase_add_test(tc, test_from_decimal_to_int_manual5);
  tcase_add_test(tc, test_from_decimal_to_int_manual6);
  tcase_add_test(tc, test_from_decimal_to_int_manual7);
  tcase_add_test(tc, test_from_decimal_to_int_manual8);
  tcase_add_test(tc, test_from_decimal_to_int1);
  tcase_add_test(tc, test_from_decimal_to_int2);
  tcase_add_test(tc, test_from_decimal_to_int3);
  tcase_add_test(tc, test_from_decimal_to_int4);
  tcase_add_test(tc, test_from_decimal_to_int5);
  tcase_add_test(tc, test_from_decimal_to_int6);
  tcase_add_test(tc, test_from_decimal_to_int7);
  tcase_add_test(tc, test_from_decimal_to_int8);
  tcase_add_test(tc, test_from_decimal_to_int9);
  tcase_add_test(tc, test_from_decimal_to_int10);
  tcase_add_test(tc, test_from_decimal_to_int11);
  tcase_add_test(tc, test_from_decimal_to_int12);
  tcase_add_test(tc, test_from_decimal_to_int13);
  tcase_add_test(tc, test_from_decimal_to_int14);
  tcase_add_test(tc, test_from_decimal_to_int15);
  tcase_add_test(tc, test_from_decimal_to_int16);
  tcase_add_test(tc, test_from_decimal_to_int17);
  tcase_add_test(tc, test_from_decimal_to_int18);
  tcase_add_test(tc, test_from_decimal_to_int19);
  tcase_add_test(tc, test_from_decimal_to_int20);
  tcase_add_test(tc, test_from_decimal_to_int21);
  tcase_add_test(tc, test_from_decimal_to_int22);
  tcase_add_test(tc, test_from_decimal_to_int23);
  tcase_add_test(tc, test_from_decimal_to_int24);
  tcase_add_test(tc, test_from_decimal_to_int25);
  tcase_add_test(tc, test_from_decimal_to_int26);
  tcase_add_test(tc, test_from_decimal_to_int27);
  tcase_add_test(tc, test_from_decimal_to_int28);
  tcase_add_test(tc, test_from_decimal_to_int29);
  tcase_add_test(tc, test_from_decimal_to_int30);
  tcase_add_test(tc, test_from_decimal_to_int31);
  tcase_add_test(tc, test_from_decimal_to_int32);
  tcase_add_test(tc, test_from_decimal_to_int33);
  tcase_add_test(tc, test_from_decimal_to_int34);
  tcase_add_test(tc, test_from_decimal_to_int35);
  tcase_add_test(tc, test_from_decimal_to_int36);
  tcase_add_test(tc, test_from_decimal_to_int37);
  tcase_add_test(tc, test_from_decimal_to_int38);
  tcase_add_test(tc, test_from_decimal_to_int39);
  tcase_add_test(tc, test_from_decimal_to_int40);
  tcase_add_test(tc, test_from_decimal_to_int41);
  tcase_add_test(tc, test_from_decimal_to_int42);
  tcase_add_test(tc, test_from_decimal_to_int43);
  tcase_add_test(tc, test_from_decimal_to_int44);
  tcase_add_test(tc, test_from_decimal_to_int45);
  tcase_add_test(tc, test_from_decimal_to_int46);
  tcase_add_test(tc, test_from_decimal_to_int47);
  tcase_add_test(tc, test_from_decimal_to_int48);
  tcase_add_test(tc, test_from_decimal_to_int49);
  tcase_add_test(tc, test_from_decimal_to_int50);
  tcase_add_test(tc, test_from_decimal_to_int51);
  tcase_add_test(tc, test_from_decimal_to_int52);
  tcase_add_test(tc, test_from_decimal_to_int53);
  tcase_add_test(tc, test_from_decimal_to_int54);
  tcase_add_test(tc, test_from_decimal_to_int55);
  tcase_add_test(tc, test_from_decimal_to_int56);
  tcase_add_test(tc, test_from_decimal_to_int57);
  tcase_add_test(tc, test_from_decimal_to_int58);
  tcase_add_test(tc, test_from_decimal_to_int59);
  tcase_add_test(tc, test_from_decimal_to_int60);
  tcase_add_test(tc, test_from_decimal_to_int61);
  tcase_add_test(tc, test_from_decimal_to_int62);
  tcase_add_test(tc, test_from_decimal_to_int63);
  tcase_add_test(tc, test_from_decimal_to_int64);
  tcase_add_test(tc, test_from_decimal_to_int65);
  tcase_add_test(tc, test_from_decimal_to_int66);
  tcase_add_test(tc, test_from_decimal_to_int67);
  tcase_add_test(tc, test_from_decimal_to_int68);
  tcase_add_test(tc, test_from_decimal_to_int69);
  tcase_add_test(tc, test_from_decimal_to_int70);
  tcase_add_test(tc, test_from_decimal_to_int71);
  tcase_add_test(tc, test_from_decimal_to_int72);
  tcase_add_test(tc, test_from_decimal_to_int73);
  tcase_add_test(tc, test_from_decimal_to_int74);
  tcase_add_test(tc, test_from_decimal_to_int75);
  tcase_add_test(tc, test_from_decimal_to_int76);
  tcase_add_test(tc, test_from_decimal_to_int77);
  tcase_add_test(tc, test_from_decimal_to_int78);
  tcase_add_test(tc, test_from_decimal_to_int79);
  tcase_add_test(tc, test_from_decimal_to_int80);
  tcase_add_test(tc, test_from_decimal_to_int81);
  tcase_add_test(tc, test_from_decimal_to_int82);
  tcase_add_test(tc, test_from_decimal_to_int83);
  tcase_add_test(tc, test_from_decimal_to_int84);
  tcase_add_test(tc, test_from_decimal_to_int85);
  tcase_add_test(tc, test_from_decimal_to_int86);
  tcase_add_test(tc, test_from_decimal_to_int87);
  tcase_add_test(tc, test_from_decimal_to_int88);
  tcase_add_test(tc, test_from_decimal_to_int89);
  tcase_add_test(tc, test_from_decimal_to_int90);
  tcase_add_test(tc, test_from_decimal_to_int91);
  tcase_add_test(tc, test_from_decimal_to_int92);
  tcase_add_test(tc, test_from_decimal_to_int93);
  tcase_add_test(tc, test_from_decimal_to_int94);
  tcase_add_test(tc, test_from_decimal_to_int95);
  tcase_add_test(tc, test_from_decimal_to_int96);
  tcase_add_test(tc, test_from_decimal_to_int97);
  tcase_add_test(tc, test_from_decimal_to_int98);
  tcase_add_test(tc, test_from_decimal_to_int99);
  tcase_add_test(tc, test_from_decimal_to_int100);
  return s1;
}