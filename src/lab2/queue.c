#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printNodesBetweenLevels(struct Node* root, int startLevel, int endLevel) {
    if (root == NULL) {
        return;
    }
    
    int level = 0;
    struct Node* queue[1000];
    int front = 0, rear = 0;
    
    queue[rear++] = root;
    
    while (front < rear) {
        int size = rear - front;
        
        while (size-- > 0) {
            struct Node* currentNode = queue[front++];
            
            if (level >= startLevel - 1 && level <= endLevel - 1) {
                printf("%d ", currentNode->data);
            }
            
            if (currentNode->left != NULL) {
                queue[rear++] = currentNode->left;
            }
            
            if (currentNode->right != NULL) {
                queue[rear++] = currentNode->right;
            }
        }
        
        level++;
    }
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);
    root->right->right->right = createNode(8);
    root->left->left->left = createNode(7);
    root->left->left->left->right = createNode(9);

    int startLevel = 3;
    int endLevel = 4;

    printf("Nodes between levels %d and %d: ", startLevel, endLevel);
    printNodesBetweenLevels(root, startLevel, endLevel);
    
    return 0;
}
