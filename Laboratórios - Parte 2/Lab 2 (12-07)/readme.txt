    // movl a,     %eax
    // cmpl %eax,  %eax
    // jne after_if_1
    //     movl    $5,     %edx
    //     movslq  %edx,   %rdx
    //     cmpq    b,      %rdx
    //     jge block_else

    //     # b = (a << 1) + (a * b);
    //     sarl    $1,  a
    //     movl    a,  %eax
    //     imul    b,  %eax
    //     addl    a,  %eax
    //     movl    %eax,    b
    //     jmp after_if_2
    //     block_else:
    //         # a = b ^ 0x1FL;
    //         movl    b,      %ecx
    //         movslq  %ecx,   %rcx
    //         movl    $0x1F,  %edx
    //         movslq  %edx,   %rdx
    //         xorq    %rdx,   %rcx
    //         movl    %ecx,   a
    //     after_if_2:
    // after_if_1:




    movl a, %r8d
    cmpl $0, %r8d
    je after

    movl $200, a
    movl $100, %r8d
    movl %r8d, a
    if(a == 0) goto endif
    if(a != 0){
        a = 200
        a = 100
        goto endif
    }
    leave
    ret
after:
    movl a, %r9d
    movl $1000, %r9d
    movl %r9d, a
