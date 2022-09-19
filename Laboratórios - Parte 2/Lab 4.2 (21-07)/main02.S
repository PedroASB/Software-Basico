.data
# int i = 0;
.globl i
.align 4
i: .int 0

# short vetA[5] = {28, 42, 16, 23, 47};
.globl vetA
.align 2
vetA: .short 28, 42, 16, 23, 47

# int vetB[5] = {0, 0, 0, 0, 0};
.globl vetB
.align 4
vetB: .int 0, 0, 0, 0, 0


.text
.globl main
main:
    pushq %rbp
    movq  %rsp, %rbp

    # short v;   ->   %ax

    # while (i < 5)
    # i = 0
    loop:
        cmpl $5, i
        jge after_loop    

        /*
            v = vetA[i] << 2;
        */

        movq    $vetA,  %r8     # Definindo um registrador como ponteiro para o vetor
        movslq  i,      %r9     # Estendendo a variável do índice
        imulq   $2,     %r9     # Multiplicando por "sizeof(short)"
        addq    %r9,    %r8     # Avançando para a posição desejada

        # (%r8) contém o valor de vetA[i]

        movw    (%r8),  %r10w   # %r10w é um registrador temporário
        shlw    $2,     %r10w   # vetA[i] << 2; (Left Shift)
        movw    %r10w,  %ax     # v = vetA[i] << 2;

        /*
            process(i, v, &vetB[i]);
        */

        movq    $vetB,  %r10    # Definindo um registrador como ponteiro para o vetor
        movslq  i,      %r11    # Estendendo a variável do índice
        imulq   $4,     %r11    # Multiplicando por "sizeof(int)"
        addq    %r11,   %r10    # Avançando para a posição desejada

        # (%r10) contém o valor de vetB[i]

        # process(i, v, &vetB[i]);
        movl    i,      %edi    # int x
        movw    %ax,    %si     # short v
        movq    %r10,   %rdx    # int *pos
        call    process
        
        incl i
        jmp loop
    after_loop:

    # show(vetB, 5);
    movq    $vetB,  %rdi    # int *vet
    movq    $5,     %rsi    # long size
    call    show

    # return 0;
    movl $0, %eax

    leave
    ret