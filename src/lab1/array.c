#include <stdio.h>
#include <stdlib.h>
#include "array.h"

// Инициализация динамического массива
void initDynamicArray(DynamicArray *array, int initialSize) {
    array->arr = (int *)malloc(initialSize * sizeof(int));
    array->size = initialSize;
}

// Получение элемента по индексу
int getDynamicArray(DynamicArray *array, int index) {
    if (index < array->size && index >= 0) {
        return array->arr[index];
    } else {
        printf("Ошибка: неверный индекс\n");
        return -1; // Возвращаем значение по умолчанию в случае ошибки
    }
}

// Установка значения элемента по индексу
void setDynamicArray(DynamicArray *array, int index, int value) {
    if (index < array->size && index >= 0) {
        array->arr[index] = value;
    } else {
        printf("Ошибка: неверный индекс\n");
    }
}

// Очистка динамического массива
void clearDynamicArray(DynamicArray *array) {
    free(array->arr);
    array->arr = NULL;
    array->size = 0;
}
