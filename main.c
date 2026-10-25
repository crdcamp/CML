#include <stdlib.h>
#include <string.h>

#include "csv.h"

int main(void) {
    FILE *salary_file_pointer = fopen("data/Salary_dataset.csv", "r");
    load_csv(salary_file_pointer);
    fclose(salary_file_pointer);

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
    // Compare the name of the column to
    return 0;
}

// Load the csv into memory as a hash table and close the file pointer
void load_csv(FILE *file_pointer) {
    // Get the first row of the dataset (the column names)
    char columns_buffer[MAX_ROW_SIZE + 1]; // Never forget to account for the null terminator '\0'
    char *columns = fgets(columns_buffer, sizeof(columns_buffer), file_pointer);

    // Strip the `\n` from the end of the row if found
    int columns_size = strlen(columns);
    char last_char = columns[columns_size - 1];
    if (columns[columns_size - 1] == '\n') {
        columns[columns_size - 1] = 0;
    }
    else printf("Newline character now found for row: %s\n", columns);

    // Count the number of columns in the dataset for hash table assignment
    unsigned int columns_count = 1;
    for (int i = 0; i < columns_size; i++) {
        if (columns[i] == ',') {
            columns_count++;
        }
    }

    // Assign each column name to its corresponding index in the hash table
    char *column_token = strtok(columns, ",");
    char *table[columns_count];
    unsigned int index = 0;
    while (column_token != NULL) {
        table[index] = column_token;
        index++;
        column_token = strtok(NULL, ",");
    }

    // Iterate through the rest of the file and assign the results to the hash table
    // First, you need to check if the row is == `columns`, If it is, move onto the next
    // Don't forget to remove the newline character
    // You'll also need to work on the hash function part of the way through this
    // Final requirements:
    // Convert remove newline section to a function
    // Convert strtok operations to a function (maybe...)
}
