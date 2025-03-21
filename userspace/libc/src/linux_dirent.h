#ifndef _LINUX_DIRENT_H
#define _LINUX_DIRENT_H

// https://man7.org/linux/man-pages/man2/getdents.2.html
struct linux_dirent
{
    unsigned long d_ino;     /* Inode number */
    unsigned long d_off;     /* Not an offset; see below */
    unsigned short d_reclen; /* Length of this linux_dirent */
    char d_name[];           /* Filename (null-terminated) */
                             /* length is actually (d_reclen - 2 -
                                offsetof(struct linux_dirent, d_name)) */
    /*
    char           pad;       // Zero padding byte
    char           d_type;    // File type (only since Linux
                              // 2.6.4); offset is (d_reclen - 1)
    */
};

#endif
