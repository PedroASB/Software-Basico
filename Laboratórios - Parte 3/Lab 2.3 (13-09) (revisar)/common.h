#ifndef COMMON_H
#define COMMON_H

struct guid_s // SIZE = 16 (align 4)
{
    unsigned int part1;     // +0
    unsigned short part2;   // +4
    unsigned short part3;   // +6
    unsigned char part4[8]; // +8
};

typedef struct guid_s guid_t;

struct rfid_object_s // SIZE = 24 (align 4)
{
    char enabled; // +0
                  // +3 bytes de padding
    guid_t id;    // +4
    short pin;    // +20
                  // +2 bytes de padding
};

typedef struct rfid_object_s rfid_object_t;

void init_obj(rfid_object_t *obj, int base);

void init_pins(short pins[2][3]);

int compare_guid(guid_t *id1, guid_t *id2);

#endif