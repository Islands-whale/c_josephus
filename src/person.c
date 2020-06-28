#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "person.h"

struct _Person{
    char name[10];
    unsigned age;
};

Person* person_new(unsigned count){                     // TODO
    Person *person = (Person*)malloc(count * sizeof(Person));

    for (int i = 0; i < count; i++){
        person[i] = (Person)malloc(sizeof(struct _Person));
        if(person[i] == NULL)
            return NULL;
    }
    
    return person;                                      //TODO
}

void person_destroy(Person *this, unsigned count){    
    for (int i = 0; i < count; i++){
        free(this[i]);
    }
    free(this);
}

int person_init(Person this, char *target){
    // char *info;                                       //TODO
    // info = strtok(target, ",");
    // strcpy(this->name, info);
    // info = strtok(NULL, ",");
    // this->age = atoi(info);

    char info[10];                                       
    sprintf(info, "%s", strtok(target, ","));
    strcpy(this->name, info);

    sprintf(info, "%s", strtok(NULL, ","));
    if (atoi(info) <= 0)
        return EINVAL;

    this->age = atoi(info);
    return SUCCESS;
}

void person2str(Person this, char *target){
    strcpy(target, "name:");
    strcat(target, this->name);

    strcat(target, "    age:");
    char str[3];
    itoa(this->age, str, 10);
    strcat(target, str);
}

char* person_get_name(Person this){
    return this->name;
}

int person_get_age(Person this){
    return this->age;
}