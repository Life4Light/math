#include "../s21_math.h"

long double s21_floor(double x) {
  long intPart = (long)x;
  long double ret = intPart;

  if (x < 0 && x < (double)intPart) ret = (intPart - 1);

  if ((x == S21_POS_INF) || (x == S21_NEG_INF) || isNAN(x)) {
    ret = s21_inf(x);
    if (x == S21_NEG_INF) {
      return -ret;
    }
  }
  return ret;
}
