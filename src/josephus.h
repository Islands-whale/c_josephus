#ifndef __JOSEPHUS_H__
#define __JOSEPHUS_H__

#include "m-array.h"
#include "person.h"

ARRAY_DEF(array_person, Person, M_POD_OPLIST)

typedef struct _Josephus *Josephus;  // TODO 颜色

Josephus josephus_new();
void josephus_destroy(Josephus);
void josephus_init(Josephus, unsigned, unsigned);
void josephus_del(Josephus);
void josephus_add(Josephus, Person);
void josephus_pop(Josephus, unsigned, Person*);
int josephus_len(Josephus);
void josephus_display(Josephus);
void josephus_sort(Josephus, Person*);

#endif 