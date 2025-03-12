#include "sys/wait.h"
#include "syscalls.h"

int waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options)
{
    return __syscall$waitid(idtype, id, infop, options, 0);
}

pid_t waitpid(pid_t pid, int *stat_loc, int options)
{
    // TODO: Support stat_loc
    (void)stat_loc;

    siginfo_t infop;
    infop.si_pid = 0;

    return waitid(P_PID, pid, &infop, options | WEXITED);
}
