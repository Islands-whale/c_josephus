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
        person[i]->name = (char*)malloc(10 * sizeof(char));
    }
    return person;
}

void person_destroy(Person **this, unsigned count){    // TODO
    for (int i = 0; i < count; i++){
        free(this[i]->name);
        free(this[i]);
    }
    free(this);
}

void person_create(Person *this, char *target){
    char *info;
    info = strtok(target, ",");
    strcpy(this->name, info);
    info = strtok(NULL, ",");
    this->age = atoi(info);
}

void person2str(Person *this, char *target){
    strcpy(target, "name:");
    strcat(target, this->name);
    strcat(target, "    age:");
    char str[3];
    itoa(this->age, str, 10);
    strcat(target, str);
}