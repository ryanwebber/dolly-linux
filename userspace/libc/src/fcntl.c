#include <fcntl.h>
#include "syscalls.h"

int open(const char *path, int oflag, ...)
{
    // TODO: Support mode_t mode for O_CREAT
    return __syscall$open(path, oflag, 0);
}
