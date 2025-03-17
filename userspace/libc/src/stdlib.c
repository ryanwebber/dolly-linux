#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "todo.h"

#define __MALLOC_HEAP_SIZE (4 * 1024 * 1024)

static char heap[__MALLOC_HEAP_SIZE];
static size_t heap_offset = 0;

void exit(int status)
{
    _exit(status);
}

void abort(void)
{
    exit(1);
}

// Trivial malloc implementation that just leaks memory
// just to get the system stood up
void *malloc(size_t size)
{
    if (heap_offset + size >= __MALLOC_HEAP_SIZE)
    {
        return NULL;
    }

    void *ptr = &heap[heap_offset];
    heap_offset += size;
    return ptr;
}

void free(void *ptr)
{
    // Noop for now, we just leak memory
    (void)ptr;
}

char *getenv(const char *name)
{
    for (char **env = &environ[0]; *env; env++)
    {
        char *current = *env;
        while (*current != '=')
        {
            current++;
        }

        if (strncmp(*env, name, current - *env) == 0)
        {
            return current + 1;
        }
    }

    return NULL;
}

int posix_openpt(int oflag)
{
    return open("/dev/ptmx", oflag);
}

int grantpt(int fildes)
{
    // Get the corresponding slave pseudoterminal path
    char *slave_path = ptsname(fildes);
    if (!slave_path)
    {
        return -1;
    }

    // Change ownership to the current user and group (tty group)
    uid_t uid = getuid();
    gid_t gid = getgid();

    if (chown(slave_path, uid, gid) == -1)
    {
        return -2;
    }

    // Change permissions to 0620 (rw--w----)
    if (chmod(slave_path, S_IRUSR | S_IWUSR | S_IWGRP) == -1)
    {
        return -3;
    }

    return 0;
}

int unlockpt(int fildes)
{
    int unlock_flag = 0;
    if (ioctl(fildes, 0x40045431 /* TIOCSPTLCK */, &unlock_flag) == -1)
    {
        return -1;
    }

    return 0;
}

char *ptsname(int fildes)
{
    static char buffer[256];

    unsigned int pts_number;
    if (ioctl(fildes, 0x80045430 /* TIOCGPTN */, &pts_number) == -1)
    {
        return NULL;
    }

    snprintf(buffer, sizeof(buffer), "/dev/pts/%d", (int)pts_number);
    return buffer;
}

double strtod(const char *restrict nptr, char **restrict endptr)
{
    (void)nptr;
    (void)endptr;
    TODO("strtod");
}

int abs(int i)
{
    return i < 0 ? -i : i;
}
