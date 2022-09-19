.section .rodata

.data
# int a = 0;
.globl a
.align 4
a: .int 0

# long b = 2;
.globl b
.align 8
b: .quad 2


.text
.globl ex02
ex02:
   pushq %rbp
   movq  %rsp, %rbp

    // if (a)
    cmpl $0, a
    je after_if_1
        // if (b < 5)
        cmp $5, b
        jge block_else
            # b = (a << 1) + (a * b);
            movl    a,      %eax
            shll    $1,     %eax

            movslq  a,      %rcx
            imulq   b,      %rcx

            movslq  %eax,   %rax
            addq    %rcx,   %rax

            movq    %rax,    b
        jmp after_if_2
        block_else:
            # a = b ^ 0x1FL;
            movq b, %rax
            xorq $0x1F, %rax
            movl %eax, a
        after_if_2:
    after_if_1:

    leave
    ret