// https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/math.h.html

#ifndef _MATH_H
#define _MATH_H

#define HUGE_VAL (__builtin_huge_val())

double acos(double x);
double asin(double x);
double atan2(double y, double x);
double ceil(double x);
double cos(double x);
double cosh(double x);
double exp(double x);
double fabs(double x);
double floor(double x);
double fmod(double x, double y);
double frexp(double value, int *exp);
double ldexp(double x, int n);
double log(double x);
double log10(double x);
double log2(double x);
double pow(double x, double y);
double sin(double x);
double sinh(double x);
double sqrt(double x);
double tan(double x);
double tanh(double x);

#endif
