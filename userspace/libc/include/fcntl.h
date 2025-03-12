// https://pubs.opengroup.org/onlinepubs/007904875/basedefs/fcntl.h.html

#ifndef _FCNTL_H
#define _FCNTL_H

#define O_RDONLY 0
#define O_WRONLY 1
#define O_RDWR 2
#define O_CREAT 0x40
#define O_EXCL 0x80
#define O_NOCTTY 0x100
#define O_TRUNC 0x200
#define O_APPEND 0x400
#define O_NONBLOCK 0x800
#define O_DIRECTORY 0x10000

int open(const char *path, int oflag, ...);

#endif
