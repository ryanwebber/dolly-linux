// https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/stdio.h.html

#ifndef _STDIO_H
#define _STDIO_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

#define __FILE_BUFFER_SIZE 1024

#define BUFSIZ __FILE_BUFFER_SIZE
#define EOF (-1)

#define L_tmpnam (256)

#define SEEK_SET 0 /* Seek from beginning of file.  */
#define SEEK_CUR 1 /* Seek from current position.  */
#define SEEK_END 2 /* Seek from end of file.  */

#define _IOFBF 0 /* Fully buffered.  */
#define _IOLBF 1 /* Line buffered.  */
#define _IONBF 2 /* No buffering.  */

// Defined in stdio.c
struct __file;

typedef struct __file FILE;

extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

#define getc(stream) fgetc(stream)

char *fgets(char *restrict str, int size, FILE *restrict stream);
FILE *fopen(const char *restrict path, const char *restrict mode);
FILE *freopen(const char *path, const char *mode, FILE *stream);
int fclose(FILE *stream);
int feof(FILE *stream);
int fflush(FILE *stream);
int fgetc(FILE *stream);
int fprintf(FILE *stream, const char *format, ...);
int fputc(int c, FILE *stream);
int fputs(const char *s, FILE *stream);
int fseek(FILE *stream, long offset, int whence);
int printf(const char *format, ...);
int putchar(int c);
int setvbuf(FILE *restrict stream, char *restrict buf, int type, size_t size);
int snprintf(char *restrict str, size_t size, const char *restrict format, ...);
int sprintf(char *restrict str, const char *restrict format, ...);
int ungetc(int c, FILE *stream);
int vfprintf(FILE *restrict stream, const char *restrict format, va_list ap);
int vsnprintf(char *restrict str, size_t size, const char *restrict format, va_list ap);
long ftell(FILE *stream);
size_t fread(void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);
size_t fwrite(const void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);

char *strerror(int errnum);
int ferror(FILE *stream);
void clearerr(FILE *stream);
void perror(const char *s);

char *tmpnam(char *s);
FILE *tmpfile(void);
int remove(const char *path);
int rename(const char *old, const char *new);

#endif
