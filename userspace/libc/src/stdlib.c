#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib+.h>
#include <unistd.h>

#define __MALLOC_HEAP_SIZE (4 * 1024 * 1024)

void exit(int status)
{
    _exit(status);
}

void abort(void)
{
    fprintf(stderr, "Aborted\n");
    exit(1);
}

void *malloc(size_t size)
{
    // Trivial malloc implementation that just leaks memory
    // just to get the system stood up

    static char heap[__MALLOC_HEAP_SIZE];
    static size_t heap_offset = 0;

    if (heap_offset + size >= __MALLOC_HEAP_SIZE)
    {
        return NULL;
    }

    // Write the size of the allocation at the beginning of the block
    size_t *size_ptr = (size_t *)&heap[heap_offset];
    *size_ptr = size;

    heap_offset += sizeof(size_t);

    void *ptr = &heap[heap_offset];
    heap_offset += size;
    return ptr;
}

void *realloc(void *ptr, size_t size)
{
    // Trivial realloc implementation that just leaks memory
    // just to get the system stood up
    if (ptr == NULL)
    {
        return malloc(size);
    }

    size_t *size_ptr = (size_t *)((char *)ptr - sizeof(size_t));
    size_t old_size = *size_ptr;

    void *new_ptr = malloc(size);
    if (new_ptr == NULL)
    {
        return NULL;
    }

    if (old_size < size)
    {
        memcpy(new_ptr, ptr, old_size);
    }
    else
    {
        memcpy(new_ptr, ptr, size);
    }

    return new_ptr;
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

int system(const char *command)
{
    (void)command;
    TODO("system");
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
