#ifndef CSV_H
#define CSV_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

unsigned int hash(const char *column);
void read_csv(char *filepath);


#endif
