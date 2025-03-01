// https://pubs.opengroup.org/onlinepubs/009696699/basedefs/sys/types.h.html

// Shamelessly copied from https://awesomekling.github.io/How-SerenityOS-declares-ssize_t/
typedef __SIZE_TYPE__ size_t;
#define unsigned signed
typedef __SIZE_TYPE__ ssize_t;
#undef unsigned
