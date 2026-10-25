#include "load.h"

char *strip_newline(char *text) {
    int text_size = strlen(text);
    if (text_size == 0) {
        // Poor error handling here
        printf("`strip_newline` error: No text found\n");
        return NULL;
    }
    if (text[text_size - 1] == '\n') {
        text[text_size - 1] = 0;
    }
    else {
        printf("`strip_newline` error: no newline character found for row: %s\n", text);
    }

    return text;
}

// Load the csv into memory as a hash table and close the file pointer
void load_csv(FILE *file_pointer) {
    // Get the column names so they can be assigned as hash table indices
    char columns_buffer[MAX_ROW_SIZE + 1]; // Never forget to account for the null terminator '\0'
    char *columns = fgets(columns_buffer, sizeof(columns_buffer), file_pointer);

    // Strip the `\n` from the end of the columns row if found
    int columns_size = strlen(columns);
    columns = strip_newline(columns);
    columns_size = strlen(columns); // Reassign columxns_size after newline char is stripped

    // Count the number of columns in the dataset for hash table assignment
    // using commas as delimiters
    unsigned int columns_count = 1; // Comma count will always be one less than column count
    for (int i = 0; i < columns_size; i++) {
        if (columns[i] == ',') {
            columns_count++;
        }
    }

    // Allocate memory for the table
    Node *table = malloc(sizeof(Node) * columns_count);
    if (table == NULL) {
        printf("Error allocating memory for hash table\n");
        return;
    }

    // Assign each column name to its corresponding index in the hash table
    char *column_token = strtok(columns, ",");
    unsigned int index = 0;
    while (column_token != NULL) {
        if (strlen(column_token) > MAX_COL_NAME_SIZE) {
            printf("Error: Column name '%s' exceeds maximum column name size\n", column_token);
            return;
        }
        strcpy(table[index].column_name, column_token);
        index++;
        column_token = strtok(NULL, ",");
    }

    for (unsigned int i = 0; i < columns_count; i++) {
        printf("Hash table index %i: '%s'\n", i, table[i].column_name);
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
    char row_buffer[MAX_ROW_SIZE + 1];
    while ((row = fgets(row_buffer, sizeof(row_buffer), file_pointer)) != NULL) {
        // If we're on the the first row (the column names), then we want to skip it
        // There's gotta be a better way than checking every iteration for this though
        // Maybe there's a way to delete the columns row from the data above when we're
        // done with it!?!?
        // For now, let's just get the rest of the function done
        if ((strcmp(row, columns) == 0) || (strcmp(row, "\n") == 0)) {
            continue;
        }

        // Assign the row to the corresponding entry in the hash table
        // We can reuse a few variables here for correctly assigning indices
        // We might also want to consider making the use of `strtok` its own function

    }
}
