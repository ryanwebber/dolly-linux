#include <setjmp.h>
#include <stdlib+.h>

int setjmp(jmp_buf env)
{
    asm volatile(
        "movq %%rbx, %0\n"      // Save rbx
        "movq %%r12, %1\n"      // Save r12
        "movq %%r13, %2\n"      // Save r13
        "movq %%r14, %3\n"      // Save r14
        "movq %%r15, %4\n"      // Save r15
        "movq %%rbp, %5\n"      // Save rbp
        "movq %%rsp, %6\n"      // Save rsp
        "movq (%%rsp), %%rax\n" // Get return address from stack
        "movq %%rax, %7\n"      // Save rip (return address)
        : "=m"(env[0].rbx), "=m"(env[0].r12), "=m"(env[0].r13), "=m"(env[0].r14),
          "=m"(env[0].r15), "=m"(env[0].rbp), "=m"(env[0].rsp), "=m"(env[0].rip)
        : /* no inputs */
        : "memory", "rax");

    // Support for the signal mask
    env[0].did_save_signal_mask = 0;

    return 0;
}

__attribute__((noreturn)) void longjmp(jmp_buf env, int val)
{
    if (val == 0)
    {
        // Ensure return value is non-zero
        val = 1;
    }

    if (env[0].did_save_signal_mask)
    {
        // TODO: Restore signal mask
    }

    asm volatile(
        "movq %0, %%rax\n" // Load val into rax (the return value)
        "movq %1, %%rbx\n" // Restore rbx
        "movq %2, %%r12\n" // Restore r12
        "movq %3, %%r13\n" // Restore r13
        "movq %4, %%r14\n" // Restore r14
        "movq %5, %%r15\n" // Restore r15
        "movq %6, %%rbp\n" // Restore rbp
        "movq %7, %%rsp\n" // Restore rsp
        "movq %8, %%rcx\n" // Load return address (rip) from memory
        "jmp *%%rcx\n"     // Jump to the address in rcx
        :                  /* no outputs */
        : "m"(val), "m"(env[0].rbx), "m"(env[0].r12), "m"(env[0].r13), "m"(env[0].r14),
          "m"(env[0].r15), "m"(env[0].rbp), "m"(env[0].rsp), "m"(env[0].rip)
        : "memory", "rcx", "rax");

    UNREACHABLE();
}
