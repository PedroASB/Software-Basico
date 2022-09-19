.text
#             %edi   %esi   %edx   %ecx   %r8d   %r9d    
# int process(int a, int b, int c, int d, int e, int f)
.globl process
process:
    pushq %rbp
    movq %rsp, %rbp

    subq $48, %rsp

    movq %rdi,  -8(%rbp)
    movq %rsi, -16(%rbp)
    movq %rdx, -24(%rbp)
    movq %rcx, -32(%rbp)
    movq %r8,  -40(%rbp)
    movq %r9,  -48(%rbp)

    # --- %r10d = registrador temporário ---

    # Trocando 'a' com 'f'
    movl %edi, %r10d
    movl %r9d, %edi
    movl %r10d, %r9d
    
    # Trocando 'b' com 'e'
    movl %esi, %r10d
    movl %r8d, %esi
    movl %r10d, %r8d

    # Trocando 'c' com 'd'
    movl %edx, %r10d
    movl %ecx, %edx
    movl %r10d, %ecx

    # int r = calc(f, e, d, c, b, a);
    call calc
    # %eax contém o retorno de calc

    movq  -8(%rbp), %rdi
    movq -16(%rbp), %rsi
    movq -24(%rbp), %rdx
    movq -32(%rbp), %rcx
    movq -40(%rbp), %r8
    movq -48(%rbp), %r9

    # %eax = r + a + b + c + d + e + f
    addl %edi, %eax
    addl %esi, %eax
    addl %edx, %eax
    addl %ecx, %eax
    addl %r8d, %eax
    addl %r9d, %eax

    # return r + a + b + c + d + e + f;

    leave
    ret
