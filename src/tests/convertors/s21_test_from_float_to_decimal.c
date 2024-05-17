#include "s21_test_convertors.h"

START_TEST(test_from_float_to_decimal_manual1) {
  float f = 0.0;
  s21_decimal result;
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}
END_TEST

START_TEST(test_from_float_to_decimal_manual2) {
  float f = -0.0;
  s21_decimal result;
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}
END_TEST

START_TEST(test_from_float_to_decimal_manual3) {
  float f = INFINITY;
  s21_decimal result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_manual4) {
  float f = -INFINITY;
  s21_decimal result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_manual5) {
  float f = NAN;
  s21_decimal result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_manual6) {
  float f = -NAN;
  s21_decimal result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_manual7) {
  float f = 1.0f;
  ck_assert_int_eq(s21_from_float_to_decimal(f, NULL), S21_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_manual8) {
  float f = 340282346638528859811704183484516925440.f;
  s21_decimal result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_manual9) {
  float f = -340282346638528859811704183484516925440.f;
  s21_decimal result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_manual10) {
  float f =
      0.00000000000000000000000000009999999429857660888699309391359540480357727713304344f;
  s21_decimal result;
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_ERROR);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}
END_TEST

START_TEST(test_from_float_to_decimal_manual11) {
  float f =
      -0.00000000000000000000000000009999998828004553267688105311366433422567940670147579f;
  s21_decimal result;
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_ERROR);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}
END_TEST

