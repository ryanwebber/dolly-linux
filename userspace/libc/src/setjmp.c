#include <setjmp.h>
#include "todo.h"

int setjmp(jmp_buf env)
{
    (void)env;
    TODO("setjmp");
}

__attribute__((noreturn)) void longjmp(jmp_buf env, int val)
{
    (void)env;
    (void)val;
    TODO("longjmp");
}
