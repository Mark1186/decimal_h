#include "s21_test_comparison.h"

START_TEST(test_is_not_equal0) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_FALSE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_FALSE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_FALSE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal3) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal4) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal5) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal6) {
  // 52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal7) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal8) {
  // -52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal9) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal10) {
  // 52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal11) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal12) {
  // -52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal13) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal14) {
  // 5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal15) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal16) {
  // -5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal17) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal18) {
  // 5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal19) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal20) {
  // -5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal21) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal22) {
  // 5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal23) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal24) {
  // -5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal25) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal26) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal27) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal28) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal29) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal30) {
  // 7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal31) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal32) {
  // -7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal33) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal34) {
  // 1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal35) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal36) {
  // -1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal37) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal38) {
  // 1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal39) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal40) {
  // -1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal41) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal42) {
  // 1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal43) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal44) {
  // -1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal45) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal46) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal47) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal48) {
  // -1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal49) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal50) {
  // 1.0
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal51) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal52) {
  // -1.0
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal53) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal54) {
  // 1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal55) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal56) {
  // -1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal57) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal58) {
  // 1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal59) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal60) {
  // -1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal61) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal62) {
  // 1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal63) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal64) {
  // -1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal65) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal66) {
  // 1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal67) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal68) {
  // -1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal69) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal70) {
  // 1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal71) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal72) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal73) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765.000000000000000001
  s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal74) {
  // 1431655765.000000000000000001
  s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal75) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765.000000000000000001
  s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal76) {
  // -1431655765.000000000000000001
  s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal77) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal78) {
  // 1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal79) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal80) {
  // -1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal81) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal82) {
  // 0.9999999999999999999999999999
  s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal83) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal84) {
  // -0.9999999999999999999999999999
  s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal85) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal86) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal87) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal88) {
  // -0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal89) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal90) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal91) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal92) {
  // -0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal93) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.00000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal94) {
  // -0.00000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal95) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.00000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal96) {
  // 0.00000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal97) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal98) {
  // -0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal99) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_not_equal100) {
  // 0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(decimal1, decimal2));
}

END_TEST

