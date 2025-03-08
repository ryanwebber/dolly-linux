
#include <poll.h>
#include <fnctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 128

// TODO: Implement isatty in libc
bool isatty(int fd)
{
    (void)fd;
    return false;
}

void setup_tty()
{
    // Ensure the shell is connected to a TTY. If not, create a new session.
    if (!isatty(STDIN_FILENO))
    {
        setsid(); // Create a new session.
        int fd = open("/dev/tty", O_RDWR);
        if (fd >= 0)
        {
            dup2(fd, STDIN_FILENO);
            dup2(fd, STDOUT_FILENO);
            dup2(fd, STDERR_FILENO);
            close(fd);
        }
        else
        {
            write(STDERR_FILENO, "Failed to open /dev/tty\n", 24);
            _exit(1);
        }
    }
}

void execute_command(char *cmd, char *args[], char *envp[])
{
    pid_t pid = fork();
    if (pid < 0)
    {
        write(STDERR_FILENO, "fork failed\n", 12);
    }
    else if (pid == 0)
    {
        // Child process: execute command
        execve(cmd, args, envp);
        write(STDERR_FILENO, "execve failed\n", 14);
        _exit(1);
    }
    else
    {
        // Parent process: wait for the child process to complete
        siginfo_t info;
        waitid(P_ALL, 0, &info, WEXITED);
    }
}

size_t tokenize_in_place(char *string, char **tokens)
{
    size_t count = 0;
    char *current = string;

    while (*current != '\0')
    {
        // Skip leading whitespace
        while (*current == ' ')
        {
            current++;
        }

        if (*current == '\0')
        {
            break;
        }

        // Start of a new token
        tokens[count++] = current;

        // Move to the end of the token
        while (*current != '\0' && *current != ' ')
        {
            current++;
        }

        // Null-terminate the token if we are not at the end of the string
        if (*current != '\0')
        {
            *current = '\0';
            current++;
        }
    }

    return count;
}

int main(int argc, char *argv[], char *envp[])
{
    (void)argc;
    (void)argv;

    char input[MAX_INPUT];
    char *args[MAX_ARGS];

    struct pollfd fds;
    fds.fd = STDIN_FILENO;
    fds.events = POLLIN;

    while (1)
    {
        // Print the prompt
        write(STDOUT_FILENO, "sh> ", 4);

        // Wait for input to be available on stdin
        while (poll(&fds, 1, -1) <= 0 || !(fds.revents & POLLIN))
        {
            // Do nothing
        }

        size_t len = read(STDIN_FILENO, input, MAX_INPUT - 1);
        if (len <= 0)
        {
            write(STDOUT_FILENO, "\n", 1);
            continue;
        }

        // Remove newline character from input
        input[len - 1] = '\0';

        size_t arg_count = tokenize_in_place(input, args);

        // Null-terminate the argument list
        args[arg_count] = NULL;

        // If the user entered an empty command, skip
        if (arg_count == 0)
        {
            continue;
        }

        if (args[0][0] == '.')
        {
            printf("Setup TTY...\n");
            setup_tty();
            continue;
        }

        // Execute the command
        execute_command(args[0], args, envp);
    }
}
