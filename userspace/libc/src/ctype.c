#include <ctype.h>

int isalnum(int c)
{
    return isalpha(c) || isdigit(c);
}

int isalpha(int c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int iscntrl(int c)
{
    return (c >= 0 && c <= 31) || c == 127;
}

int isdigit(int c)
{
    return c >= '0' && c <= '9';
}

int isgraph(int c)
{
    return c >= 33 && c <= 126;
}

int islower(int c)
{
    return c >= 'a' && c <= 'z';
}

int isnumber(int c)
{
    return isdigit(c) || c == '+' || c == '-';
}

int isprint(int c)
{
    return c >= 32 && c <= 126;
}

int ispunct(int c)
{
    return isgraph(c) && !isalnum(c);
}

int isspace(int c)
{
    return c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v';
}

int isupper(int c)
{
    return c >= 'A' && c <= 'Z';
}

int isxdigit(int c)
{
    return isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

int tolower(int c)
{
    return isupper(c) ? c + 32 : c;
}

int toupper(int c)
{
    return islower(c) ? c - 32 : c;
}
