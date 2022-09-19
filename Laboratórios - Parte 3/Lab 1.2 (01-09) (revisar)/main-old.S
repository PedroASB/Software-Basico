.section .rodata

str01:
   .string "Diferença em %d/%d: %ld\n"


.data

.globl prods
.align 8
prods:
	.zero 12

.text

.globl main


media:
   pushq %rbp
   movq %rsp, %rbp

   movq %rdi, %r12   # *ptr
   movq %rsi, %r13   # size
   movl $0, %r14d    # i = 0
   movq $0, %r15     # soma = 0

loop_f:
   movl %r14d, %eax  
   cmpq %r13, %rax   # i >= size
   jge fim_loop_f

   #soma += ptr[i].preco;
   movl %r14d, %eax  
   movq 8(%rax), %rdx
   movq 4(%rdx), %rax
   subq %rdx, %rax
   addq %r12, %rax
   movq 8(%rax), %rax
   addq %rax, %r15

   incl %r14d        #i++

fim_loop_f:
   #return soma / size;
   movq %r15, %rax
   idivq %r13
   leave
   ret

main:
   pushq %rbp
   movq %rsp, %rbp
   subq $24, %rsp

   movl $0, %r8d     # i = 0
  
   movl $1, prods(%rip)    
   movq $100, prods(%rip)
   movl $2020, prods(%rip)
   
   movl $2, prods(%rip)
   movq $120, prods(%rip)
   movl $2020, prods(%rip)
  
   # m = media(prods, SIZE);
   movl $2, %esi  # SIZE
   movl $prods, %edi # prods

   call media

   movq %rax, %r9    # %r9(m) recebe o retorno de media

loop_w:
   cmpl $2, %r8d
   jg fim_loop_w

   movl %r8d , %eax

   movq 8(%rax), %rdx
   movq 4(%rdx), %rax
   subq %rdx, %rax
   movq prods(%rax), %rax
   movq %rax, %rcx
   subq %r9, %rcx  # prods[i].preco - m)

   movl %r8d, %eax

   movq 8(%rax), %rdx
   movq 4(%rdx), %rax
   subq %rdx, %rax
   movl prods(%rax), %edi

   movl %r8d, %eax
 
   movq 8(%rax), %rdx
   movq 4(%rdx), %rax
   subq %rdx, %rax
  
   movzbl prods(%rax), %eax
   movsbl %al,%esi      #  (int)prods[i].mes

   movl %edi, %edx      #prods[i].ano
   movl $str01, %edi    # "Diferença em %d/%d: %ld\n"
   
   movl $0, %eax
   call printf

   incl %r8d      # i++

   jmp loop_w

fim_loop_w:
   movl $0, %eax
   leave
   ret
