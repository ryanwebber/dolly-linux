// https://pubs.opengroup.org/onlinepubs/007904875/basedefs/fcntl.h.html

#ifndef _FNCTL_H
#define _FNCTL_H

#define O_RDONLY 0x00000000  /* open for reading only */
#define O_WRONLY 0x00000001  /* open for writing only */
#define O_RDWR 0x00000002    /* open for reading and writing */
#define O_ACCMODE 0x00000003 /* mask for above modes */
#define O_DIRECTORY 0x10000  /* must be a directory */

int open(const char *path, int oflag, ...);

#endif
