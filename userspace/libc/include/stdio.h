// https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/stdio.h.html

#ifndef _STDIO_H
#define _STDIO_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

#define __FILE_BUFFER_SIZE 1024

struct __file
{
    // File descriptor (e.g., 1 for stdout)
    int fd;

    // Pointer to buffer
    char *buffer;

    // Size of the buffer
    size_t buf_size;

    // Current position in the buffer
    size_t buf_pos;

    // Flags for error, EOF, etc.
    int flags;

    // Mode of the stream (read/write)
    int mode;

    // Whether the stream is line-buffered
    bool is_line_buffered;
};

typedef struct __file FILE;

extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

int fprintf(FILE *stream, const char *format, ...);
int fputc(int c, FILE *stream);
int fputs(const char *s, FILE *stream);
int printf(const char *format, ...);
int putchar(int c);
int snprintf(char *restrict str, size_t size, const char *restrict format, ...);
int vfprintf(FILE *restrict stream, const char *restrict format, va_list ap);
int vsnprintf(char *restrict str, size_t size, const char *restrict format, va_list ap);

void perror(const char *s);

#endif
