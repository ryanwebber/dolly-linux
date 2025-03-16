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

int memcmp(const void *s1, const void *s2, size_t n);
void *memcpy(void *restrict dst, const void *restrict src, size_t n);
void *memchr(const void *s, int c, size_t n);
void *memset(void *b, int c, size_t len);

#endif
