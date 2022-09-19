.section .rodata

.data
# sum
.globl sum
.align 4
sum: .int 0
# i
.globl i
.align 4
i: .int 0

.text
.globl testing
testing:
   pushq %rbp
   movq  %rsp, %rbp


    # Inicialização
    movl i, %ecx    # i
    movl sum, %eax  # sum


    # Laço de repetição
    loop:
        # Teste
        cmpl $10, %ecx
        jge after

        addl %ecx, %eax

         # Incremento
        incl %ecx
        jmp loop
    after:
        movl %eax, sum

    # Acessando array com índice variável

    # Definir um registrador como ponteiro
    movq $vet, %rax
    # Estender a variável do índice
    movslq i, %rcx
    # Multiplicar pelo "sizeof()"
    imulq $4, %rcx 
    # Avançar para a posição desejada
    addq %rax, %rcx

    # Realizar a atribuição
    # Exemplos
    movl (%rcx), %edx
    # ou
    movl %edx, (%rcx) 



   leave

   ret