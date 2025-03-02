// https://pubs.opengroup.org/onlinepubs/7908799/xsh/syswait.h.html

#ifndef _SYS_WAIT_H
#define _SYS_WAIT_H

#include <signal.h>

#define WEXITED 4

typedef enum {
    P_ALL = 1,
    P_PID,
    P_PGID
} idtype_t;

int waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options);

#endif
