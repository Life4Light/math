#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  long double ret = x;
  double x_1, y_1;

  y_1 = y;
  x_1 = x;
  if ((y == 0) || (x == S21_POS_INF) || (x == S21_NEG_INF)) {
    ret = S21_NAN;
    return -ret;
  }
  if ((x != x) || (y != y)) {
    ret = S21_NAN;
    return ret;
  }

  if ((x < 0) || (y < 0)) {
    x = s21_fabs(x);
    y = s21_fabs(y);
  }

  while (x >= y) x -= y;

  ret = x;

  if (((x_1 > 0) && (y_1 > 0)) || ((x_1 < 0) && (y_1 < 0))) {
  }

  else {
    if (x_1 < 0) {
      ret = -ret;
    }
  }
  return ret;
}
