#include <stdlib.h>
#include <string.h>

#include "load.h"

int main(void) {
    // Open ze csv file
    char *salary_file_string = "data/Salary_dataset.csv";
    FILE *salary_file_pointer = fopen(salary_file_string, "r");
    if (salary_file_pointer == NULL) {
        printf("Error opening %s\n", salary_file_string);
        return 0;
    }

    // Load ze csv file into memory and close the file pointer
    Table salary_table;
    csv_load(salary_file_pointer);
    fclose(salary_file_pointer);
    //csv_unload(salary_table);

    return 0;
}
