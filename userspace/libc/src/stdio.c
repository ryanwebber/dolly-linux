#include "stdarg.h"
#include "stdio.h"
#include "unistd.h"

#define __FILE_BUFFER_SIZE 1024

static FILE stdin_file = (FILE){
    .fd = STDIN_FILENO,
    .buffer = NULL,
    .buf_size = 0,
    .buf_pos = 0,
    .flags = 0,
    .mode = 0,
    .is_line_buffered = false,
};

static char stdout_buffer[__FILE_BUFFER_SIZE];
static FILE stdout_file = (FILE){
    .fd = STDOUT_FILENO,
    .buffer = &stdout_buffer[0],
    .buf_size = __FILE_BUFFER_SIZE,
    .buf_pos = 0,
    .flags = 0,
    .mode = 0,
    .is_line_buffered = true,
};

static char stderr_buffer[__FILE_BUFFER_SIZE];
static FILE stderr_file = (FILE){
    .fd = STDERR_FILENO,
    .buffer = &stderr_buffer[0],
    .buf_size = __FILE_BUFFER_SIZE,
    .buf_pos = 0,
    .flags = 0,
    .mode = 0,
    .is_line_buffered = true,
};

FILE *stdin = &stdin_file;
FILE *stdout = &stdout_file;
FILE *stderr = &stderr_file;

static size_t fnwrites(const char *str, size_t count, FILE *stream)
{
    for (size_t i = 0; i < count; i++)
    {
        fputc(str[i], stream);
    }

    return count;
}

static int flush_buffer(FILE *stream)
{
    if (stream->fd < 0)
    {
        return -1;
    }

    if (stream->buf_pos > 0)
    {
        // Write the buffer content to stdout
        write(1, stream->buffer, stream->buf_pos);

        // Reset the buffer position
        stream->buf_pos = 0;
    }

    // TODO: This is not always successful
    return 0;
}

int fprintf(FILE *restrict stream, const char *restrict format, ...)
{
    va_list args;
    va_start(args, format);

    int result = vfprintf(stream, format, args);

    va_end(args);

    return result;
}

int fputc(int c, FILE *stream)
{
    // Add the character to the buffer
    stream->buffer[stream->buf_pos++] = (char)c;

    // If the buffer is full, flush it
    if (stream->buf_pos >= stream->buf_size)
    {
        flush_buffer(stream);
    }

    // If the stream is line-buffered, flush on newline
    if (stream->is_line_buffered && c == '\n')
    {
        flush_buffer(stream);
    }

    return c; // Return the character written
}

int fputs(const char *s, FILE *stream)
{
    size_t len = 0;
    while (s[len] != '\0')
    {
        len++;
    }

    return fnwrites(s, len, stream);
}

int printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int result = vfprintf(stdout, format, args);

    va_end(args);

    return result;
}

int putchar(int c)
{
    return fputc(c, stdout);
}

int snprintf(char *restrict str, size_t size, const char *restrict format, ...)
{
    va_list args;
    va_start(args, format);

    int result = vsnprintf(str, size, format, args);

    va_end(args);

    return result;
}

int vfprintf(FILE *restrict stream, const char *restrict format, va_list args)
{
    while (*format != '\0')
    {
        if (*format == '%' && *(format + 1) != '\0')
        {
            format++;
            switch (*format)
            {
            case 'd':
            {
                int i = va_arg(args, int);
                if (i < 0)
                {
                    fputc('-', stream);
                    i = -i;
                }

                // Write out the digits in order
                int divisor = 1;
                while (i / divisor >= 10)
                {
                    divisor *= 10;
                }

                // Print each digit
                while (divisor > 0)
                {
                    int digit = i / divisor;
                    fputc('0' + digit, stream);
                    i %= divisor;
                    divisor /= 10;
                }

                break;
            }
            case 's':
            {
                char *s = va_arg(args, char *);
                fputs(s, stream);
                break;
            }
            default:
            {
                fnwrites("{?}", 3, stream);
                break;
            }
            }
        }
        else
        {
            fputc(*format, stream);
        }

        format++;
    }

    return 0;
}

int vsnprintf(char *restrict str, size_t size, const char *restrict format, va_list ap)
{
    FILE stream = {
        .fd = -1,
        .buffer = str,
        .buf_size = size,
        .buf_pos = 0,
        .flags = 0,
        .mode = 0,
        .is_line_buffered = false,
    };

    vfprintf(&stream, format, ap);

    // Null-terminate the string
    if (size > 0)
    {
        str[size - 1] = '\0';
    }

    return 0;
}

size_t fwrite(const void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream)
{
    size_t count = size * nitems;
    const char *str = ptr;
    return fnwrites(str, count, stream);
}

void perror(const char *s)
{
    // TODO: Print the error message corresponding to errno
    fprintf(stderr, "error: %s\n", s);
}
