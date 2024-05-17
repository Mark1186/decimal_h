#include "s21_test_convertors.h"

START_TEST(test_from_decimal_to_float_manual1) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  ck_assert_int_eq(S21_ERROR, s21_from_decimal_to_float(decimal, NULL));
}
END_TEST

START_TEST(test_from_decimal_to_float_manual2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal = {{0, 0, 0, 1000000000}};
  float result;
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, &result), S21_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_float_manual3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{-1, 0, 0, 0x1D0000}};
  float result;
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, &result), S21_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_float_manual4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{0, 0, 0, 0x1D0000}};
  float result;
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, &result), S21_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_float_manual5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C0001}};
  float result;
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, &result), S21_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_float_manual6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C8000}};
  float result;
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, &result), S21_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_float_manual7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x11C0000}};
  float result;
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, &result), S21_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_float_manual8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x401C0000}};
  float result;
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, &result), S21_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_float1) {
  // 79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  float check = 79228162514264337593543950336.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float2) {
  // -79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  float check = -79228162514264337593543950336.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float3) {
  // 7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  float check = 7922816369485595831095525376.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float4) {
  // -7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  float check = -7922816369485595831095525376.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float5) {
  // 20995463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x0}};
  float check = 20995461932912093573574295552.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float6) {
  // -20995463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80000000}};
  float check = -20995461932912093573574295552.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float7) {
  // 792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  float check = 792281607433769065174269952.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float8) {
  // -792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  float check = -792281607433769065174269952.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float9) {
  // 2099546306628004946228914683.9
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x10000}};
  float check = 2099546281835580911163277312.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float10) {
  // -2099546306628004946228914683.9
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80010000}};
  float check = -2099546281835580911163277312.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float11) {
  // 79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  float check = 79228166277400128630292480.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float12) {
  // -79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  float check = -79228166277400128630292480.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float13) {
  // 209954630662800494622891468.39
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x20000}};
  float check = 209954624494209276374417408.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float14) {
  // -209954630662800494622891468.39
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80020000}};
  float check = -209954624494209276374417408.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float15) {
  // 7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  float check = 7922816051279260559605760.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float16) {
  // -7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  float check = -7922816051279260559605760.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float17) {
  // 20995463066280049462289146.839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x30000}};
  float check = 20995463832926733165658112.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float18) {
  // -20995463066280049462289146.839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80030000}};
  float check = -20995463832926733165658112.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float19) {
  // 792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  float check = 792281605127926055960576.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float20) {
  // -792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  float check = -792281605127926055960576.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float21) {
  // 2099546306628004946228914.6839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x40000}};
  float check = 2099546296823560471052288.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float22) {
  // -2099546306628004946228914.6839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80040000}};
  float check = -2099546296823560471052288.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float23) {
  // 79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  float check = 79228162314232456544256.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float24) {
  // -79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  float check = -79228162314232456544256.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float25) {
  // 209954630662800494622891.46839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x50000}};
  float check = 209954626079476345208832.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float26) {
  // -209954630662800494622891.46839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80050000}};
  float check = -209954626079476345208832.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float27) {
  // 7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  float check = 7922816344013236338688.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float28) {
  // -7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  float check = -7922816344013236338688.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float29) {
  // 20995463066280049462289.146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x60000}};
  float check = 20995463959027522732032.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float30) {
  // -20995463066280049462289.146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80060000}};
  float check = -20995463959027522732032.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float31) {
  // 792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  float check = 792281620327574798336.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float32) {
  // -792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  float check = -792281620327574798336.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float33) {
  // 2099546306628004946228.9146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x70000}};
  float check = 2099546339607756931072.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float34) {
  // -2099546306628004946228.9146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80070000}};
  float check = -2099546339607756931072.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float35) {
  // 79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  float check = 79228160273538875392.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float36) {
  // -79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  float check = -79228160273538875392.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float37) {
  // 209954630662800494622.89146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80000}};
  float check = 209954630442338484224.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float38) {
  // -209954630662800494622.89146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80080000}};
  float check = -209954630442338484224.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float39) {
  // 7922816251426433759.3543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};
  float check = 7922816357207375872.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float40) {
  // -7922816251426433759.3543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};
  float check = -7922816357207375872.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float41) {
  // 20995463066280049462.289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x90000}};
  float check = 20995462604429197312.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float42) {
  // -20995463066280049462.289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80090000}};
  float check = -20995462604429197312.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float43) {
  // 792281625142643375.93543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};
  float check = 792281621976842240.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float44) {
  // -792281625142643375.93543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};
  float check = -792281621976842240.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float45) {
  // 2099546306628004946.2289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xA0000}};
  float check = 2099546315418501120.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float46) {
  // -2099546306628004946.2289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800A0000}};
  float check = -2099546315418501120.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float47) {
  // 79228162514264337.593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};
  float check = 79228162197684224.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float48) {
  // -79228162514264337.593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};
  float check = -79228162197684224.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float49) {
  // 209954630662800494.62289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xB0000}};
  float check = 209954631541850112.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float50) {
  // -209954630662800494.62289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800B0000}};
  float check = -209954631541850112.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float51) {
  // 7922816251426433.7593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};
  float check = 7922816112394240.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float52) {
  // -7922816251426433.7593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};
  float check = -7922816112394240.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float53) {
  // 20995463066280049.462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xC0000}};
  float check = 20995462295191552.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float54) {
  // -20995463066280049.462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800C0000}};
  float check = -20995462295191552.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float55) {
  // 792281625142643.37593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  float check = 792281611239424.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float56) {
  // -792281625142643.37593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  float check = -792281611239424.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float57) {
  // 2099546306628004.9462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xD0000}};
  float check = 2099546310049792.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float58) {
  // -2099546306628004.9462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800D0000}};
  float check = -2099546310049792.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float59) {
  // 79228162514264.337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};
  float check = 79228162801664.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float60) {
  // -79228162514264.337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  float check = -79228162801664.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float61) {
  // 209954630662800.49462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xE0000}};
  float check = 209954627649536.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float62) {
  // -209954630662800.49462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800E0000}};
  float check = -209954627649536.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float63) {
  // 7922816251426.4337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};
  float check = 7922816385024.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float64) {
  // -7922816251426.4337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  float check = -7922816385024.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float65) {
  // 20995463066280.049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xF0000}};
  float check = 20995463184384.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float66) {
  // -20995463066280.049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800F0000}};
  float check = -20995463184384.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float67) {
  // 792281625142.64337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};
  float check = 792281612288.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float68) {
  // -792281625142.64337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};
  float check = -792281612288.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float69) {
  // 2099546306628.0049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x100000}};
  float check = 2099546292224.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float70) {
  // -2099546306628.0049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80100000}};
  float check = -2099546292224.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float71) {
  // 79228162514.264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};
  float check = 79228166144.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float72) {
  // -79228162514.264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};
  float check = -79228166144.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float73) {
  // 209954630662.80049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x110000}};
  float check = 209954635776.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float74) {
  // -209954630662.80049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80110000}};
  float check = -209954635776.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float75) {
  // 7922816251.4264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};
  float check = 7922816000.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float76) {
  // -7922816251.4264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};
  float check = -7922816000.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float77) {
  // 20995463066.280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x120000}};
  float check = 20995463168.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float78) {
  // -20995463066.280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80120000}};
  float check = -20995463168.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float79) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  float check = 792281600.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float80) {
  // -792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  float check = -792281600.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float81) {
  // 2099546306.6280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x130000}};
  float check = 2099546368.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float82) {
  // -2099546306.6280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80130000}};
  float check = -2099546368.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float83) {
  // 79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  float check = 79228160.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float84) {
  // -79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  float check = -79228160.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float85) {
  // 209954630.66280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x140000}};
  float check = 209954624.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float86) {
  // -209954630.66280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80140000}};
  float check = -209954624.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float87) {
  // 7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  float check = 7922816.500000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float88) {
  // -7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  float check = -7922816.500000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float89) {
  // 20995463.066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x150000}};
  float check = 20995464.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float90) {
  // -20995463.066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80150000}};
  float check = -20995464.000000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float91) {
  // 792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  float check = 792281.625000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float92) {
  // -792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  float check = -792281.625000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float93) {
  // 2099546.3066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x160000}};
  float check = 2099546.250000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float94) {
  // -2099546.3066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80160000}};
  float check = -2099546.250000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float95) {
  // 79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  float check = 79228.164062;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float96) {
  // -79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  float check = -79228.164062;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float97) {
  // 209954.63066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x170000}};
  float check = 209954.625000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float98) {
  // -209954.63066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80170000}};
  float check = -209954.625000;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float99) {
  // 7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  float check = 7922.816406;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

START_TEST(test_from_decimal_to_float100) {
  // -7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  float check = -7922.816406;
  float result = check;
  ck_assert_int_eq(S21_OK, s21_from_decimal_to_float(decimal, &result));
  ck_assert_float_eq_tol(check, result, ACCU);
}
END_TEST

Suite *from_decimal_to_float_suite(void) {
  Suite *s1 = suite_create("test_from_decimal_to_float");
  TCase *tc = tcase_create("test_from_decimal_to_float");
  suite_add_tcase(s1, tc);
  tcase_add_test(tc, test_from_decimal_to_float_manual1);
  tcase_add_test(tc, test_from_decimal_to_float_manual2);
  tcase_add_test(tc, test_from_decimal_to_float_manual3);
  tcase_add_test(tc, test_from_decimal_to_float_manual4);
  tcase_add_test(tc, test_from_decimal_to_float_manual5);
  tcase_add_test(tc, test_from_decimal_to_float_manual6);
  tcase_add_test(tc, test_from_decimal_to_float_manual7);
  tcase_add_test(tc, test_from_decimal_to_float_manual8);
  tcase_add_test(tc, test_from_decimal_to_float1);
  tcase_add_test(tc, test_from_decimal_to_float2);
  tcase_add_test(tc, test_from_decimal_to_float3);
  tcase_add_test(tc, test_from_decimal_to_float4);
  tcase_add_test(tc, test_from_decimal_to_float5);
  tcase_add_test(tc, test_from_decimal_to_float6);
  tcase_add_test(tc, test_from_decimal_to_float7);
  tcase_add_test(tc, test_from_decimal_to_float8);
  tcase_add_test(tc, test_from_decimal_to_float9);
  tcase_add_test(tc, test_from_decimal_to_float10);
  tcase_add_test(tc, test_from_decimal_to_float11);
  tcase_add_test(tc, test_from_decimal_to_float12);
  tcase_add_test(tc, test_from_decimal_to_float13);
  tcase_add_test(tc, test_from_decimal_to_float14);
  tcase_add_test(tc, test_from_decimal_to_float15);
  tcase_add_test(tc, test_from_decimal_to_float16);
  tcase_add_test(tc, test_from_decimal_to_float17);
  tcase_add_test(tc, test_from_decimal_to_float18);
  tcase_add_test(tc, test_from_decimal_to_float19);
  tcase_add_test(tc, test_from_decimal_to_float20);
  tcase_add_test(tc, test_from_decimal_to_float21);
  tcase_add_test(tc, test_from_decimal_to_float22);
  tcase_add_test(tc, test_from_decimal_to_float23);
  tcase_add_test(tc, test_from_decimal_to_float24);
  tcase_add_test(tc, test_from_decimal_to_float25);
  tcase_add_test(tc, test_from_decimal_to_float26);
  tcase_add_test(tc, test_from_decimal_to_float27);
  tcase_add_test(tc, test_from_decimal_to_float28);
  tcase_add_test(tc, test_from_decimal_to_float29);
  tcase_add_test(tc, test_from_decimal_to_float30);
  tcase_add_test(tc, test_from_decimal_to_float31);
  tcase_add_test(tc, test_from_decimal_to_float32);
  tcase_add_test(tc, test_from_decimal_to_float33);
  tcase_add_test(tc, test_from_decimal_to_float34);
  tcase_add_test(tc, test_from_decimal_to_float35);
  tcase_add_test(tc, test_from_decimal_to_float36);
  tcase_add_test(tc, test_from_decimal_to_float37);
  tcase_add_test(tc, test_from_decimal_to_float38);
  tcase_add_test(tc, test_from_decimal_to_float39);
  tcase_add_test(tc, test_from_decimal_to_float40);
  tcase_add_test(tc, test_from_decimal_to_float41);
  tcase_add_test(tc, test_from_decimal_to_float42);
  tcase_add_test(tc, test_from_decimal_to_float43);
  tcase_add_test(tc, test_from_decimal_to_float44);
  tcase_add_test(tc, test_from_decimal_to_float45);
  tcase_add_test(tc, test_from_decimal_to_float46);
  tcase_add_test(tc, test_from_decimal_to_float47);
  tcase_add_test(tc, test_from_decimal_to_float48);
  tcase_add_test(tc, test_from_decimal_to_float49);
  tcase_add_test(tc, test_from_decimal_to_float50);
  tcase_add_test(tc, test_from_decimal_to_float51);
  tcase_add_test(tc, test_from_decimal_to_float52);
  tcase_add_test(tc, test_from_decimal_to_float53);
  tcase_add_test(tc, test_from_decimal_to_float54);
  tcase_add_test(tc, test_from_decimal_to_float55);
  tcase_add_test(tc, test_from_decimal_to_float56);
  tcase_add_test(tc, test_from_decimal_to_float57);
  tcase_add_test(tc, test_from_decimal_to_float58);
  tcase_add_test(tc, test_from_decimal_to_float59);
  tcase_add_test(tc, test_from_decimal_to_float60);
  tcase_add_test(tc, test_from_decimal_to_float61);
  tcase_add_test(tc, test_from_decimal_to_float62);
  tcase_add_test(tc, test_from_decimal_to_float63);
  tcase_add_test(tc, test_from_decimal_to_float64);
  tcase_add_test(tc, test_from_decimal_to_float65);
  tcase_add_test(tc, test_from_decimal_to_float66);
  tcase_add_test(tc, test_from_decimal_to_float67);
  tcase_add_test(tc, test_from_decimal_to_float68);
  tcase_add_test(tc, test_from_decimal_to_float69);
  tcase_add_test(tc, test_from_decimal_to_float70);
  tcase_add_test(tc, test_from_decimal_to_float71);
  tcase_add_test(tc, test_from_decimal_to_float72);
  tcase_add_test(tc, test_from_decimal_to_float73);
  tcase_add_test(tc, test_from_decimal_to_float74);
  tcase_add_test(tc, test_from_decimal_to_float75);
  tcase_add_test(tc, test_from_decimal_to_float76);
  tcase_add_test(tc, test_from_decimal_to_float77);
  tcase_add_test(tc, test_from_decimal_to_float78);
  tcase_add_test(tc, test_from_decimal_to_float79);
  tcase_add_test(tc, test_from_decimal_to_float80);
  tcase_add_test(tc, test_from_decimal_to_float81);
  tcase_add_test(tc, test_from_decimal_to_float82);
  tcase_add_test(tc, test_from_decimal_to_float83);
  tcase_add_test(tc, test_from_decimal_to_float84);
  tcase_add_test(tc, test_from_decimal_to_float85);
  tcase_add_test(tc, test_from_decimal_to_float86);
  tcase_add_test(tc, test_from_decimal_to_float87);
  tcase_add_test(tc, test_from_decimal_to_float88);
  tcase_add_test(tc, test_from_decimal_to_float89);
  tcase_add_test(tc, test_from_decimal_to_float90);
  tcase_add_test(tc, test_from_decimal_to_float91);
  tcase_add_test(tc, test_from_decimal_to_float92);
  tcase_add_test(tc, test_from_decimal_to_float93);
  tcase_add_test(tc, test_from_decimal_to_float94);
  tcase_add_test(tc, test_from_decimal_to_float95);
  tcase_add_test(tc, test_from_decimal_to_float96);
  tcase_add_test(tc, test_from_decimal_to_float97);
  tcase_add_test(tc, test_from_decimal_to_float98);
  tcase_add_test(tc, test_from_decimal_to_float99);
  tcase_add_test(tc, test_from_decimal_to_float100);
  return s1;
}