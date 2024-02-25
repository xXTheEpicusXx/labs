#pragma once

class Array {
private:
	int* data;
	int size;
public:
	Array(int size) : size(size) {
		data = new int[size];
	}
	void set(int index, int value);
	int get(int index);
};