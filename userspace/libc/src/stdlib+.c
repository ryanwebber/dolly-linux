#include <stdlib+.h>
#include <stdio.h>

__attribute__((noreturn)) void __todo(const char *function, const char *file, int line)
{
    fprintf(stderr, "TODO: %s at %s:%d\n", function, file, line);
    abort();
}

__attribute__((noreturn)) void __unreachable(const char *function, const char *file, int line)
{
    fprintf(stderr, "Reached unreachable code in `%s` at %s:%d\n", function, file, line);
    abort();
}
