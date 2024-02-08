#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

// Функция для создания нового узла
 Node* createNode(int key, int value) {
     Node* newNode = ( Node*)malloc(sizeof( Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Функция для инициализации хэш таблицы
void initHashTable( HashTable* ht) {
    for (int i = 0; i < SIZE; i++) {
        ht->array[i] = NULL;
    }
}

// Функция для вычисления хэша ключа
int hash(int key) {
    return key % SIZE;
}

// Функция для добавления элемента в хэш таблицу
void insert( HashTable* ht, int key, int value) {
    int index = hash(key);
     Node* newNode = createNode(key, value);
    
    if (ht->array[index] == NULL) {
        ht->array[index] = newNode;
    } else {
         Node* current = ht->array[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Функция для поиска элемента по ключу в хэш таблице
int search( HashTable* ht, int key) {
    int index = hash(key);
    
     Node* current = ht->array[index];
    
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    
    return -1; // Элемент не найден
}

// Функция для удаления элемента по ключу из хэш таблицы
void delete( HashTable* ht, int key) {
    int index = hash(key);
    
     Node* current = ht->array[index];
     Node* prev = NULL;
    
    while (current != NULL && current->key != key) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Элемент с ключом %d не найден\n", key);
        return;
    }
    
    if (prev == NULL) {
        ht->array[index] = current->next;
    } else {
        prev->next = current->next;
    }
    
    free(current);
}
