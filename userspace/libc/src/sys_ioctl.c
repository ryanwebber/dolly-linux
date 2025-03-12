#include "stdarg.h"
#include "sys/ioctl.h"
#include "syscalls.h"

int ioctl(int fildes, unsigned long request, ...)
{
    // Just call __syscall$ioctl with the same arguments
    va_list args;
    va_start(args, request);
    int ret = __syscall$ioctl(fildes, request, va_arg(args, void *));
    va_end(args);

    return ret;
}
