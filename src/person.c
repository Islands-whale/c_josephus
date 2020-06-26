#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

struct _Person{
    char *name;
    unsigned age;
};

Person* person_new(unsigned count){
    Person *person = (Person*)malloc(count * sizeof(Person));

    for (int i = 0; i < count; i++){
        person[i] = (Person)malloc(sizeof(struct _Person));
        if(person[i] == NULL)
            return NULL;

        person[i]->name = (char*)malloc(10 * sizeof(char));
        if(person[i]->name == NULL)
            return NULL;
    }
    
    return person;
}

void person_destroy(Person *this, unsigned count){    // TODO
    for (int i = 0; i < count; i++){
        free(this[i]->name);
        free(this[i]);
    }
    free(this);
}

void person_init(Person this, char *target){
    // char *info;                                       //TODO
    // info = strtok(target, ",");
    // strcpy(this->name, info);

    // info = strtok(NULL, ",");
    // this->age = atoi(info);

    char info[10];                                       //TODO
    sprintf(info, "%s", strtok(target, ","));
    strcpy(this->name, info);

    sprintf(info, "%s", strtok(NULL, ","));
    this->age = atoi(info);
}

void person2str(Person this, char *target){
    strcpy(target, "name:");
    strcat(target, this->name);

    strcat(target, "    age:");
    char str[3];
    itoa(this->age, str, 10);
    strcat(target, str);
}