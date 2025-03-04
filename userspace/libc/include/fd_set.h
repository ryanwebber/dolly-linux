#ifndef _FD_SET_H
#define _FD_SET_H

#define FD_SETSIZE 1024

#define FD_ZERO(set)    \
    do                  \
    {                   \
        __fd_zero(set); \
    } while (0)

#define FD_CLR(fd, set) ((set)->fds_bits[(fd / 8)] &= ~(1 << (fd) % 8))
#define FD_SET(fd, set) ((set)->fds_bits[(fd / 8)] |= (1 << (fd) % 8))
#define FD_ISSET(fd, set) ((set)->fds_bits[(fd / 8)] & (1 << (fd) % 8))

struct fd_set
{
    unsigned char fds_bits[FD_SETSIZE / 8];
};

typedef struct fd_set fd_set;

static void __fd_zero(fd_set *set)
{
    for (int i = 0; i < FD_SETSIZE / 8; i++)
    {
        set->fds_bits[i] = 0;
    }
}

#endif
