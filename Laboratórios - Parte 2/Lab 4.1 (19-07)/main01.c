#include <stdio.h>

// gcc -no-pie main01.c sum.c -o main01 && ./main01
// gcc -no-pie main01.S sum.c -o main01-asm && ./main01-asm

int sum(const char *prefix, int v1, short v2, int *s);
void show(int err, int r);

int val = 432;
short age = 4;
int r = 0;
int err = 0;

int main() {
    err = sum("Hello", val, age, &r);
    show(err, r);
    return 0;
}