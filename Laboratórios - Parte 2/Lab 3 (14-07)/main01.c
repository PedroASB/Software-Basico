#include <stdio.h>

// gcc -no-pie main01.c sum.c -o main01 && ./main01
// gcc -no-pie main01.c sum.S -o main01-asm && ./main01-asm

extern int s;

void sum();

int main() {
    sum();
    printf("soma = %d\n", s);
    return 0;
}