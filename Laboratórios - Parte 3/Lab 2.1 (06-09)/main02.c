#include <stdio.h>

// gcc -no-pie main02.c calc02.c -o main02 && ./main02
// gcc -no-pie main02.c calc02.S -o main02-asm && ./main02-asm


int calc();

void filli(int *v, int cols, int k) {
    int i;
    (void) k;

    for (i = 0; i < cols; i++) {
        v[i] = 1;
    }

}

void fills(short *v, int cols, int k) {
    int i;
    (void) k;

    for (i = 0; i < cols; i++) {
        v[i] = 2;
    }
}

int main() {
    printf("%d\n", calc());
    return 0;
}