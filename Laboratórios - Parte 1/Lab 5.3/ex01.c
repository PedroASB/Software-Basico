#include <stdio.h>

struct X1 {
    char c1;
    int i;
    char c2;
};

struct X2 {
    long long l;
    char c;
};

struct X3 {
    int i;
    char c1;
    char c2;
};

struct X4 {
    struct X2 x;
    char c;
};

struct X5 {
    short s1;
    int i;
    int c[2][3];
    short s2;
};

union U1 {
    int i;
    char c[5];
};

union U2 {
    short s;
    char c[5];
};

union U3 {
    struct X3 x;
    union U2 u;
};

int main() {
    struct X1 x1 = {'a', 10, 'b'};
    struct X2 x2 = {125, 'c'};
    struct X3 x3 = {45, 'h', 'k'};
    struct X4 x4 = {470, 't', 'j'};
    struct X5 x5 = {90, 1572, {{1, 2, 3}, {4, 5, 6}}, 16};
    union U1 u1 = {.c = "abc"};
    union U2 u2 = {75};
    union U3 u3 = {.u.c = "def"};

    // X1
    printf("\nStruct X1 (size: %ld)\n", sizeof(struct X1));
    printf("Offset de \"c1\": %lu\n", (unsigned long long) &x1.c1 - (unsigned long long) &x1);
    printf("Offset de \"i\": %lu\n", (unsigned long long) &x1.i - (unsigned long long) &x1);
    printf("Offset de \"c2\": %lu\n", (unsigned long long) &x1.c2 - (unsigned long long) &x1);

    // X2
    printf("\nStruct X2 (size: %ld)\n", sizeof(struct X2));
    printf("Offset de \"l\": %lu\n", (unsigned long long) &x2.l - (unsigned long long) &x2);
    printf("Offset de \"c\": %lu\n", (unsigned long long) &x2.c - (unsigned long long) &x2);

    // X3
    printf("\nStruct X3 (size: %ld)\n", sizeof(struct X3));
    printf("Offset de \"i\": %lu\n", (unsigned long long) &x3.i - (unsigned long long) &x3);
    printf("Offset de \"c1\": %lu\n", (unsigned long long) &x3.c1 - (unsigned long long) &x3);
    printf("Offset de \"c2\": %lu\n", (unsigned long long) &x3.c2 - (unsigned long long) &x3);

    // X4
    printf("\nStruct X4 (size: %ld)\n", sizeof(struct X4));
    printf("Offset de \"x.l\": %lu\n", (unsigned long long) &x4.x.l - (unsigned long long) &x4);
    printf("Offset de \"x.c\": %lu\n", (unsigned long long) &x4.x.c - (unsigned long long) &x4);
    printf("Offset de \"c\": %lu\n", (unsigned long long) &x4.c - (unsigned long long) &x4);

    // X5
    printf("\nStruct X5 (size: %ld)\n", sizeof(struct X5));
    printf("Offset de \"s1\": %lu\n", (unsigned long long) &x5.s1 - (unsigned long long) &x5);
    printf("Offset de \"i\": %lu\n", (unsigned long long) &x5.i - (unsigned long long) &x5);
    printf("Offset de \"c\": %lu\n", (unsigned long long) &x5.c - (unsigned long long) &x5);
    printf("Offset de \"s2\": %lu\n", (unsigned long long) &x5.s2 - (unsigned long long) &x5);

    // U1
    printf("\nUnion U1 (size: %ld)\n", sizeof(union U1));
    printf("Offset de \"c\": %lu\n", (unsigned long long) &u1.c - (unsigned long long) &u1);

    // U2
    printf("\nUnion U2 (size: %ld)\n", sizeof(union U2));
    printf("Offset de \"s\": %lu\n", (unsigned long long) &u2.s - (unsigned long long) &u2);

    // U3
    printf("\nUnion U3 (size: %ld)\n", sizeof(union U3));
    printf("Offset de \"u.c\": %lu\n", (unsigned long long) &u3.u.c - (unsigned long long) &u3);

    printf("\n%ld, %ld, %ld\n", sizeof(int **), sizeof(int[2][3]), sizeof(x5.c));

    return 0;
}