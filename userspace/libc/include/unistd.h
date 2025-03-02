// https://pubs.opengroup.org/onlinepubs/7908799/xsh/unistd.h.html

#ifndef _UNISTD_H
#define _UNISTD_H

#include <sys/types.h>

void _exit(int status);

int execve(const char *path, char *const argv[], char *const envp[]);
pid_t fork(void);

ssize_t read(int fildes, void *buf, size_t nbyte);
ssize_t write(int fildes, const void *buf, size_t nbyte);

#endif
