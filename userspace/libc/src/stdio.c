#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib+.h>
#include <unistd.h>

#define __FILE_BUFFER_SIZE 1024
#define __FILE_FLAG_EOF 0b001

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

static char stdin_buffer[__FILE_BUFFER_SIZE];
static FILE stdin_file = (FILE){
    .fd = STDIN_FILENO,
    .buffer = stdin_buffer,
    .buf_size = __FILE_BUFFER_SIZE,
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

static int flush_buffer(FILE *stream)
{
    if (stream->fd < 0)
    {
        return -1;
    }

    if (stream->buf_pos > 0)
    {
        // Write the buffer content
        write(stream->fd, stream->buffer, stream->buf_pos);

        // Reset the buffer position
        stream->buf_pos = 0;
    }

    // TODO: This is not always successful
    return 0;
}

static size_t print_sign(long long value)
{
    size_t count = 0;
    if (value < 0)
    {
        count++;
        fputc('-', stdout);
    }

    return count;
}

static size_t print_integral(unsigned long long value)
{
    size_t count = 0;
    unsigned long long divisor = 1;
    while (value / divisor >= 10)
    {
        divisor *= 10;
    }

    while (divisor > 0)
    {
        count++;
        int digit = value / divisor;
        fputc('0' + digit, stdout);
        value %= divisor;
        divisor /= 10;
    }

    return count;
}

char *fgets(char *restrict str, int size, FILE *restrict stream)
{
    int i = 0;
    while (i < size - 1)
    {
        int c = fgetc(stream);
        if (c == EOF)
        {
            break;
        }

        str[i++] = c;
        if (c == '\n')
        {
            break;
        }
    }

    str[i] = '\0';
    return str;
}

FILE *fopen(const char *restrict path, const char *restrict mode)
{
    int imode = 0;
    while (*mode != '\0')
    {
        if (*mode == 'r')
        {
            imode |= O_RDONLY;
        }
        else if (*mode == 'w')
        {
            imode |= O_WRONLY | O_CREAT | O_TRUNC;
        }
        else if (*mode == 'a')
        {
            imode |= O_WRONLY | O_CREAT | O_APPEND;
        }
        else
        {
            return NULL;
        }

        mode++;
    }

    int fd = open(path, imode);
    if (fd < 0)
    {
        return NULL;
    }

    FILE *stream = malloc(sizeof(FILE));
    stream->fd = fd;
    stream->buffer = malloc(__FILE_BUFFER_SIZE);
    stream->buf_size = __FILE_BUFFER_SIZE;
    stream->buf_pos = 0;
    stream->flags = 0;
    stream->mode = imode;
    stream->is_line_buffered = false;

    return stream;
}

FILE *freopen(const char *path, const char *mode, FILE *stream)
{
    fclose(stream);
    return fopen(path, mode);
}

int fprintf(FILE *restrict stream, const char *restrict format, ...)
{
    va_list args;
    va_start(args, format);

    int result = vfprintf(stream, format, args);

    va_end(args);

    return result;
}

int fclose(FILE *stream)
{
    if (stream->fd < 0)
    {
        return -1;
    }

    int result = 0;
    if (stream->buf_pos > 0)
    {
        result = write(stream->fd, stream->buffer, stream->buf_pos);
    }

    close(stream->fd);
    free(stream->buffer);
    free(stream);

    return result;
}

int feof(FILE *stream)
{
    return stream->flags & __FILE_FLAG_EOF;
}

int fflush(FILE *stream)
{
    return flush_buffer(stream);
}

int fgetc(FILE *stream)
{
    if (stream->fd < 0)
    {
        return EOF;
    }

    if (stream->buf_pos >= stream->buf_size)
    {
        flush_buffer(stream);
    }

    char c;
    if (read(stream->fd, &c, 1) == 1)
    {
        return c;
    }
    else
    {
        stream->flags |= __FILE_FLAG_EOF;
        return EOF;
    }
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
    size_t len = strlen(s);
    fwrite(s, 1, len, stream);
    return len;
}

int fseek(FILE *stream, long offset, int whence)
{
    if (stream->fd < 0)
    {
        return -1;
    }

    if (stream->buf_pos > 0)
    {
        flush_buffer(stream);
    }

    return lseek(stream->fd, offset, whence);
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

int setvbuf(FILE *restrict stream, char *restrict buf, int type, size_t size)
{
    if (stream->fd < 0)
    {
        return -1;
    }

    if (type == _IONBF)
    {
        stream->buffer = NULL;
        stream->buf_size = 0;
    }
    else if (type == _IOLBF || type == _IOFBF)
    {
        if (buf == NULL)
        {
            stream->buffer = malloc(size);
            stream->buf_size = size;
        }
        else
        {
            stream->buffer = buf;
            stream->buf_size = size;
        }
    }
    else
    {
        return -1;
    }

    stream->is_line_buffered = type == _IOLBF;
    return 0;
}

int sprintf(char *restrict str, const char *restrict format, ...)
{
    va_list args;
    va_start(args, format);

    // man(3): The sprintf() and vsprintf() functions effectively assume a size of INT_MAX + 1.
    size_t size = ((size_t)2147483647) + 1;
    assert(size > 2147483647);

    int result = vsnprintf(str, size, format, args);

    va_end(args);

    return result;
}

int ungetc(int c, FILE *stream)
{
    if (stream->fd < 0)
    {
        return -1;
    }

    if (stream->buf_pos == 0)
    {
        return -1;
    }

    stream->buffer[--stream->buf_pos] = c;
    return c;
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
    int count = 0;
    while (*format != '\0')
    {
        if (*format == '%' && *(format + 1) != '\0')
        {
            format++;
            switch (*format)
            {
            case 'd': // %d
            {
                int i = va_arg(args, int);
                count += print_sign((long long)i);
                count += print_integral((unsigned long long)i);
                break;
            }
            case 's': // %s
            {
                char *s = va_arg(args, char *);
                count += fputs(s, stream);
                break;
            }
            case 'l':
            {
                // Check next character
                format++;
                assert(*format != '\0');
                switch (*format)
                {
                case 'd': // %ld
                {
                    long i = va_arg(args, long);
                    count += print_sign((long long)i);
                    count += print_integral((unsigned long long)i);
                    break;
                }
                case 'l': // %ll
                {
                    format++;
                    assert(*format != '\0');
                    switch (*format)
                    {
                    case 'd': // %lld
                    {
                        long long i = va_arg(args, long long);
                        count += print_sign((long long)i);
                        count += print_integral((unsigned long long)i);
                        break;
                    }
                    default:
                    {
                        UNREACHABLE();
                    }
                    }
                    break;
                }
                default:
                {
                    UNREACHABLE();
                }
                }
                break;
            }
            default:
            {
                UNREACHABLE();
            }
            }
        }
        else
        {
            count++;
            fputc(*format, stream);
        }

        format++;
    }

    return count;
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

    int count = vfprintf(&stream, format, ap);

    // Null-terminate the string
    if (size > 0)
    {
        if ((size_t)count < size)
        {
            str[count] = '\0';
        }
        else
        {
            str[size - 1] = '\0';
        }
    }

    return 0;
}

long ftell(FILE *stream)
{
    if (stream->fd < 0)
    {
        return -1;
    }

    if (stream->buf_pos > 0)
    {
        flush_buffer(stream);
    }

    return lseek(stream->fd, 0, SEEK_CUR);
}

size_t fread(void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream)
{
    size_t count = size * nitems;
    char *str = ptr;
    for (size_t i = 0; i < count; i++)
    {
        int c = fgetc(stream);
        if (c == EOF)
        {
            return i;
        }

        str[i] = c;
    }

    return count;
}

size_t fwrite(const void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream)
{
    size_t count = size * nitems;
    const char *str = ptr;
    for (size_t i = 0; i < count; i++)
    {
        fputc(str[i], stream);
    }

    return count;
}

int ferror(FILE *stream)
{
    return stream->flags;
}

void clearerr(FILE *stream)
{
    stream->flags = 0;
}

char *strerror(int errnum)
{
    static char buffer[256];
    switch (errnum)
    {
    case E2BIG:
        return "Argument list too long";
    case EACCES:
        return "Permission denied";
    case EAGAIN:
        return "Resource temporarily unavailable";
    case EBADF:
        return "Bad file descriptor";
    case EBUSY:
        return "Device or resource busy";
    case ECHILD:
        return "No child processes";
    case EEXIST:
        return "File exists";
    case EFAULT:
        return "Bad address";
    case EINTR:
        return "Interrupted system call";
    case EINVAL:
        return "Invalid argument";
    case EIO:
        return "I/O error";
    case EISDIR:
        return "Is a directory";
    case ENFILE:
        return "File table overflow";
    case ENODEV:
        return "No such device";
    case ENOENT:
        return "No such file or directory";
    case ENOMEM:
        return "Out of memory";
    case ENOTDIR:
        return "Not a directory";
    case ENXIO:
        return "No such device or address";
    case EPERM:
        return "Operation not permitted";
    case ESRCH:
        return "No such process";
    case EXDEV:
        return "Cross-device link";
    default:
        snprintf(buffer, sizeof(buffer), "error %d", errnum);
        return buffer;
    }
}

void perror(const char *s)
{
    // TODO: Print the error message corresponding to errno
    fprintf(stderr, "error: %s\n", s);
}

char *tmpnam(char *s)
{
    (void)s;
    TODO("tmpnam");
}

FILE *tmpfile(void)
{
    char path[] = "/tmp/tmpfileXXXXXX";
    int fd = mkstemp(path);
    if (fd < 0)
    {
        return NULL;
    }

    FILE *stream = malloc(sizeof(FILE));
    stream->fd = fd;
    stream->buffer = malloc(__FILE_BUFFER_SIZE);
    stream->buf_size = __FILE_BUFFER_SIZE;
    stream->buf_pos = 0;
    stream->flags = 0;
    stream->mode = O_RDWR;
    stream->is_line_buffered = false;

    return stream;
}

int remove(const char *path)
{
    (void)path;
    TODO("remove");
}

int rename(const char *old, const char *new)
{
    (void)old;
    (void)new;
    TODO("rename");
}
