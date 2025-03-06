#include "sys/stat.h"
#include "syscalls.h"

int mkdir(const char *path, mode_t mode)
{
    return __syscall$mkdir(path, mode);
}
