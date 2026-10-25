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
    return 0;
}

// Given a file path, read a `.csv` file and load
// it into memory as a hash table
// Assumes there are column names and no row indices
void read_csv(char *filepath) {
    // Open and read the file
    FILE *fp = fopen(filepath, "r");
    if (fp == NULL) {
        // Temporary assignment for error handling
        // Will switch to something else when the function return
        // type is finalized
        fp = NULL;
    }


    // Get the first row of the dataset (the column names)
    char *row;
    char columns_buffer[MAX_ROW_SIZE + 1]; // Never forget to account for the null terminator '\0'
    char *columns = fgets(columns_buffer, sizeof(columns_buffer), fp);

    // Strip the newline char from the end of the row
    int columns_size = sizeof(columns);
    char last_char = columns[columns_size - 1];
    if (last_char == '\n') {
        columns[columns_size - 1] = 0;
    }

    printf("COLUMN NAMES: %s\n", columns);

    // Assign each column name to its corresponding index in the `table` hash table
    char *table[MAX_HASH_INDICES];
    unsigned int index = 0;
    char *column_name = strtok(columns, ",");
    while (column_name != NULL) {
        column_name = strtok(NULL, ","); // Grab individual columns
        printf("Assigning %s to index %i\n", column_name, index);
        table[index] = column_name;
        index++;
    }

    // Remove NULL indices from the hash table

    // Iterate starting with i = 1 (not i = 0)

    // Now we need a hash function for assigning the column data
    // by column name
}
