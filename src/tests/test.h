#ifndef S21_DECIMAL_TEST_H
#define S21_DECIMAL_TEST_H

#include <check.h>

#include "../s21_decimal.h"

#define ACCU 1e-7

#include "./arithmetic/s21_test_arithmetic.h"
#include "./comparison/s21_test_comparison.h"
#include "./convertors/s21_test_convertors.h"
#include "./other/s21_test_other.h"

#define S21_OK 0
#define S21_ERROR 1
#define S21_TOO_LARGE 1
#define S21_TOO_SMALL 2
#define S21_DIVISION_BY_ZERO 4

#define S21_FALSE 0
#define S21_TRUE 1

int main();

#endif
