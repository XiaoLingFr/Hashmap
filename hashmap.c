#include "hashmap.h"

size_t hashfunction(Hashmap *hashmap, const char *str, size_t size){
    size_t hash = 0;
    for(size_t i = 0; i < size; i++){
        hash = hash*67 + ((unsigned char)(str[i]));
    }
    return (hash%(hashmap->size));
}

Hashmap *init(size_t size){
    Hashmap *hashmap = calloc(1, sizeof(Hashmap));
    if(hashmap != NULL){
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
                hashmap->size = LARGE;
            }
        }
    }

    return hashmap;
}

void recursive_reset(Node *loc_current_end){
    if(loc_current_end->next != NULL){
        recursive_reset(loc_current_end->next);   
    }
    free(loc_current_end->value);
    free(loc_current_end->associated);
    free(loc_current_end);
    return;
}

void reset(Hashmap *hashmap){
    for(size_t i = 0; i<hashmap->size; i++){
        if((hashmap->map)[i] != NULL){
            recursive_reset((hashmap->map)[i]);
        }
    }
    return;
}

bool insert(Hashmap *hashmap, const char *str, size_t size){
    size_t loc_index = hashfunction(hashmap, str, size);
    Node *loc_current_end = (hashmap->map)[loc_index];
    bool code = false;

    if(loc_current_end == NULL){
        //create node
        loc_current_end = calloc(1, sizeof(Node));
        ((hashmap->map)[loc_index]) = loc_current_end;

        //initialize node
        loc_current_end->value = calloc(size, sizeof(char));
        loc_current_end->value = memcpy(loc_current_end->value, str, size);
        loc_current_end->value_size = size;

        //insert
        loc_current_end->next = NULL;
    }
    else{
        bool exit = false;
        while(exit == false){
            //if this is not the correct node
            if(memcmp(loc_current_end->value, str, size) == 0){
                //if no continuation
                if(loc_current_end->next == NULL){
                    //create node
                    loc_current_end->next = calloc(1, sizeof(Node));
                    if(loc_current_end->next != NULL){
                        loc_current_end = loc_current_end->next;

                        //initialize node
                        loc_current_end->value = calloc(size, sizeof(char));
                        if(loc_current_end->value == NULL){
                            free(loc_current_end);
                        }
                        else{
                            loc_current_end->value = memcpy(loc_current_end->value, str, size);
                            loc_current_end->value_size = size;

                            //insert
                            loc_current_end->next = NULL;
                            code = true;
                        }
                    }
                    //exit
                    exit = true;
                }
                //continuation exists
                else{
                    loc_current_end = loc_current_end->next;
                }
            }
            //if correct node
            else{
                exit = true;
                code = true;
            }
        }
    }
    return code;
}

bool delete(Hashmap *hashmap, const char *str, size_t size){
    size_t loc_index = hashfunction(hashmap, str, size);
    Node *loc_current_end = (hashmap->map)[loc_index];
    Node *prev_current_end = NULL;
    bool code = false;

    if(loc_current_end != NULL){
        bool exit = false;
        while(exit == false){
            //if this is the correct node
            if(memcmp(loc_current_end->value, str, size) == 0){
                //if first node
                if(prev_current_end == NULL){
                    (hashmap->map)[loc_index] = loc_current_end->next;
                    free(loc_current_end->value);
                    free(loc_current_end->associated);
                    free(loc_current_end);
                }
                //if in middle or end
                else{
                    prev_current_end->next = loc_current_end->next;
                    free(loc_current_end->value);
                    free(loc_current_end->associated);
                    free(loc_current_end);
                }
                exit = true;
                code = true;
            }
            //if not the current node
            else{
                //if there is continuation
                if(loc_current_end->next != NULL){
                    prev_current_end = loc_current_end;
                    loc_current_end = loc_current_end->next;
                }
                //if there is no continuation
                else{
                    exit = true;
                }
            }
        }
    }
    
    return code;
}

void *modify(Hashmap *hashmap, const char *str, size_t size){
    size_t loc_index = hashfunction(hashmap, str, size);
    Node *loc_current_end = (hashmap->map)[loc_index];

    //if there is any stored in buckets
    if(loc_current_end != NULL){
        bool exit = false;
        while(exit == false){
            //if this is the correct node
            if(memcmp(loc_current_end->value, str, size) == 0){
                exit = true;
            }
            else{
                //if continuation does not exist
                if(loc_current_end->next == NULL){
                    loc_current_end = NULL;
                    exit = true;
                }
                //if continuation does exist
                else{
                    loc_current_end = loc_current_end->next;
                }
            }
        }
    }
    return loc_current_end;
}