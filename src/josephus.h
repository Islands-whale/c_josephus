#ifndef __JOSEPHUS_H__
#define __JOSEPHUS_H__

#include "person.h"

typedef struct _Josephus *Josephus;

Josephus josephus_new();
void josephus_destroy(Josephus);
int josephus_init(Josephus, unsigned, unsigned);
int josephus_add(Josephus, Person);
int josephus_pop(Josephus, unsigned, Person*);
int josephus_len(Josephus);
void josephus_display(Josephus);
void josephus_sort(Josephus, Person*);

#endif 