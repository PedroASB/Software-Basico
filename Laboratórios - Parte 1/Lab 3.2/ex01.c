#include <stdio.h>
#include <stdlib.h>

 int xbyte(unsigned int word, int bytenum) {
     unsigned char temp = ((unsigned char*) &word)[bytenum];

    if (0b1000000 - temp > 0) { // Caso 1
        return (int) 0xFFFFFF00 + temp;
    }
    else if (0b11000000 - temp > 0) { // Caso 2
        return (int) temp * 256;
    }
    else { // Caso 3
        return (int) 0xFF00FFFF + (temp * 65536);
    }
}

int main(int argc, char **argv) {
    int x;

    x = xbyte(0x01ABCD02, 0);
    printf("0x%08X\n", x);    // 0xFFFFFF02 (caso 1)

    x = xbyte(0x01ABCD02, 1);
    printf("0x%08X\n", x);    // 0xFFCDFFFF (caso 3)

    x = xbyte(0x01ABCD02, 2);
    printf("0x%08X\n", x);    // 0x0000AB00 (caso 2)

    x = xbyte(0x11E032A5, 0);
    printf("0x%08X\n", x);    // 0x0000A500 (caso 2)

    x = xbyte(0x11E032A5, 1);
    printf("0x%08X\n", x);    // 0xFFFFFF32 (caso 1)

    x = xbyte(0x11E032A5, 2);
    printf("0x%08X\n", x);    // 0xFFE0FFFF (caso 3)

    x = xbyte(0x11E032A5, 3);
    printf("0x%08X\n", x);    // 0xFFFFFF11 (caso 1)

    x = xbyte(0xABCD, 3);
    printf("0x%08X\n", x);    // 0xFFFFFF00 (caso 1)

    x = xbyte(0xABCD, 1);
    printf("0x%08X\n", x);    // 0x0000AB00 (caso 2)

    return 0;
}