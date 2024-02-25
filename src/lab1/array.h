typedef struct {
    int *start;
    int size;
} Array;

Array *initArray(int size);
void setItem(Array *arr, int ind, int val);
int getItem(Array *arr, int ind);
void clearData(Array *arr);
