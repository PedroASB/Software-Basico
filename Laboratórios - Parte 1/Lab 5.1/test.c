#include <stdio.h>

typedef struct {
    int   a;
    short b;
    int   c;
} Estrutura;

// Estrutura var = {15, 12, 7};
Estrutura var = {
    .c = 7,
    .b = 12,
    .a = 15
};

int main() {

    printf("%d %hd %d\n", var.a, var.b, var.c);

    return 0;
}