#include <poll.h>
#include "syscalls.h"

int poll(struct pollfd fds[], nfds_t nfds, int timeout)
{
    return __syscall$poll(fds, nfds, timeout);
}
