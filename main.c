#include <stdio.h>
#include <stdlib.h>

#include "src/error.h"
#include "src/person.h"
#include "src/josephus.h"
#include "src/file_reader.h"

int main(){
    unsigned count = 0;
    const char *path = "data/people.txt";
    if(reader_get_line_count(path, &count) != SUCCESS){
        printf("Failed to open the file\n");
        return 0;
    }

    Person *person = person_new(count);
    Josephus ring = josephus_new();
    Reader reader = reader_new();

    // if (person == NULL || ring == NULL || reader == NULL){
    //     printf("Memory allocation error\n");
    //     return 0;
    // }

    reader_init(reader, path, count);
    if(reader_get_people_data(reader, person) != SUCCESS){
        printf("Get people data error\n");
        return 0;
    }

    josephus_init(ring, 1, 2);
    for (int i = 0; i < count; ++i){
        josephus_add(ring, person[i]);
    }

    printf("\nThe sequence before sorting is:\n");
    josephus_display(ring);

    Person result[count];
    josephus_sort(ring, result);

    char str[20];
    printf("\nThe sequence after sorting is:\n");
    for (int i = 0; i < count; i++){
        printf("Eliminate:%d  ", i + 1);
        person2str(result[i], str);
        printf("%s\n", str);
    } 

    person_destroy(person, count);
    josephus_destroy(ring);
    reader_destroy(reader);

    return 0;
}