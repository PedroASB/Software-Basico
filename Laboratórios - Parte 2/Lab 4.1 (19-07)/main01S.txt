.section .rodata
# .align 1
fmt: .string "Hello"


.data
# int val = 432;
.globl val
.align 4
val: .int 432

# short age = 4;
.globl age
.align 2
age: .short 4

# int r = 0;
.globl r
.align 4
r: .int 0

# int err = 0;
.globl err
.align 4
err: .int 0


.text
.globl main
main:
    pushq %rbp
    movq  %rsp, %rbp

    # err = sum("Hello", val, age, &r);
    movq  $fmt, %rdi     # const char *prefix
    movl  val,  %esi     # int v1
    movw  age,  %dx      # short v2
    movq  $r,   %rcx     # int *s
    call  sum            # Chamada da função "sum"

    movl  %eax, err      # Retorno da função "sum"

    # show(err, r);
    movl  err,  %edi     # int err
    movl  r,    %esi     # int r
    call  show           # Chamada da função "show"

    # return 0;
    movl $0, %eax

    leave
    ret