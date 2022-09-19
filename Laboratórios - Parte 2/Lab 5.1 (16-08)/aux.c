#include <stdio.h>

// gcc -no-pie main02.c aux.c -o main02 && ./main02
// gcc -no-pie main02.c aux.S -o main02-asm && ./main02-asm

long x = 10;

long aux(int i, long *ptr) {
    x = 5;
    printf("Valor: x = %ld, i = %d\n", x, i);
    return x + i + *ptr;
}