#include "dirent+.h"
#include "syscalls.h"

int readdir_nonalloc(DIR *dir, struct dirent *entry)
{
    return __syscall$getdents(dir->fd, (struct linux_dirent *)entry, sizeof(struct dirent));
}
