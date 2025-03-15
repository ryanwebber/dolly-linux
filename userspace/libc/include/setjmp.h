// https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/setjmp.h.html

#ifndef _SETJMP_H
#define _SETJMP_H

#include "stdint.h"

struct __jmp_buf
{
    uint64_t rbx;
    uint64_t r12;
    uint64_t r13;
    uint64_t r14;
    uint64_t r15;
    uint64_t rbp;
    uint64_t rsp;
    uint64_t rip;
    int did_save_signal_mask;
    // sigset_t saved_signal_mask;
};

typedef struct __jmp_buf jmp_buf[1];

__attribute__((noreturn)) void longjmp(jmp_buf, int val);

#endif
