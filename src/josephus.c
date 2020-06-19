#include "josephus.h"

struct Josephus{
    unsigned current_id;
    unsigned step;
    char **info;        // TODO
    unsigned count;
    array_uint_t people;
};

Josephus* josephus_new(unsigned count, char ***info){
    Josephus *ring = (Josephus*)malloc(sizeof(Josephus));
    ring->info = (char**)malloc(count * sizeof(char*));
    for (int i = 0; i < count; i++){
        ring->info[i] = (char*)malloc(20 * sizeof(char));
    }
    *info = ring->info;
    return ring;
}

void josephus_destroy(Josephus *this){
    for (int i = 0; i < this->count; i++){
        free(this->info[i]);
    }
    free(this->info);
    free(this);
}

void josephus_create(Josephus *this, unsigned start, unsigned step, unsigned count){
    array_uint_init(this->people);
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
