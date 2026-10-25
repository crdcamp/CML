#ifndef ARENA_H
#define ARENA_H
#include <stddef.h>
#include <stdint.h>

typedef struct Arena {
    uint8_t *base;
    size_t size;
    size_t used;
} Arena;

// Simply start with the arena initialization
Arena *arena_init(size_t size);

#endif
