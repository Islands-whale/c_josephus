#ifndef __PERSON_H__
#define __PERSON_H__

typedef struct{
    char *name;
    unsigned age;
}Person;

void person_new(Person*);
void person_destroy(Person*);
void person_create(Person*, char*);
void person2str(Person*, char *);

#endif