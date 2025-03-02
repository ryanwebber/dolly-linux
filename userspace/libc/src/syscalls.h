#ifndef _SYSCALLS_H
#define _SYSCALLS_H

ssize_t __syscall$read(int fildes, void *buf, size_t nbyte);
ssize_t __syscall$write(int fildes, const void *buf, size_t nbyte);

#endif
