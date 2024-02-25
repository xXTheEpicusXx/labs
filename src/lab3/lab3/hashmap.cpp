#include "hashmap.h"

int HashMap::hash(int key) {
    return key % SIZE;
}

// Функция для добавления элемента в хэш таблицу
void HashMap::insert(int key, int value) {
    int index = hash(key);
    Node* newNode = createNode(key, value);

    if (array[index] == nullptr) {
        array[index] = newNode;
    }
    else {
        Node* current = array[index];
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Функция для поиска элемента по ключу в хэш таблице
int HashMap::search(int key) {
    int index = hash(key);

    Node* current = array[index];

    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }

    return -1; // Элемент не найден
}

// Функция для удаления элемента по ключу из хэш таблицы
void HashMap::remove(int key) {
    int index = hash(key);

    Node* current = array[index];
    Node* prev = nullptr;

    while (current != nullptr && current->key != key) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        std::cout << "Элемент с ключом " << key << " не найден" << std::endl;
        return;
    }

    if (prev == nullptr) {
        array[index] = current->next;
    }
    else {
        prev->next = current->next;
    }

    delete current;
}