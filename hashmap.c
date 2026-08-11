#include "hashmap.h"

size_t hashfunction(Hashmap *hashmap, const char *str, size_t size){
    size_t hash = 0;
    for(size_t i = 0; i < size_t; i++){
        hash = hash*((unsigned char)(str[i])) + ((unsigned char)(str[i]));
    }
    return (hash%(hashmap->size));
}

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


