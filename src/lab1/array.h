typedef struct {
    int *arr;
    int size;
} DynamicArray;

void initDynamicArray(DynamicArray *array, int initialSize);
int getDynamicArray(DynamicArray *array, int index);
void setDynamicArray(DynamicArray *array, int index, int value);
void clearDynamicArray(DynamicArray *array);