START_TEST(test_from_float_to_decimal1) {
  // 2.28401628E-19
  float f = 2.28401628E-19;
  // 0.0000000000000000002284016
  s21_decimal result = {{0x22D9F0, 0x0, 0x0, 0x190000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal2) {
  // -2.28401628E-19
  float f = -2.28401628E-19;
  // -0.0000000000000000002284016
  s21_decimal result = {{0x22D9F0, 0x0, 0x0, 0x80190000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal3) {
  // 5.92141241E+23
  float f = 5.92141241E+23;
  // 592141200000000000000000
  s21_decimal result = {{0xBF280000, 0x9ED0576, 0x7D64, 0x0}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal4) {
  // -5.92141241E+23
  float f = -5.92141241E+23;
  // -592141200000000000000000
  s21_decimal result = {{0xBF280000, 0x9ED0576, 0x7D64, 0x80000000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal5) {
  // 2.1349025E-18
  float f = 2.1349025E-18;
  // 0.000000000000000002134902
  s21_decimal result = {{0x209376, 0x0, 0x0, 0x180000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal6) {
  // -2.1349025E-18
  float f = -2.1349025E-18;
  // -0.000000000000000002134902
  s21_decimal result = {{0x209376, 0x0, 0x0, 0x80180000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal7) {
  // 2.38582807E-08
  float f = 2.38582807E-08;
  // 0.00000002385828
  s21_decimal result = {{0x2467A4, 0x0, 0x0, 0xE0000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal8) {
  // -2.38582807E-08
  float f = -2.38582807E-08;
  // -0.00000002385828
  s21_decimal result = {{0x2467A4, 0x0, 0x0, 0x800E0000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal9) {
  // 7.91617864E+11
  float f = 7.91617864E+11;
  // 791617900000
  s21_decimal result = {{0x501A8DE0, 0xB8, 0x0, 0x0}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal10) {
  // -7.91617864E+11
  float f = -7.91617864E+11;
  // -791617900000
  s21_decimal result = {{0x501A8DE0, 0xB8, 0x0, 0x80000000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal11) {
  // 1.99102057E+21
  float f = 1.99102057E+21;
  // 1991021000000000000000
  s21_decimal result = {{0x5F048000, 0xEEF78A9E, 0x6B, 0x0}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal12) {
  // -1.99102057E+21
  float f = -1.99102057E+21;
  // -1991021000000000000000
  s21_decimal result = {{0x5F048000, 0xEEF78A9E, 0x6B, 0x80000000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal13) {
  // 9.29209423E+24
  float f = 9.29209423E+24;
  // 9292094000000000000000000
  s21_decimal result = {{0xE380000, 0x6CD28004, 0x7AFAD, 0x0}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal14) {
  // -9.29209423E+24
  float f = -9.29209423E+24;
  // -9292094000000000000000000
  s21_decimal result = {{0xE380000, 0x6CD28004, 0x7AFAD, 0x80000000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal15) {
  // 0.000115481133
  float f = 0.000115481133;
  // 0.0001154811
  s21_decimal result = {{0x119EFB, 0x0, 0x0, 0xA0000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal16) {
  // -0.000115481133
  float f = -0.000115481133;
  // -0.0001154811
  s21_decimal result = {{0x119EFB, 0x0, 0x0, 0x800A0000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal17) {
  // 8.66900895E-23
  float f = 8.66900895E-23;
  // 0.0000000000000000000000866901
  s21_decimal result = {{0xD3A55, 0x0, 0x0, 0x1C0000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal18) {
  // -8.66900895E-23
  float f = -8.66900895E-23;
  // -0.0000000000000000000000866901
  s21_decimal result = {{0xD3A55, 0x0, 0x0, 0x801C0000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal19) {
  // 3.91406387E+11
  float f = 3.91406387E+11;
  // 391406400000
  s21_decimal result = {{0x21A3B200, 0x5B, 0x0, 0x0}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal20) {
  // -3.91406387E+11
  float f = -3.91406387E+11;
  // -391406400000
  s21_decimal result = {{0x21A3B200, 0x5B, 0x0, 0x80000000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal21) {
  // 1.54636995E-16
  float f = 1.54636995E-16;
  // 0.000000000000000154637
  s21_decimal result = {{0x25C0D, 0x0, 0x0, 0x150000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal22) {
  // -1.54636995E-16
  float f = -1.54636995E-16;
  // -0.000000000000000154637
  s21_decimal result = {{0x25C0D, 0x0, 0x0, 0x80150000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal23) {
  // 1.05583253E-13
  float f = 1.05583253E-13;
  // 0.0000000000001055833
  s21_decimal result = {{0x101C59, 0x0, 0x0, 0x130000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal24) {
  // -1.05583253E-13
  float f = -1.05583253E-13;
  // -0.0000000000001055833
  s21_decimal result = {{0x101C59, 0x0, 0x0, 0x80130000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal25) {
  // 4882.71582
  float f = 4882.71582;
  // 4882.716
  s21_decimal result = {{0x4A811C, 0x0, 0x0, 0x30000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal26) {
  // -4882.71582
  float f = -4882.71582;
  // -4882.716
  s21_decimal result = {{0x4A811C, 0x0, 0x0, 0x80030000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal27) {
  // 1.9929916E-26
  float f = 1.9929916E-26;
  // 0.0000000000000000000000000199
  s21_decimal result = {{0xC7, 0x0, 0x0, 0x1C0000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal28) {
  // -1.9929916E-26
  float f = -1.9929916E-26;
  // -0.0000000000000000000000000199
  s21_decimal result = {{0xC7, 0x0, 0x0, 0x801C0000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal29) {
  // 3574.10864
  float f = 3574.10864;
  // 3574.109
  s21_decimal result = {{0x36895D, 0x0, 0x0, 0x30000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal30) {
  // -3574.10864
  float f = -3574.10864;
  // -3574.109
  s21_decimal result = {{0x36895D, 0x0, 0x0, 0x80030000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal31) {
  // 3.62930687E-13
  float f = 3.62930687E-13;
  // 0.0000000000003629307
  s21_decimal result = {{0x3760FB, 0x0, 0x0, 0x130000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal32) {
  // -3.62930687E-13
  float f = -3.62930687E-13;
  // -0.0000000000003629307
  s21_decimal result = {{0x3760FB, 0x0, 0x0, 0x80130000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal33) {
  // 2.1409382E-19
  float f = 2.1409382E-19;
  // 0.0000000000000000002140938
  s21_decimal result = {{0x20AB0A, 0x0, 0x0, 0x190000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal34) {
  // -2.1409382E-19
  float f = -2.1409382E-19;
  // -0.0000000000000000002140938
  s21_decimal result = {{0x20AB0A, 0x0, 0x0, 0x80190000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal35) {
  // 241.244507
  float f = 241.244507;
  // 241.2445
  s21_decimal result = {{0x24CF9D, 0x0, 0x0, 0x40000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal36) {
  // -241.244507
  float f = -241.244507;
  // -241.2445
  s21_decimal result = {{0x24CF9D, 0x0, 0x0, 0x80040000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal37) {
  // 802580.063
  float f = 802580.063;
  // 802580.1
  s21_decimal result = {{0x7A76C9, 0x0, 0x0, 0x10000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal38) {
  // -802580.063
  float f = -802580.063;
  // -802580.1
  s21_decimal result = {{0x7A76C9, 0x0, 0x0, 0x80010000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal39) {
  // 8.38680669E+16
  float f = 8.38680669E+16;
  // 83868070000000000
  s21_decimal result = {{0xB858FC00, 0x129F590, 0x0, 0x0}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal40) {
  // -8.38680669E+16
  float f = -8.38680669E+16;
  // -83868070000000000
  s21_decimal result = {{0xB858FC00, 0x129F590, 0x0, 0x80000000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal41) {
  // 3.93541897E-17
  float f = 3.93541897E-17;
  // 0.00000000000000003935419
  s21_decimal result = {{0x3C0CBB, 0x0, 0x0, 0x170000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal42) {
  // -3.93541897E-17
  float f = -3.93541897E-17;
  // -0.00000000000000003935419
  s21_decimal result = {{0x3C0CBB, 0x0, 0x0, 0x80170000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal43) {
  // 1.45764168E-20
  float f = 1.45764168E-20;
  // 0.00000000000000000001457642
  s21_decimal result = {{0x163DEA, 0x0, 0x0, 0x1A0000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal44) {
  // -1.45764168E-20
  float f = -1.45764168E-20;
  // -0.00000000000000000001457642
  s21_decimal result = {{0x163DEA, 0x0, 0x0, 0x801A0000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal45) {
  // 1.34647118E+20
  float f = 1.34647118E+20;
  // 134647100000000000000
  s21_decimal result = {{0x207FC000, 0x4C9A980F, 0x7, 0x0}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal46) {
  // -1.34647118E+20
  float f = -1.34647118E+20;
  // -134647100000000000000
  s21_decimal result = {{0x207FC000, 0x4C9A980F, 0x7, 0x80000000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal47) {
  // 2.20958198E-20
  float f = 2.20958198E-20;
  // 0.00000000000000000002209582
  s21_decimal result = {{0x21B72E, 0x0, 0x0, 0x1A0000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal48) {
  // -2.20958198E-20
  float f = -2.20958198E-20;
  // -0.00000000000000000002209582
  s21_decimal result = {{0x21B72E, 0x0, 0x0, 0x801A0000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal49) {
  // 5.36623235E-09
  float f = 5.36623235E-09;
  // 0.000000005366232
  s21_decimal result = {{0x51E1D8, 0x0, 0x0, 0xF0000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal50) {
  // -5.36623235E-09
  float f = -5.36623235E-09;
  // -0.000000005366232
  s21_decimal result = {{0x51E1D8, 0x0, 0x0, 0x800F0000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal51) {
  // 4.71008997E+17
  float f = 4.71008997E+17;
  // 471009000000000000
  s21_decimal result = {{0xA3031000, 0x6895C30, 0x0, 0x0}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal52) {
  // -4.71008997E+17
  float f = -4.71008997E+17;
  // -471009000000000000
  s21_decimal result = {{0xA3031000, 0x6895C30, 0x0, 0x80000000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal53) {
  // 2.36363464E-11
  float f = 2.36363464E-11;
  // 0.00000000002363635
  s21_decimal result = {{0x2410F3, 0x0, 0x0, 0x110000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal54) {
  // -2.36363464E-11
  float f = -2.36363464E-11;
  // -0.00000000002363635
  s21_decimal result = {{0x2410F3, 0x0, 0x0, 0x80110000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal55) {
  // 0.0255207196
  float f = 0.0255207196;
  // 0.02552072
  s21_decimal result = {{0x26F108, 0x0, 0x0, 0x80000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal56) {
  // -0.0255207196
  float f = -0.0255207196;
  // -0.02552072
  s21_decimal result = {{0x26F108, 0x0, 0x0, 0x80080000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal57) {
  // 3.9575282E-24
  float f = 3.9575282E-24;
  // 0.0000000000000000000000039575
  s21_decimal result = {{0x9A97, 0x0, 0x0, 0x1C0000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal58) {
  // -3.9575282E-24
  float f = -3.9575282E-24;
  // -0.0000000000000000000000039575
  s21_decimal result = {{0x9A97, 0x0, 0x0, 0x801C0000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal59) {
  // 0.00399137754
  float f = 0.00399137754;
  // 0.003991378
  s21_decimal result = {{0x3CE752, 0x0, 0x0, 0x90000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal60) {
  // -0.00399137754
  float f = -0.00399137754;
  // -0.003991378
  s21_decimal result = {{0x3CE752, 0x0, 0x0, 0x80090000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal61) {
  // 1.95127377E-05
  float f = 1.95127377E-05;
  // 0.00001951274
  s21_decimal result = {{0x1DC62A, 0x0, 0x0, 0xB0000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal62) {
  // -1.95127377E-05
  float f = -1.95127377E-05;
  // -0.00001951274
  s21_decimal result = {{0x1DC62A, 0x0, 0x0, 0x800B0000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal63) {
  // 1.26745242E-20
  float f = 1.26745242E-20;
  // 0.00000000000000000001267452
  s21_decimal result = {{0x1356FC, 0x0, 0x0, 0x1A0000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal64) {
  // -1.26745242E-20
  float f = -1.26745242E-20;
  // -0.00000000000000000001267452
  s21_decimal result = {{0x1356FC, 0x0, 0x0, 0x801A0000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal65) {
  // 0.0764362067
  float f = 0.0764362067;
  // 0.07643621
  s21_decimal result = {{0x74A1E5, 0x0, 0x0, 0x80000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal66) {
  // -0.0764362067
  float f = -0.0764362067;
  // -0.07643621
  s21_decimal result = {{0x74A1E5, 0x0, 0x0, 0x80080000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal67) {
  // 1.19421885E-18
  float f = 1.19421885E-18;
  // 0.000000000000000001194219
  s21_decimal result = {{0x1238EB, 0x0, 0x0, 0x180000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal68) {
  // -1.19421885E-18
  float f = -1.19421885E-18;
  // -0.000000000000000001194219
  s21_decimal result = {{0x1238EB, 0x0, 0x0, 0x80180000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal69) {
  // 7.93902012E-16
  float f = 7.93902012E-16;
  // 0.000000000000000793902
  s21_decimal result = {{0xC1D2E, 0x0, 0x0, 0x150000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal70) {
  // -7.93902012E-16
  float f = -7.93902012E-16;
  // -0.000000000000000793902
  s21_decimal result = {{0xC1D2E, 0x0, 0x0, 0x80150000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal71) {
  // 5.86327048E-15
  float f = 5.86327048E-15;
  // 0.00000000000000586327
  s21_decimal result = {{0x8F257, 0x0, 0x0, 0x140000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal72) {
  // -5.86327048E-15
  float f = -5.86327048E-15;
  // -0.00000000000000586327
  s21_decimal result = {{0x8F257, 0x0, 0x0, 0x80140000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal73) {
  // 8.52215659E-11
  float f = 8.52215659E-11;
  // 0.00000000008522157
  s21_decimal result = {{0x8209AD, 0x0, 0x0, 0x110000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal74) {
  // -8.52215659E-11
  float f = -8.52215659E-11;
  // -0.00000000008522157
  s21_decimal result = {{0x8209AD, 0x0, 0x0, 0x80110000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal75) {
  // 9.61645806E-28
  float f = 9.61645806E-28;
  // 0.000000000000000000000000001
  s21_decimal result = {{0x1, 0x0, 0x0, 0x1B0000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal76) {
  // -9.61645806E-28
  float f = -9.61645806E-28;
  // -0.000000000000000000000000001
  s21_decimal result = {{0x1, 0x0, 0x0, 0x801B0000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal77) {
  // 46282560
  float f = 46282560;
  // 46282560
  s21_decimal result = {{0x2C23740, 0x0, 0x0, 0x0}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal78) {
  // -46282560
  float f = -46282560;
  // -46282560
  s21_decimal result = {{0x2C23740, 0x0, 0x0, 0x80000000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal79) {
  // 1.15109615E-12
  float f = 1.15109615E-12;
  // 0.000000000001151096
  s21_decimal result = {{0x119078, 0x0, 0x0, 0x120000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal80) {
  // -1.15109615E-12
  float f = -1.15109615E-12;
  // -0.000000000001151096
  s21_decimal result = {{0x119078, 0x0, 0x0, 0x80120000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal81) {
  // 2.83794689E-11
  float f = 2.83794689E-11;
  // 0.00000000002837947
  s21_decimal result = {{0x2B4DBB, 0x0, 0x0, 0x110000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal82) {
  // -2.83794689E-11
  float f = -2.83794689E-11;
  // -0.00000000002837947
  s21_decimal result = {{0x2B4DBB, 0x0, 0x0, 0x80110000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal83) {
  // 8.43187742E-10
  float f = 8.43187742E-10;
  // 0.0000000008431877
  s21_decimal result = {{0x80A905, 0x0, 0x0, 0x100000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal84) {
  // -8.43187742E-10
  float f = -8.43187742E-10;
  // -0.0000000008431877
  s21_decimal result = {{0x80A905, 0x0, 0x0, 0x80100000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal85) {
  // 9.83161032E+17
  float f = 9.83161032E+17;
  // 983161000000000000
  s21_decimal result = {{0x72049000, 0xDA4E3B8, 0x0, 0x0}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal86) {
  // -9.83161032E+17
  float f = -9.83161032E+17;
  // -983161000000000000
  s21_decimal result = {{0x72049000, 0xDA4E3B8, 0x0, 0x80000000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal87) {
  // 5010.18115
  float f = 5010.18115;
  // 5010.181
  s21_decimal result = {{0x4C7305, 0x0, 0x0, 0x30000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal88) {
  // -5010.18115
  float f = -5010.18115;
  // -5010.181
  s21_decimal result = {{0x4C7305, 0x0, 0x0, 0x80030000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal89) {
  // 5.82704236E-25
  float f = 5.82704236E-25;
  // 0.0000000000000000000000005827
  s21_decimal result = {{0x16C3, 0x0, 0x0, 0x1C0000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal90) {
  // -5.82704236E-25
  float f = -5.82704236E-25;
  // -0.0000000000000000000000005827
  s21_decimal result = {{0x16C3, 0x0, 0x0, 0x801C0000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal91) {
  // 5.07265574E+16
  float f = 5.07265574E+16;
  // 50726560000000000
  s21_decimal result = {{0x9D7A4000, 0xB43789, 0x0, 0x0}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal92) {
  // -5.07265574E+16
  float f = -5.07265574E+16;
  // -50726560000000000
  s21_decimal result = {{0x9D7A4000, 0xB43789, 0x0, 0x80000000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal93) {
  // 1.35639493E+19
  float f = 1.35639493E+19;
  // 13563950000000000000
  s21_decimal result = {{0xFD28E000, 0xBC3CD4A8, 0x0, 0x0}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal94) {
  // -1.35639493E+19
  float f = -1.35639493E+19;
  // -13563950000000000000
  s21_decimal result = {{0xFD28E000, 0xBC3CD4A8, 0x0, 0x80000000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal95) {
  // 1.2867606E+27
  float f = 1.2867606E+27;
  // 1286761000000000000000000000
  s21_decimal result = {{0x8FA00000, 0x955F02E9, 0x428623D, 0x0}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal96) {
  // -1.2867606E+27
  float f = -1.2867606E+27;
  // -1286761000000000000000000000
  s21_decimal result = {{0x8FA00000, 0x955F02E9, 0x428623D, 0x80000000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal97) {
  // 9.07980924E+20
  float f = 9.07980924E+20;
  // 907980900000000000000
  s21_decimal result = {{0x6B7A4000, 0x38C429DC, 0x31, 0x0}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal98) {
  // -9.07980924E+20
  float f = -9.07980924E+20;
  // -907980900000000000000
  s21_decimal result = {{0x6B7A4000, 0x38C429DC, 0x31, 0x80000000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal99) {
  // 15372566
  float f = 15372566;
  // 15372570
  s21_decimal result = {{0xEA911A, 0x0, 0x0, 0x0}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

START_TEST(test_from_float_to_decimal100) {
  // -15372566
  float f = -15372566;
  // -15372570
  s21_decimal result = {{0xEA911A, 0x0, 0x0, 0x80000000}};
  s21_decimal check = result;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(result, check), S21_TRUE);
}

Suite *from_float_to_decimal_suite(void) {
  Suite *s1 = suite_create("test_from_float_to_decimal");
  TCase *tc = tcase_create("test_from_float_to_decimal");
  suite_add_tcase(s1, tc);
  tcase_add_test(tc, test_from_float_to_decimal_manual1);
  tcase_add_test(tc, test_from_float_to_decimal_manual2);
  tcase_add_test(tc, test_from_float_to_decimal_manual3);
  tcase_add_test(tc, test_from_float_to_decimal_manual4);
  tcase_add_test(tc, test_from_float_to_decimal_manual5);
  tcase_add_test(tc, test_from_float_to_decimal_manual6);
  tcase_add_test(tc, test_from_float_to_decimal_manual7);
  tcase_add_test(tc, test_from_float_to_decimal_manual8);
  tcase_add_test(tc, test_from_float_to_decimal_manual9);
  tcase_add_test(tc, test_from_float_to_decimal_manual10);
  tcase_add_test(tc, test_from_float_to_decimal_manual11);
  tcase_add_test(tc, test_from_float_to_decimal1);
  tcase_add_test(tc, test_from_float_to_decimal2);
  tcase_add_test(tc, test_from_float_to_decimal3);
  tcase_add_test(tc, test_from_float_to_decimal4);
  tcase_add_test(tc, test_from_float_to_decimal5);
  tcase_add_test(tc, test_from_float_to_decimal6);
  tcase_add_test(tc, test_from_float_to_decimal7);
  tcase_add_test(tc, test_from_float_to_decimal8);
  tcase_add_test(tc, test_from_float_to_decimal9);
  tcase_add_test(tc, test_from_float_to_decimal10);
  tcase_add_test(tc, test_from_float_to_decimal11);
  tcase_add_test(tc, test_from_float_to_decimal12);
  tcase_add_test(tc, test_from_float_to_decimal13);
  tcase_add_test(tc, test_from_float_to_decimal14);
  tcase_add_test(tc, test_from_float_to_decimal15);
  tcase_add_test(tc, test_from_float_to_decimal16);
  tcase_add_test(tc, test_from_float_to_decimal17);
  tcase_add_test(tc, test_from_float_to_decimal18);
  tcase_add_test(tc, test_from_float_to_decimal19);
  tcase_add_test(tc, test_from_float_to_decimal20);
  tcase_add_test(tc, test_from_float_to_decimal21);
  tcase_add_test(tc, test_from_float_to_decimal22);
  tcase_add_test(tc, test_from_float_to_decimal23);
  tcase_add_test(tc, test_from_float_to_decimal24);
  tcase_add_test(tc, test_from_float_to_decimal25);
  tcase_add_test(tc, test_from_float_to_decimal26);
  tcase_add_test(tc, test_from_float_to_decimal27);
  tcase_add_test(tc, test_from_float_to_decimal28);
  tcase_add_test(tc, test_from_float_to_decimal29);
  tcase_add_test(tc, test_from_float_to_decimal30);
  tcase_add_test(tc, test_from_float_to_decimal31);
  tcase_add_test(tc, test_from_float_to_decimal32);
  tcase_add_test(tc, test_from_float_to_decimal33);
  tcase_add_test(tc, test_from_float_to_decimal34);
  tcase_add_test(tc, test_from_float_to_decimal35);
  tcase_add_test(tc, test_from_float_to_decimal36);
  tcase_add_test(tc, test_from_float_to_decimal37);
  tcase_add_test(tc, test_from_float_to_decimal38);
  tcase_add_test(tc, test_from_float_to_decimal39);
  tcase_add_test(tc, test_from_float_to_decimal40);
  tcase_add_test(tc, test_from_float_to_decimal41);
  tcase_add_test(tc, test_from_float_to_decimal42);
  tcase_add_test(tc, test_from_float_to_decimal43);
  tcase_add_test(tc, test_from_float_to_decimal44);
  tcase_add_test(tc, test_from_float_to_decimal45);
  tcase_add_test(tc, test_from_float_to_decimal46);
  tcase_add_test(tc, test_from_float_to_decimal47);
  tcase_add_test(tc, test_from_float_to_decimal48);
  tcase_add_test(tc, test_from_float_to_decimal49);
  tcase_add_test(tc, test_from_float_to_decimal50);
  tcase_add_test(tc, test_from_float_to_decimal51);
  tcase_add_test(tc, test_from_float_to_decimal52);
  tcase_add_test(tc, test_from_float_to_decimal53);
  tcase_add_test(tc, test_from_float_to_decimal54);
  tcase_add_test(tc, test_from_float_to_decimal55);
  tcase_add_test(tc, test_from_float_to_decimal56);
  tcase_add_test(tc, test_from_float_to_decimal57);
  tcase_add_test(tc, test_from_float_to_decimal58);
  tcase_add_test(tc, test_from_float_to_decimal59);
  tcase_add_test(tc, test_from_float_to_decimal60);
  tcase_add_test(tc, test_from_float_to_decimal61);
  tcase_add_test(tc, test_from_float_to_decimal62);
  tcase_add_test(tc, test_from_float_to_decimal63);
  tcase_add_test(tc, test_from_float_to_decimal64);
  tcase_add_test(tc, test_from_float_to_decimal65);
  tcase_add_test(tc, test_from_float_to_decimal66);
  tcase_add_test(tc, test_from_float_to_decimal67);
  tcase_add_test(tc, test_from_float_to_decimal68);
  tcase_add_test(tc, test_from_float_to_decimal69);
  tcase_add_test(tc, test_from_float_to_decimal70);
  tcase_add_test(tc, test_from_float_to_decimal71);
  tcase_add_test(tc, test_from_float_to_decimal72);
  tcase_add_test(tc, test_from_float_to_decimal73);
  tcase_add_test(tc, test_from_float_to_decimal74);
  tcase_add_test(tc, test_from_float_to_decimal75);
  tcase_add_test(tc, test_from_float_to_decimal76);
  tcase_add_test(tc, test_from_float_to_decimal77);
  tcase_add_test(tc, test_from_float_to_decimal78);
  tcase_add_test(tc, test_from_float_to_decimal79);
  tcase_add_test(tc, test_from_float_to_decimal80);
  tcase_add_test(tc, test_from_float_to_decimal81);
  tcase_add_test(tc, test_from_float_to_decimal82);
  tcase_add_test(tc, test_from_float_to_decimal83);
  tcase_add_test(tc, test_from_float_to_decimal84);
  tcase_add_test(tc, test_from_float_to_decimal85);
  tcase_add_test(tc, test_from_float_to_decimal86);
  tcase_add_test(tc, test_from_float_to_decimal87);
  tcase_add_test(tc, test_from_float_to_decimal88);
  tcase_add_test(tc, test_from_float_to_decimal89);
  tcase_add_test(tc, test_from_float_to_decimal90);
  tcase_add_test(tc, test_from_float_to_decimal91);
  tcase_add_test(tc, test_from_float_to_decimal92);
  tcase_add_test(tc, test_from_float_to_decimal93);
  tcase_add_test(tc, test_from_float_to_decimal94);
  tcase_add_test(tc, test_from_float_to_decimal95);
  tcase_add_test(tc, test_from_float_to_decimal96);
  tcase_add_test(tc, test_from_float_to_decimal97);
  tcase_add_test(tc, test_from_float_to_decimal98);
  tcase_add_test(tc, test_from_float_to_decimal99);
  tcase_add_test(tc, test_from_float_to_decimal100);
  return s1;
}