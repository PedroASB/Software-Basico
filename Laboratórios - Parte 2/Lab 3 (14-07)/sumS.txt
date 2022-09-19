.data
# int s = 0;
.globl s
.align 4
s: .int 0

# int nums[4] = {65, -105, 111, 34};
.globl nums
.align 4
nums: .int 65, -105, 111, 34

.text
.globl sum
sum:
    pushq %rbp
    movq  %rsp, %rbp

    movl s, %eax

    # int i = 0;
    movl $0, %edx
    while:
        # i >= 4
        cmpl $4, %edx
        jge after_while

        # s = s + nums[i];

        # Definindo um registrador como ponteiro para o vetor
        movq $nums, %rcx

        # Estendendo a variável do índice
        movslq %edx, %rsi // Observação: como a operação é com sinal, deve-se realizar a extensão

        # Multiplicando por "sizeof(int)"
        imulq $4, %rsi 

        # Avançando para a posição desejada
        addq %rsi, %rcx

        # Atribuindo nums[i] em s
        movl (%rcx), %eax
        addl %eax, s

        # i++;
        incl %edx       
        jmp while
    after_while:

    leave
    ret