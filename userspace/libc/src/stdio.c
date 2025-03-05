#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%' && *(format + 1) != '\0')
        {
            format++;
            switch (*format)
            {
            case 'd':
            {
                int i = va_arg(args, int);
                (void)i;
                write(stdout, "{d}", 3);
                break;
            }
            case 's':
            {
                char *s = va_arg(args, char *);
                (void)s;
                write(stdout, "{s}", 3);
                break;
            }
            default:
            {
                write(stdout, "{?}", 3);
                break;
            }
            }
        }
        else
        {
            write(stdout, format, 1);
        }

        format++;
    }

    va_end(args);

    return 0;
}
