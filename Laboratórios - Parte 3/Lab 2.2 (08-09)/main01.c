#include <stdlib.h>
#include <stdio.h>
#include "aux.h"

// gcc -no-pie main01.c aux.c -o main01 && ./main01
// gcc -no-pie main01.S aux.c -o main01-asm && ./main01-asm

void showPerson(struct Person *person);

void showCar(struct Car *car);

int main() {
    struct Person p;
    struct Car c[2];

    readPerson(&p);
    readCar(&c[0]);
    readCar(&c[1]);

    showPerson(&p);
    showCar(&c[0]);
    showCar(&c[1]);

    return 0;
}

void showPerson(struct Person *person) {
    printf("tipo = %d, ID = %ld, nome = '%s', idade = %d\n",
    person->type, person->ID, person->name, person->age);
}

void showCar(struct Car *car) {
    printf("tipo = %d, ID = %ld, nome = '%s', cor = '%s'\n",
    car->type, car->ID, car->name, car->color);
}