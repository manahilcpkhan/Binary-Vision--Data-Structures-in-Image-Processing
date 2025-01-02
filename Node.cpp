#include "Node.h"

template <class T>
Node<T>::Node() {
	data = 0;
	next = nullptr;
}
template <class T>
Node<T>::Node(T data) {
	this->data = data;
	this->next = nullptr;
}

template <class T>
Node<T>::~Node() {
	//delete this;
}
template <class T>
Node<T>* Node<T>::getNext() {
	return this->next;
}
template <class T>
T Node<T>::getData() {
	return data;
}
template <class T>
void Node<T>::setNext(Node* next) {
	this->next = next;
}
template <class T>
void Node<T>::setData(T data) {
	this->data = data;
}
