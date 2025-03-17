#include <signal.h>

sig_t signal(int sig, sig_t func)
{
    (void)sig;
    (void)func;
    return SIG_ERR;
}
