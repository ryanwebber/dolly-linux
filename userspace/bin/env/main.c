#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    (void)argc;
    (void)argv;

    for (char *const *env = envp; *env != 0; env++)
    {
        printf("%s\n", *env);
    }

    return 0;
}
