#include <stdio+.h>

int printfn(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int ret = vfprintf(stdout, format, args);
    putchar('\n');
    va_end(args);
    return ret;
}
