#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[])
{
    (void)argc;
    (void)argv;
    (void)envp;

    for (char *const *env = environ; *env != 0; env++)
    {
        printf("%s\n", *env);
    }

    return 0;
}
