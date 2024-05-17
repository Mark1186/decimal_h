#include "s21_test_comparison.h"

START_TEST(test_is_equal0) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal3) {
  // 5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  // -1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal4) {
  // -1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // 5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal5) {
  // 5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal6) {
  // 0.9999999999999999999999999999
  s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal7) {
  // 5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal8) {
  // -0.9999999999999999999999999999
  s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal9) {
  // 5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal10) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal11) {
  // 5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal12) {
  // -0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal13) {
  // 5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal14) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal15) {
  // 5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal16) {
  // -0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal17) {
  // 5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  // -0.00000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal18) {
  // -0.00000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
  // 5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal19) {
  // 5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  // 0.00000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal20) {
  // 0.00000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
  // 5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal21) {
  // 5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal22) {
  // -0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal23) {
  // 5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal24) {
  // 0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal25) {
  // 5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  // -305820564510.46084593589468994
  s21_decimal decimal2 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x80110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal26) {
  // -305820564510.46084593589468994
  s21_decimal decimal1 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x80110000}};
  // 5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal27) {
  // 5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  // 305820564510.46084593589468994
  s21_decimal decimal2 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal28) {
  // 305820564510.46084593589468994
  s21_decimal decimal1 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x110000}};
  // 5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal29) {
  // 5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  // 5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  ck_assert_int_eq(S21_TRUE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal30) {
  // 5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  // 5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  ck_assert_int_eq(S21_TRUE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal31) {
  // 5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal32) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // 5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal33) {
  // 5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  // 20786105945010.405849433600269
  s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal34) {
  // 20786105945010.405849433600269
  s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
  // 5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal35) {
  // 5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  // -20786105945010.405849433600269
  s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal36) {
  // -20786105945010.405849433600269
  s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
  // 5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal37) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal38) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal39) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal40) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal41) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal42) {
  // 52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal43) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // -52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal44) {
  // -52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal45) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // 52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal46) {
  // 52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal47) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // -52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal48) {
  // -52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal49) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // 5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal50) {
  // 5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal51) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // -5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal52) {
  // -5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal53) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // 5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal54) {
  // 5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal55) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // -5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal56) {
  // -5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal57) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // 5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal58) {
  // 5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal59) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // -5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal60) {
  // -5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal61) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal62) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal63) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal64) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal65) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal66) {
  // 7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal67) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal68) {
  // -7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal69) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // 1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal70) {
  // 1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal71) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // -1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal72) {
  // -1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal73) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // 1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal74) {
  // 1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal75) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // -1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal76) {
  // -1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal77) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // 1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal78) {
  // 1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal79) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // -1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal80) {
  // -1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal81) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal82) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal83) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal84) {
  // -1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal85) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal86) {
  // 1.0
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal87) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal88) {
  // -1.0
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal89) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // 1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal90) {
  // 1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal91) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // -1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal92) {
  // -1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal93) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // 1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal94) {
  // 1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal95) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // -1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal96) {
  // -1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal97) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // 1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal98) {
  // 1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal99) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // -1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_equal100) {
  // -1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(decimal1, decimal2));
}
END_TEST

