.section .rodata


.data
# int a = 30;
.globl a
.align 4
a:  .int    30

# int b = 45;
.globl b
.align 4
b:  .int    45


# int c = -10;
.globl c
.align 4
c:  .int    -10

# int d = 25;
.globl d
.align 4
d:  .int    25


.text
.globl ex01
ex01:
    pushq %rbp
    movq  %rsp, %rbp

    // if (a > b)
    movl a, %eax
    cmpl b, %eax
    jle after_if_1
        # c = -c;
        negl c

        # d = 2 * c;
        movl  c, %ecx
        imull $2, %ecx
        movl  %ecx, d
    after_if_1:

    // if (b >= a)
    cmpl %eax, b
    jl after_if_2
        # c = (a + b) * c;
        addl  b, %eax
        imull c, %eax
        movl  %eax, c

        # d = 1024;
        movl $1024, d
    after_if_2:

    leave
    ret