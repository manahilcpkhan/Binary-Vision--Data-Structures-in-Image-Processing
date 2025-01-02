#pragma once
#include "Node.cpp"
template <class T>
class List
{
private:
	Node<T>* head;
	Node<T>* current;
	Node<T>* lastCurrent;
	int size;
public:
	List();
	~List();
	Node<T>* getCurrent();
	Node<T>* getHead();
	//void setCurrent(Node* newCurrent);
	void add(T data);
	void remove(T dataToRemove);
	bool find(T data);
	void addAtFirstLocation(T data);
	void addAtLast(T data);
	void displayList();
	void displayRLCList();
};

