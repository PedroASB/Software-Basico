#include <stdio.h>

int odd_ones(unsigned int x) {
    // unsigned int temp = 0x00000001;
    int counter = 0;

    for (int i = 0; i < 32; i++) {
        // if (x & temp) counter++;
        if (x & (1 << i))
            counter++;
        // temp <<= 1;
    }

    return counter & 1;
}

int main() {
    unsigned int v;

    v = 0x01010101;
    printf("%X tem número %s de bits 1\n", v, odd_ones(v) ? "impar" : "par");

    v = 0x01030101;
    printf("%X tem número %s de bits 1\n", v, odd_ones(v) ? "impar" : "par");

    return 0;
}