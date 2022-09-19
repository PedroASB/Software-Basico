#include <stdio.h>
#include <stdint.h>

typedef unsigned char byte; // %hhu

int main() {
    byte a, b, r;

//    Operador & (AND)
//    Testar bits
    printf("Testando bits\n");
    a = 0b10001000;
    b = 0b00000100;
    if (a & 0x04) /* a & b ---- a & (1<<2) */
        printf("1\n\n");
    else
        printf("0\n\n");

//    Operador & (AND)
//    Extrair uma parte do valor
    printf("Extraindo uma parte do valor\n");
    a = 0b11110101;
    b = 0b00111100;
    r = 0b00110100;
    printf("%hhu (%hhu)\n\n", a & b, r);

//    Operador | (OR)
//    Ativar bits
    printf("Ativando bits\n");
    a = 0b00001111;
    r = 0b10001111;
    printf("%hhu (%hhu)\n\n", a | 0b10000000, r);

//    Operador | (OR)
//    Fundir valores
    printf("Fundindo valores\n");
    a = 0b11000001;
    b = 0b00110010;
    r = 0b11110011;
    printf("%hhu (%hhu)\n", a | b, r);

    return 0;
}

int exemplo_da_aula() {
    uint8_t tmp1, tmp2, tmp3;
    uint8_t a, c, r;
    uint16_t b;

    a = (uint8_t) 0b00101000;
    b = (uint16_t) 0b0000000111000000;
    c = (uint8_t) 0b00001001;

    tmp1 = (a >> 3) & 0b00000111;
//    tmp1 = (a >> 3) & 0x07;

    tmp2 = (b >> 3) & 0b00111000;
//    tmp2 = (b >> 3) & 0x38;

    tmp3 = ((c & 0b00000001) << 2 ) | (c & 0b00001000);
//    tmp3 = ((c & 0x1) << 2) | (c & 0x8);
    tmp3 = tmp3 << 4;
//    tmp3 <<= 4;

    r = tmp1 | tmp2 | tmp3;

    printf("r = %d\n(%d)", r, 0b11111101);

    return 0;
}
