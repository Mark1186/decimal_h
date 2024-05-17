#include "s21_test_comparison.h"

START_TEST(test_is_less_or_equal0) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal1) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal2) {
  // 1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal3) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // -1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal4) {
  // -1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal5) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal6) {
  // 0.9999999999999999999999999999
  s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal7) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal8) {
  // -0.9999999999999999999999999999
  s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal9) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal10) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal11) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal12) {
  // -0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal13) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal14) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal15) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal16) {
  // -0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal17) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // -0.00000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal18) {
  // -0.00000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal19) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // 0.00000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal20) {
  // 0.00000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal21) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal22) {
  // -0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal23) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal24) {
  // 0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal25) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // -19290120297533996546.12653034
  s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80080000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal26) {
  // -19290120297533996546.12653034
  s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80080000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal27) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // 19290120297533996546.12653034
  s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal28) {
  // 19290120297533996546.12653034
  s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal29) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal30) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal31) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal32) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal33) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // 858826877820029649465.1465162
  s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal34) {
  // 858826877820029649465.1465162
  s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal35) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // -858826877820029649465.1465162
  s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal36) {
  // -858826877820029649465.1465162
  s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal37) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal38) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal39) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal40) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal41) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal42) {
  // 52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal43) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal44) {
  // -52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal45) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal46) {
  // 52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal47) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal48) {
  // -52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal49) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal50) {
  // 5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal51) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal52) {
  // -5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal53) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal54) {
  // 5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal55) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal56) {
  // -5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal57) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal58) {
  // 5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal59) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal60) {
  // -5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal61) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal62) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal63) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal64) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal65) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal66) {
  // 7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal67) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal68) {
  // -7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal69) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal70) {
  // 1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal71) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal72) {
  // -1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal73) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal74) {
  // 1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal75) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal76) {
  // -1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal77) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal78) {
  // 1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal79) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal80) {
  // -1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal81) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal82) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal83) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal84) {
  // -1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal85) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal86) {
  // 1.0
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal87) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal88) {
  // -1.0
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal89) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal90) {
  // 1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal91) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal92) {
  // -1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal93) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal94) {
  // 1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal95) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal96) {
  // -1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal97) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal98) {
  // 1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal99) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less_or_equal100) {
  // -1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(decimal1, decimal2));
}
END_TEST

