#include <stdio.h>

// gcc -no-pie main01.c show.c -o main01 && ./main01
// gcc -no-pie main01.c show.S -o main01-asm && ./main01-asm

void show(int *v, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d\n", v[i]);
    }
}
