#include "josephus.h"
#include "person.h"

struct _Josephus{
    unsigned current_id;
    unsigned step;
    array_person_t people;
};

Josephus josephus_new(){
    Josephus ring = (Josephus)malloc(sizeof(struct _Josephus));
    return ring;
}

void josephus_destroy(Josephus this){
    free(this);
}

void josephus_init(Josephus this, unsigned start, unsigned step){
    array_person_init(this->people);
    this->current_id = start -1;
    this->step = step;
}

void josephus_del(Josephus this){
    array_person_clear(this->people);
}

void josephus_add(Josephus this, Person target){
    array_person_push_back(this->people, target); 
}

void josephus_pop(Josephus this, unsigned pop_id, Person *target){
    array_person_pop_at(target, this->people, pop_id);
}

int josephus_len(Josephus this){
    int length = array_person_size(this->people);
    return length;
}

void josephus_sort(Josephus this, Person *target){
    int upbound = josephus_len(this);
    for (int i = 0; i < upbound; ++i){
        this->current_id = (this->current_id + this->step - 1) % josephus_len(this);
        josephus_pop(this, this->current_id, &target[i]);
    }
}
