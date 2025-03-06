#include "sys/mount.h"
#include "syscalls.h"

int mount(const char *source, const char *target, const char *filesystemtype, unsigned long mountflags, const void *data)
{
    return __syscall$mount(source, target, filesystemtype, mountflags, data);
}
