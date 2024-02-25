#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

struct Node {
    int key;
    int value;
    struct Node* next;
};

struct Node* createNode(int key, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

struct HashTable {
    struct Node* table[SIZE];
};

int hashFunction(int key) {
    return key % SIZE;
}

void insert(struct HashTable* ht, int key, int value) {
    int index = hashFunction(key);
    
    struct Node* newNode = createNode(key, value);
    
    if (ht->table[index] == NULL) {
        ht->table[index] = newNode;
    } else {
        struct Node* current = ht->table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void display(struct HashTable* ht) {
    for (int i = 0; i < SIZE; i++) {
        struct Node* current = ht->table[i];
        printf("Bucket %d: ", i);
        while (current != NULL) {
            printf("(%d, %d) -> ", current->key, current->value);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct HashTable ht;
    for (int i = 0; i < SIZE; i++) {
        ht.table[i] = NULL;
    }
    
    insert(&ht, 10, 20);
    insert(&ht, 10, 34);
    insert(&ht, 30, 40);
    insert(&ht, 4, 6);
    insert(&ht, 15, 25);
    
    display(&ht);
    
    return 0;
}
