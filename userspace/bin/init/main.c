#include <unistd.h>
#include <sys/wait.h>

int main()
{
    while (1)
    {
        pid_t fork_result = fork();
        if (fork_result == 0)
        {
            execve("/usr/bin/sh", 0, 0);
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
