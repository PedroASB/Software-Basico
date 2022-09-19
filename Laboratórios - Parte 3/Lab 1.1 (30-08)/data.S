.section .rodata
fmt: .string "%ld\n"


.text
# void show(struct data *d)
.globl show
show:
    pushq %rbp
    movq %rsp, %rbp

    # int i     ->  %ebx
    # long *ptr ->  %r12
    # d         ->  %rdi

    subq $32, %rsp
    movq %rbx, -8(%rbp)
    movq %r12, -16(%rbp)
    movq %rdi, -24(%rbp)

    # long *ptr = d->elems;
    // movq %rdi, %r12
    // addq $8, %r12
    leaq 8(%rdi), %r12

    # for (i = 0; i < d->len; i++)
    movl $0, %ebx
for_begin:
    movq -24(%rbp), %r8
    cmpl (%r8), %ebx
    jge for_end

    # printf("%ld\n", ptr[i]);
    movq %r12, %r9
    movslq %ebx, %r10
    imulq $8, %r10
    addq %r10, %r9

    # (%r9) contém ptr[i]

    movq (%r9), %rsi
    movq $fmt, %rdi
    movl $0, %eax
    call printf

    incl %ebx
    jmp for_begin
for_end:

    movq -8(%rbp), %rbx
    movq -16(%rbp), %r12
    movq -24(%rbp), %rdi

    leave
    ret
