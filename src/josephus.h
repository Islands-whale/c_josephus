#ifndef __JOSEPHUS_H__
#define __JOSEPHUS_H__

#include "m-array.h"
#include "person.h"

ARRAY_DEF(array_uint, char*)

typedef struct Josephus Josephus;  // TODO 1首字母 2颜色

Josephus* josephus_new(unsigned, char***);
void josephus_destroy(Josephus*);
void josephus_create(Josephus*, unsigned, unsigned, unsigned);
void josephus_add(Josephus*, char*);
void josephus_pop(Josephus*, unsigned, char**);
int josephus_len(Josephus*);
void josephus_sort(Josephus*, char***);

#endif