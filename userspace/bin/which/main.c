#include "stdio.h"
#include "which+.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: %s <command>\n", argv[0]);
        return 1;
    }

    char *executable = which(argv[1]);
    if (executable == NULL)
    {
        fprintf(stderr, "%s: command not found\n", argv[1]);
        return 1;
    }

    printf("%s\n", executable);
    free(executable);

    return 0;
}
