// https://pubs.opengroup.org/onlinepubs/009696699/basedefs/sys/types.h.html

#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

// Shamelessly copied from https://awesomekling.github.io/How-SerenityOS-declares-ssize_t/
typedef __SIZE_TYPE__ size_t;
#define unsigned signed
typedef __SIZE_TYPE__ ssize_t;
#undef unsigned

typedef int id_t;
typedef int pid_t;
typedef int uid_t;

#endif
