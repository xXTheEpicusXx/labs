#include <iostream>
#include "array.h"

void Array::set(int index, int value) {
	if (index >= 0 && index < size) {
		data[index] = value;
	}
	else {
		std::cout << "Index out of bounds!" << std::endl;
	}
}

int Array::get(int index) {
	if (index >= 0 && index < size) {
		return data[index];
	}
	else {
		std::cout << "Index out of bounds!" << std::endl;
		return -1;
	}
}