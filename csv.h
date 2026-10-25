#ifndef CSV_H
#define CSV_H

#include <stdio.h>

#define MAX_ROW_SIZE 1000
#define MAX_HASH_INDICES 20

unsigned int hash(const char *column);
void load_csv(FILE *file_pointer);


#endif
