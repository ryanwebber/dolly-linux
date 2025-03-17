// https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/unistd.h.html

#ifndef _UNISTD_H
#define _UNISTD_H

#include <sys/types.h>

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#define R_OK 4 /* Test for read permission.  */
#define W_OK 2 /* Test for write permission.  */
#define X_OK 1 /* Test for execute permission.  */
#define F_OK 0 /* Test for existence.  */

// Defined by crt0
extern char **environ;

__attribute__((noreturn)) void _exit(int status);

int execve(const char *path, char *const argv[], char *const envp[]);
int execvp(const char *file, char *const argv[]);

pid_t fork(void);

ssize_t read(int fildes, void *buf, size_t nbyte);
ssize_t write(int fildes, const void *buf, size_t nbyte);
off_t lseek(int fildes, off_t offset, int whence);
int close(int fildes);
int dup2(int fildes, int fildes2);

int mkstemp(char *template);

int access(const char *path, int mode);
int chown(const char *path, uid_t owner, gid_t group);

gid_t getgid(void);
uid_t getuid(void);
pid_t setsid(void);

#endif
