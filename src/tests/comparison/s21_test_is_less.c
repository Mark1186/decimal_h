#include "s21_test_comparison.h"

START_TEST(test_is_less0) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less1) {
  // -518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less2) {
  // 1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  // -518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less3) {
  // -518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  // -1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less4) {
  // -1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // -518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less5) {
  // -518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less6) {
  // 0.9999999999999999999999999999
  s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less7) {
  // -518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less8) {
  // -0.9999999999999999999999999999
  s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less9) {
  // -518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less10) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less11) {
  // -518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less12) {
  // -0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // -518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less13) {
  // -518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less14) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // -518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less15) {
  // -518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less16) {
  // -0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // -518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less17) {
  // -518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  // -0.00000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less18) {
  // -0.00000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
  // -518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less19) {
  // -518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  // 0.00000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less20) {
  // 0.00000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
  // -518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less21) {
  // -518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less22) {
  // -0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // -518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less23) {
  // -518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less24) {
  // 0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // -518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less25) {
  // -518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  // -5491184418.5106300524956975593
  s21_decimal decimal2 = {{0x734381E9, 0x8ACE66A, 0xB16E034E, 0x80130000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less26) {
  // -5491184418.5106300524956975593
  s21_decimal decimal1 = {{0x734381E9, 0x8ACE66A, 0xB16E034E, 0x80130000}};
  // -518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less27) {
  // -518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  // 5491184418.5106300524956975593
  s21_decimal decimal2 = {{0x734381E9, 0x8ACE66A, 0xB16E034E, 0x130000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less28) {
  // 5491184418.5106300524956975593
  s21_decimal decimal1 = {{0x734381E9, 0x8ACE66A, 0xB16E034E, 0x130000}};
  // -518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less29) {
  // -518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  // -518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less30) {
  // -518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  // -518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less31) {
  // -518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less32) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // -518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less33) {
  // -518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  // -7347194860180725191424.9548934
  s21_decimal decimal2 = {{0x8A5D3486, 0x8A87F668, 0xED66924A, 0x80070000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less34) {
  // -7347194860180725191424.9548934
  s21_decimal decimal1 = {{0x8A5D3486, 0x8A87F668, 0xED66924A, 0x80070000}};
  // -518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less35) {
  // -518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  // 7347194860180725191424.9548934
  s21_decimal decimal2 = {{0x8A5D3486, 0x8A87F668, 0xED66924A, 0x70000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less36) {
  // 7347194860180725191424.9548934
  s21_decimal decimal1 = {{0x8A5D3486, 0x8A87F668, 0xED66924A, 0x70000}};
  // -518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less37) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less38) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less39) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less40) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less41) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less42) {
  // 52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less43) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // -52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less44) {
  // -52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less45) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // 52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less46) {
  // 52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less47) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // -52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less48) {
  // -52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less49) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // 5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less50) {
  // 5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less51) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // -5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less52) {
  // -5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less53) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // 5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less54) {
  // 5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less55) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // -5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less56) {
  // -5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less57) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // 5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less58) {
  // 5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less59) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // -5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less60) {
  // -5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less61) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less62) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less63) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less64) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less65) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less66) {
  // 7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less67) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less68) {
  // -7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less69) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // 1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less70) {
  // 1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less71) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // -1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less72) {
  // -1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less73) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // 1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less74) {
  // 1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less75) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // -1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less76) {
  // -1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less77) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // 1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less78) {
  // 1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less79) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // -1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less80) {
  // -1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less81) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less82) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less83) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less84) {
  // -1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less85) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less86) {
  // 1.0
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less87) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less88) {
  // -1.0
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less89) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // 1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less90) {
  // 1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less91) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // -1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less92) {
  // -1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less93) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // 1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less94) {
  // 1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less95) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // -1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less96) {
  // -1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less97) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // 1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less98) {
  // 1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less99) {
  // 518571519399.48581393334040314
  s21_decimal decimal1 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  // -1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(decimal1, decimal2));
}
END_TEST

START_TEST(test_is_less100) {
  // -1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  // 518571519399.48581393334040314
  s21_decimal decimal2 = {{0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(decimal1, decimal2));
}

Suite *is_less_suite(void) {
  Suite *s1 = suite_create("test_is_less");
  TCase *tc = tcase_create("test_is_less");
  suite_add_tcase(s1, tc);
  tcase_add_test(tc, test_is_less0);
  tcase_add_test(tc, test_is_less1);
  tcase_add_test(tc, test_is_less2);
  tcase_add_test(tc, test_is_less3);
  tcase_add_test(tc, test_is_less4);
  tcase_add_test(tc, test_is_less5);
  tcase_add_test(tc, test_is_less6);
  tcase_add_test(tc, test_is_less7);
  tcase_add_test(tc, test_is_less8);
  tcase_add_test(tc, test_is_less9);
  tcase_add_test(tc, test_is_less10);
  tcase_add_test(tc, test_is_less11);
  tcase_add_test(tc, test_is_less12);
  tcase_add_test(tc, test_is_less13);
  tcase_add_test(tc, test_is_less14);
  tcase_add_test(tc, test_is_less15);
  tcase_add_test(tc, test_is_less16);
  tcase_add_test(tc, test_is_less17);
  tcase_add_test(tc, test_is_less18);
  tcase_add_test(tc, test_is_less19);
  tcase_add_test(tc, test_is_less20);
  tcase_add_test(tc, test_is_less21);
  tcase_add_test(tc, test_is_less22);
  tcase_add_test(tc, test_is_less23);
  tcase_add_test(tc, test_is_less24);
  tcase_add_test(tc, test_is_less25);
  tcase_add_test(tc, test_is_less26);
  tcase_add_test(tc, test_is_less27);
  tcase_add_test(tc, test_is_less28);
  tcase_add_test(tc, test_is_less29);
  tcase_add_test(tc, test_is_less30);
  tcase_add_test(tc, test_is_less31);
  tcase_add_test(tc, test_is_less32);
  tcase_add_test(tc, test_is_less33);
  tcase_add_test(tc, test_is_less34);
  tcase_add_test(tc, test_is_less35);
  tcase_add_test(tc, test_is_less36);
  tcase_add_test(tc, test_is_less37);
  tcase_add_test(tc, test_is_less38);
  tcase_add_test(tc, test_is_less39);
  tcase_add_test(tc, test_is_less40);
  tcase_add_test(tc, test_is_less41);
  tcase_add_test(tc, test_is_less42);
  tcase_add_test(tc, test_is_less43);
  tcase_add_test(tc, test_is_less44);
  tcase_add_test(tc, test_is_less45);
  tcase_add_test(tc, test_is_less46);
  tcase_add_test(tc, test_is_less47);
  tcase_add_test(tc, test_is_less48);
  tcase_add_test(tc, test_is_less49);
  tcase_add_test(tc, test_is_less50);
  tcase_add_test(tc, test_is_less51);
  tcase_add_test(tc, test_is_less52);
  tcase_add_test(tc, test_is_less53);
  tcase_add_test(tc, test_is_less54);
  tcase_add_test(tc, test_is_less55);
  tcase_add_test(tc, test_is_less56);
  tcase_add_test(tc, test_is_less57);
  tcase_add_test(tc, test_is_less58);
  tcase_add_test(tc, test_is_less59);
  tcase_add_test(tc, test_is_less60);
  tcase_add_test(tc, test_is_less61);
  tcase_add_test(tc, test_is_less62);
  tcase_add_test(tc, test_is_less63);
  tcase_add_test(tc, test_is_less64);
  tcase_add_test(tc, test_is_less65);
  tcase_add_test(tc, test_is_less66);
  tcase_add_test(tc, test_is_less67);
  tcase_add_test(tc, test_is_less68);
  tcase_add_test(tc, test_is_less69);
  tcase_add_test(tc, test_is_less70);
  tcase_add_test(tc, test_is_less71);
  tcase_add_test(tc, test_is_less72);
  tcase_add_test(tc, test_is_less73);
  tcase_add_test(tc, test_is_less74);
  tcase_add_test(tc, test_is_less75);
  tcase_add_test(tc, test_is_less76);
  tcase_add_test(tc, test_is_less77);
  tcase_add_test(tc, test_is_less78);
  tcase_add_test(tc, test_is_less79);
  tcase_add_test(tc, test_is_less80);
  tcase_add_test(tc, test_is_less81);
  tcase_add_test(tc, test_is_less82);
  tcase_add_test(tc, test_is_less83);
  tcase_add_test(tc, test_is_less84);
  tcase_add_test(tc, test_is_less85);
  tcase_add_test(tc, test_is_less86);
  tcase_add_test(tc, test_is_less87);
  tcase_add_test(tc, test_is_less88);
  tcase_add_test(tc, test_is_less89);
  tcase_add_test(tc, test_is_less90);
  tcase_add_test(tc, test_is_less91);
  tcase_add_test(tc, test_is_less92);
  tcase_add_test(tc, test_is_less93);
  tcase_add_test(tc, test_is_less94);
  tcase_add_test(tc, test_is_less95);
  tcase_add_test(tc, test_is_less96);
  tcase_add_test(tc, test_is_less97);
  tcase_add_test(tc, test_is_less98);
  tcase_add_test(tc, test_is_less99);
  tcase_add_test(tc, test_is_less100);
  return s1;
}