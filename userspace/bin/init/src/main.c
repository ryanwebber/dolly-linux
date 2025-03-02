#include <unistd.h>
#include <sys/wait.h>

int main()
{
    char buffer[256];

    while (1)
    {
        buffer[0] = '\0';
        write(1, "initsh> ", 9);
        ssize_t count = read(0, buffer, sizeof(buffer));
        if (count <= 0) {
            continue;
        }

        buffer[count - 1] = '\0';
        pid_t fork_result = fork();
        if (fork_result == 0) {
            execve(buffer, 0, 0);
            break;
        } else {
            siginfo_t info;
            waitid(P_ALL, 0, &info, WEXITED);
        }
    }

    return 0;
}
