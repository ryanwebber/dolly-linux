// https://pubs.opengroup.org/onlinepubs/009695199/basedefs/time.h.html

#ifndef _TIME_H
#define _TIME_H

#include <sys/types.h>

/* Required to be 1 million on all XSI-conformant systems, so good enough for us */
#define CLOCKS_PER_SEC ((clock_t)1000000)

struct tm
{
    int tm_sec;   /* Seconds (0-60) */
    int tm_min;   /* Minutes (0-59) */
    int tm_hour;  /* Hours (0-23) */
    int tm_mday;  /* Day of the month (1-31) */
    int tm_mon;   /* Month (0-11) */
    int tm_year;  /* Year - 1900 */
    int tm_wday;  /* Day of the week (0-6, Sunday = 0) */
    int tm_yday;  /* Day in the year (0-365, 1 Jan = 0) */
    int tm_isdst; /* Daylight saving time */
};

time_t time(time_t *tloc);
clock_t clock(void);

struct tm *gmtime(const time_t *clock);
time_t mktime(struct tm *timeptr);
double difftime(time_t time1, time_t time0);
struct tm *localtime(const time_t *clock);

size_t strftime(char *restrict s, size_t maxsize, const char *restrict format, const struct tm *restrict timeptr);

#endif
