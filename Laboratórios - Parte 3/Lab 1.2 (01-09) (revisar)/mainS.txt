.section .rodata
str01: .string "Diferença em %d/%d: %ld\n"

.data

// struct Produto {
//     char  mes;    # +0
//                   # 7 bytes de padding
//     long  preco;  # +8
//     int   ano;    # +16
                     # 4 bytes de padding
// };


// struct Produto prods[SIZE];
.globl prods
.align 8
prods: 
   .zero 48      # Vetor de duas structs


.text
.globl media
media:
   pushq %rbp
   movq %rsp, %rbp

   # Alocando espaço no registro de ativação
   subq $32, %rsp

   # Salvando os registradores callee-saved
   movq %r12, -8(%rbp)
   movq %r13, -16(%rbp)
   movq %r14, -24(%rbp)
   movq %r15, -32(%rbp)

   movq %rdi, %r12   # *ptr
   movq %rsi, %r13   # size
   movl $0, %r14d    # i = 0
   movq $0, %r15     # soma = 0

   movl $0, %r14d    # i = 0 (Mais literal possível)
loop_f:
   movslq %r14d, %rax
   cmpq %r13, %rax   # i >= size
   jge fim_loop_f

   # soma += ptr[i].preco;
   movq %r12, %rcx
   movslq %r14d, %rdx
   imulq $24, %rdx   # sizeof(Produto) = 24
   addq %rdx, %rcx   # %rcx aponta para o início da struct (ptr[i].mes)
   addq $8, %rcx     # %rcx aponta para o elemetro preco (ptr[i].preco)
   addq %rcx, %r15   # soma += ptr[i].preco

   incl %r14d        # i++
   jmp loop_f
fim_loop_f:
   # return soma / size;
   movq %r15, %rax
   cqto
   idivq %r13

   # %rax contém o quociente da divisão, e é o retorno da função

   # Recuperando os registradores callee-saved
   movq -8(%rbp), %r12
   movq -16(%rbp), %r13
   movq -24(%rbp), %r14
   movq -32(%rbp), %r15

   leave
   ret


.globl main
main:
   pushq %rbp
   movq %rsp, %rbp

   subq $16, %rsp

   movl $0, %r8d     # i = 0


   movq $prods, %rcx       # (%rcx) = prods[0]   

   movb $1,      (%rcx)    # (%rcx) = prods[0].mes
   movq $100,   8(%rcx)    # 8(%rcx) = prods[0].preco
   movl $2020, 16(%rcx)    # 16(%rcx) = prods[0].ano

   addq $24, %rcx          # (%rcx) = prods[1]

   movb $2,      (%rcx)    # (%rcx) = prods[1].mes
   movq $120,   8(%rcx)    # 8(%rcx) = prods[1].preco
   movl $2020, 16(%rcx)    # 16(%rcx) = prods[1].ano

   # m = media(prods, SIZE);
   movq $prods, %rdi    # prods
   movq $2, %rsi        # SIZE

   movq %r8, -8(%rbp)
   call media
   movq -8(%rbp), %r8

   movq %rax, %r9    # %r9 (m) recebe o retorno de media

loop_w:
   cmpl $2, %r8d
   jge fim_loop_w

   movl %r8d , %eax

   # (int)prods[i].mes
   movq $prods, %r10
   movslq %eax, %r11
   imulq $24, %r11
   addq %r11, %r10         # %r10 = &prods[i]
   
   movsbl (%r10), %esi     # 2o. parâmetro

   # prods[i].ano
   movl 16(%r10), %edx     # 3o. parâmetro

   # prods[i].preco - m
   movq 8(%r10), %rcx
   subq %r9, %rcx          # 4o. parâmetro
   
   movq $str01, %rdi       # 1o. parâmetro
   movl $0, %eax

   movq %r8, -8(%rbp)
   call printf
   movq -8(%rbp), %r8

   incl %r8d      # i++
   jmp loop_w
fim_loop_w:

   movl $0, %eax

   leave
   ret
