// https://man7.org/linux/man-pages/man2/ioctl.2.html

#ifndef _SYS_IOCTL_H
#define _SYS_IOCTL_H

int ioctl(int fildes, unsigned long request, ...);

#endif
