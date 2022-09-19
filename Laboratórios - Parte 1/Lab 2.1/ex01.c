#include <stdio.h>

void dump(void *addr, int n) {
    unsigned char *p = (unsigned char *) addr;
    while (n--) {
        printf("%p - %02x\n", p, *p);
        p++;
    }
}

int main() {
    // Cada byte: varia de 0x00 a 0xFF (0 a 255) 
    int i = 0x45CDA8B1;
    // long i = 255;
    // short i = 255;
    // char i = 'a'; 
    // 97 = 0x61

    // A saída exibe o endereço de cada byte, seguido pelo valor que está contido nele
    // dump(&i, sizeof(i));

    char p[] = "10"; // Há sempre um byte ao final que representa o fim da string ('\0')
    // 'A' - 0x41 (65)
    // '' - 0x00 (0)
    // '\n' - 0x0A (15)
    // '$' - 0x24 (36)
    dump(p, sizeof(p));
    return 0;
}