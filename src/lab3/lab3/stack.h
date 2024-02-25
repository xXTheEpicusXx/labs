#pragma once
#define MAX_SIZE 100

class Stack {
private:
	int* array;
	int top;
	int capacity;

public:
	Stack(int capacity) : capacity(capacity), top(-1) {
		array = new int[capacity];
	}
	~Stack() {
		delete[] array;
	}
	bool isFull();
	bool isEmpty();
	void push(int item);
	int pop();
	int peek();
};