#pragma once
#include <iostream>
#include <cstring>
using namespace std;

template <class T>
class stackArray
{

	T B;
	T* data;
	int capacity;
	int size;
	
public:
	stackArray();
	stackArray(int capacity);
	~stackArray();
	void push(T);
	int getSize();
	T pop();
	T top();
	bool isEmpty();
	bool isFull();
	void print();
	int getCapacity();
};
