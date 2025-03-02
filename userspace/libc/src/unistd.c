#include "unistd.h"
#include "syscalls.h"

ssize_t read(int fildes, void *buf, size_t nbyte) {
    return __syscall$read(fildes, buf, nbyte);
}

ssize_t write(int fildes, const void *buf, size_t nbyte) {
    return __syscall$write(fildes, buf, nbyte);
}
