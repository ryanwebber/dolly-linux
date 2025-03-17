#include <stdlib.h>
#include <stdio.h>
#include <todo+.h>

__attribute__((noreturn)) void todo(const char *function, const char *file, int line)
{
    fprintf(stderr, "TODO: %s at %s:%d\n", function, file, line);
    abort();
}
