#ifndef __PERSON_H__
#define __PERSON_H__

typedef struct Person Person;

Person** person_new(unsigned);
void person_destroy(Person**, unsigned);  
void person_create(Person*, char*);
void person2str(Person*, char *);

#endif