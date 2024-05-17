#include "s21_test_comparison.h"

START_TEST(test_is_greater0) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater1) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater2) {
  // 1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater3) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // -1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater4) {
  // -1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater5) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater6) {
  // 0.9999999999999999999999999999
  s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater7) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater8) {
  // -0.9999999999999999999999999999
  s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater9) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater10) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater11) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater12) {
  // -0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater13) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater14) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater15) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater16) {
  // -0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater17) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // -0.00000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater18) {
  // -0.00000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater19) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // 0.00000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater20) {
  // 0.00000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater21) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater22) {
  // -0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater23) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater24) {
  // 0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater25) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // -19290120297533996546.12653034
  s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80080000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater26) {
  // -19290120297533996546.12653034
  s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80080000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater27) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // 19290120297533996546.12653034
  s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater28) {
  // 19290120297533996546.12653034
  s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater29) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater30) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater31) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater32) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater33) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // 858826877820029649465.1465162
  s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater34) {
  // 858826877820029649465.1465162
  s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater35) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // -858826877820029649465.1465162
  s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater36) {
  // -858826877820029649465.1465162
  s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater37) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater38) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater39) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater40) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater41) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater42) {
  // 52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater43) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater44) {
  // -52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater45) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater46) {
  // 52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater47) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater48) {
  // -52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater49) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater50) {
  // 5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater51) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater52) {
  // -5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater53) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater54) {
  // 5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater55) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater56) {
  // -5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater57) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater58) {
  // 5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater59) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater60) {
  // -5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater61) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater62) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater63) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater64) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater65) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater66) {
  // 7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater67) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater68) {
  // -7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater69) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater70) {
  // 1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater71) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater72) {
  // -1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater73) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater74) {
  // 1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater75) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater76) {
  // -1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater77) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater78) {
  // 1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater79) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater80) {
  // -1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater81) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater82) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater83) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater84) {
  // -1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater85) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater86) {
  // 1.0
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater87) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater88) {
  // -1.0
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater89) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater90) {
  // 1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater91) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater92) {
  // -1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater93) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater94) {
  // 1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater95) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater96) {
  // -1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater97) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater98) {
  // 1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater99) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // -1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_greater100) {
  // -1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(decimal1, decimal2));
}
END_TEST

