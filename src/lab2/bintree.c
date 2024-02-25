#include <stdio.h>
#include <stdlib.h>

// Структура для представления узла двоичного дерева
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Функция для создания нового узла
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* findNode(struct Node* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    
    if (root->data == value) {
        return root;
    }
    
    struct Node* foundNode = findNode(root->left, value);
    if (foundNode != NULL) {
        return foundNode;
    }
    
    foundNode = findNode(root->right, value);
    return foundNode;
}

int findLevelOfLastNode(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    
    int leftLevel = findLevelOfLastNode(root->left);
    int rightLevel = findLevelOfLastNode(root->right);
    
    // Выбираем максимальный уровень из левого и правого поддеревьев
    return 1 + ((leftLevel > rightLevel) ? leftLevel : rightLevel);
}

int main() {
    // Создание примера двоичного дерева
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);
    root->right->right->right = createNode(8);
    root->left->left->left = createNode(7);
    root->left->left->left->right = createNode(9);
    
    int k = 3; // Значение узла k
    int downlevel = findLevelOfLastNode(findNode(root, k));
    if (downlevel == 0) {
        printf("Узел с данным значением не найден в дереве.\n");
    } else {
        printf("Количество уровней между узлом %d и последним уровнем его поддерева: %d\n", k, downlevel - 1);
    }

    return 0;
}
