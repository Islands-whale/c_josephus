#ifndef __PERSON_H__
#define __PERSON_H__

// typedef struct Person Person;

typedef struct{
    char *name;
    char *age;
}Person;

void person_new(Person*);
void person_destroy(Person*);
void person_create(Person*, char*);
void person2str(Person*, char *);

#endif