Suite *is_greater_suite(void) {
  Suite *s1 = suite_create("test_is_greater");
  TCase *tc = tcase_create("test_is_greater");
  suite_add_tcase(s1, tc);
  tcase_add_test(tc, test_is_greater0);
  tcase_add_test(tc, test_is_greater1);
  tcase_add_test(tc, test_is_greater2);
  tcase_add_test(tc, test_is_greater3);
  tcase_add_test(tc, test_is_greater4);
  tcase_add_test(tc, test_is_greater5);
  tcase_add_test(tc, test_is_greater6);
  tcase_add_test(tc, test_is_greater7);
  tcase_add_test(tc, test_is_greater8);
  tcase_add_test(tc, test_is_greater9);
  tcase_add_test(tc, test_is_greater10);
  tcase_add_test(tc, test_is_greater11);
  tcase_add_test(tc, test_is_greater12);
  tcase_add_test(tc, test_is_greater13);
  tcase_add_test(tc, test_is_greater14);
  tcase_add_test(tc, test_is_greater15);
  tcase_add_test(tc, test_is_greater16);
  tcase_add_test(tc, test_is_greater17);
  tcase_add_test(tc, test_is_greater18);
  tcase_add_test(tc, test_is_greater19);
  tcase_add_test(tc, test_is_greater20);
  tcase_add_test(tc, test_is_greater21);
  tcase_add_test(tc, test_is_greater22);
  tcase_add_test(tc, test_is_greater23);
  tcase_add_test(tc, test_is_greater24);
  tcase_add_test(tc, test_is_greater25);
  tcase_add_test(tc, test_is_greater26);
  tcase_add_test(tc, test_is_greater27);
  tcase_add_test(tc, test_is_greater28);
  tcase_add_test(tc, test_is_greater29);
  tcase_add_test(tc, test_is_greater30);
  tcase_add_test(tc, test_is_greater31);
  tcase_add_test(tc, test_is_greater32);
  tcase_add_test(tc, test_is_greater33);
  tcase_add_test(tc, test_is_greater34);
  tcase_add_test(tc, test_is_greater35);
  tcase_add_test(tc, test_is_greater36);
  tcase_add_test(tc, test_is_greater37);
  tcase_add_test(tc, test_is_greater38);
  tcase_add_test(tc, test_is_greater39);
  tcase_add_test(tc, test_is_greater40);
  tcase_add_test(tc, test_is_greater41);
  tcase_add_test(tc, test_is_greater42);
  tcase_add_test(tc, test_is_greater43);
  tcase_add_test(tc, test_is_greater44);
  tcase_add_test(tc, test_is_greater45);
  tcase_add_test(tc, test_is_greater46);
  tcase_add_test(tc, test_is_greater47);
  tcase_add_test(tc, test_is_greater48);
  tcase_add_test(tc, test_is_greater49);
  tcase_add_test(tc, test_is_greater50);
  tcase_add_test(tc, test_is_greater51);
  tcase_add_test(tc, test_is_greater52);
  tcase_add_test(tc, test_is_greater53);
  tcase_add_test(tc, test_is_greater54);
  tcase_add_test(tc, test_is_greater55);
  tcase_add_test(tc, test_is_greater56);
  tcase_add_test(tc, test_is_greater57);
  tcase_add_test(tc, test_is_greater58);
  tcase_add_test(tc, test_is_greater59);
  tcase_add_test(tc, test_is_greater60);
  tcase_add_test(tc, test_is_greater61);
  tcase_add_test(tc, test_is_greater62);
  tcase_add_test(tc, test_is_greater63);
  tcase_add_test(tc, test_is_greater64);
  tcase_add_test(tc, test_is_greater65);
  tcase_add_test(tc, test_is_greater66);
  tcase_add_test(tc, test_is_greater67);
  tcase_add_test(tc, test_is_greater68);
  tcase_add_test(tc, test_is_greater69);
  tcase_add_test(tc, test_is_greater70);
  tcase_add_test(tc, test_is_greater71);
  tcase_add_test(tc, test_is_greater72);
  tcase_add_test(tc, test_is_greater73);
  tcase_add_test(tc, test_is_greater74);
  tcase_add_test(tc, test_is_greater75);
  tcase_add_test(tc, test_is_greater76);
  tcase_add_test(tc, test_is_greater77);
  tcase_add_test(tc, test_is_greater78);
  tcase_add_test(tc, test_is_greater79);
  tcase_add_test(tc, test_is_greater80);
  tcase_add_test(tc, test_is_greater81);
  tcase_add_test(tc, test_is_greater82);
  tcase_add_test(tc, test_is_greater83);
  tcase_add_test(tc, test_is_greater84);
  tcase_add_test(tc, test_is_greater85);
  tcase_add_test(tc, test_is_greater86);
  tcase_add_test(tc, test_is_greater87);
  tcase_add_test(tc, test_is_greater88);
  tcase_add_test(tc, test_is_greater89);
  tcase_add_test(tc, test_is_greater90);
  tcase_add_test(tc, test_is_greater91);
  tcase_add_test(tc, test_is_greater92);
  tcase_add_test(tc, test_is_greater93);
  tcase_add_test(tc, test_is_greater94);
  tcase_add_test(tc, test_is_greater95);
  tcase_add_test(tc, test_is_greater96);
  tcase_add_test(tc, test_is_greater97);
  tcase_add_test(tc, test_is_greater98);
  tcase_add_test(tc, test_is_greater99);
  tcase_add_test(tc, test_is_greater100);
  return s1;
}