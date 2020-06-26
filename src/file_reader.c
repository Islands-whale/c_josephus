#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_reader.h"

struct _Reader{
    char *path;
    unsigned count;
};

int reader_get_line_count(const char *path, unsigned *count){
    int i = 0;
    FILE *fp;
    char buff[255];

    if((fp = fopen(path, "r")) == NULL)
        return FAILURE;

    while (fgets(buff, 256, fp) != NULL){
        i++;
    }
    *count = i;

    fclose(fp);
    return SUCCESS;
}

Reader reader_new(){
    Reader reader = (Reader)malloc(sizeof(struct _Reader)); 

    reader->path = (char*)malloc(20 * sizeof(char));
    if (reader->path == NULL)
        return NULL;
    
    return reader;
}

void reader_destroy(Reader this){
    free(this->path);
    free(this);
}

void reader_init(Reader this, const char *path, unsigned count){
    strcpy(this->path, path);
    this->count = count;
}

int reader_get_people_data(Reader this, Person *target){
    FILE *fp;
    char buff[255];
    
    if((fp = fopen(this->path, "r")) == NULL)
        return FAILURE;

    for(int i = 0; i < this->count; ++i){
        fgets(buff, 256, fp);
        person_init(target[i], buff);
    }

    fclose(fp); 
    return SUCCESS;
}