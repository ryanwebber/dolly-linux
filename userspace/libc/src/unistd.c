#include <stdlib.h>
#include <todo+.h>
#include <unistd.h>
#include <which+.h>
#include "syscalls.h"

void _exit(int status)
{
    __syscall$exit(status);
}

int execve(const char *path, char *const argv[], char *const envp[])
{
    return __syscall$execve(path, argv, envp);
}

int execvp(const char *file, char *const argv[])
{
    // TODO: Look up the PATH environment variable and try to find the executable
    char *full_path = which(file);
    if (full_path == NULL)
    {
        return execve(file, argv, environ);
    }
    else
    {
        int result = execve(full_path, argv, environ);
        free(full_path);
        return result;
    }
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

off_t lseek(int fildes, off_t offset, int whence)
{
    return __syscall$lseek(fildes, offset, whence);
}

int close(int fildes)
{
    return __syscall$close(fildes);
}

int dup2(int fildes, int fildes2)
{
    return __syscall$dup2(fildes, fildes2);
}

int mkstemp(char *template)
{
    (void)template;
    TODO("mkstemp");
}

int access(const char *path, int mode)
{
    return __syscall$access(path, mode);
}

int chown(const char *path, uid_t owner, gid_t group)
{
    return __syscall$chown(path, owner, group);
}

gid_t getgid(void)
{
    return __syscall$getgid();
}

uid_t getuid(void)
{
    return __syscall$getuid();
}

pid_t setsid(void)
{
    return __syscall$setsid();
}
