#include "test.h"

int main(void) {
  SRunner *sr = srunner_create(NULL);

  srunner_add_suite(sr, add_suite());
  srunner_add_suite(sr, div_suite());
  srunner_add_suite(sr, mul_suite());
  srunner_add_suite(sr, sub_suite());

  srunner_add_suite(sr, is_equal_suite());
  srunner_add_suite(sr, is_greater_or_equal_suite());
  srunner_add_suite(sr, is_greater_suite());
  srunner_add_suite(sr, is_less_or_equal_suite());
  srunner_add_suite(sr, is_less_suite());
  srunner_add_suite(sr, is_not_equal_suite());

  srunner_add_suite(sr, floor_suite());
  srunner_add_suite(sr, negate_suite());
  srunner_add_suite(sr, round_suite());
  srunner_add_suite(sr, truncate_suite());

  srunner_add_suite(sr, from_decimal_to_float_suite());
  srunner_add_suite(sr, from_decimal_to_int_suite());
  srunner_add_suite(sr, from_float_to_decimal_suite());
  srunner_add_suite(sr, from_int_to_decimal_suite());

  srunner_run_all(sr, CK_ENV);
  int failed_count = srunner_ntests_failed(sr);
  srunner_free(sr);
  return failed_count == 0 ? 0 : 1;
}