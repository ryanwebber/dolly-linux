#include "dirent+.h"
#include "fnctl.h"
#include "linux_dirent.h"
#include "syscalls.h"
#include "unistd.h"

int opendir_nonalloc(const char *name, DIR *dir)
{
    int fd = open(name, O_RDONLY | O_DIRECTORY);
    if (fd < 0)
    {
        return -1;
    }

    if (!dir)
    {
        close(fd);
        return -2;
    }

    dir->fd = fd;
    dir->buf_pos = 0;
    dir->buf_size = 0;

    return 0;
}

int readdir_nonalloc(DIR *dirp, struct dirent *entry)
{
    if (dirp->buf_pos >= dirp->buf_size)
    {
        // Buffer is empty or exhausted; refill it using getdents
        int nread = __syscall$getdents(dirp->fd, (struct linux_dirent *)dirp->buffer, sizeof(dirp->buffer));
        if (nread <= 0)
        {
            // No more entries or error
            return nread;
        }

        dirp->buf_pos = 0;
        dirp->buf_size = nread;
    }

    // Extract the next directory entry from the buffer
    struct linux_dirent *d = (struct linux_dirent *)(dirp->buffer + dirp->buf_pos);
    dirp->buf_pos += d->d_reclen; // Advance position by the size of the entry

    // Convert linux_dirent64 to dirent (user-facing structure)
    entry->d_ino = d->d_ino;
    entry->d_name = d->d_name;

    return 1;
}

void closedir_nonalloc(DIR *dir)
{
    close(dir->fd);
}
