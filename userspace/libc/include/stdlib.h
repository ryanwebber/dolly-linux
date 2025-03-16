// https://pubs.opengroup.org/onlinepubs/009695299/basedefs/stdlib.h.html

#ifndef _STDLIB_H
#define _STDLIB_H

#define NULL 0

#define EXIT_FAILURE 1 /* Failing exit status.  */
#define EXIT_SUCCESS 0 /* Successful exit status.  */

// Shamelessly copied from https://awesomekling.github.io/How-SerenityOS-declares-ssize_t/
typedef __SIZE_TYPE__ size_t;
#define unsigned signed
typedef __SIZE_TYPE__ ssize_t;
#undef unsigned

typedef __PTRDIFF_TYPE__ ptrdiff_t;

#define offsetof(type, member) __builtin_offsetof(type, member)

void exit(int status);
void abort(void);

void *malloc(size_t size);
void free(void *ptr);

char *getenv(const char *name);

int posix_openpt(int oflag);
int grantpt(int fildes);
int unlockpt(int fildes);
char *ptsname(int fildes);

int system(const char *command);

double strtod(const char *restrict nptr, char **restrict endptr);

int abs(int i);

#endif
