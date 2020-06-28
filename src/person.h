#ifndef __PERSON_H__
#define __PERSON_H__

typedef struct _Person *Person;

Person* person_new(unsigned);
void person_destroy(Person*, unsigned);  
int person_init(Person, char*);
void person2str(Person, char*);
char* person_get_name(Person);
int person_get_age(Person);

#endif