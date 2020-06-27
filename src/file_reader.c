#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "file_reader.h"

struct _Reader{
    char path[20];
    unsigned count;
};

int reader_get_line_count(const char *path, unsigned *count){
    int i = 0;
    FILE *fp;
    char buff[255];

    if((fp = fopen(path, "r")) == NULL)
        return ENOFILE;

    while (fgets(buff, 256, fp) != NULL){
        i++;
    }
    *count = i;

    fclose(fp);
    return SUCCESS;
}

Reader reader_new(){
    Reader reader = (Reader)malloc(sizeof(struct _Reader)); 
    return reader;
}

void reader_destroy(Reader this){
    free(this);
}

void reader_init(Reader this, const char *path, unsigned count){  //TODO  unsigned
    strcpy(this->path, path);
    this->count = count;
}

int reader_get_people_data(Reader this, Person *target){
    FILE *fp;
    char buff[255];
    
    if((fp = fopen(this->path, "r")) == NULL)
        return ENOFILE;

    for(int i = 0; i < this->count; ++i){
        fgets(buff, 256, fp);
        person_init(target[i], buff);
    }

    fclose(fp); 
    return SUCCESS;
}