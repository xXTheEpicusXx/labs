#pragma once
#include <queue>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class CompleteBinaryTree {
private:
    Node* root;

public:
    CompleteBinaryTree() : root(nullptr) {}

    Node* getRoot(CompleteBinaryTree tree);

    void insert(int data);

    void inorderTraversal(Node* root);


};

