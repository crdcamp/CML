#include "load.h"
#include <cstring>
#include <string.h>

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
        printf("`strip_newline` error: No newline character found for row: %s\n", text);
    }

    return text;
}

// Split the given row by commas and assign the data to its corresponding table indices
void assign_row_to_table(char *row, int row_index, int num_columns, int column_index, Table *table) {
    // Assign a copy of the row to avoid editing the original
    char *row_copy = malloc(sizeof(row));
    int index = 0;
    if (row_copy == NULL) {
        printf("`assign_row_to_table` error: Error allocating memory for `row_copy`\n");
    }
    strcpy(row_copy, row);

    // Split the row by commas
    char *row_token = strtok(row_copy, ",");
    while(row_token != NULL) {
        if (strlen(row_token) > MAX_ROW_SIZE + 1) {
            printf("`assign_row_to_table` error: Row input exceeds maximum row size\n");
            return;
        }
    // Assign each column in the row to its respective column in the table
    strcpy(table[index].data[row_index], row_token);
    ++;
    }

    free(row_copy);
}

// Load the csv into memory as a hash table and close the file pointer
// Should just handle the file pointer in here and just instead pass a string
// file path to this function
Table *csv_load(FILE *file_pointer) {
    // Get the column names so they can be assigned as hash table indices
    char columns_buffer[MAX_ROW_SIZE + 1]; // Never forget to account for the null terminator '\0'
    char *columns = fgets(columns_buffer, sizeof(columns_buffer), file_pointer);

    // Strip the `\n` from the end of the columns row if found
    int columns_size = strlen(columns);
    columns = strip_newline(columns);
    columns_size = strlen(columns); // Reassign columxns_size after newline char is stripped

    // Count the number of columns in the dataset for hash table assignment
    // using commas as delimiters
    unsigned int columns_count = 1; // The number of commas will always be one less than column count
    for (int i = 0; i < columns_size; i++) {
        if (columns[i] == ',') {
            columns_count++;
        }
    }

    // Allocate memory for the table (just a single malloc, would you look at that!)
    Table *table = malloc(sizeof(Table) * columns_count);
    if (table == NULL) {
        printf("Error allocating memory for hash table\n");
        return NULL;
    }

    // Assign each column name to its corresponding index in the hash table
    char *column_token = strtok(columns, ",");
    unsigned int index = 0;
    while (column_token != NULL) {
        if (strlen(column_token) > MAX_ROW_SIZE + 1) {
            printf("Error: Column name '%s' exceeds maximum column name size\n", column_token);
            return NULL;
        }
        strcpy(table[index].column_name, column_token);
        index++;
        column_token = strtok(NULL, ",");
    }

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
        // This is a mess.
        // WHEN YOU REVISIT THIS:
        // Priority #1 is seeing if you can convert the `strtok` operations
        // into a function.

        // Moreover, YOU NEED TO USE STRCPY BEFORE STRTOK, STRTOK EDITS THE VALUES
        // You can also make th strtok function return an array of strings. This means
        // one of the inputs would need to be the number of columns

        // Next, use print statements to figure this out. Print the row, the columns
        // and their corresponding indices, and the row indices, and figure it out
        // from there
        row = strip_newline(row);
        char *cell_token = strtok(row, ",");
    }

    return table;

    for (int i = 0; i < columns_count; i++) {
        for (int j = 0; j < MAX_ROW_SIZE; j++) {
            printf("Table %i data: %s", j, table[i].data[j]);
        }
        printf("\n\n");
    }
}
