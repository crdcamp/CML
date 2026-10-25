#ifndef CSV_H
#define CSV_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    size_t n_rows;
    size_t n_columns;
    char **column_names;
    char **columns;
} Table;

void read_csv(char *filepath);

#endif
