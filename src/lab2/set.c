#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int elements[MAX_SIZE];
    int size;
} Set;

void initialize(Set *set) {
    set->size = 0;
}

void addElement(Set *set, int element) {
    if (set->size < MAX_SIZE) {
        set->elements[set->size++] = element;
    } else {
        printf("Множество полное, невозможно добавить элемент.\n");
    }
}

void removeElement(Set *set, int element) {
    int i, found = 0;
    for (i = 0; i < set->size; i++) {
        if (set->elements[i] == element) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (; i < set->size - 1; i++) {
            set->elements[i] = set->elements[i + 1];
        }
        set->size--;
    } else {
        printf("Элемент не найден в множестве.\n");
    }
}

int containsElement(Set *set, int element) {
    int i;
    for (i = 0; i < set->size; i++) {
        if (set->elements[i] == element) {
            return 1;
        }
    }
    return 0;
}

void unionSets(Set *set1, Set *set2, Set *result) {
    int i;

    for (i = 0; i < set1->size; i++) {
        addElement(result, set1->elements[i]);
    }

    for (i = 0; i < set2->size; i++) {
        if (!containsElement(result, set2->elements[i])) {
            addElement(result, set2->elements[i]);
        }
    }
}

void intersectSets(Set *set1, Set *set2, Set *result) {
    int i;

    for (i = 0; i < set1->size; i++) {
        if (containsElement(set2, set1->elements[i])) {
            addElement(result, set1->elements[i]);
        }
    }
}

void differenceSets(Set *set1, Set *set2, Set *result) {
    int i;

    for (i = 0; i < set1->size; i++) {
        if (!containsElement(set2, set1->elements[i])) {
            addElement(result, set1->elements[i]);
        }
    }
}

void printSet(Set *set) {
    int i;
    printf("{ ");
    for (i = 0; i < set->size; i++) {
        printf("%d ", set->elements[i]);
    }
    printf("}\n");
}

int main() {
    Set set1, set2, result;
    
    initialize(&set1);
    initialize(&set2);
    initialize(&result);

    addElement(&set1, 1);
    addElement(&set1, 2);
    addElement(&set1, 3);

    addElement(&set2, 3);
    addElement(&set2, 4);
    addElement(&set2, 5);

    printf("Множество 1: ");
    printSet(&set1);

    printf("Множество 2: ");
    printSet(&set2);

    unionSets(&set1, &set2, &result);
    printf("Объединение множеств: ");
    printSet(&result);

    initialize(&result);
    intersectSets(&set1, &set2, &result);
    printf("Пересечение множеств: ");
    printSet(&result);

    initialize(&result);
    differenceSets(&set1, &set2, &result);
    printf("Разность множеств (множество 1 - множество 2): ");
    printSet(&result);

    return 0;
}
