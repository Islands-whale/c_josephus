#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_reader.h"

void reader_get_line_count(const char *path, unsigned *count){
    int i = 0;
    char buff[255];
    FILE *fp = fopen(path, "r");

    while (fgets(buff, 256, fp) != NULL){
        i++;
    }
    *count = i;
    fclose(fp);
}

void reader_new(Reader *this){
    this->path = (char*)malloc(20 * sizeof(char));
}

void reader_destroy(Reader *this){
    free(this->path);
}

void reader_create(Reader *this, char *path, unsigned count){
    strcpy(this->path, path);
    this->count = count;
}

void reader_get_people_data(Reader *this, Person *target){
    char buff[255];
    FILE *fp = fopen(this->path, "r");

    for(int i = 0; i < this->count; ++i){
        fgets(buff, 256, fp);
        person_create(&target[i], buff);
    }

    fclose(fp);
}