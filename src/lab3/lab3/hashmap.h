#pragma once

#include <iostream>

#define SIZE 10

// ��������� ��� �������� �������� � ��� �������
struct Node {
    int key;
    int value;
    Node* next;
};

// ����� ��� �������
class HashMap {
private:
    Node* array[SIZE];

    // ������� ��� �������� ������ ����
    Node* createNode(int key, int value) {
        Node* newNode = new Node;
        newNode->key = key;
        newNode->value = value;
        newNode->next = nullptr;
        return newNode;
    }

    // ������� ��� ���������� ���� �����
    int hash(int key);

public:
    HashMap() {
        for (int i = 0; i < SIZE; i++) {
            array[i] = nullptr;
        }
    }

    void insert(int key, int value);

    int search(int key);

    void remove(int key);
};
