#include <stdio.h>

// gcc -no-pie main01.c max.c -o main01 && ./main01
// gcc -no-pie main01.S max.c -o main01-asm && ./main01-asm

int maximo(char x, char y);
char a = 97;
char b = 105;

int main() {
    int ret = maximo(a, b);

    if (ret == a)
        printf("'a' maior do que 'b'\n");

    else
        printf("Valor de 'b': %d\n", (int)b);

    return 0;
}