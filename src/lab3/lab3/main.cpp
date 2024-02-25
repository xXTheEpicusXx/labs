#include <iostream>

#include "compbintree.h"

void main() {
	CompleteBinaryTree tree;
	tree.insert(1);
	tree.insert(2);
	tree.insert(4);
	tree.insert(12);
	tree.insert(6);
	tree.inorderTraversal(tree.getRoot(tree));
}