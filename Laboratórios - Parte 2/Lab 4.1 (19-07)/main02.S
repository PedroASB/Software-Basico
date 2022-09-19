.section .rodata


.data
# int i = 0;
.globl i
.align 4
i: .int 0

# long bias = 256;
.globl bias
.align 8
bias: .quad 256

# unsigned char vet[LEN] = {12, 3, 20, 8};
.globl vet
.align 1
vet: .byte 12, 3, 20, 8


.text
.globl main
main:
    pushq %rbp
    movq  %rsp, %rbp

    # for (i = 0; i < LEN; i++)
    movl $0, i
    loop:
        cmpl $4, i
        jge after_loop

        # bias = filtro(vet[i], LIM, bias);

        movq    $vet,   %r8     # Definindo um registrador como ponteiro para o vetor
        movslq  i,      %r9     # Estendendo a variável do índice
        # imulq $1,     %r9     # Multiplicando por "sizeof(unsigned char)"
        addq    %r9,    %r8     # Avançando para a posição desejada

        # (%r8) contém o valor de vet[i]

        movb (%r8), %dil        # unsigned char x
        movw $10,   %si         # short lim
        movq bias,  %rdx        # long b
        call filtro             # Chamada da função "filtro"
        
        movq %rax, bias         # Retorno da função "filtro"

        incl i
        jmp loop
    after_loop:

    # return 0;
    movl $0, %eax

    leave
    ret