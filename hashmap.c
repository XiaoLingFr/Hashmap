#include "hashmap.h"

void *init(size_t size){
    Hashmap *hashmap = calloc(1, sizeof(Hashmap));
    if(size == 1){
        hashmap->map = calloc(SMALL, sizeof(void *));
        hashmap->size = SMALL;
    }
    else{
        if(size == 2){
            hashmap->map = calloc(STANDARD, sizeof(void *));
            hashmap->size = STANDARD;
        }
        else{
            hashmap->map = calloc(LARGE, sizeof(void *));
            hashmap->map = LARGE;
        }
    }

    return hashmap;
}

