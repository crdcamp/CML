#ifndef ARENA_H
#define ARENA_H
#include <stddef.h>
#include <stdint.h>

#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b

// https://www.bytesbeneath.com/p/the-arena-custom-memory-allocators
typedef struct {
    uint8_t *size; // Unsigned 8 bit integer: https://medium.com/@sami.hamdiapps/a-deep-dive-into-uint8-t-in-c-mastering-the-basics-4605edb7b14d
    size_t offset; // Tracks the amount of memory used
    size_t capacity; // Maximum size of the arena

} Arena;

void *arena_alloc(size_t size);

#endif
