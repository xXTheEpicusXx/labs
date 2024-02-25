#include "compbintree.h"
#include <iostream>

Node* CompleteBinaryTree::getRoot(CompleteBinaryTree tree) {
    return tree.root;
}

void CompleteBinaryTree::insert(int data) {
    Node* newNode = new Node(data);

    if (root == nullptr) {
        root = newNode;
        return;
    }

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left == nullptr) {
            temp->left = newNode;
            break;
        }
        else if (temp->right == nullptr) {
            temp->right = newNode;
            break;
        }
        else {
            q.push(temp->left);
            q.push(temp->right);
        }
    }
}

void CompleteBinaryTree::inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}