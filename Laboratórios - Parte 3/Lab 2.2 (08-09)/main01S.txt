.section .rodata
fmt01: .string "tipo = %d, ID = %ld, nome = '%s', idade = %d\n"
fmt02: .string "tipo = %d, ID = %ld, nome = '%s', cor = '%s'\n"

.data

.text
.globl showPerson
showPerson:
    pushq %rbp
    movq %rsp, %rbp

    # printf("tipo = %d, ID = %ld, nome = '%s', idade = %d\n",
    # person->type, person->ID, person->name, person->age);

    movl (%rdi), %esi
    movq 8(%rdi), %rdx
    leaq 16(%rdi), %rcx
    movl 32(%rdi), %r8d

    movq $fmt01, %rdi
    movl $0, %eax
    call printf

    leave
    ret


.globl showCar
showCar:
    pushq %rbp
    movq %rsp, %rbp

    # printf("tipo = %d, ID = %ld, nome = '%s', cor = '%s'\n",
    # car->type, car->ID, car->name, car->color);

    movl (%rdi), %esi
    movq 8(%rdi), %rdx
    leaq 16(%rdi), %rcx
    leaq 32(%rdi), %r8

    movq $fmt02, %rdi
    movl $0, %eax
    call printf

    leave
    ret


.globl main
main:
    pushq %rbp
    movq %rsp, %rbp

    subq $128, %rsp

    # struct Person p;
    # p -> -40(%rbp)

    # struct Car c[2];
    # c[0] -> -120(%rbp)
    # c[1] -> -80(%rbp)

    # readPerson(&p);
    leaq -40(%rbp), %rdi
    call readPerson

    # readCar(&c[0]);
    leaq -120(%rbp), %rdi
    call readCar

    # readCar(&c[1]);
    leaq -80(%rbp), %rdi
    call readCar


    # showPerson(&p);
    leaq -40(%rbp), %rdi
    call showPerson

    # showCar(&c[0]);
    leaq -120(%rbp), %rdi
    call showCar

    # showCar(&c[1]);
    leaq -80(%rbp), %rdi
    call showCar


    movl $0, %eax   # return 0;
    leave
    ret
