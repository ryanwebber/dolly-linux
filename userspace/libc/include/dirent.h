// https://pubs.opengroup.org/onlinepubs/007904875/basedefs/dirent.h.html

#ifndef DIRENT_H
#define DIRENT_H

#include <sys/types.h>

struct dirent
{
    ino_t d_ino;
    char *d_name;
};

typedef struct
{
    // File descriptor for the directory
    int fd;

    // Buffer to hold directory entries
    char buffer[4096];

    // Current position within the buffer
    size_t buf_pos;

    // Total size of valid data in buffer
    size_t buf_size;
} DIR;

DIR *opendir(const char *filename);
int closedir(DIR *dirp);

struct dirent *readdir(DIR *dirp);

#endif
