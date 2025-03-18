#include <time.h>
#include <stdlib+.h>

time_t time(time_t *tloc)
{
    (void)tloc;

    // TODO: Implement time
    return 1742250559;
}

clock_t clock(void)
{
    TODO("clock");
}

struct tm *gmtime(const time_t *clock)
{
    (void)clock;
    TODO("gmtime");
}

time_t mktime(struct tm *timeptr)
{
    (void)timeptr;
    TODO("mktime");
}

double difftime(time_t time1, time_t time0)
{
    (void)time1;
    (void)time0;
    TODO("difftime");
}

struct tm *localtime(const time_t *clock)
{
    (void)clock;
    TODO("localtime");
}

size_t strftime(char *restrict s, size_t maxsize, const char *restrict format, const struct tm *restrict timeptr)
{
    (void)s;
    (void)maxsize;
    (void)format;
    (void)timeptr;
    TODO("strftime");
}
