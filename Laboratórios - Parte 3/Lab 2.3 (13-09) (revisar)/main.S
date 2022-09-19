.section .rodata
fmt01: .string "Objetos iguais!\n"
fmt02: .string "Pin conhecido!\n"

.data
# rfid_object_t gObj;
.globl gObj
.align 4
gObj: .zero 24


.text
.globl main
main:
    pushq %rbp
    movq %rsp, %rbp

    subq $64, %rsp

    # rfid_object_t lObj; -> -24(%rbp)
    # short pins[2][3]; -> -36(%rbp)

    movq %r12, -48(%rbp)
    movq %r13, -56(%rbp)

    # init_obj(&gObj, 0);
    leaq $gObj, %rdi
    movl $0, %esi
    call init_obj

    # init_obj(&lObj, 2);
    leaq -24(%rbp), %rdi
    movl $2, %esi
    call init_obj

    # init_pins(pins);
    leaq -36(%rbp), %rdi
    call init_pins

    
    // if (compare_guid(&gObj.id, &lObj.id))
    movq $gObj, %rdi
    addq $4, %rdi        # leaq 4(%rdi), %rdi
    leaq -20(%rbp), %rsi
    call compare_guid

    cmp $0, %eax
    je end_if_01

    movq $fmt01, %rdi
    movl $0, %eax
    call printf         # printf("Objetos iguais!\n");

end_if_01:


// ----- BLOCO FOR -----


# for (int i = 0; i < 2; i++)
    movl $0, %r12d      # i
for_01_begin:
    cmpl $2, %r12d
    jge for_01_end
    
    # for (int j = 0; j < 3; j++)
    movl $0, %r13d      # j
for_02_begin:
    cmpl $3, %r13d
    jge for_02_end

    // if (pins[i][j] == lObj.pin)
    leaq -36(%rbp), %rcx # pins[i][j]
    movslq %r12d, %r8   # estendendo "i"
    imulq $2, %r8       # multiplicando por sizeof(short)
    movslq %r13d, %r9   # estendendo "j"
    imulq $2, %r9       # multiplicando por sizeof(short)
    imulq 

    cmpw 
    jne end_if_02
    
    movq $fmt02, %rdi
    movl $0, %eax
    call printf     # printf("Pin conhecido!\n");
    jmp main_end
end_if_02:


    incl %r13d
    jmp for_02_begin
for_02_end:

    incl %r12d
    jmp for_01_begin
for_01_end:


// ----- FIM DO BLOCO FOR -----


main_end:

    movq -48(%rbp), %r12
    movq -56(%rbp), %r13

    movl $0, %eax       # return 0;

    leave
    ret
