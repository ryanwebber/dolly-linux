#include "stdlib.h"
#include "string.h"
#include "unistd.h"

char *strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == c)
        {
            return (char *)s;
        }
        s++;
    }

    return c == '\0' ? (char *)s : NULL;
}

char *strdup(const char *s1)
{
    size_t len = strlen(s1);
    char *dup = (char *)malloc(len + 1);
    if (dup == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < len; i++)
    {
        dup[i] = s1[i];
    }

    dup[len] = '\0';
    return dup;
}

size_t strlen(const char *s)
{
    size_t len = 0;
    while (s[len] != '\0')
    {
        (void)s;
        len++;
    }
    return len;
}

int strncmp(const char *s1, const char *s2, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
        {
            return s1[i] - s2[i];
        }
        if (s1[i] == '\0')
        {
            return 0;
        }
    }

    return 0;
}

char *strsep(char **stringp, const char *delim)
{
    char *string = *stringp;
    if (string == NULL)
    {
        return NULL;
    }

    char *tok_start = string;
    char *tok_end = strchr(string, *delim);

    if (tok_end != NULL)
    {
        *tok_end = '\0';
        *stringp = tok_end + 1;
    }
    else
    {
        *stringp = NULL;
    }

    return tok_start;
}

void *memcpy(void *restrict dst, const void *restrict src, size_t n)
{
    char *d = dst;
    const char *s = src;
    for (size_t i = 0; i < n; i++)
    {
        d[i] = s[i];
    }
    return dst;
}

void *memmove(void *dst, const void *src, size_t n)
{
    char *d = dst;
    const char *s = src;
    if (d < s)
    {
        for (size_t i = 0; i < n; i++)
        {
            d[i] = s[i];
        }
    }
    else
    {
        for (size_t i = n; i > 0; i--)
        {
            d[i - 1] = s[i - 1];
        }
    }
    return dst;
}

void *memset(void *b, int c, size_t len)
{
    char *dst = b;
    for (size_t i = 0; i < len; i++)
    {
        dst[i] = c;
    }
    return b;
}

void *memchr(const void *s, int c, size_t n)
{
    const unsigned char *src = s;
    for (size_t i = 0; i < n; i++)
    {
        if (src[i] == c)
        {
            return (void *)&src[i];
        }
    }
    return NULL;
}

int memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *src1 = s1;
    const unsigned char *src2 = s2;
    for (size_t i = 0; i < n; i++)
    {
        if (src1[i] != src2[i])
        {
            return src1[i] - src2[i];
        }
    }
    return 0;
}
