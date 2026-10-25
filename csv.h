#ifndef CSV_H
#define CSV_H

#include <stdio.h>

#define MAX_ROW_SIZE 1000

// This is some sort of hybrid between and arena allocator and a hash table
// (no idea if that's even semantically correct tbh)
// to avoid scattering the memory all over the heap
typedef struct node {
    struct node *rows[MAX_ROW_SIZE];
} node;

// CSV handling
char *strip_newline(char *text);
void load_csv(FILE *file_pointer);


#endif
