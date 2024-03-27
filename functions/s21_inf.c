#include "../s21_math.h"

long double s21_inf(double x) {
  long double ret;
  if ((x == S21_POS_INF) || (x == S21_NEG_INF)) {
    if (x == S21_POS_INF) {
      ret = S21_POS_INF;
    }
    if (x == S21_NEG_INF) {
      ret = S21_NEG_INF;
      return -ret;
    }

  } else {
    ret = S21_NAN;
  }
  return ret;
}
