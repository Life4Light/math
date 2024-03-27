#include "../s21_math.h"

long double s21_fabs(double x) {
  long double ret = x;
  if (x < 0) ret = -x;

  return ret;
}
