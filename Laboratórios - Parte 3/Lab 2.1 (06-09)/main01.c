#include <stdio.h>

// gcc -no-pie main01.c aux01.c -o main01 && ./main01
// gcc -no-pie main01.S aux01.c -o main01-asm && ./main01-asm

char constante();
void init(short factor, long *pl, int *pi);

int main() {
    short s;     // Deve ser registrador
    int i;
    long l;

    s = (short)constante();
    init(s, &l, &i);

    printf("Soma: %ld\n", l + i + s);

    return 0;
}