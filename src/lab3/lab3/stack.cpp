#include "stack.h"
#include <cstdlib>
#include <iostream>

bool Stack::isFull() {
	return top == capacity - 1;
}

bool Stack::isEmpty() {
	return top == -1;
}

void Stack::push(int item) {
	if (isFull()) {
		std::cout << "Stack is full" << std::endl;
		return;
	}
	array[++top] = item;
}

int Stack::pop() {
	if (isEmpty()) {
		std::cout << "Stack is empty" << std::endl;
		return -1;
	}
	return array[top--];
}

int Stack::peek() {
	if (isEmpty()) {
		std::cout << "Stack is empty" << std::endl;
		return -1;
	}
	return array[top];
}