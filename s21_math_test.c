#include "s21_math.h"

#include <check.h>
#include <math.h>

START_TEST(abs_test) {
    ck_assert_int_eq(s21_abs(1), abs(1));
    ck_assert_int_eq(s21_abs(-1), abs(-1));
    ck_assert_int_eq(s21_abs(-99999999), abs(-99999999));
    ck_assert_int_eq(s21_abs(999999999), abs(999999999));
    ck_assert_int_eq(s21_abs(0), abs(0));
    ck_assert_int_eq(s21_abs(-0), abs(-0));
    ck_assert_int_eq(s21_abs(+0), abs(+0));
    ck_assert_int_eq(s21_abs(21), abs(21));
    ck_assert_int_eq(s21_abs(-21), abs(-21));
    ck_assert_int_eq(s21_abs((int)NAN), abs((int)NAN));
    ck_assert_int_eq(s21_abs((int)INFINITY), abs((int)INFINITY));
    ck_assert_int_eq(s21_abs((int)-INFINITY), abs((int)-INFINITY));
}
END_TEST

START_TEST(s21_math_acos_test) {
    ck_assert_float_eq(s21_acos(1), acos(1));
    ck_assert_float_eq(s21_acos(0), acos(0));
    ck_assert_float_eq(s21_acos(-1), acos(-1));
    ck_assert_ldouble_nan(s21_acos(NAN));
    ck_assert_ldouble_nan(s21_acos(NAN));
    ck_assert_ldouble_nan(acos(NAN));
    ck_assert_ldouble_nan(s21_acos(NAN));
    ck_assert_ldouble_nan(acos(NAN));
    ck_assert_ldouble_eq_tol(s21_acos(1.0), acos(1.0), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_acos(-1.0), acos(-1.0), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_acos(0.0), acos(0.0), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_acos(-0.0), acos(-0.0), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), S21_EPS);
}
END_TEST

START_TEST(s21_math_asin_test) {
    ck_assert_ldouble_nan(s21_asin(INFINITY));
    ck_assert_ldouble_nan(asin(INFINITY));
    ck_assert_ldouble_nan(s21_asin(-INFINITY));
    ck_assert_ldouble_nan(asin(-INFINITY));
    ck_assert_ldouble_nan(s21_asin(NAN));
    ck_assert_ldouble_nan(asin(NAN));
    ck_assert_ldouble_eq_tol(s21_asin(1.0), asin(1.0), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_asin(-1.0), asin(-1.0), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_asin(0.0), asin(0.0), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_asin(-0.0), asin(-0.0), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_asin(0.0), asin(0.0), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), S21_EPS);
}
END_TEST

START_TEST(s21_math_fmod_test) {
    ck_assert_ldouble_eq(s21_fmod(-10.66, -3.0), fmod(-10.66, -3.0));
    ck_assert_ldouble_eq(s21_fmod(-10.66, 3.0), fmod(-10.66, 3.0));
    ck_assert_ldouble_eq(s21_fmod(10.66, -3.0), fmod(10.66, -3.0));
    ck_assert_ldouble_eq(s21_fmod(10.66, 3.0), fmod(10.66, 3.0));
    ck_assert_ldouble_eq(s21_fmod(-20000, -7), fmod(-20000, -7));
    ck_assert_ldouble_eq(s21_fmod(-7, -20000), fmod(-7, -20000));
    ck_assert_ldouble_eq(s21_fmod(-33.45, 3), fmod(-33.45, 3));
    ck_assert_ldouble_eq(s21_fmod(3, -33.45), fmod(3, -33.45));
    ck_assert_ldouble_eq(s21_fmod(33.45, 3), fmod(33.45, 3));
    ck_assert_ldouble_eq(s21_fmod(3, 33.45), fmod(3, 33.45));
    ck_assert_ldouble_eq(s21_fmod(20000, 7), fmod(20000, 7));
    ck_assert_ldouble_eq(s21_fmod(-7, -7), fmod(-7, -7));
    ck_assert_ldouble_eq(s21_fmod(10, 5), fmod(10, 5));
    ck_assert_ldouble_eq(s21_fmod(0, 23), fmod(0, 23));
    ck_assert_ldouble_nan(s21_fmod(2.4555, 0));
    ck_assert_ldouble_nan(fmod(2.4555, 0));
    ck_assert_ldouble_nan(s21_fmod(0, 0));
    ck_assert_ldouble_nan(fmod(0, 0));
    ck_assert_ldouble_nan(fmod(0, 0));
    ck_assert_ldouble_nan(fmod(S21_INF, 0));
    ck_assert_ldouble_nan(s21_fmod(S21_INF, 0));
    ck_assert_ldouble_nan(fmod(S21_INF, S21_INF));
    ck_assert_ldouble_nan(fmod(S21_NAN, S21_NAN));
    ck_assert_ldouble_nan(fmod(S21_INF, S21_INF));
    ck_assert_ldouble_nan(s21_fmod(S21_INF, S21_INF));
    ck_assert_ldouble_nan(s21_fmod(S21_NAN, S21_NAN));
    ck_assert_ldouble_nan(s21_fmod(S21_INF, S21_INF));
    ck_assert_ldouble_eq(s21_fmod(1.0, S21_INF), fmod(1.0, S21_INF));
    ck_assert_ldouble_eq(s21_fmod(1.0, S21_INF), fmod(1.0, S21_INF));
    ck_assert_ldouble_eq(s21_fmod(1.0, -S21_INF), fmod(1.0, -S21_INF));
}
END_TEST

