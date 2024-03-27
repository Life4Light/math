#include "../s21_math.h"

long double s21_asin(double x) {
  if (x == 0.0) {
    return 0;
  }

  double guess = x;
  int maxIterations = 100;

  for (int i = 0; i < maxIterations; i++) {
    double f = s21_sin(guess) - x;
    double df = s21_cos(guess);

    guess = guess - f / df;

    if (s21_fabs(f) < S21_EPS) {
      return guess;
    }
  }

  return guess;
}
