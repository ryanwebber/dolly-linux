// https://pubs.opengroup.org/onlinepubs/007904975/basedefs/sys/select.h.html

#ifndef _SYS_SELECT_H
#define _SYS_SELECT_H

#include <fd_set.h>

// TODO: Support timeout parameter
int select(int nfds, fd_set *restrict readfds, fd_set *restrict writefds, fd_set *restrict errorfds, void *timeout);

#endif
