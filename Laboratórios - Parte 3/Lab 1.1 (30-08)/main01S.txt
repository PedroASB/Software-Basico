.section .rodata
fmt: .string "color: %ld, filled: %d\n"


.data
# struct Circle c1;
.globl c1
.align 8    # Maior tipo é um long (color)
c1:
    # Forma reduzida: .zero 24
    .int 0  # int x         (+0)
    .int 0  # int y         (+4)
    .byte 0 # char filled   (+8)
    .zero 7 # (padding)
    .quad 0 # long color    (+16)


.text
.globl main
main:
    pushq %rbp
    movq %rsp, %rbp

    movq $c1, %rcx

    # c1.x = 10;
    movl $10, (%rcx)

    # c1.y = 2 * c1.x;
    movl (%rcx), %edx
    imull $2, %edx
    movl %edx, 4(%rcx)

    # c1.filled = 1;
    movb $1, 8(%rcx)


    // if (c1.y > 30 || c1.filled == 1)
    //     c1.color = RED;
    // else
    //     c1.color = BLUE;
    cmpl $30, 4(%rcx)
    jg if_block
    cmpl $1, 8(%rcx)
    jne else
if_block:
    movq $2, 16(%rcx)
    jmp if_end
else:
    movq $1, 16(%rcx)
if_end:


    # printf("color: %ld, filled: %d\n", c1.color, (int)c1.filled);
    movq 16(%rcx), %rsi
    movsbl 8(%rcx), %edx
    movq $fmt, %rdi
    movl $0, %eax
    call printf

    leave
    ret
