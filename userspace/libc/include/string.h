// https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/string.h.html

#ifndef _STRING_H
#define _STRING_H

#include <stdlib.h>

char *strchr(const char *s, int c);
char *strcpy(char *dst, const char *src);
char *strdup(const char *s1);
char *strpbrk(const char *s, const char *charset);
char *strsep(char **stringp, const char *delim);
int strcoll(const char *s1, const char *s2);
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
size_t strlen(const char *s);
size_t strspn(const char *s, const char *charset);
char *strstr(const char *haystack, const char *needle);

#define memmove(dst, src, n) __builtin_memmove(dst, src, n)
#define memset(b, c, len) __builtin_memset(b, c, len)
#define memchr(s, c, n) __builtin_memchr(s, c, n)
#define memcmp(s1, s2, n) __builtin_memcmp(s1, s2, n)
#define memcpy(dst, src, n) __builtin_memcpy(dst, src, n)

#endif
