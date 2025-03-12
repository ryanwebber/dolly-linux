#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <sys/wait.h>
#include <termios.h>
#include <unistd.h>

// Terminal dimensions
#define TERM_ROWS 24
#define TERM_COLS 80

// Screen buffer for terminal emulator
char screen_buffer[TERM_ROWS][TERM_COLS];

// Function to clear the screen buffer
void clear_screen_buffer()
{
    for (int i = 0; i < TERM_ROWS; i++)
    {
        memset(screen_buffer[i], ' ', TERM_COLS);
    }
}

// Function to render the screen buffer
void render_screen(int master_fd)
{
    // Clear the terminal
    write(master_fd, "\033[2J", 4); // ANSI escape to clear screen
    write(master_fd, "\033[H", 3);  // Move cursor to top-left

    // Render the buffer
    for (int i = 0; i < TERM_ROWS; i++)
    {
        write(master_fd, screen_buffer[i], TERM_COLS);
        write(master_fd, "\n", 1);
    }
}

// Function to fork a shell as a child process and use PTY for communication
pid_t fork_shell(int *master_fd)
{
    int slave_fd;
    pid_t pid;

    // Open pseudo-terminal
    *master_fd = posix_openpt(O_RDWR | O_NOCTTY);
    if (*master_fd < 0)
    {
        perror("posix_openpt");
        exit(1);
    }

    // Grant PTY slave
    if (grantpt(*master_fd) < 0)
    {
        perror("grantpt");
        exit(1);
    }

    // Unlock PTY slave
    if (unlockpt(*master_fd) < 0)
    {
        perror("unlockpt");
        exit(1);
    }

    // Fork the process
    pid = fork();
    if (pid == 0)
    {
        // Open the slave side of the PTY
        const char *slave_name = ptsname(*master_fd);
        if (slave_name == NULL)
        {
            perror("ptsname");
            exit(1);
        }
        slave_fd = open(ptsname(*master_fd), O_RDWR);
        if (slave_fd < 0)
        {
            perror("open slave pty");
            exit(1);
        }

        // Redirect input/output to the slave PTY
        dup2(slave_fd, STDIN_FILENO);
        dup2(slave_fd, STDOUT_FILENO);
        dup2(slave_fd, STDERR_FILENO);
        close(slave_fd);
        close(*master_fd); // The child doesn't need the master PTY

        // Start a shell (e.g., bash)
        char *args[] = {"/bin/bash", NULL};
        execvp("sh", args);
        perror("execvp failed");
        exit(1);
    }

    return pid;
}

// Function to handle terminal input and output
void handle_io(int master_fd)
{
    fd_set fds;
    char buffer[256];
    int n;

    // Main event loop
    while (1)
    {
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        FD_SET(master_fd, &fds);

        // Wait for input from either the user or the shell
        if (select(master_fd + 1, &fds, NULL, NULL, NULL) < 0)
        {
            perror("select");
            break;
        }

        // User input
        if (FD_ISSET(STDIN_FILENO, &fds))
        {
            n = read(STDIN_FILENO, buffer, sizeof(buffer));
            if (n > 0)
            {
                // Send user input to the shell
                write(master_fd, buffer, n);
            }
        }

        // Shell output
        if (FD_ISSET(master_fd, &fds))
        {
            n = read(master_fd, buffer, sizeof(buffer));
            if (n > 0)
            {
                // For now, just write the shell output to the terminal
                // (We can later interpret and update the internal buffer)
                write(STDOUT_FILENO, buffer, n);
            }
        }
    }
}

int main()
{
    int master_fd;

    // Fork and execute the shell
    pid_t shell_pid = fork_shell(&master_fd);

    // Clear the screen buffer
    clear_screen_buffer();

    // Clear the screen
    write(STDOUT_FILENO, "\033[2J", 4);
    write(STDOUT_FILENO, "\033[H", 3);

    // Main input/output handling loop
    handle_io(master_fd);

    // Wait for the shell to exit
    waitpid(shell_pid, NULL, 0);
    close(master_fd);

    return 0;
}
