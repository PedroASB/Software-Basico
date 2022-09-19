.section .rodata
# String de formatação
fmt: .string "Valor: x = %ld, i = %d\n"


.data
# long x = 10;
.globl x
.align 8
x: .quad 10


.text
#           %edi    %rsi
# long aux(int i, long *ptr)
.globl aux
aux:
    pushq %rbp
    movq %rsp, %rbp

    subq $16, %rsp

    # x = 5;
    movq $5, x

    # printf("Valor: x = %ld, i = %d\n", x, i);

    movq %rdi, -8(%rbp)
    movq %rsi, -16(%rbp)

    movl %edi, %edx
    movq $fmt, %rdi
    movq x, %rsi

    movl $0, %eax
    call printf

    movq -8(%rbp), %rdi
    movq -16(%rbp), %rsi

    # return x + i + *ptr;
    // movq x, %r8
    // movslq %edi, %r9
    // addq %r9, %r8
    // addq (%rsi), %r8
    // movq %r8, %rax

    # # return x + i + *ptr;
    movslq %edi, %rax
    addq x, %rax
    addq (%rsi), %rax


    leave
    ret
