// https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/unistd.h.html

#ifndef _UNISTD_H
#define _UNISTD_H

#include <sys/types.h>

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

void _exit(int status);

int execve(const char *path, char *const argv[], char *const envp[]);
pid_t fork(void);

ssize_t read(int fildes, void *buf, size_t nbyte);
ssize_t write(int fildes, const void *buf, size_t nbyte);

int close(int fildes);
int dup2(int fildes, int fildes2);

pid_t setsid(void);

#endif
