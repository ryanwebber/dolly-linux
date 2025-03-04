#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        write(stdout, argv[i], strlen(argv[i]));
        if (i < argc - 1)
        {
            write(stdout, " ", 1);
        }
    }

    write(stdout, "\n", 1);

    return 0;
}
