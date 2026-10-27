#ifndef CSV_H
#define CSV_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COL_SIZE 1000
#define MAX_ROW_SIZE 500
#define MAX_COLS 30

// This is some sort of hybrid between an arena allocator and a hash table
// (no idea if that's even semantically correct tbh... probably not)
// to avoid scattering the memory all over the heap, and instead just scatter it a lil bit

// It's essentially a hash table where all the memory is allocated upfront, where only
// a single malloc is required and you don't end up with what Casey Muratori would
// call a "pointer jungle".

// This is likely very overcomplicated for this specific application, but it's a good
// exercise for when I do the better alternative and just make a memory arena instead
typedef struct Table {
    char column_name[MAX_COLS];
    char *data[MAX_COL_SIZE];
} Table;


char *strip_newline(char *text);
void assign_row_to_table(char *row, int row_index, int num_columns, Table *table);
Table *csv_load(FILE *file_pointer);

#endif
