#include <stdlib.h>
#include <stdlib+.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <which+.h>

char *which(const char *name)
{
    (void)name;
    char *path = getenv("PATH");
    if (path == NULL)
    {
        return NULL;
    }

    char pathbuf[1024];

    char *token = NULL;
    char *path_dup AUTOFREE = strdup(path);
    while ((token = strsep(&path_dup, ":")) != NULL)
    {
        // Construct the full path to the executable by concatenating the directory and the command
        snprintf(pathbuf, sizeof(pathbuf), "%s/%s", token, name);

        // Check if the file exists and is executable, and if so, return the path
        if (access(pathbuf, X_OK) == 0)
        {
            return strdup(pathbuf);
        }
    }

    return NULL;
}
