#include <sys/select.h>
#include "syscalls.h"

// TODO: Support timeout parameter
int select(int nfds, fd_set *restrict readfds, fd_set *restrict writefds, fd_set *restrict errorfds, void *timeout)
{
    return __syscall$select(nfds, readfds, writefds, errorfds, timeout);
}