START_TEST(s21_math_atan_test) {
    ck_assert_ldouble_eq_tol(s21_atan(INFINITY), (M_PI / 2.0), S21_EPS);
    ck_assert_ldouble_eq_tol(atan(INFINITY), (M_PI / 2.0), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_atan((-INFINITY)), ((M_PI) / -2.0), S21_EPS);
    ck_assert_ldouble_eq_tol(atan(-INFINITY), ((M_PI) / -2.0), S21_EPS);
    ck_assert_ldouble_nan(s21_atan(NAN));
    ck_assert_ldouble_nan(atan(NAN));
    ck_assert_ldouble_eq_tol(s21_atan(2.1234567e-7), atan(2.1234567e-7), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_atan(2.1234567e-16), atan(2.1234567e-16),
                             S21_EPS);
    ck_assert_float_nan(s21_atan(S21_NAN));
}
END_TEST

START_TEST(s21_math_ceil) {
    ck_assert_ldouble_eq(s21_ceil(-15.01), ceil(-15.01));
    ck_assert_ldouble_eq(s21_ceil(15.01), ceil(15.01));
    ck_assert_ldouble_eq(s21_ceil(INFINITY), ceil(INFINITY));
    ck_assert_ldouble_eq(s21_ceil(-INFINITY), ceil(-INFINITY));
    ck_assert_ldouble_eq(s21_ceil(-0.12), ceil(-0.12));
    ck_assert_ldouble_infinite(s21_ceil(INFINITY));
    ck_assert_ldouble_infinite(ceil(INFINITY));
    ck_assert_ldouble_nan(s21_ceil(NAN));
    ck_assert_ldouble_nan(ceil(NAN));
    ck_assert_ldouble_eq(s21_ceil(0), ceil(0));
    ck_assert_ldouble_eq(s21_ceil(0.0), ceil(0.0));
    ck_assert_ldouble_eq(s21_ceil(21.21), ceil(21.21));
    ck_assert_ldouble_eq(s21_ceil(21.91), ceil(21.91));
    ck_assert_ldouble_eq(s21_ceil(-21.21), ceil(-21.21));
    ck_assert_ldouble_eq(s21_ceil(-21.91), ceil(-21.91));
}
END_TEST

START_TEST(s21_math_cos) {
    ck_assert_float_eq(s21_cos(0), cos(0));
    ck_assert_float_eq(s21_cos(-1), cos(-1));
    ck_assert_double_eq_tol(s21_cos(0), cosl(0), 1e-06);
    ck_assert_ldouble_nan(s21_cos(-INFINITY));
    ck_assert_ldouble_nan(cosl(-INFINITY));
    ck_assert_ldouble_nan(s21_cos(INFINITY));
    ck_assert_ldouble_nan(cosl(INFINITY));
    ck_assert_ldouble_nan(s21_cos(NAN));
    ck_assert_ldouble_nan(cosl(NAN));
    ck_assert_double_eq_tol(s21_cos(0.0), cosl(0.0), 1e-06);
    ck_assert_double_eq_tol(s21_cos(M_PI / 4), cosl(M_PI / 4), 1e-06);
    ck_assert_double_eq_tol(s21_cos(M_PI / 6), cosl(M_PI / 6), 1e-06);
    ck_assert_double_eq_tol(s21_cos(M_PI / 3), cosl(M_PI / 3), 1e-06);
    ck_assert_double_eq_tol(s21_cos(M_PI / 2), cosl(M_PI / 2), 1e-06);
    ck_assert_double_eq_tol(s21_cos(3 * M_PI / 2), cosl(3 * M_PI / 2), 1e-06);
    ck_assert_double_eq_tol(s21_cos(2 * M_PI), cosl(2 * M_PI), 1e-06);
}
END_TEST

