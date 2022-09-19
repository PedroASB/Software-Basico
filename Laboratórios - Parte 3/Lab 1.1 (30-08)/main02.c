#include <stdio.h>
#include "data.h"

// gcc -no-pie main02.c data.c -o main02 && ./main02
// gcc -no-pie main02.c data.S -o main02-asm && ./main02-asm

struct data d1 = {3, {1, 2, 3, 0, 0} };
struct data d2 = {5, {10, 20, 30, 40, 50} };

void show(struct data *d);

int main() {
    show(&d1);
    printf("---\n");
    show(&d2);

    return 0;
}