#include "../s21_math.h"

long double s21_log(double x) {
  if (x == S21_POS_INF) return x;
  if (x == 0) return S21_NEG_INF;
  if (x < 0) return S21_NAN;
  long double result = 0, compare = 0;
  int e_repeat = 0;
  for (; x >= S21_EXP; e_repeat++) x /= S21_EXP;
  for (int i = 0; i < 100; i++) {
    compare = result;
    result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
  }
  result += e_repeat;
  return result;
}