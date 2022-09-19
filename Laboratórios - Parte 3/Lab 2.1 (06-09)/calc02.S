.data

.text
.globl calc
calc:
    pushq %rbp
    movq %rsp, %rbp

    subq $64, %rsp
    
    # Salvando os registradores callee-saved
    # i -> %r12
    movq %r12, -8(%rbp)
    # j -> %r13
    movq %r13, -8(%rbp)

    # int i = 0;
    movl $0, %r12d
    # int j = 4;
    movl $4, %r13d

    # Alocando as variáveis locais
    # int sum;
    movq $0, -20(%rbp)
    # int vet1[5];
    movq $0, -40(%rbp)       # 4 * 5 = 20 bytes
    # short vet2[5];
    movq $0, -50(%rbp)       # 2 * 5 = 10 bytes

    # filli(vet1, 5, i);
    leaq -40(%rbp), %rdi
    movl $5, %esi
    movl %r12d, %edx

    call filli

    # fills(vet2, 5, j);
    leaq -50(%rbp), %rdi
    movl $5, %esi
    movl %r13d, %edx

    call fills


    # sum = 0;
    # for ( ; i < 5; i++, j--) {
    #     sum += vet1[i] + vet2[j];
    # }
    movl $0, -20(%rbp)
for_begin:
    cmpl $5, %r12d
    jge for_end

    leaq -40(%rbp), %rcx
    movslq %r12d, %r8
    imulq $4, %r8
    addq %r8, %rcx
    # rcx -> vet1[i]

    leaq -50(%rbp), %rdx
    movslq %r13d, %r9
    imulq $2, %r9
    addq %r9, %rdx
    # rdx -> vet2[j]

    movswl (%rdx), %r10d
    addl (%rcx), %r10d

    addl %r10d, -20(%rbp)

    incl %r12d
    decl %r13d
    jmp for_begin
for_end:


    # return sum;
    movl -20(%rbp), %eax

    # Recuperando os registradores callee-saved
    movq -8(%rbp), %r12
    movq -8(%rbp), %r13

    leave
    ret
