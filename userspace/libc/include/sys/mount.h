#ifndef SYS_MOUNT_H
#define SYS_MOUNT_H

#include <sys/types.h>

int mount(const char *source, const char *target, const char *filesystemtype, unsigned long mountflags, const void *data);

#endif
