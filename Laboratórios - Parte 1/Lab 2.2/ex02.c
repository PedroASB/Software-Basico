#include <stdio.h>
#include <ctype.h>
#include <string.h>

void num2string(int num, int base, char *resp) {
    memset(resp, 0, sizeof(resp));

    if (num >= base) 
        num2string(num / base, base, resp);

    char digit[2];

    if (num % base < 9)
        sprintf(digit, "%d", num % base);
    else
        sprintf(digit, "%c", 'a' - 10 + num % base);

    strcat(resp, digit);
}

int main () {
    char buf[128];

    num2string(1024, 2, buf);
    printf("==> %s\n", buf);

    num2string(1024, 16, buf);
    printf("==> %s\n", buf);

    num2string(1024, 32, buf);
    printf("==> %s\n", buf);

    return 0;
}