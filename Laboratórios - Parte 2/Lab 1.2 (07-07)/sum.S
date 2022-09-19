.section .rodata
fmt: .string "Soma: %ld\n"


.data

# long sum = 0;
.globl sum
.align 8
sum: .quad 0

# long vet[5] = {10, 20, 30, 40, 50};
.globl vet
.align 8
vet: .quad 10, 20, 30, 40, 50


.text
.globl main
main:
    pushq %rbp
    movq %rsp, %rbp

    # Registrador %ecx como sendo 'i'
    # int i = 0;
    movl $0, %ecx

    # Registrador %r8 como sendo 'ptr'
    # long *ptr = vet;
    movq $vet, %r8

    beginwhile:
        cmpl $5, %ecx
        jge  endwhile

        # sum = sum + *ptr;
        movq (%r8), %rax
        addq sum, %rax
        movq %rax, sum

        # movq (%r8), %rdx
        # addq %rdx, sum
  
        # ptr++;
        addq $8, %r8
        # Aritmética de ponteiro considerando .align 8
        # %r8 = %r8 + sizeof(long)

        # i++;
        incl %ecx

        jmp beginwhile
    endwhile:

    movq $fmt, %rdi
    movq sum, %rsi
    movl $0, %eax
    call printf

    movl $0, %eax

    leave
    ret