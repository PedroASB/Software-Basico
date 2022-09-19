#include <stdio.h> 

// circular left shift
unsigned char rotate_left(unsigned char x, int n) {
    unsigned char temp;

    for (int i = 1; i <= n; i++) {
        temp = 0b10000000 & x;
        temp = temp >> 7;
        x = x << 1;
        x = x | temp;
    }

    return x;
    // return (x << n) | (x >> (8 - n));
}

int main() {
    unsigned char uc = 0x61; // 0110 0001

    printf("uc = 0x%08X\n\n", uc);

    // Rotate left de 1 bit = 0xC2 (1100 0010)
    printf(">>> 0x%08X\n", rotate_left(uc, 1));

    // Rotate left de 2 bits = 0x85 (1000 0101)
    printf(">>> 0x%08X\n", rotate_left(uc, 2));

    // Rotate left de 3 bits = 0x85 (0000 1011)
    printf(">>> 0x%08X\n", rotate_left(uc, 3));

    // Rotate left de 7 bits = 0xB0 (1011 0000) 
    printf(">>> 0x%08X\n", rotate_left(uc, 7));

    return 0;
}