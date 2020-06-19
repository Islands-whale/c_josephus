#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

struct Person{
    char *name;
    unsigned age;
};

Person** person_new(unsigned count){
    Person **person = (Person**)malloc(count * sizeof(Person*));

    for (int i = 0; i < count; i++){
        person[i] = (Person*)malloc(sizeof(Person));
        if(person[i] == NULL)
            return NULL;

        person[i]->name = (char*)malloc(10 * sizeof(char));
        if(person[i]->name == NULL)
            return NULL;
    }
    
    return person;
}

int person_destroy(Person **this, unsigned count){    // TODO
    for (int i = 0; i < count; i++){
        free(this[i]->name);
        free(this[i]);
    }
    free(this);

    return SUCCESS;
}

int person_create(Person *this, char *target){
    char *info;                                       //TODO
    info = strtok(target, ",");
    strcpy(this->name, info);

    info = strtok(NULL, ",");
    this->age = atoi(info);

    return SUCCESS;
}

int person2str(Person *this, char *target){
    strcpy(target, "name:");
    strcat(target, this->name);

    strcat(target, "    age:");
    char str[3];
    itoa(this->age, str, 10);
    strcat(target, str);
    
    return SUCCESS;
}