//hashmap.h
#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct Node{
    struct Node *next;
    void *value;
    void *associated;
    size_t value_size;
    size_t associated_size;
} Node; 

enum size{
    SMALL = 32749,
    STANDARD = 110503,
    LARGE = 216091,
};

typedef struct Hashmap{
    size_t size;
    Node **map;
} Hashmap;

Hashmap *init(size_t size);
void reset(Hashmap *hashmap);

void insert(Hashmap *hashmap, const char *str, size_t size);
void delete(Hashmap *hashmap, const char *str, size_t size);
void *modify(Hashmap *hashmap, const char *str, size_t size);