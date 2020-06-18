#include "josephus.h"

// struct Josephus{
//     unsigned current_id;
//     unsigned step;
//     list_uint_t people;
// };

void josephus_new(Josephus *this){
    this->info = (char**)malloc(this->count * sizeof(char*));
    for (int i = 0; i < this->count; i++){
        this->info[i] = (char*)malloc(20 * sizeof(char));
    }
}

void josephus_destroy(Josephus *this){
    for (int i = 0; i < this->count; i++){
        free(this->info[i]);
    }
    free(this->info);
}

void josephus_create(Josephus *this, unsigned start, unsigned step, unsigned count){
    this->current_id = start -1;
    this->step = step;
    this->count = count;
}

void josephus_add(Josephus *this, char *target){
    array_uint_push_back(this->people, target);
}

void josephus_pop(Josephus *this, unsigned pop_id, char **target){
    array_uint_pop_at(target, this->people, pop_id);
}

int josephus_len(Josephus *this){
    int length = array_uint_size(this->people);
    return length;
}

char** josephus_sort(Josephus *this){
    int up_bound = josephus_len(this);
    char **result = (char**)malloc(up_bound * sizeof(char*));
    for (int i = 0; i < up_bound; ++i){
        this->current_id = (this->current_id + this->step - 1) % josephus_len(this);
        josephus_pop(this, this->current_id, &result[i]);
    }
    return result;
}
