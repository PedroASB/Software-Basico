.data
# long last = 0;
.globl last
.align 8
last: .quad 0

# long values[5] = {50, -10, 60, -20, 70};
.globl values
.align 8
values: .quad 50, -10, 60, -20, 70


.text
.globl swap
swap:
    pushq %rbp
    movq  %rsp, %rbp

    # int j = 4;
    movl $4, %r9d

    # i = 0
    movl $0, %r8d
    for:
        # i >= j
        cmpl %r9d, %r8d
        jge after_for

        # long tmp = values[i];
        # values[i] = values[j];
        # values[j] = tmp;

        # Definindo um registradores como ponteiros para os vetores
        movq $values, %rax
        movq $values, %rcx

        # Estendendo as variáveis de índice
        movslq %r8d, %r10 // Deve-se mudar de registrador para não alterar o valor de "i"
        movslq %r9d, %r11 // Deve-se mudar de registrador para não alterar o valor de "j"

        # Multiplicando por "sizeof(long)"
        imulq $8, %r10
        imulq $8, %r11

        # Avançando para a posição "i"
        addq %r10, %rax

        # Avançando para a posição "j"
        addq %r11, %rcx

        # tmp: %rdx

        # Atribuindo "values[i]" em "tmp"
        movq (%rax), %rdx

        # Atribuindo "values[j]" em "values[i]"
        movq (%rcx), %rsi
        movq %rsi, (%rax)

        # Atribuindo "tmp" em "values[j]"
        movq %rdx, (%rcx)

        # i++
        incl %r8d 

        # j--
        decl %r9d

        jmp for
    after_for:    

    # last = values[4];
    movq $values, %rax
    // addq $32, %rax
    // movq (%rax), %rdx
    // movq %rdx, last
    movq 32(%rax), %rcx
    movq %rcx, last

    
    leave
    ret