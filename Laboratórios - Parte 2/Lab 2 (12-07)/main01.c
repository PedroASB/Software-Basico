#include <stdio.h>

// gcc -no-pie main01.c ex01.c -o main && ./main
// gcc -no-pie main01.c ex01.S -o main-asm && ./main-asm

extern int a;
extern int b;
extern int c;
extern int d;

void ex01();

int main() {
    ex01();
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    printf("d = %d\n", d);
    return 0;
}