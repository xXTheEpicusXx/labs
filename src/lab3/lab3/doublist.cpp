#include "doublist.h"

void DoublyLinkedList::append(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

void DoublyLinkedList::deleteNode(int data) {
    Node* temp = head;
    while (temp != nullptr && temp->data != data) {
        temp = temp->next;
    }
    if (temp == nullptr) return;
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }
    else {
        head = temp->next;
    }
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    delete temp;
}