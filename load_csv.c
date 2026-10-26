#include "load.h"
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
        printf("`strip_newline` error: no newline character found for row: %s\n", text);
    }

    return text;
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
    unsigned int columns_count = 1; // Comma count will always be one less than column count
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
        if (strlen(column_token) > MAX_CELL_SIZE + 1) {
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
        // Next, use print statements to figure this out. Print the row, the columns
        // and their corresponding indices, and the row indices, and figure it out
        // from there
        row = strip_newline(row);
        char *cell_token = strtok(row, ",");
        while (cell_token != NULL) {
            if (strlen(cell_token) > MAX_CELL_SIZE + 1) {
                printf("Error: Column name '%s' exceeds maximum column name size\n", column_token);
                return NULL;
            }
            // Assign each column in the row to it's corresponding table index
            int column = 0;
            int row_index = 0;
            for (unsigned int i = 0; i < columns_count; i++) {
                strcpy(table[column].data[row_index], cell_token);
                cell_token = strtok(NULL, ",");
                column++;
            }
            row_index++;
        }
    }

    return table;

    for (int i = 0; i < columns_count; i++) {
        for (int j = 0; j < MAX_ROW_SIZE; j++) {
            printf("Table %i data: %s", j, table[i].data[j]);
        }
        printf("\n\n");
    }
}
