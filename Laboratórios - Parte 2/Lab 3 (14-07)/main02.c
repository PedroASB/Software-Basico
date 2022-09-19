#include <stdio.h>

// gcc -no-pie main02.c swap.c -o main02 && ./main02
// gcc -no-pie main02.c swap.S -o main02-asm && ./main02-asm

extern long last;
extern long values[5];

void swap();

int main() {
    swap();

    for (int i = 0; i < 5; i++) {
        printf("values[%d] = %ld\n", i, values[i]);
    }

    printf("last = %ld\n", last);

    return 0;
}