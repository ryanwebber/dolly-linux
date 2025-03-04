
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 128

// void setup_tty() {
//     // Ensure the shell is connected to a TTY. If not, create a new session.
//     if (!isatty(STDIN_FILENO)) {
//         setsid(); // Create a new session.
//         int fd = open("/dev/tty", O_RDWR);
//         if (fd >= 0) {
//             dup2(fd, STDIN_FILENO);
//             dup2(fd, STDOUT_FILENO);
//             dup2(fd, STDERR_FILENO);
//             close(fd);
//         } else {
//             perror("Failed to set up TTY");
//             exit(EXIT_FAILURE);
//         }
//     }
// }

void execute_command(char *cmd, char *args[])
{
    pid_t pid = fork();
    if (pid < 0)
    {
        write(stderr, "fork failed\n", 12);
    }
    else if (pid == 0)
    {
        // Child process: execute command
        execve(cmd, args, NULL);
        write(stderr, "execve failed\n", 14);
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

int main()
{
    // setup_tty();

    char input[MAX_INPUT];
    char *args[MAX_ARGS];

    struct pollfd fds;
    fds.fd = stdin;
    fds.events = POLLIN;

    while (1)
    {
        // Print the prompt
        write(stdout, "sh> ", 4);

        // Wait for input to be available on stdin
        while (poll(&fds, 1, -1) <= 0 || !(fds.revents & POLLIN))
        {
            // Do nothing
        }

        size_t len = read(stdin, input, MAX_INPUT - 1);
        if (len <= 0)
        {
            write(stdout, "\n", 1);
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

        // Execute the command
        execute_command(args[0], args);
    }
}
