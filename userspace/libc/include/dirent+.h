#ifndef _DIRENT_EXT_H
#define _DIRENT_EXT_H

#include <dirent.h>

int readdir_nonalloc(DIR *dir, struct dirent *entry);
int opendir_nonalloc(const char *name, DIR *dir);
void closedir_nonalloc(DIR *dir);

#endif
