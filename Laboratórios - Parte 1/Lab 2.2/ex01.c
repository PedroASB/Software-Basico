#include <stdio.h>

int is_little() {
    short tmp = 0xAABB;

    unsigned char *p = (unsigned char *) &tmp;

    if (*p == 0xBB) 
        return 1;
    else
        return 0;
}

int main () {
    if (is_little())
        printf("Little-endian\n");
    else
        printf("Big-endian\n");
        
    return 0;
}