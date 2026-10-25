#include <stdlib.h>
#include <string.h>

#include "csv.h"

int main(void) {
    // Open ze csv file
    char *salary_file_string = "data/Salary_dataset.csv";
    FILE *salary_file_pointer = fopen(salary_file_string, "r");
    if (salary_file_pointer == NULL) {
        printf("Error opening %s\n", salary_file_string);
        return 0;
    }

    // Load ze csv file into memory and close the file pointer
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

char *strip_newline(char *text) {
    int text_size = strlen(text);
    char last_char = text[text_size - 1];
    if (text[text_size - 1] == '\n') {
        text[text_size - 1] = 0;
    }
    else {
        return NULL;
    }

    return text;
}

// Load the csv into memory as a hash table and close the file pointer
void load_csv(FILE *file_pointer) {
    // Get the column names so they can be assigned as hash table indices
    char row_buffer[MAX_ROW_SIZE + 1]; // Never forget to account for the null terminator '\0'
    char *columns = fgets(row_buffer, sizeof(row_buffer), file_pointer);

    // Strip the `\n` from the end of the columns row if found
    int columns_size = strlen(columns);
    columns = strip_newline(columns);
    if (columns == NULL) {
        printf("Error: no newline character found for row: %s\n", columns);
        return;
    }

    // Count the number of columns in the dataset for hash table assignment
    // using commas as delimiters
    unsigned int columns_count = 1; // Comma count will always be one less than column count
    for (int i = 0; i < columns_size; i++) {
        if (columns[i] == ',') {
            columns_count++;
        }
    }

    // Assign each column name to its corresponding index in the hash table
    char *column_token = strtok(columns, ",");
    EntryNode *table[columns_count];
    unsigned int index = 0;
    while (column_token != NULL) {
        table[index]->column_name = column_token;
        index++;
        column_token = strtok(NULL, ",");
    }

    for (int i = 0; i < columns_count; i++) {
        printf("Hash table index %i: '%s'\n", i, table[i]->column_name);
    }

    // Iterate through the rest of the file and assign the results to the hash table
    // First, you need to check if the row is == `columns`, If it is, move onto the next
    // Don't forget to remove the newline character
    // You'll also need to work on the hash function part of the way through this
    // Final requirements:
    // Convert remove newline section to a function
    // Convert strtok operations to a function (maybe...)

    // Might want to do a for loop instead of a while loop for skipping the first row
    // This way, you don't have to check the row on every single iteration

    // We also want to keep track of the max number of rows as well.
    char *row;
    while ((row = fgets(row_buffer, sizeof(row_buffer), file_pointer)) != NULL) {
        // If we're on the the first row (the column names), then we want to skip it
        // There's gotta be a better way than checking every iteration for this though
        // Maybe there's a way to delete the columns row from the data above when we're
        // done with it!?!?
        // For now, let's just get the rest of the function done
        if (row == columns) {
            continue;
        }

        // Assign the row to the corresponding entry in the hash table
        // We can reuse a few variables here for correctly assigning indices
        // We might also want to consider making the use of `strtok` its own function

    }
}
