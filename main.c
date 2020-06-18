#include <stdio.h>
#include <stdlib.h>
#include "src/person.h"
#include "src/josephus.h"
#include "src/file_reader.h"

int main(){
    unsigned count = 0;
    char *path = "data/people.txt";
    reader_get_line_count(path, &count);

    
    Reader reader;
    reader_new(&reader);
    reader_create(&reader, path, count);

    Person person[count];
    for (int i = 0; i < count; i++){
        person_new(&person[i]);
    }
    
    reader_get_people_data(&reader, person);

    Josephus ring;
    array_uint_init(ring.people);
    josephus_create(&ring, 1, 2, count);

    josephus_new(&ring);

    for (int i = 0; i < count; ++i){
        person2str(&person[i], ring.info[i]);
        josephus_add(&ring, ring.info[i]);  
    }

    char **temp = josephus_sort(&ring);
    printf("\nThe sequence after sorting is:\n");
    for (int i = 0; i < count; i++){
        printf("Eliminate:%d  ", i + 1);
        printf("%s", temp[i]);
    } 

    for (int i = 0; i < count; i++){
        person_destroy(&person[i]);
    }
    josephus_destroy(&ring);
    reader_destroy(&reader);
    free(temp);

    return 0;
}