.data

# short v1[2] = {1, 2};
.globl v1
.align 2
v1: .short 1, 2

# long v2[3] = {1, 2, 3};
.globl v2
.align 8
v2: .quad 1, 2, 3


.text

# void sum(short *a1, int p1, long *a2, int p2);
# Não é necessário declarar a "sum" em Assembly, 
# ela só serve para a linguagem C fazer a verificação de tipos


# void aux(short *a1, int p1)
.globl aux
aux:
    pushq %rbp
    movq %rsp, %rbp

    subq $32, %rsp
    movq %rbx, -8(%rbp)

    # for (i = 2; i >= 0; i--)
    movl $2, %ebx
for:
        cmpl $0, %ebx
        jl end_for

        # void sum(short *a1, int p1, long *a2, int p2);
        # sum(a1, p1, v2, i);

        # %rdi => short *a1
        # %esi => int p1
        movq $v2, %rdx
        movl %ebx, %ecx

        movq %rdi, -16(%rbp)
        movq %rsi, -24(%rbp)

        call sum
        
        movq -16(%rbp), %rdi
        movq -24(%rbp), %rsi

        decl %ebx
        jmp for
end_for:

    movq -8(%rbp), %rbx
    leave
    ret


# int main()
.globl main
main:
    pushq %rbp
    movq %rsp, %rbp

    subq $16, %rsp
    movq %rbx, -8(%rbp)

    movl $0, %ebx   # int i = 0;
while:              # while (i < 2)
        cmpl $2, %ebx
        jge end_while

        # void aux(short *a1, int p1)
        # aux(v1, i);
        movq $v1, %rdi
        movl %ebx, %esi

        call aux

        incl %ebx   # i++
        jmp while
end_while:

    movl $0, %eax   # return 0;

    movq -8(%rbp), %rbx
    leave
    ret
