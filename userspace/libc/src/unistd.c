#include "unistd.h"
#include "syscalls.h"

void _exit(int status)
{
    __syscall$exit(status);
}

int execve(const char *path, char *const argv[], char *const envp[])
{
    return __syscall$execve(path, argv, envp);
}

pid_t fork(void)
{
    return __syscall$fork();
}

ssize_t read(int fildes, void *buf, size_t nbyte)
{
    return __syscall$read(fildes, buf, nbyte);
}

ssize_t write(int fildes, const void *buf, size_t nbyte)
{
    return __syscall$write(fildes, buf, nbyte);
}
