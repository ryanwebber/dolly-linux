// https://pubs.opengroup.org/onlinepubs/007904875/basedefs/dirent.h.html

#ifndef DIRENT_H
#define DIRENT_H

#include <sys/types.h>

struct dirent
{
    ino_t d_ino;
    off_t d_off;
    unsigned short d_reclen;
    char d_name[256];
    char pad;
    char d_type;
};

typedef struct
{
    int fd;
    struct dirent current;
} DIR;

DIR *opendir(const char *filename);
int closedir(DIR *dirp);

struct dirent *readdir(DIR *dirp);

#endif
