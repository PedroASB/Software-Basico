#include <stdio.h>

union U {
    short s[4];
    char c[20];
    int i[3][2];
};

union U var;

int main() {
    var.i[0][0] = 1024;
    var.i[1][1] = 42;
    var.s[0] = 125;
    var.s[1] = -93;

    printf("i[0][0] = %d\n", var.i[0][0]);
    printf("i[1][1] = %d\n", var.i[1][1]);
    printf("s[0] = %d\n", var.s[0]);
    printf("s[1] = %d\n", var.s[1]);

    var.c[3] = 0x00;

    printf("---\n");
    printf("i[0][0] = %d\n", var.i[0][0]);
    printf("i[1][1] = %d\n", var.i[1][1]);
    printf("s[0] = %d\n", var.s[0]);
    printf("s[1] = %d\n", var.s[1]);

    var.c[12] = 57;

    printf("---\n");
    printf("i[0][0] = %d\n", var.i[0][0]);
    printf("i[1][1] = %d\n", var.i[1][1]);
    printf("s[0] = %d\n", var.s[0]);
    printf("s[1] = %d\n", var.s[1]);

    return 0;
}

