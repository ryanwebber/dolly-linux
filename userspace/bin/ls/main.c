#include <stdio.h>
#include <dirent+.h>
#include <stdlib.h>
#include <fnctl.h>
#include <unistd.h>

int opendir_nonalloc(const char *name, DIR *dir)
{
    // Open the directory using the open() system call
    dir->fd = open(name, O_RDONLY | O_DIRECTORY);
    return dir->fd;
}

int closedir(DIR *dir)
{
    // Close the directory using the close() system call
    return close(dir->fd);
}

int main(int argc, char *argv[])
{
    const char *path;

    // If no arguments are given, list the current directory
    if (argc == 1)
    {
        path = ".";
    }
    else
    {
        path = argv[1];
    }

    // Open the directory
    DIR dir;
    if (opendir_nonalloc(path, &dir) < 0)
    {
        fprintf(stderr, "ls: cannot access '%s': No such file or directory\n", path);
        return 1;
    }

    printf("Listing directory (%d): %s\n", dir.fd, path);

    // Read and print the directory entries
    int i = 0;
    struct dirent entry;
    while (i++ < 1024 && readdir_nonalloc(&dir, &entry) > 0)
    {
        printf("%s\n", entry.d_name);
    }

    // Close the directory
    closedir(&dir);

    return 0;
}
