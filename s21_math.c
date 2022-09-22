// Copyright 2022 <Loewe Thalia>
#include "./s21_math.h"

int s21_abs(int x) { return (x > 0 ? x : x * -1); }

long double s21_acos(double x) {
    long double res = 0.0;
    if (x == 1.)
        res = 0.0;
    else if (x == 0.0)
        res = S21_PI / 2;
    else if (x == -1.)
        res = S21_PI;
    else if (x > 0 && x < 1)
        res = s21_atan(s21_sqrt(1 - x * x) / x);
    else if (x > -1 && x < 0)
        res = S21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
    else
        res = S21_NAN;
    return res;
}

long double s21_asin(double x) {
    long double res = 0.0;
    if (x == 1.)
        res = S21_PI / 2;
    else if (x == -1.)
        res = S21_PI / -2;
    else if (x > -1 && x < 1)
        res = s21_atan(x / s21_sqrt(1 - x * x));
    else
        res = S21_NAN;
    return res;
}

long double s21_fmod(double x, double y) {
    long double res = 0.0;
    long long int tmp = 0;
    if (x == S21_INF && y == S21_INF) {
        res = S21_NAN;
    } else if (x == S21_INF || x == -S21_INF) {
        res = S21_NAN;
    } else if (y == S21_INF || y == -S21_INF) {
        res = x;
    } else if (y == 0) {
        res = S21_NAN;
    } else {
        tmp = x / y;
        res = (long double)x - tmp * (long double)y;
    }
    if (res == 0 && x < 0) res = -0;
    return res;
}

long double s21_ceil(double x) {
    double res = x;
    int temp = res;
    if (x == S21_INF || x == -S21_INF)
        res = x;
    else if (x != x)
        res = S21_NAN;
    else if (temp == res)
        res = temp;
    else if (res < 0)
        res = temp;
    else
        res = temp + 1;
    return res;
}

long double s21_fabs(double x) {
    if (x != x) return S21_NAN;
    if (x == -S21_INF || x == S21_INF) {
        if (x < 0) {
            return -x;
        }
        return x;
    }
    return (x > 0 ? x : x * -1);
}

long double s21_floor(double x) {
    double res = x;
    int temp = res;
    if (x == S21_INF || x == -S21_INF)
        res = x;
    else if (x != x)
        res = S21_NAN;
    else if (temp == res)
        res = temp;
    else if (res < 0)
        res = temp - 1;
    else
        res = temp;
    return res;
}

long double s21_sqrt(double x) {
    double t = 0;
    double root = x / 2;
    if (x == S21_INF) {
        root = S21_INF;
    } else if (x == -S21_INF || x != x) {
        root = S21_NAN;
    } else {
        while ((t - root) != 0) {
            t = root;
            root = (t + (x / t)) / 2;
        }
    }
    return root;
}

long double s21_exp(double x) {
    int i = 1;
    long double num = 1.0;
    long double res = 1.0;
    if (x == S21_NAN) {
        res = S21_NAN;
    } else if (x == -S21_INF) {
        res = 0;
    } else if (x == S21_INF) {
        res = S21_INF;
    } else {
        while (s21_fabs(num) > 0.0000001) {
            num *= x / i++;
            res += num;
        }
    }
    return res;
}

long double s21_sin(double x) {
    long double res = 0;
    if (x == S21_INF || x == -S21_INF || x == S21_NAN) {
        res = -S21_NAN;
    } else {
        while (x > S21_PI || x < -S21_PI) {
            if (x > S21_PI) {
                x -= 2 * S21_PI;
            } else if (x < -S21_PI) {
                x += 2 * S21_PI;
            }
        }
        res = x;
        int i = 1;
        long double num = x / i++;
        int sign = 1;
        while (s21_fabs(num) > 0.0000001) {
            sign = (-1) * sign;
            num *= x / i++;
            num *= x / i++;
            res += sign * num;
        }
    }
    return res;
}

long double s21_cos(double x) {
    long double res = 1.0;
    int i = 1;
    long double num = 1.0;
    int sign = 1;

    if (x == S21_INF || x == -S21_INF || x == S21_NAN) {
        res = -S21_NAN;
    } else {
        while ((x > S21_PI || x < -S21_PI)) {
            if (x > S21_PI) {
                x -= 2 * S21_PI;
            } else if (x < -S21_PI) {
                x += 2 * S21_PI;
            }
        }
        while (s21_fabs(num) > 0.0000001) {
            sign = (-1) * sign;
            num *= x / i++;
            num *= x / i++;
            res += sign * num;
        }
    }
    return res;
}

