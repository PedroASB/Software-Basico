.section .rodata
fmt01: .string "'a' maior do que 'b'\n"
fmt02: .string "Valor de 'b': %d\n"


.data
# char a = 97;
.globl a
a: .byte 97

# char b = 105;
.globl b
b: .byte 105


.text
.globl main
main:
    pushq %rbp
    movq  %rsp, %rbp

    # int ret = maximo(a, b);
    movb a, %dil
    movb b, %sil
    call maximo

    # %eax contém o retorno da função "maximo" (retorno do tipo int)
    movl %eax, %ecx

    # Extensão de 'a' para 4 bytes
    movsbl a, %edx

    // if (ret == a)
    cmpl %edx, %ecx
    jne else
        # printf("'a' maior do que 'b'\n");
        movq $fmt01, %rdi
        movl $0, %eax
        call printf
        jmp end
    else:
        # printf("Valor de 'b': %d\n", (int)b);
        movq $fmt02, %rdi
        movsbl b, %esi
        movl $0, %eax
        call printf
    end:

    # return 0;
    movl $0, %eax

    leave
    ret