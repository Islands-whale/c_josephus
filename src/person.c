#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

#define SUCCESS 0

void person_new(Person *this){
    this->name = (char*)malloc(10 * sizeof(char));
}

void person_destroy(Person *this){
    free(this->name);
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