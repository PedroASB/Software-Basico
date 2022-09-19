.data

# char c = -20;
.globl c
# .align 1
c:  .byte   -20

# int i = -256;
.globl i
.align 4
i:  .int    -256

# int j = 512;
.globl j
.align 4
j:  .int    512

# long l = 128;
.globl l
.align 8
l:  .quad   128

# unsigned short us = 111;
.globl us
.align 2
us: .short  111

# unsigned int ui = 1024;
.globl ui
.align 4
ui: .int    1024

# unsigned long ul = 2048;
.globl ul
.align 8
ul: .quad   2048


.text

.globl aux
aux:
    pushq %rbp
    movq  %rsp, %rbp


    ### Atribuições simples ###

    # j = 68000;
    movl    $68000, j

    # l = 4096;
    movq    $4096,  l
    
    # i = j;
    movl    j,      %eax
    movl    %eax,   i


    ### Expressões ###
    
    # j = 10 + i - 5;
    movl    i,      %eax
    addl    $10,    %eax
    subl    $5,     %eax
    movl    %eax,   j

    # i = (i * 2) - (j + 5);
    movl    i,      %eax
    imull   $2,     %eax
    movl    j,      %ecx
    addl    $5,     %ecx
    subl    %ecx,   %eax
    movl    %eax,   i


    ### Casts ###

    # ui = i;
    movl    i,     %eax
    movl    %eax,   ui

    # j = c;
    movb    c,      %al
    movsbl  %al,    %eax
    movl    %eax,   j

    # ul = ui;
    movl    ui,     %eax
    movq    %rax,   ul      # "movzlq" não existe

    # us = ul;
    movq    ul,     %rax
    movw    %ax,   us

    # c = i + j;
    movl    i,      %eax
    addl    j,      %eax
    movb    %al,    c


    ### Ponteiros ###

    # long *ptr;
    # ptr = &l;
    movq    $l,     %rax
    # *ptr = 128;
    movq    $128,   (%rax)

    # int *iptr;
    # iptr = &i;
    movq    $i,     %rcx
    # j = j + *iptr;
    movl    j,      %edx
    addl    (%rcx), %edx
    movl    %edx,   j


    leave

    ret