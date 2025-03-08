#include <stdio+.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

void init_devfs()
{
    printfn("Creating /dev");
    mkdir("/dev", 0755);

    printfn("Mounting devtmpfs to /dev");
    mount("devtmpfs", "/dev", "devtmpfs", 0, 0);
}

int main()
{
    init_devfs();

    while (1)
    {
        pid_t fork_result = fork();
        if (fork_result == 0)
        {
            char *argv[] = {
                "/usr/bin/sh",
                0,
            };

            char *envp[] = {
                "PATH=/usr/bin",
                "HOME=/",
                "PWD=/",
                0,
            };

            execve(argv[0], &argv[0], &envp[0]);
            break;
        }
        else
        {
            siginfo_t info;
            waitid(P_ALL, 0, &info, WEXITED);
            write(1, "Shell exited...\n", 16);
        }
    }

    return 0;
}
