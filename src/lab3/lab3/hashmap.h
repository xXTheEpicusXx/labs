#pragma once

#include <iostream>

#define SIZE 10

// Структура для хранения элемента в хэш таблице
struct Node {
    int key;
    int value;
    Node* next;
};

// Класс хэш таблицы
class HashMap {
private:
    Node* array[SIZE];

    // Функция для создания нового узла
    Node* createNode(int key, int value) {
        Node* newNode = new Node;
        newNode->key = key;
        newNode->value = value;
        newNode->next = nullptr;
        return newNode;
    }

    // Функция для вычисления хэша ключа
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
