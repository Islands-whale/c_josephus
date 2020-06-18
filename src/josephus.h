#ifndef __JOSEPHUS_H__
#define __JOSEPHUS_H__

#include "m-array.h"
#include "person.h"

ARRAY_DEF(array_uint, char*)

typedef struct{
    unsigned current_id;
    unsigned step;
    char **info;
    unsigned count;
    array_uint_t people;
}Josephus;

void josephus_new(Josephus*);
void josephus_destroy(Josephus*);
void josephus_create(Josephus*, unsigned, unsigned, unsigned);
void josephus_add(Josephus*, char*);
void josephus_pop(Josephus*, unsigned, char**);
int josephus_len(Josephus*);
char** josephus_sort(Josephus*);

#endif