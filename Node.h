#pragma once
#include <iostream>

using namespace std;
template <class T>
class Node
{
private:
	Node* next;
	T data;
public:
	Node();
	~Node();
	Node(T data);
	Node* getNext();
	T getData();
	void setNext(Node* next);
	void setData(T data);
};

