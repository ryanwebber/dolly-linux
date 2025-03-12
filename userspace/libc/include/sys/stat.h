// https://pubs.opengroup.org/onlinepubs/009696699/basedefs/sys/stat.h.html

#ifndef _STAT_H
#define _STAT_H

#include <sys/types.h>

#define S_IRUSR 0400
#define S_IWUSR 0200
#define S_IWGRP 0020

int mkdir(const char *path, mode_t mode);

int chmod(const char *path, mode_t mode);

#endif
