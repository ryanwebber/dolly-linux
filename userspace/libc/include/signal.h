// https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/signal.h.html

#ifndef _SIGNAL_H
#define _SIGNAL_H

#include <sys/types.h>

#define SIG_ERR ((sig_t)(-1))
#define SIG_DFL ((sig_t)(0))
#define SIG_IGN ((sig_t)(1))

#define SIGINT 2   // Interactive attention signal.
#define SIGILL 4   // Illegal instruction.
#define SIGABRT 6  // Abnormal termination.
#define SIGFPE 8   // Erroneous arithmetic operation.
#define SIGSEGV 11 // Invalid access to storage.
#define SIGTERM 15 // Termination request.

#define SIGHUP 1   // Hangup.
#define SIGQUIT 3  // Quit.
#define SIGTRAP 5  // Trace/breakpoint trap.
#define SIGKILL 9  // Killed.
#define SIGPIPE 13 // Broken pipe.
#define SIGALRM 14 // Alarm clock.

union sigval
{
    int sival_int;
    void *sival_ptr;
};

typedef struct siginfo
{
    int si_signo;
    int si_code;
    int si_errno;
    pid_t si_pid;
    uid_t si_uid;
    void *si_addr;
    int si_status;
    int si_band;
    union sigval si_value;
} siginfo_t;

typedef void (*sig_t)(int);

sig_t signal(int sig, sig_t func);

#endif
