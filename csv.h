#ifndef CSV_H
#define CSV_H

#include "headers/csv.h"
#include <stdio.h>

#define MAX_ROW_SIZE 1000

// This is some sort of hybrid between an arena allocator and a hash table
// (no idea if that's even semantically correct tbh)
// to avoid scattering the memory all over the heap, and instead just scatter it a lil bit

// We use `EntryNode` here so that we can access the data by column name.
// After a user points to an `EntryNode`, (which, again, only contains the column's name)
// you then point to the allocated space of data found in `Node`

// Pretty sure I'm greatly overcomplicating this, but I really want
// the ability to refer to column names in this project, as the Boston dataset
// has way more columns than the Salary dataset
typedef struct Node {
    char data[MAX_ROW_SIZE];
} Node;

typedef struct EntryNode {
    char *column_name;
    Node *node;
} EntryNode;


// CSV handling
char *strip_newline(char *text);
void load_csv(FILE *file_pointer);


#endif
