#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node{
    struct Node *next;
    void *value;
    void *associated;
    size_t value_size;
    size_t associated_size;
} Node;

enum size{
    SMALL = 32749;
    STANDARD = 110503;
    LARGE = 216091;
}

typedef struct Hashmap{
    size_t size;
    void *map;
} Hashmap;