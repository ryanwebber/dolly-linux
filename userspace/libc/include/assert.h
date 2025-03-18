// https://pubs.opengroup.org/onlinepubs/009695299/basedefs/assert.h.html

#ifndef _ASSERT_H
#define _ASSERT_H

#include <stdio.h>

#define assert(expr) \
    ((expr) ? (void)0 : (fprintf(stderr, "Assertion failed: %s, file %s, line %d\n", #expr, __FILE__, __LINE__), abort()))

#endif
