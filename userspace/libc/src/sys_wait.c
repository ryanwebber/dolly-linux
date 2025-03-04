#include "sys/wait.h"
#include "syscalls.h"

int waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options)
{
    return __syscall$waitid(idtype, id, infop, options, 0);
}
