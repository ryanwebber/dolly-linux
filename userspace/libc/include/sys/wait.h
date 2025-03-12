// https://pubs.opengroup.org/onlinepubs/7908799/xsh/syswait.h.html

#ifndef _SYS_WAIT_H
#define _SYS_WAIT_H

#include <signal.h>

#define WNOHANG 0x00000001
#define WUNTRACED 0x00000002
#define WSTOPPED WUNTRACED
#define WEXITED 0x00000004
#define WCONTINUED 0x00000008
#define WNOWAIT 0x01000000

typedef enum
{
    P_ALL = 0,
    P_PID,
    P_PGID
} idtype_t;

int waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options);
pid_t waitpid(pid_t pid, int *stat_loc, int options);

#endif