long double s21_tan(double x) {
    long double res = 0;
    if (x == S21_INF || x == -S21_INF || x == S21_NAN) {
        res = -S21_NAN;
    } else {
        if (s21_cos(x) == 0) {
            if (s21_sin(x) > 0) {
                res = S21_INF;
            } else if (s21_sin(x) < 0) {
                res = -S21_INF;
            }
        } else {
            res = s21_sin(x) / s21_cos(x);
        }
    }
    return res;
}

long double s21_atan(double x) {
    long double res = 0;
    int i = 0;
    long double num = 1;
    int sign = -1;
    if (x == S21_NAN) {
        res = -S21_NAN;
    } else if (x == S21_INF) {
        res = S21_PI / 2;
    } else if (x == -S21_INF) {
        res = -S21_PI / 2;
    } else {
        if (s21_fabs(x) <= 1) {
            while (s21_fabs(num) > 0.0000001) {
                sign = (-1) * sign;
                num = s21_pow(x, 1 + 2 * i) / (1 + 2 * i);
                res += sign * num;
                i++;
            }
        } else {
            while (s21_fabs(num) > 0.0000001) {
                sign = (-1) * sign;
                num = s21_pow(x, (-1) * (1 + 2 * i)) / (1 + 2 * i);
                res += sign * num;
                i++;
            }
            res = ((S21_PI * s21_fabs(x)) / (2 * x)) - res;
        }
    }
    return res;
}

long double s21_log(double x) {
    double res = 0;
    double befor = 0;
    int pow = 0;
    int i = 0;

    if (x == S21_INF) {
        res = S21_INF;
    } else if (x == -S21_INF) {
        res = S21_NAN;
    } else if (x < 0) {
        res = S21_NAN;
    } else if (x == 1) {
        res = 0;
    } else if (x == S21_E) {
        res = 1;
    } else if (x == 0) {
        res = -S21_INF;
    } else {
        while (x > S21_E) {
            x = x / S21_E;
            pow++;
            continue;
        }
        while (i < 200) {
            res = befor + 2 * (x - s21_exp(befor)) / (x + s21_exp(befor));
            befor = res;
            i++;
        }
    }
    return (res + pow);
}

long double s21_pow(double base, double exp) {
  double res = 0;
  double b_res = 1;

  if (exp == 0 || ((base == 1 || base == -1) && exp == S21_INF)) {
    res = 1;
  } else if ((base == 1 || base == -1) && exp == -S21_INF) {
    res = 1;
  } else if ((base == -S21_INF && exp == 1)) {
    res = -S21_INF;
  } else if ((base == -S21_INF && exp <= -1)) {
    res = -0;
  } else if ((base == 0 && exp < 0)) {
    res = S21_INF;
  } else if (base == -S21_INF && (exp > 0 && exp < 1)) {
    res = S21_INF;
  } else if ((base < -1 || base > 1) && (exp == S21_INF)) {
    res = S21_INF;
  } else if ((base > 0 && base < 1) && (exp == -S21_INF)) {
    res = S21_INF;
  } else if (isnan_(exp) || isnan_(base)) {  // not work((
    res = S21_NAN;
  } else if ((base < 0 && base > -1) && (exp < 0 && exp > -1)) {
    res = S21_NAN;
  } else if ((base < 0 && base > -1) && (exp > 0 && exp < 1)) {
    res = S21_NAN;
  } else if ((base == S21_INF && (exp == -1 || exp == -S21_INF))) {
    res = 0;
  } else if (((base < -1 || base > 1) && exp == -S21_INF)) {
    res = 0;
  } else if ((base >= 0 && exp == S21_INF)) {
    res = 0;
  } else if (exp < -1) {
    while (exp < -1) {
      res = b_res * base;
      b_res = res;
      exp++;
    }
    res = 1 / b_res;

  } else if (exp >= 1) {
    while (exp > 0) {
      res = b_res * base;
      b_res = res;
      exp--;
    }
  } else if (base == 1 && exp == S21_NAN) {
    res = 1;
  }
  return res;
}

