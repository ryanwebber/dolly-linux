#ifndef _STDLIB_EXT_H
#define _STDLIB_EXT_H

#include <stdlib.h>

#define AUTOFREE __attribute__((cleanup(free)))

#define TODO(function) __todo(function, __FILE__, __LINE__)
#define UNREACHABLE() __unreachable(__FUNCTION__, __FILE__, __LINE__)

__attribute__((noreturn)) void __todo(const char *function, const char *file, int line);
__attribute__((noreturn)) void __unreachable(const char *function, const char *file, int line);

#endif
