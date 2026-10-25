#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

#include "headers/csv.h"
#include "headers/arena.h"

int main(void) {
    read_csv("data/Salary_dataset.csv");
    return 0;
}

// First, you need to find a generic way to read the csv into memory
// Resource: https://stdin.top/posts/csv-in-c/

// THEN you can think about the linear regression and doing all of that in
// memory. You can use the idea of an arena as inspiration, but you need
// to figure out how you'd actually implement that idea into this use case
// after studying the linear regression equations

// Begin with simple linear regression, then you can move onto multiple
// linear regression

unsigned int hash(const char *column) {

}

// Given a file path, read a `.csv` file and load
// it into memory as a hash table
void read_csv(char *filepath) {
    FILE *fp = fopen(filepath, "r");
    if (fp == NULL) {
        // Temporary assignment for error handling\
        // Will switch to something else when ready
        fp = NULL;
    }

    // Declare the hash table, which will store the column names
    char *table[MAX_COLS];

    // Assign the column names to the corresponding hash index


    // Now we need a hash function for assigning the column data
    // by column name

    char *row;
    char row_buffer[MAX_ROWS + 1];
    size_t row_buffer_size = sizeof(row_buffer);
}
