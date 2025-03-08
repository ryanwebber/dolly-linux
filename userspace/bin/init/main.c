#include <fnctl.h>
#include <stdio+.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define __INIT_LOG_PREFIX "[init] "

void init_devfs()
{
    printfn(__INIT_LOG_PREFIX "Creating /dev");
    mkdir("/dev", 0755);

    printfn(__INIT_LOG_PREFIX "Mounting devtmpfs to /dev");
    mount("devtmpfs", "/dev", "devtmpfs", 0, 0);
}

void init_console()
{
    printf(__INIT_LOG_PREFIX "Opening console...\n");

    setsid();
    int fd = open("/dev/console", O_RDWR);
    if (fd >= 0)
    {
        if (dup2(fd, STDIN_FILENO) < 0)
        {
            fprintf(stderr, __INIT_LOG_PREFIX "Failed to dup2 stdin\n");
        }

        if (dup2(fd, STDOUT_FILENO) < 0)
        {
            fprintf(stderr, __INIT_LOG_PREFIX "Failed to dup2 stdout\n");
        }

        if (dup2(fd, STDERR_FILENO) < 0)
        {
            fprintf(stderr, __INIT_LOG_PREFIX "Failed to dup2 stderr\n");
        }

        if (fd > 2)
        {
            // Close the original fd if it's not one of the stdio ones
            close(fd);
        }
    }
    else
    {
        fprintf(stderr, __INIT_LOG_PREFIX "Failed to open /dev/console\n");
    }
}

int main()
{
    init_devfs();
    init_console();

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
            printf(__INIT_LOG_PREFIX "[init] Shell exited with status %d\n", info.si_status);
        }
    }

    return 0;
}
