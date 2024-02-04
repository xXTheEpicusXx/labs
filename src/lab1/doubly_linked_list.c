#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

// Функция для создания нового узла
 Node* createNode(int data) {
     Node* newNode = ( Node*)malloc(sizeof( Node));
    newNode->data = data;
    newNode->prev = NULL;
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
    newNode->prev = current;
}

// Функция для удаления узла по значению
void deleteNode( Node** head, int data) {
     Node* temp = *head;
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }
    if (temp == NULL) return;
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

// Функция для печати списка в прямом порядке
void printListForward( Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Функция для печати списка в обратном порядке
void printListBackward( Node* node) {
     Node* last = NULL;
    while (node != NULL) {
        last = node;
        node = node->next;
    }
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}
