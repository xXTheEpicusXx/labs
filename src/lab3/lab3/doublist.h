#pragma once

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    

public:
    Node* head;
    DoublyLinkedList() : head(nullptr) {}
    void append(int data);
    void deleteNode(int data);
};