Suite *is_less_or_equal_suite(void) {
  Suite *s1 = suite_create("test_is_less_or_equal");
  TCase *tc = tcase_create("test_is_less_or_equal");
  suite_add_tcase(s1, tc);
  tcase_add_test(tc, test_is_less_or_equal0);
  tcase_add_test(tc, test_is_less_or_equal1);
  tcase_add_test(tc, test_is_less_or_equal2);
  tcase_add_test(tc, test_is_less_or_equal3);
  tcase_add_test(tc, test_is_less_or_equal4);
  tcase_add_test(tc, test_is_less_or_equal5);
  tcase_add_test(tc, test_is_less_or_equal6);
  tcase_add_test(tc, test_is_less_or_equal7);
  tcase_add_test(tc, test_is_less_or_equal8);
  tcase_add_test(tc, test_is_less_or_equal9);
  tcase_add_test(tc, test_is_less_or_equal10);
  tcase_add_test(tc, test_is_less_or_equal11);
  tcase_add_test(tc, test_is_less_or_equal12);
  tcase_add_test(tc, test_is_less_or_equal13);
  tcase_add_test(tc, test_is_less_or_equal14);
  tcase_add_test(tc, test_is_less_or_equal15);
  tcase_add_test(tc, test_is_less_or_equal16);
  tcase_add_test(tc, test_is_less_or_equal17);
  tcase_add_test(tc, test_is_less_or_equal18);
  tcase_add_test(tc, test_is_less_or_equal19);
  tcase_add_test(tc, test_is_less_or_equal20);
  tcase_add_test(tc, test_is_less_or_equal21);
  tcase_add_test(tc, test_is_less_or_equal22);
  tcase_add_test(tc, test_is_less_or_equal23);
  tcase_add_test(tc, test_is_less_or_equal24);
  tcase_add_test(tc, test_is_less_or_equal25);
  tcase_add_test(tc, test_is_less_or_equal26);
  tcase_add_test(tc, test_is_less_or_equal27);
  tcase_add_test(tc, test_is_less_or_equal28);
  tcase_add_test(tc, test_is_less_or_equal29);
  tcase_add_test(tc, test_is_less_or_equal30);
  tcase_add_test(tc, test_is_less_or_equal31);
  tcase_add_test(tc, test_is_less_or_equal32);
  tcase_add_test(tc, test_is_less_or_equal33);
  tcase_add_test(tc, test_is_less_or_equal34);
  tcase_add_test(tc, test_is_less_or_equal35);
  tcase_add_test(tc, test_is_less_or_equal36);
  tcase_add_test(tc, test_is_less_or_equal37);
  tcase_add_test(tc, test_is_less_or_equal38);
  tcase_add_test(tc, test_is_less_or_equal39);
  tcase_add_test(tc, test_is_less_or_equal40);
  tcase_add_test(tc, test_is_less_or_equal41);
  tcase_add_test(tc, test_is_less_or_equal42);
  tcase_add_test(tc, test_is_less_or_equal43);
  tcase_add_test(tc, test_is_less_or_equal44);
  tcase_add_test(tc, test_is_less_or_equal45);
  tcase_add_test(tc, test_is_less_or_equal46);
  tcase_add_test(tc, test_is_less_or_equal47);
  tcase_add_test(tc, test_is_less_or_equal48);
  tcase_add_test(tc, test_is_less_or_equal49);
  tcase_add_test(tc, test_is_less_or_equal50);
  tcase_add_test(tc, test_is_less_or_equal51);
  tcase_add_test(tc, test_is_less_or_equal52);
  tcase_add_test(tc, test_is_less_or_equal53);
  tcase_add_test(tc, test_is_less_or_equal54);
  tcase_add_test(tc, test_is_less_or_equal55);
  tcase_add_test(tc, test_is_less_or_equal56);
  tcase_add_test(tc, test_is_less_or_equal57);
  tcase_add_test(tc, test_is_less_or_equal58);
  tcase_add_test(tc, test_is_less_or_equal59);
  tcase_add_test(tc, test_is_less_or_equal60);
  tcase_add_test(tc, test_is_less_or_equal61);
  tcase_add_test(tc, test_is_less_or_equal62);
  tcase_add_test(tc, test_is_less_or_equal63);
  tcase_add_test(tc, test_is_less_or_equal64);
  tcase_add_test(tc, test_is_less_or_equal65);
  tcase_add_test(tc, test_is_less_or_equal66);
  tcase_add_test(tc, test_is_less_or_equal67);
  tcase_add_test(tc, test_is_less_or_equal68);
  tcase_add_test(tc, test_is_less_or_equal69);
  tcase_add_test(tc, test_is_less_or_equal70);
  tcase_add_test(tc, test_is_less_or_equal71);
  tcase_add_test(tc, test_is_less_or_equal72);
  tcase_add_test(tc, test_is_less_or_equal73);
  tcase_add_test(tc, test_is_less_or_equal74);
  tcase_add_test(tc, test_is_less_or_equal75);
  tcase_add_test(tc, test_is_less_or_equal76);
  tcase_add_test(tc, test_is_less_or_equal77);
  tcase_add_test(tc, test_is_less_or_equal78);
  tcase_add_test(tc, test_is_less_or_equal79);
  tcase_add_test(tc, test_is_less_or_equal80);
  tcase_add_test(tc, test_is_less_or_equal81);
  tcase_add_test(tc, test_is_less_or_equal82);
  tcase_add_test(tc, test_is_less_or_equal83);
  tcase_add_test(tc, test_is_less_or_equal84);
  tcase_add_test(tc, test_is_less_or_equal85);
  tcase_add_test(tc, test_is_less_or_equal86);
  tcase_add_test(tc, test_is_less_or_equal87);
  tcase_add_test(tc, test_is_less_or_equal88);
  tcase_add_test(tc, test_is_less_or_equal89);
  tcase_add_test(tc, test_is_less_or_equal90);
  tcase_add_test(tc, test_is_less_or_equal91);
  tcase_add_test(tc, test_is_less_or_equal92);
  tcase_add_test(tc, test_is_less_or_equal93);
  tcase_add_test(tc, test_is_less_or_equal94);
  tcase_add_test(tc, test_is_less_or_equal95);
  tcase_add_test(tc, test_is_less_or_equal96);
  tcase_add_test(tc, test_is_less_or_equal97);
  tcase_add_test(tc, test_is_less_or_equal98);
  tcase_add_test(tc, test_is_less_or_equal99);
  tcase_add_test(tc, test_is_less_or_equal100);
  return s1;
}