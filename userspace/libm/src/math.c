#include <math.h>
#include <float.h>

union x87_control_word get_cw_x87()
{
    union x87_control_word cw;
    asm("fnstcw %0"
        : "=m"(cw));
    return cw;
}
void set_cw_x87(union x87_control_word control_word)
{
    asm("fldcw %0" ::"m"(control_word));
}

double floor(double value)
{
    union x87_control_word cw = get_cw_x87();
    union x87_control_word new_cw = cw;
    new_cw.rounding_control = ROUNDING_MODE_DOWN;
    set_cw_x87(new_cw);
    asm("frndint"
        : "+t"(value));

    set_cw_x87(cw);
    return value;
}
