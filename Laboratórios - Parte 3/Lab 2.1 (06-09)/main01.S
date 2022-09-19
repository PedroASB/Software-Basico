.section .rodata
fmt: .string "Soma: %ld\n"

.data

.text
.globl main
main:
    pushq %rbp
    movq %rsp, %rbp

    subq $32, %rsp

    # Salvando registradores callee-saved
    # short s; -> %bx
    movq %rbx, -8(%rbp)

    # Alocando as variáveis locais
    # -12(%rbp)      # i
    # -24(%rbp)      # l

    # s = (short)constante();
    call constante
    movw %ax, %bx

    # init(s, &l, &i);
    movw %bx, %di           # s
    leaq -24(%rbp), %rsi    # &l
    leaq -12(%rbp), %rdx    # &i

    call init

    # printf("Soma: %ld\n", l + i + s);
    movq    -24(%rbp),  %rsi
    movslq  -12(%rbp),  %r8
    addq    %r8,        %rsi
    movswq  %bx,  %r8
    addq    %r8,        %rsi
    
    movq $fmt, %rdi
    movl $0, %eax
    call printf

    # Recuperando registradores callee-saved
    movq -8(%rbp), %rbx

    movl $0, %eax    # return 0;
    leave
    ret