START_TEST(s21_math_exp) {
    ck_assert_int_eq(s21_exp(0), exp(0));
    ck_assert_int_eq(s21_exp(1), exp(1));
    ck_assert_int_eq(s21_exp(2), exp(2));
    ck_assert_int_eq(s21_exp(3), exp(3));
    ck_assert_int_eq(s21_exp(1.5), exp(1.5));
    ck_assert_int_eq(s21_exp(-1.5), exp(-1.5));
    ck_assert_int_eq(s21_exp(0.5), exp(0.5));
    ck_assert_int_eq(s21_exp(-0.5), exp(-0.5));
    ck_assert_float_eq(s21_exp(2), exp(2));
    ck_assert_float_eq(s21_exp(-2), exp(-2));
    ck_assert_ldouble_eq_tol(s21_exp(-INFINITY), expl(-INFINITY), 1e-06);
    ck_assert_ldouble_infinite(s21_exp(INFINITY));
    ck_assert_ldouble_infinite(expl(INFINITY));
    ck_assert_ldouble_nan(s21_exp(NAN));
    ck_assert_ldouble_nan(expl(NAN));
}
END_TEST

START_TEST(s21_math_fabs) {
    ck_assert_ldouble_eq(s21_fabs(0.000001), fabs(0.000001));
    ck_assert_ldouble_eq(s21_fabs(-21.000345), fabs(-21.000345));
    ck_assert_ldouble_eq(s21_fabs(-2147483600.543), fabs(-2147483600.543));
    ck_assert_ldouble_eq(s21_fabs(2147483600.4857), fabs(2147483600.4857));
    ck_assert_ldouble_eq(s21_fabs(-5.53151413431), fabs(-5.53151413431));
    ck_assert_ldouble_nan(s21_fabs(NAN));
    ck_assert_ldouble_nan(fabs(NAN));
    ck_assert_ldouble_infinite(s21_fabs(S21_INF));
    ck_assert_ldouble_infinite(fabs(S21_INF));
    ck_assert_ldouble_eq_tol(s21_fabs(-9519359135915.53151413431),
                             fabs(-9519359135915.53151413431), S21_EPS);
    ck_assert_ldouble_nan(s21_fabs(NAN));
    ck_assert_ldouble_nan(fabs(NAN));
    ck_assert_ldouble_eq(s21_fabs(-15.01), fabs(-15.01));
    ck_assert_ldouble_eq(s21_fabs(15.01), fabs(15.01));
    ck_assert_ldouble_eq(s21_fabs(INFINITY), fabs(INFINITY));
    ck_assert_ldouble_eq(s21_fabs(-INFINITY), fabs(-INFINITY));
}
END_TEST

START_TEST(s21_math_floor) {
    ck_assert_ldouble_eq(s21_floor(0.0), floor(0.0));
    ck_assert_ldouble_eq(s21_floor(21.21), floor(21.21));
    ck_assert_ldouble_eq(s21_floor(21.91), floor(21.91));
    ck_assert_ldouble_eq(s21_floor(-21.21), floor(-21.21));
    ck_assert_ldouble_eq(s21_floor(-21.91), floor(-21.91));
    ck_assert_ldouble_infinite(s21_floor(INFINITY));
    ck_assert_ldouble_infinite(floor(INFINITY));
    ck_assert_ldouble_nan(s21_floor(NAN));
    ck_assert_ldouble_nan(floor(NAN));
    ck_assert_ldouble_eq(s21_floor(0), floor(0));
    ck_assert_ldouble_eq(s21_floor(-15.01), floor(-15.01));
    ck_assert_ldouble_eq(s21_floor(15.01), floor(15.01));
    ck_assert_ldouble_eq(s21_floor(INFINITY), floor(INFINITY));
    ck_assert_ldouble_eq(s21_floor(-INFINITY), floor(-INFINITY));
    ck_assert_ldouble_eq(s21_floor(-0), floor(-0));
}
END_TEST

