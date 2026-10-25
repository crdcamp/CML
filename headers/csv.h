#ifndef CSV_H
#define CSV_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW_SIZE 1000
#define MAX_HASH_INDICES 20

unsigned int hash(const char *column);
void read_csv(char *filepath);


#endif
