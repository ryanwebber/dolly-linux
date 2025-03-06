#include "string.h"
#include "unistd.h"

size_t strlen(const char *s)
{
    size_t len = 0;
    while (s[len] != '\0')
    {
        (void)s;
        len++;
    }
    return len;
}
