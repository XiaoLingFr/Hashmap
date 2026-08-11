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

void recursive_reset(Node *loc_current_end){
    if(loc_current_end == NULL){
        return;
    }
    else{
        recursive_reset(loc_current_end->next);
        free(loc_current_end);
    }
    return;
}

void reset(Hashmap *hashmap){
    for(size_t i = 0; i<hashmap->size; i++){
        recursive_reset((hashmap->map)[i]);
    }
    return;
}

void insert(Hashmap *hashmap, const char *str, size_t size){
    size_t loc_index = hashfunction(hashmap, str, size);
    Node *loc_current_end = (hashmap->map)[loc_index];

    if(loc_current_end == NULL){
        loc_current_end = calloc(1, size_t Node);
        ((hashmap->map)[loc_index]) = loc_current_end;


    }

    return;
}

void delete(Hashmap *hashmap, const char *str, size_t size){
    return;
}

void *modify(Hashmap *hashmap, const char *str, size_t size){
    Node *loc_current_end = NULL;
    return loc_current_end;
}