#ifndef _SYSCALLS_H
#define _SYSCALLS_H

#include "poll.h"
#include "signal.h"
#include "sys/select.h"
#include "sys/types.h"
#include "sys/wait.h"

struct linux_dirent;

__attribute__((noreturn)) void
__syscall$exit(int status);

int __syscall$execve(const char *path, char *const argv[], char *const envp[]);
pid_t __syscall$fork(void);
int __syscall$waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options, void *);

ssize_t __syscall$read(int fildes, void *buf, size_t nbyte);
ssize_t __syscall$write(int fildes, const void *buf, size_t nbyte);

int __syscall$open(const char *path, int oflag, mode_t mode);
int __syscall$close(int fildes);
int __syscall$dup2(int fildes, int fildes2);

pid_t __syscall$setsid(void);

// TODO: Support timeout parameter
int __syscall$select(int nfds, fd_set *restrict readfds, fd_set *restrict writefds, fd_set *restrict errorfds, void *timeout);

int __syscall$poll(struct pollfd fds[], nfds_t nfds, int timeout);

int __syscall$mkdir(const char *path, mode_t mode);
long __syscall$getdents(unsigned int fd, struct linux_dirent *dirp, unsigned int count);

int __syscall$mount(const char *source, const char *target, const char *filesystemtype, unsigned long mountflags, const void *data);

#endif
