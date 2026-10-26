#ifndef CSV_H
#define CSV_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CELL_SIZE 80
#define MAX_ROW_SIZE 1000
#define MAX_COLS 30

// This is some sort of hybrid between an arena allocator and a hash table
// (no idea if that's even semantically correct tbh... probably not)
// to avoid scattering the memory all over the heap, and instead just scatter it a lil bit
typedef struct Table {
    char column_name[MAX_CELL_SIZE];
    char *data[MAX_ROW_SIZE];
} Table;


char *strip_newline(char *text);
Table *csv_load(FILE *file_pointer);
void csv_unload(Table *table);

#endif
