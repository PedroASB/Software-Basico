.data
# char str[] = "BEBAMUITOCAFE";
.globl str
# .align 1
str: .string "BEBAMUITOCAFE"


.text
.globl process
process:
    pushq %rbp
    movq  %rsp, %rbp

    # Registrador %r8 como sendo 'ptr'
    # ptr = str
    movq $str, %r8

    beginwhile:
        cmpb $0, (%r8)
        je endwhile

        # *ptr += 32;
        addb $32, (%r8)
        
        # ptr++;
        incq %r8
        # addq $1, %r8 (Aritmética de ponteiro considerando .align 1)

        jmp beginwhile
    endwhile:

    leave
    ret