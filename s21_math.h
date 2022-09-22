#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_
#include <stdio.h>
#include <stdlib.h>
#define S21_E 2.718281828459045091
#define logE 1
#define pr 1e-16
#define S21_INF 1.0 / 0.0
#define S21_NAN 0.0 / 0.0
#define E_10 2.302585092994046
#define S21_PI 3.14159265358979323846264338327950288
#define S21_EPS 1e-9
#define isnan_(x) __builtin_isnan(x)

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
int s21_factorial(int x);
#endif  // SRC_S21_MATH_H_
