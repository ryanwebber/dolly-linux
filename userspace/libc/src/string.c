#include "stdlib.h"
#include "string.h"
#include "unistd.h"

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
