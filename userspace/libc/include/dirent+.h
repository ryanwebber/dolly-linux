#ifndef _DIRENT_EXT_H
#define _DIRENT_EXT_H

#include <dirent.h>

int readdir_nonalloc(DIR *dir, struct dirent *entry);

#endif