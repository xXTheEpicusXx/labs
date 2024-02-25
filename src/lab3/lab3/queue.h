#pragma once

// ��������� ���� �������
struct Node {
	int data;
	Node* next;
};

// ����� �������
class Queue {
private:
	Node* front;
	Node* rear;

public:
	Queue() : front(nullptr), rear(nullptr) {}
	void enqueue(int data);
	int dequeue();
	int getFront();
	int getRear();
};