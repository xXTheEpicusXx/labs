#include <iostream>
#include "singlist.h"

void SinglyLinkedList::addFront(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void SinglyLinkedList::removeFront() {
    if (head == nullptr) {
        std::cout << "List is empty. Cannot remove from empty list." << std::endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}