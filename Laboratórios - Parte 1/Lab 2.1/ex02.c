#include <ctype.h>
#include <stdio.h>

int old_string2num(char *s) {
    int a = 0;
    for ( ; *s; s++) { // Enquanto *s for diferente de zero
        a = a * 10 + (*s - '0');
        printf("*s: %d || a: %d\n", *s, a);
    }
    return a;
}

int string2num(char *s, int base) {
    int a = 0;
    for ( ; *s; s++) {
        if (isalpha(*s)) 
            a = a * base + (*s - 'a' + 10); // (*s - 87)
        else a = a * base + (*s - '0');
    }
    return a;
}

int main () {
    // printf("==> %d\n", string2num("1234"));
    // printf("==> %d\n", string2num("1234") + 1);
    // printf("==> %d\n", string2num("1234") + string2num("1"));

    printf("%d\n", string2num("1111", 2));
    printf("%d\n", string2num("777", 8));
    printf("%d\n", string2num("777", 10));

    // A maior base que pode ser representada 
    // utilizando 36 dígitos (0, 1, ..., 9, A, B, ..., Z) é 36
    printf("%d\n", string2num("1a", 16));
    printf("%d\n", string2num("a09b", 16));
    printf("%d\n", string2num("k09b", 36));
    return 0;
}