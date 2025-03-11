.global _start
.global environ                        # declare global variable for envp

_start:                                # _start is the entry point known to the linker
    xor     ebp, ebp                   # effectively RBP := 0, mark the end of stack frames

    mov     edi, [rsp]                 # get argc from the stack (implicitly zero-extended to 64-bit)
    lea     rsi, [rsp + 8]             # take the address of argv from the stack
    lea     rdx, [rsp + rdi * 8 + 16]  # take the address of envp from the stack

    mov     [environ], rdx             # store the address of envp in the global variable

    xor     eax, eax                   # per ABI and compatibility with icc
    call    main                       # edi, rsi, rdx are the three args (of which first two are C standard) to main

    mov     edi, eax                   # transfer the return of main to the first argument of _exit
    xor     eax, eax                   # per ABI and compatibility with icc
    mov     rax, 60                    # Syscall number for exit
    syscall

.section .bss                          # reserve space for environ in the .bss section
    .comm environ, 8                   # allocate 8 bytes for a 64-bit pointer (for envp)
