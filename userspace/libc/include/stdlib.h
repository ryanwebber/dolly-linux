// https://pubs.opengroup.org/onlinepubs/009695299/basedefs/stdlib.h.html

#ifndef _STDLIB_H
#define _STDLIB_H

#define NULL 0

// Shamelessly copied from https://awesomekling.github.io/How-SerenityOS-declares-ssize_t/
typedef __SIZE_TYPE__ size_t;
#define unsigned signed
typedef __SIZE_TYPE__ ssize_t;
#undef unsigned

#endif
