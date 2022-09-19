#include <stdio.h>

// gcc -no-pie main01.c fat.c -o main01 && ./main01
// gcc -no-pie main01.c fat.S -o main01-asm && ./main01-asm

int fat(int n);

int main(void) {
    printf("%d\n", fat(5));
    return 0;
}