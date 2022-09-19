#include <stdio.h>
#include "common.h"

// gcc -no-pie main.c common.c compare.c -o main && ./main

rfid_object_t gObj;

int main()
{

    printf("sizeof(guid_t)) = %ld\n", sizeof(guid_t));
    printf("sizeof(rfid_object_t) = %ld\n", sizeof(rfid_object_t));

    return 0;

    rfid_object_t lObj;
    short pins[2][3];

    init_obj(&gObj, 0);
    init_obj(&lObj, 2);
    init_pins(pins);

    if (compare_guid(&gObj.id, &lObj.id))
        printf("Objetos iguais!\n");

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            if (pins[i][j] == lObj.pin)
            {
                printf("Pin conhecido!\n");
                goto fim_main;
            }

fim_main:

    return 0;
}
