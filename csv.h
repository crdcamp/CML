#ifndef CSV_H
#define CSV_H

typedef struct {
    float crim;
    float zn;
    float indus;
    int chas;
    float nox;
    float rm;
    float age;
    float dis;
    int rad;
    int tax;
    float ptratio;
    float b;
    float lstat;
    float medv;
} Boston;

void read_csv(char *file_path);

#endif
