#include <stdio.h>
#include <stdlib.h>
#include "array.h"

Array *initArray(int size) {
    Array *arr = (Array *) malloc(sizeof(Array));
    arr->size = size;
    arr->start = 0;
    arr->start = (int *)malloc(arr->size * sizeof(int));
    return arr;
}
void setItem(Array *arr, int ind, int val) {
    if (ind < arr->size || ind < 0) {
        *(arr->start + ind) = val;
    } else {
        printf("Index out of bounds exception\n");
    }      
}
int getItem(Array *arr, int ind) {
    if (ind < arr->size || ind < 0) {
        return *(arr->start + ind);
    } else {
        printf("Index out of bounds exception\n");
        return -1;
    }      
}
void clearData(Array *arr) {
    free(arr->start);
    free(arr);
}
