#include <stdio.h>

// gcc -no-pie main02.c proc.c -o main02 && ./main02
// gcc -no-pie main02.S proc.c -o main02-asm && ./main02-asm

void show(int *vet, long size);
void process(int x, short v, int *pos);

int i = 0;
short vetA[5] = {28, 42, 16, 23, 47};
int vetB[5] = {0, 0, 0, 0, 0};

int main() {
    short v;

    while (i < 5) {
        v = vetA[i] << 2;
        // A função "printf" altera registradores, portanto não será usada
        // printf("Iteração %d, v = %d\n", i, (int)v);
        process(i, v, &vetB[i]);
        i++;
    }

    show(vetB, 5);

    return 0;
}