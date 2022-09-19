#include <stdio.h>

// gcc -no-pie main02.c ex02.c -o main02 && ./main02
// gcc -no-pie main02.c ex02.S -o main02-asm && ./main02-asm

extern int a;
extern long b;
void ex02();

int main() {
    ex02();
    printf("a = %d (0x%.8X)\n", a, a);
    printf("b = %ld (0x%.16lX)\n", b, b);
    return 0;
}