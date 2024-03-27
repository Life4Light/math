#include "../s21_math.h"

long double s21_pow(double base, double exp) {
  if (!exp) return 1.0;
  if (base == S21_NEG_INF && exp == S21_NEG_INF) return 0.0;
  if (s21_abs(base) == 1.0 && (exp == S21_POS_INF || exp == S21_NEG_INF))
    return 1.0;
  if (exp == S21_POS_INF || exp == S21_NEG_INF) return S21_POS_INF;
  if (base < 0 && exp != (long long int)exp) return S21_NAN;
  long double res = 0;
  int sign = base < 0 ? -1 : 1;
  res = s21_exp(exp * s21_log(base * sign));
  if (s21_fmod(exp, 2)) res *= sign;
  return res;
}
