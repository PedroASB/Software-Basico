#include <stdio.h>

unsigned int convertB2L(unsigned int x) {
    unsigned int bigEndian = 0;

    unsigned int a = x & 0x000000FF;
    unsigned int b = x & 0x0000FF00;
    unsigned int c = x & 0x00FF0000;
    unsigned int d = x & 0xFF000000;

    bigEndian |= (a << 24);
    bigEndian |= (b << 8);
    bigEndian |= (c >> 8);
    bigEndian |= (d >> 24);

    return bigEndian;
}

int main() {
    unsigned int b = 0x12AB34CD;
    unsigned int l = convertB2L(b);

    printf("b = 0x%08X\n", b);
    printf("l = 0x%08X\n", l);

    return 0;
}