START_TEST(s21_math_log) {
    ck_assert_ldouble_infinite(s21_log(INFINITY));
    ck_assert_ldouble_infinite(log(INFINITY));
    ck_assert_ldouble_nan(s21_log(-INFINITY));
    ck_assert_ldouble_nan(log(-INFINITY));
    ck_assert_ldouble_nan(s21_log(NAN));
    ck_assert_ldouble_nan(log(NAN));
    ck_assert_ldouble_eq_tol(s21_log(1.0), log(1.0), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(1.1), log(1.1), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(1), log(1), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(100), log(100), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(DBL_MAX), log(DBL_MAX), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(S21_PI / 3), log(S21_PI / 3), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(9.234578353457e6), log(9.234578353457e6),
                             1e-6);
    ck_assert_ldouble_eq_tol(s21_log(1234567.000000004), log(1234567.000000004),
                             1e-6);
    ck_assert_ldouble_infinite(s21_log(0));
    ck_assert_ldouble_infinite(log(0));
}
END_TEST

START_TEST(s21_math_sin) {
    ck_assert_double_eq_tol(s21_sin(0), sinl(0), 1e-06);
    ck_assert_ldouble_nan(s21_sin(-INFINITY));
    ck_assert_ldouble_nan(sinl(-INFINITY));
    ck_assert_ldouble_nan(s21_sin(INFINITY));
    ck_assert_ldouble_nan(sinl(INFINITY));
    ck_assert_ldouble_nan(s21_sin(NAN));
    ck_assert_ldouble_nan(sinl(NAN));
    ck_assert_double_eq_tol(s21_sin(0.0), sin(0.0), 1e-06);
    ck_assert_double_eq_tol(s21_sin(M_PI / 6), sin(M_PI / 6), 1e-06);
    ck_assert_double_eq_tol(s21_sin(M_PI / 4), sin(M_PI / 4), 1e-06);
    ck_assert_double_eq_tol(s21_sin(M_PI / 3), sin(M_PI / 3), 1e-06);
    ck_assert_double_eq_tol(s21_sin(M_PI / 2), sin(M_PI / 2), 1e-06);
    ck_assert_double_eq_tol(s21_sin(3 * M_PI / 2), sin(3 * M_PI / 2), 1e-06);
    ck_assert_double_eq_tol(s21_sin(2 * M_PI), sin(2 * M_PI), 1e-06);
    ck_assert_double_eq_tol(s21_sin(-2 * M_PI), sin(-2 * M_PI), 1e-06);
    ck_assert_double_eq_tol(s21_sin(-3 * M_PI), sin(-3 * M_PI), 1e-06);
    ck_assert_double_eq_tol(s21_sin(-S21_PI), sin(-S21_PI), 1e-06);
}
END_TEST

START_TEST(s21_math_sqrt) {
    ck_assert_ldouble_infinite(s21_sqrt(INFINITY));
    ck_assert_ldouble_infinite(sqrt(INFINITY));
    ck_assert_ldouble_nan(s21_sqrt(NAN));
    ck_assert_ldouble_nan(sqrt(NAN));
    ck_assert_ldouble_eq_tol(s21_sqrt(1.0), sqrt(1.0), 1e-6);
    ck_assert_ldouble_eq_tol(s21_sqrt(1.1), sqrt(1.1), 1e-6);
    ck_assert_ldouble_eq_tol(s21_sqrt(0.0), sqrt(0.0), 1e-6);
    ck_assert_ldouble_eq_tol(s21_sqrt(-0.0), sqrt(-0.0), 1e-6);
    ck_assert_ldouble_eq_tol(s21_sqrt(10e+16), sqrt(10e+16), 1e-6);
    ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), 1e-6);
    ck_assert_ldouble_eq_tol(s21_sqrt(100), sqrt(100), 1e-6);
    ck_assert_ldouble_eq_tol(s21_sqrt(98765432.123), sqrt(98765432.123), 1e-6);
    ck_assert_ldouble_eq_tol(s21_sqrt(981.123e6), sqrt(981.123e6), 1e-6);
    ck_assert_ldouble_eq_tol(s21_sqrt(981.123e-15), sqrt(981.123e-15), 1e-6);
}
END_TEST

