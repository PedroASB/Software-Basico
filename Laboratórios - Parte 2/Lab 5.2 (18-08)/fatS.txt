.text
.globl fat
fat:
    pushq %rbp
    movq %rsp, %rbp

    # Alcando espaço no registro de ativação
    subq $16, %rsp

    # %edi contém o valor de n

    cmpl $0, %edi
    jle end_if

    # Salvando o registrador %rdi da função chamadora
    movq %rdi, -8(%rbp)

    decl %edi
    call fat
    # %eax contém o retorno da função fat

    # Recuperando o registrador %rdi da função chamadora
    movq -8(%rbp), %rdi

    imull %edi, %eax

    leave
    # movq %rbp, %rsp
    # popq %rbp
    ret

end_if:

    movl $1, %eax

    leave
    # movq %rbp, %rsp
    # popq %rbp
    ret