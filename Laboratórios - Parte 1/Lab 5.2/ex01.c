#include <stdio.h>

struct S {
    // Exemplo A
    // long  a;
    // char  b;  
    // int   c;
    // short d;

    // Exemplo B
    char  c[3];
    int   a;
    union {
        char x[9];
        long y;
    } d;
    short b;
};

void offsets(struct S *ptr) {
    // &(*ptr).a == &ptr->a
    // Deve-se usar "unsigned long" para armazenar o valor dos endereços
    printf("Offset de \"a\": %lu\n", (unsigned long) &ptr->a - (unsigned long) ptr);
    printf("Offset de \"b\": %lu\n", (unsigned long) &ptr->b - (unsigned long) ptr);
    printf("Offset de \"c\": %lu\n", (unsigned long) &ptr->c - (unsigned long) ptr);
    printf("Offset de \"d\": %lu\n", (unsigned long) &ptr->d - (unsigned long) ptr);
}

//----------------------------------------------
// Cria a variável varS
struct S varS;

int main() {
    offsets(&varS);
    return 0;
}
