.global _start

_start:                               # _start is the entry point known to the linker
    xor     ebp, ebp                  # effectively RBP := 0, mark the end of stack frames
    mov     edi, [rsp]                # get argc from the stack (implicitly zero-extended to 64-bit)
    lea     rsi, [rsp + 8]            # take the address of argv from the stack
    lea     rdx, [rsp + rdi * 8 + 16] # take the address of envp from the stack
    xor     eax, eax                  # per ABI and compatibility with icc
    call    main                      # edi, rsi, rdx are the three args (of which first two are C standard) to main

    mov     edi, eax                  # transfer the return of main to the first argument of _exit
    xor     eax, eax                  # per ABI and compatibility with icc
    call    _exit                     # terminate the program
