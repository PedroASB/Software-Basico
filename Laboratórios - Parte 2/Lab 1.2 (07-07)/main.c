#include <stdio.h>

// gcc -no-pie main.c aux.c -o main && ./main
// gcc -no-pie main.c aux.S -o main-asm && ./main-asm

extern char str[];
void process();

int main() {
    process();
    printf("%s\n", str);
    return 0;
}