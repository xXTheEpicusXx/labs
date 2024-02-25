#include "queue.h"
#include <cstdlib>
#include <iostream>

void Queue::enqueue(int data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = nullptr;

	if (rear == nullptr) {
		front = newNode;
		rear = newNode;
	}
	else {
		rear->next = newNode;
		rear = newNode;
	}
}

int Queue::dequeue() {
	if (front == nullptr) {
		std::cout << "Очередь пуста" << std::endl;
		return -1;
	}

	Node* temp = front;
	int data = temp->data;

	front = front->next;

	if (front == nullptr) {
		rear = nullptr;
	}

	delete temp;

	return data;
}

int Queue::getFront() {
	if (front == nullptr) {
		std::cout << "Очередь пуста" << std::endl;
		return -1;
	}

	return front->data;
}

int Queue::getRear() {
	if (rear == nullptr) {
		std::cout << "Очередь пуста" << std::endl;
		return -1;
	}

	return rear->data;
}