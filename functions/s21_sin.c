#include "../s21_math.h"

long double s21_sin(double x) {
  long double res = 0.0;
  if (x == S21_POS_INF) {
    res = S21_POS_INF;
  } else if (x == S21_NEG_INF) {
    res = S21_NEG_INF;
  } else {
    int n = 0;
    if (x > 2 * S21_PI || x < (-2 * S21_PI)) {
      x = s21_fmod(x, 2 * S21_PI);
    }
    double factorial = 1.0;
    double temp = x;
    while (temp / factorial > 1e-12 || temp / factorial < -1e-12) {
      int sign = (n % 2) * (-1) + !(n % 2);
      factorial = 1.0;
      temp = 1;
      for (int i = 1; i <= 2 * n + 1; i++) {
        temp *= x;
        factorial *= i;
      }
      res += sign * temp / factorial;
      n++;
    }
  }
  return res;
}
