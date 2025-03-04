// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/wait.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// #define MAX_INPUT 1024
// #define MAX_ARGS 128

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

// void execute_command(char *cmd, char *args[]) {
//     pid_t pid = fork();
//     if (pid < 0) {
//         perror("fork failed");
//         exit(EXIT_FAILURE);
//     } else if (pid == 0) {
//         // Child process: execute command
//         execv(cmd, args);
//         perror("execv failed");
//         exit(EXIT_FAILURE);
//     } else {
//         // Parent process: wait for the child process to complete
//         int status;
//         waitpid(pid, &status, 0);
//     }
// }

// size_t strsplit_n(char *str, char sep, char** start)
// {
//     while (str[0] != '\0' && str[0] == sep)
//     {
//         str++;
//     }

//     *start = str;

//     size_t len = 0;
//     while (str[len] != '\0')
//     {
//         if (str[len] == sep)
//         {
//             return len;
//         }

//         len++;
//     }

//     return len;
// }

int main()
{
    char buf[256];

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

        int len = read(stdin, buf, 256);
        if (len > 0)
        {
            write(1, "echo> ", 6);
            write(1, buf, len);
        }
    }

    // setup_tty();

    // char input[MAX_INPUT];
    // char *args[MAX_ARGS];

    // while (1) {
    //     // Display a prompt
    //     write(1, "sh> ", 4);

    //     // Read user input
    //     ssize_t count = read(0, input, sizeof(input) - 1);
    //     if (count <= 0) {
    //         continue;
    //     }

    //     // Remove newline character from input
    //     input[count] = '\0';
    //     input[count - 1] = '\0';

    //     int arglen;
    //     int argi = 0;
    //     char* ptr = &input[0];
    //     while (arglen = strsplit_n(ptr, ' ', &ptr))
    //     {
    //         ptr[arglen] = '\0';
    //         write(1, ptr, arglen);
    //         write(1, "\n", 1);
    //         args[argi++] = ptr;
    //         ptr += arglen + 1;
    //     }

    //     write(1, "\nargs: ", 7);
    //     char x = '0' + argi;
    //     write(1, &x, 1);
    //     write(1, "\n", 1);

    //     // Null-terminate the argument list
    //     args[argi] = NULL;

    //     // If the user entered an empty command, skip
    //     if (args[0] == NULL) {
    //         continue;
    //     }

    //     // Execute the command
    //     execute_command(args[0], args);
    // }

    // return 0;
}