START_TEST(s21_math_tan) {
    ck_assert_ldouble_nan(s21_tan(-INFINITY));
    ck_assert_ldouble_nan(tanl(-INFINITY));
    ck_assert_ldouble_nan(s21_tan(INFINITY));
    ck_assert_ldouble_nan(tanl(INFINITY));
    ck_assert_ldouble_nan(s21_tan(NAN));
    ck_assert_ldouble_nan(tanl(NAN));
    ck_assert_double_eq_tol(s21_tan(0.0), tanl(0.0), 1e-06);
    ck_assert_double_eq_tol(s21_tan(M_PI / 6), tanl(M_PI / 6), 1e-06);
    ck_assert_double_eq_tol(s21_tan(M_PI / 4), tanl(M_PI / 4), 1e-06);
    ck_assert_double_eq_tol(s21_tan(-2 * M_PI), tanl(-2 * M_PI), 1e-06);
    ck_assert_double_eq_tol(s21_tan(M_PI), tanl(M_PI), 1e-06);
    ck_assert_double_eq_tol(s21_tan(M_PI / 3), tanl(M_PI / 3), 1e-06);
    ck_assert_double_eq_tol(s21_tan(3 * M_PI / 3), tanl(3 * M_PI / 3), 1e-06);
}
END_TEST

START_TEST(s21_math_pow_test) {
    ck_assert_double_eq(pow(1, 0), s21_pow(1, 0));
    ck_assert_double_eq(pow(-1, 3), s21_pow(-1, 3));
    ck_assert_double_eq(pow(-1, 4), s21_pow(-1, 4));
    ck_assert_double_eq(pow(0, 0), s21_pow(0, 0));
    ck_assert_double_eq(pow(0, -1), s21_pow(0, -1));
    ck_assert_double_eq(pow(0, 1), s21_pow(0, 1));
    ck_assert_double_eq(pow(S21_INF, 0), s21_pow(S21_INF, 0));
    ck_assert_double_eq(pow(S21_INF, -1), s21_pow(S21_INF, -1));
    ck_assert_double_eq(pow(-1, -S21_INF), s21_pow(-1, -S21_INF));
    ck_assert_double_eq(pow(0, S21_INF), s21_pow(0, S21_INF));
    ck_assert_double_nan(s21_pow(0, S21_NAN));
    ck_assert_double_eq(pow(NAN, 0), s21_pow(S21_NAN, 0));
    ck_assert_double_nan(s21_pow(S21_NAN, S21_NAN));
    ck_assert_double_eq(pow(S21_INF, S21_INF), s21_pow(S21_INF, S21_INF));
    ck_assert_double_eq(pow(S21_INF, -S21_INF), s21_pow(S21_INF, -S21_INF));
    ck_assert_double_eq(pow(-S21_INF, S21_INF), s21_pow(-S21_INF, S21_INF));
    ck_assert_double_eq(pow(-S21_INF, -S21_INF), s21_pow(-S21_INF, -S21_INF));
    ck_assert_double_eq(pow(1, -S21_INF), s21_pow(1, -S21_INF));
    ck_assert_double_nan(s21_pow(S21_NAN, S21_INF));
    ck_assert_double_nan(s21_pow(S21_INF, S21_NAN));
    ck_assert_double_nan(s21_pow(S21_NAN, -S21_INF));
    ck_assert_double_nan(s21_pow(-S21_INF, S21_NAN));
    ck_assert_double_eq(pow(2, S21_INF), s21_pow(2, S21_INF));
    ck_assert_double_eq(pow(0.5, S21_INF), s21_pow(0.5, S21_INF));
    ck_assert_double_eq(pow(-2, S21_INF), s21_pow(-2, S21_INF));
    ck_assert_double_eq(pow(2, -S21_INF), s21_pow(2, -S21_INF));
    ck_assert_double_eq(pow(0.5, -S21_INF), s21_pow(0.5, -S21_INF));
    ck_assert_double_eq(pow(-2, -S21_INF), s21_pow(-2, -S21_INF));
}
END_TEST

int main(void) {
    Suite *s1 = suite_create("Core");
    TCase *tc1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;
    suite_add_tcase(s1, tc1);
    tcase_add_test(tc1, abs_test);
    tcase_add_test(tc1, s21_math_acos_test);
    tcase_add_test(tc1, s21_math_asin_test);
    tcase_add_test(tc1, s21_math_fmod_test);
    tcase_add_test(tc1, s21_math_atan_test);
    tcase_add_test(tc1, s21_math_ceil);
    tcase_add_test(tc1, s21_math_cos);
    tcase_add_test(tc1, s21_math_exp);
    tcase_add_test(tc1, s21_math_fabs);
    tcase_add_test(tc1, s21_math_floor);
    tcase_add_test(tc1, s21_math_log);
    tcase_add_test(tc1, s21_math_sin);
    tcase_add_test(tc1, s21_math_sqrt);
    tcase_add_test(tc1, s21_math_tan);
    tcase_add_test(tc1, s21_math_pow_test);
    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);
    return nf == 0 ? 0 : 1;
}
