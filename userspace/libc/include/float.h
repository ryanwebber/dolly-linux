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

union x87_control_word
{
    uint16_t cw;
    struct
    {
        uint16_t mask_invalid : 1;
        uint16_t mask_denorm : 1;
        uint16_t mask_zero_div : 1;
        uint16_t mask_overflow : 1;
        uint16_t mask_underflow : 1;
        uint16_t mask_precision : 1;
        uint16_t : 2;
        uint16_t precision : 2;
        uint16_t rounding_control : 2;
        uint16_t infinity_control : 1;
        uint16_t : 3;
    };
};

#endif
