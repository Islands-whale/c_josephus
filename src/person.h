#ifndef __PERSON_H__
#define __PERSON_H__

#define SUCCESS 0
#define FAILURE -1

typedef struct Person Person;

Person** person_new(unsigned);
int person_destroy(Person**, unsigned);  
int person_create(Person*, char*);
int person2str(Person*, char *);

#endif