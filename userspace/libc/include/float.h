// https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/float.h.html

#ifndef _FLOAT_H
#define _FLOAT_H

#include <stdint.h>

#define ROUNDING_MODE_NEAREST (0b00)
#define ROUNDING_MODE_DOWN (0b01)
#define ROUNDING_MODE_UP (0b10)
#define ROUNDING_MODE_TRUNC (0b11)

#define DBL_MANT_DIG 53
#define DBL_MAX_10_EXP 308

#endif
