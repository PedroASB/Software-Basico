#ifndef AUX_H
#define AUX_H

struct Object {     // SIZE = 32
    int  type;      // +0
                    // +4 bytes de padding
    long ID;        // +8
    char name[16];  // +16
};

struct Person {     // SIZE = 40
    int  type;      // +0
                    // +4 bytes de padding
    long ID;        // +8
    char name[16];  // +16
    int age;        // +32
                    // +4 bytes de padding
};

struct Car {        // SIZE = 40
    int  type;      // +0
                    // +4 bytes de padding
    long ID;        // +8 
    char name[16];  // +16
    char color[8];  // +32
};

void readPerson(struct Person *ptr);

void readCar(struct Car *ptr);

#endif