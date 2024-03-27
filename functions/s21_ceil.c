#include "../s21_math.h"

long double s21_ceil(double x) {
  long intPart = (long)x;
  long double ret = intPart;
  if (x <= 0 && x == (double)intPart) ret = x;

  if (x > 0 && x > (double)intPart) ret = (intPart + 1);
  if ((x < 0) && (ret == 0)) {
    ret = -ret;
  }
  if ((x == S21_POS_INF) || (x == S21_NEG_INF) || (x != x)) {
    ret = s21_inf(x);
    if (x == S21_NEG_INF) {
      return -ret;
    }
  }
  return ret;
}
