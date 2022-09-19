#include <stdio.h>

/*
gcc -E macro.c -o macro.i
cat macro.i
*/

#define inc(x, y)   x++; y++
#define dobro(x)   (x + x)
#define calc(x, y) (x + y * 2)

int main(){

    int a = 10;
    int b = 20;
    if (a > 15)
        inc(a, b);
   /*
    if (a > 15)
        a++; b++;
    O "if" engloba apenas o "a++;"
    */

    printf("Linha 1: a = %d, b = %d\n", a, b);

    a = 10;
    b = 20;
    a = dobro(++b);
    // a = (++b + ++b);

    printf("Linha 2: a = %d, b = %d\n", a, b);

    a = 10;
    b = 20;
    b = calc(a, 1 + 5);
    // b = (a + 1 + 5 * 2);

    printf("Linha 3: a = %d, b = %d\n", a, b);

    return 0;
}