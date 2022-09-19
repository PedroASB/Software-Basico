.section .rodata
.globl fmt
fmt: .string "%d\n"

.text
#           %rdi    %esi
# void show(int *v, int size)
.globl show
show:       
    pushq %rbp
    movq %rsp, %rbp

    subq $32, %rsp

    # i -> %ebx
    movq %rbx, -8(%rbp)

    # for (i = 0; i < size; i++)
    movl $0, %ebx
for:
    cmpl %esi, %ebx
    jge end_for

    # printf("%d\n", v[i]);

    # Salvando os registradores dos parâmetros da função chamadora
    movq %rdi, -16(%rbp)
    movq %rsi, -24(%rbp)

    movslq %ebx, %r9
    imulq $4, %r9
    addq %r9, %rdi

    # (%rdi) contém o valor de v[i]

    movl (%rdi), %esi
    movq $fmt, %rdi
    movl $0, %eax
    call printf

    # Recuperando os registradores dos parâmetros da função chamadora
    movq -16(%rbp), %rdi
    movq -24(%rbp), %rsi

    incl %ebx
    jmp for
end_for: 

    movq -8(%rbp), %rbx

    leave
    ret
