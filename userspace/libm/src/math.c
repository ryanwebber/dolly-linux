#include <math.h>
#include <float.h>

double acos(double x)
{
    return __builtin_acos(x);
}

double asin(double x)
{
    return __builtin_asin(x);
}

double atan2(double y, double x)
{
    return __builtin_atan2(y, x);
}

double ceil(double x)
{
    return __builtin_ceil(x);
}

double cos(double x)
{
    return __builtin_cos(x);
}

double cosh(double x)
{
    return __builtin_cosh(x);
}

double exp(double x)
{
    return __builtin_exp(x);
}

double fabs(double x)
{
    return __builtin_fabs(x);
}

double floor(double x)
{
    return __builtin_floor(x);
}

double fmod(double x, double y)
{
    return __builtin_fmod(x, y);
}

double frexp(double value, int *exp)
{
    return __builtin_frexp(value, exp);
}

double ldexp(double x, int n)
{
    return __builtin_ldexp(x, n);
}

double log(double x)
{
    return __builtin_log(x);
}

double log10(double x)
{
    return __builtin_log10(x);
}

double log2(double x)
{
    return __builtin_log2(x);
}

double pow(double x, double y)
{
    return __builtin_pow(x, y);
}

double sin(double x)
{
    return __builtin_sin(x);
}

double sinh(double x)
{
    return __builtin_sinh(x);
}

double sqrt(double x)
{
    return __builtin_sqrt(x);
}

double tan(double x)
{
    return __builtin_tan(x);
}

double tanh(double x)
{
    return __builtin_tanh(x);
}
