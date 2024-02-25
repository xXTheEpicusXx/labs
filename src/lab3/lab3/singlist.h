#pragma once
class Node {
public:
	int data;
	Node* next;

	Node(int data) : data(data), next(nullptr) {}
};

class SinglyLinkedList {
	

public:
	Node* head;
	SinglyLinkedList() : head(nullptr) {}
	void addFront(int data);
	void removeFront();
};