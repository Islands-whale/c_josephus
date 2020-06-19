#include <stdio.h>
#include <stdlib.h>
#include "src/person.h"
#include "src/josephus.h"
#include "src/file_reader.h"

int main(){
    unsigned count = 0;
    char *path = "data/people.txt";
    reader_get_line_count(path, &count);

    Reader *reader = reader_new();
    reader_create(reader, path, count);

    Person **person = person_new(count);
    reader_get_people_data(reader, person);
    
    char **info;
    Josephus *ring = josephus_new(count, &info);
    josephus_create(ring, 1, 2, count);
    
    for (int i = 0; i < count; ++i){
        person2str(person[i], info[i]);
        josephus_add(ring, info[i]);
    }

    char **result = (char**)malloc(count * sizeof(char*));
    josephus_sort(ring, &result);

    printf("\nThe sequence after sorting is:\n");
    for (int i = 0; i < count; i++){
        printf("Eliminate:%d  ", i + 1);
        printf("%s\n", result[i]);
    } 

    person_destroy(person, count);
    josephus_destroy(ring);
    reader_destroy(reader);
    free(result);

    return 0;
}