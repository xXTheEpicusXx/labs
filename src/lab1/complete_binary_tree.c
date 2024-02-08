#include <stdio.h>
#include <stdlib.h>
#include "comlete_binary_tree.h"

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert( Node** root, int data) {
     Node* newNode = createNode(data);
    
    if (*root == NULL) {
        *root = newNode;
        return;
    }
    
     Node* temp = *root;
    
    while (temp->left != NULL && temp->right != NULL) {
        if (temp->left != NULL) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    
    if (temp->left == NULL) {
        temp->left = newNode;
    } else {
        temp->right = newNode;
    }
}

void inorderTraversal( Node* root) {
    if (root == NULL) {
        return;
    }
    
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}
