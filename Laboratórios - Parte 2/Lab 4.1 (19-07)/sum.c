#include <stdio.h>

int sum(const char *prefix, int v1, short v2, int *s) {
    int r = v1 * v2;
    *s = v1 + v2;
    printf("%s: %d\n", prefix, *s);
    return r;
}

void show(int err, int r) {
    printf("err = %d, r = %d\n", err, r);
    return;
}