#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"

// Функция для создания нового узла
 Node* createNode(int data) {
     Node* newNode = ( Node*)malloc(sizeof( Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Функция для добавления узла в конец списка
void append( Node** head, int data) {
     Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
     Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Функция для удаления узла по значению
void deleteNode( Node** head, int data) {
     Node* temp = *head, *prev = NULL;
    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

// Функция для печати списка
void printList( Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