Suite *is_not_equal_suite(void) {
  Suite *s1 = suite_create("test_is_not_equal");
  TCase *tc = tcase_create("test_is_not_equal");
  suite_add_tcase(s1, tc);
  tcase_add_test(tc, test_is_not_equal0);
  tcase_add_test(tc, test_is_not_equal1);
  tcase_add_test(tc, test_is_not_equal2);
  tcase_add_test(tc, test_is_not_equal3);
  tcase_add_test(tc, test_is_not_equal4);
  tcase_add_test(tc, test_is_not_equal5);
  tcase_add_test(tc, test_is_not_equal6);
  tcase_add_test(tc, test_is_not_equal7);
  tcase_add_test(tc, test_is_not_equal8);
  tcase_add_test(tc, test_is_not_equal9);
  tcase_add_test(tc, test_is_not_equal10);
  tcase_add_test(tc, test_is_not_equal11);
  tcase_add_test(tc, test_is_not_equal12);
  tcase_add_test(tc, test_is_not_equal13);
  tcase_add_test(tc, test_is_not_equal14);
  tcase_add_test(tc, test_is_not_equal15);
  tcase_add_test(tc, test_is_not_equal16);
  tcase_add_test(tc, test_is_not_equal17);
  tcase_add_test(tc, test_is_not_equal18);
  tcase_add_test(tc, test_is_not_equal19);
  tcase_add_test(tc, test_is_not_equal20);
  tcase_add_test(tc, test_is_not_equal21);
  tcase_add_test(tc, test_is_not_equal22);
  tcase_add_test(tc, test_is_not_equal23);
  tcase_add_test(tc, test_is_not_equal24);
  tcase_add_test(tc, test_is_not_equal25);
  tcase_add_test(tc, test_is_not_equal26);
  tcase_add_test(tc, test_is_not_equal27);
  tcase_add_test(tc, test_is_not_equal28);
  tcase_add_test(tc, test_is_not_equal29);
  tcase_add_test(tc, test_is_not_equal30);
  tcase_add_test(tc, test_is_not_equal31);
  tcase_add_test(tc, test_is_not_equal32);
  tcase_add_test(tc, test_is_not_equal33);
  tcase_add_test(tc, test_is_not_equal34);
  tcase_add_test(tc, test_is_not_equal35);
  tcase_add_test(tc, test_is_not_equal36);
  tcase_add_test(tc, test_is_not_equal37);
  tcase_add_test(tc, test_is_not_equal38);
  tcase_add_test(tc, test_is_not_equal39);
  tcase_add_test(tc, test_is_not_equal40);
  tcase_add_test(tc, test_is_not_equal41);
  tcase_add_test(tc, test_is_not_equal42);
  tcase_add_test(tc, test_is_not_equal43);
  tcase_add_test(tc, test_is_not_equal44);
  tcase_add_test(tc, test_is_not_equal45);
  tcase_add_test(tc, test_is_not_equal46);
  tcase_add_test(tc, test_is_not_equal47);
  tcase_add_test(tc, test_is_not_equal48);
  tcase_add_test(tc, test_is_not_equal49);
  tcase_add_test(tc, test_is_not_equal50);
  tcase_add_test(tc, test_is_not_equal51);
  tcase_add_test(tc, test_is_not_equal52);
  tcase_add_test(tc, test_is_not_equal53);
  tcase_add_test(tc, test_is_not_equal54);
  tcase_add_test(tc, test_is_not_equal55);
  tcase_add_test(tc, test_is_not_equal56);
  tcase_add_test(tc, test_is_not_equal57);
  tcase_add_test(tc, test_is_not_equal58);
  tcase_add_test(tc, test_is_not_equal59);
  tcase_add_test(tc, test_is_not_equal60);
  tcase_add_test(tc, test_is_not_equal61);
  tcase_add_test(tc, test_is_not_equal62);
  tcase_add_test(tc, test_is_not_equal63);
  tcase_add_test(tc, test_is_not_equal64);
  tcase_add_test(tc, test_is_not_equal65);
  tcase_add_test(tc, test_is_not_equal66);
  tcase_add_test(tc, test_is_not_equal67);
  tcase_add_test(tc, test_is_not_equal68);
  tcase_add_test(tc, test_is_not_equal69);
  tcase_add_test(tc, test_is_not_equal70);
  tcase_add_test(tc, test_is_not_equal71);
  tcase_add_test(tc, test_is_not_equal72);
  tcase_add_test(tc, test_is_not_equal73);
  tcase_add_test(tc, test_is_not_equal74);
  tcase_add_test(tc, test_is_not_equal75);
  tcase_add_test(tc, test_is_not_equal76);
  tcase_add_test(tc, test_is_not_equal77);
  tcase_add_test(tc, test_is_not_equal78);
  tcase_add_test(tc, test_is_not_equal79);
  tcase_add_test(tc, test_is_not_equal80);
  tcase_add_test(tc, test_is_not_equal81);
  tcase_add_test(tc, test_is_not_equal82);
  tcase_add_test(tc, test_is_not_equal83);
  tcase_add_test(tc, test_is_not_equal84);
  tcase_add_test(tc, test_is_not_equal85);
  tcase_add_test(tc, test_is_not_equal86);
  tcase_add_test(tc, test_is_not_equal87);
  tcase_add_test(tc, test_is_not_equal88);
  tcase_add_test(tc, test_is_not_equal89);
  tcase_add_test(tc, test_is_not_equal90);
  tcase_add_test(tc, test_is_not_equal91);
  tcase_add_test(tc, test_is_not_equal92);
  tcase_add_test(tc, test_is_not_equal93);
  tcase_add_test(tc, test_is_not_equal94);
  tcase_add_test(tc, test_is_not_equal95);
  tcase_add_test(tc, test_is_not_equal96);
  tcase_add_test(tc, test_is_not_equal97);
  tcase_add_test(tc, test_is_not_equal98);
  tcase_add_test(tc, test_is_not_equal99);
  tcase_add_test(tc, test_is_not_equal100);
  return s1;
}