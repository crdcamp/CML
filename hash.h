#ifndef CSV_H
#define CSV_H

#include <stdio.h>

#define MAX_COL_NAME_SIZE 80
#define MAX_ROW_SIZE 1000

// This is some sort of hybrid between an arena allocator and a hash table
// (no idea if that's even semantically correct tbh)
// to avoid scattering the memory all over the heap, and instead just scatter it a lil bit
typedef struct Node {
    char column_name[MAX_COL_NAME_SIZE];
    char data[MAX_ROW_SIZE];
} Node;


// CSV handling
char *strip_newline(char *text);
void load_csv(FILE *file_pointer);


#endif