Suite *is_equal_suite(void) {
  Suite *s1 = suite_create("test_is_equal");
  TCase *tc = tcase_create("test_is_equal");
  suite_add_tcase(s1, tc);
  tcase_add_test(tc, test_is_equal0);
  tcase_add_test(tc, test_is_equal1);
  tcase_add_test(tc, test_is_equal2);
  tcase_add_test(tc, test_is_equal3);
  tcase_add_test(tc, test_is_equal4);
  tcase_add_test(tc, test_is_equal5);
  tcase_add_test(tc, test_is_equal6);
  tcase_add_test(tc, test_is_equal7);
  tcase_add_test(tc, test_is_equal8);
  tcase_add_test(tc, test_is_equal9);
  tcase_add_test(tc, test_is_equal10);
  tcase_add_test(tc, test_is_equal11);
  tcase_add_test(tc, test_is_equal12);
  tcase_add_test(tc, test_is_equal13);
  tcase_add_test(tc, test_is_equal14);
  tcase_add_test(tc, test_is_equal15);
  tcase_add_test(tc, test_is_equal16);
  tcase_add_test(tc, test_is_equal17);
  tcase_add_test(tc, test_is_equal18);
  tcase_add_test(tc, test_is_equal19);
  tcase_add_test(tc, test_is_equal20);
  tcase_add_test(tc, test_is_equal21);
  tcase_add_test(tc, test_is_equal22);
  tcase_add_test(tc, test_is_equal23);
  tcase_add_test(tc, test_is_equal24);
  tcase_add_test(tc, test_is_equal25);
  tcase_add_test(tc, test_is_equal26);
  tcase_add_test(tc, test_is_equal27);
  tcase_add_test(tc, test_is_equal28);
  tcase_add_test(tc, test_is_equal29);
  tcase_add_test(tc, test_is_equal30);
  tcase_add_test(tc, test_is_equal31);
  tcase_add_test(tc, test_is_equal32);
  tcase_add_test(tc, test_is_equal33);
  tcase_add_test(tc, test_is_equal34);
  tcase_add_test(tc, test_is_equal35);
  tcase_add_test(tc, test_is_equal36);
  tcase_add_test(tc, test_is_equal37);
  tcase_add_test(tc, test_is_equal38);
  tcase_add_test(tc, test_is_equal39);
  tcase_add_test(tc, test_is_equal40);
  tcase_add_test(tc, test_is_equal41);
  tcase_add_test(tc, test_is_equal42);
  tcase_add_test(tc, test_is_equal43);
  tcase_add_test(tc, test_is_equal44);
  tcase_add_test(tc, test_is_equal45);
  tcase_add_test(tc, test_is_equal46);
  tcase_add_test(tc, test_is_equal47);
  tcase_add_test(tc, test_is_equal48);
  tcase_add_test(tc, test_is_equal49);
  tcase_add_test(tc, test_is_equal50);
  tcase_add_test(tc, test_is_equal51);
  tcase_add_test(tc, test_is_equal52);
  tcase_add_test(tc, test_is_equal53);
  tcase_add_test(tc, test_is_equal54);
  tcase_add_test(tc, test_is_equal55);
  tcase_add_test(tc, test_is_equal56);
  tcase_add_test(tc, test_is_equal57);
  tcase_add_test(tc, test_is_equal58);
  tcase_add_test(tc, test_is_equal59);
  tcase_add_test(tc, test_is_equal60);
  tcase_add_test(tc, test_is_equal61);
  tcase_add_test(tc, test_is_equal62);
  tcase_add_test(tc, test_is_equal63);
  tcase_add_test(tc, test_is_equal64);
  tcase_add_test(tc, test_is_equal65);
  tcase_add_test(tc, test_is_equal66);
  tcase_add_test(tc, test_is_equal67);
  tcase_add_test(tc, test_is_equal68);
  tcase_add_test(tc, test_is_equal69);
  tcase_add_test(tc, test_is_equal70);
  tcase_add_test(tc, test_is_equal71);
  tcase_add_test(tc, test_is_equal72);
  tcase_add_test(tc, test_is_equal73);
  tcase_add_test(tc, test_is_equal74);
  tcase_add_test(tc, test_is_equal75);
  tcase_add_test(tc, test_is_equal76);
  tcase_add_test(tc, test_is_equal77);
  tcase_add_test(tc, test_is_equal78);
  tcase_add_test(tc, test_is_equal79);
  tcase_add_test(tc, test_is_equal80);
  tcase_add_test(tc, test_is_equal81);
  tcase_add_test(tc, test_is_equal82);
  tcase_add_test(tc, test_is_equal83);
  tcase_add_test(tc, test_is_equal84);
  tcase_add_test(tc, test_is_equal85);
  tcase_add_test(tc, test_is_equal86);
  tcase_add_test(tc, test_is_equal87);
  tcase_add_test(tc, test_is_equal88);
  tcase_add_test(tc, test_is_equal89);
  tcase_add_test(tc, test_is_equal90);
  tcase_add_test(tc, test_is_equal91);
  tcase_add_test(tc, test_is_equal92);
  tcase_add_test(tc, test_is_equal93);
  tcase_add_test(tc, test_is_equal94);
  tcase_add_test(tc, test_is_equal95);
  tcase_add_test(tc, test_is_equal96);
  tcase_add_test(tc, test_is_equal97);
  tcase_add_test(tc, test_is_equal98);
  tcase_add_test(tc, test_is_equal99);
  tcase_add_test(tc, test_is_equal100);
  return s1;
}