
#include "stackArray.h"
template <class T>

stackArray<T>::stackArray()
{
	B = 0;
	stackArray = nullptr;
	size = 50;
}
template <class T>
stackArray<T>::stackArray(int capacity) {
	B = 0;
	if (capacity <= 0) capacity = 50;
	data = new T[capacity];
	size = 0;
	this->capacity = capacity;
}
template <class T>
stackArray<T>::~stackArray() {
	delete[] data;
}
template <class T>
void stackArray<T>::push(T newElement) {
	if (isFull())
	{
		cout << "The stack is full.\n";
	}
	if (size < capacity)
		data[size++] = newElement;
}
template <class T>
T stackArray<T>::pop() {
	if (isEmpty() == true) {
		cout << "The stack is empty.\n";
		return -1;
	}
	else
	{
		return data[--size];
	}
}
template <class T>
T stackArray<T>::top() {
	return data[size - 1];
}
template <class T>
bool stackArray<T>::isEmpty() {
	if (size <= 0) {
		cout << "The stack is empty.\n";
		return true;
	}
	else {
		cout << "WAIT. The stack is NOT empty.\n";
		return false;
	}
}
template <class T>
bool stackArray<T>::isFull() {
	return size == capacity;
}
template <class T>
void stackArray<T>::print() {
	/*int temp;
	for (int j = 0; j < size / 2; j++) {
		for (int k = size; k < size / 2; k--) {
			temp = data[j];
			data[j] = data[k];
			data[k] = data[j];
		}
	}*/
	for (int i = size - 1; i >= 0; --i)
		std::cout << data[i];
}
template <class T>
int stackArray<T>::getCapacity() {
	return capacity;
}
template <class T>
int stackArray<T>::getSize() {
	return size;
}