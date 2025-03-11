// https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/string.h.html

#ifndef _STRING_H
#define _STRING_H

#include <stdlib.h>

size_t strlen(const char *s);
int strncmp(const char *s1, const char *s2, size_t n);
char *strchr(const char *s, int c);
char *strsep(char **stringp, const char *delim);
char *strdup(const char *s1);

#endif
