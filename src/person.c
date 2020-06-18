#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

#define SUCCESS 0

// struct Person{
//     char *name;
//     int *age;
// };

void person_new(Person *this){
    this->name = (char*)malloc(10 * sizeof(char));
    this->age = (char*)malloc(10 * sizeof(char));
}

void person_destroy(Person *this){
    free(this->name);
    free(this->age);
}

void person_create(Person *this, char *target){
    char *info;
    info = strtok(target, ",");
    strcpy(this->name, info);
    info = strtok(NULL, ",");
    strcpy(this->age, info);
}

void person2str(Person *this, char *target){
    strcpy(target, "name:");
    strcat(target, this->name);
    strcat(target, "    age:");
    strcat(target, this->age);
}