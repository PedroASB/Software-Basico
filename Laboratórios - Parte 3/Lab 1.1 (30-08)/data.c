#include <stdio.h>
#include "data.h"

void show(struct data *d) {
    int i;
    long *ptr = d->elems;

    for (i = 0; i < d->len; i++) {
        printf("%ld\n", ptr[i]);
    }
}