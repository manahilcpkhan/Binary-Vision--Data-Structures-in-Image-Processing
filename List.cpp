#include <iostream>
#include "List.h"

template <class T>
List<T>::List(){
	head = nullptr;
	current = nullptr;
	lastCurrent = nullptr;
	// lastNode = nullptr;
	size = 0;
}

template <class T>
List<T>:: ~List() {
	Node<T>* temp = head;
	while (temp != nullptr) {
		head = head->getNext();
		delete temp;
		temp = head;
	}
}

template <class T>
Node<T>* List<T>::getHead() {
	return head;
}
template <class T>
Node<T>* List<T>::getCurrent(){
	return current;
}

template <class T>
void List<T>::add(T data){
	Node<T>* newNode = new Node<T>(data);

	if (current != nullptr) {
		newNode->setNext(current->getNext());
		current->setNext(newNode);
		lastCurrent = current;
		current = newNode;
	}
	else {
		newNode->setNext(nullptr);
		head = newNode;
		lastCurrent = head;
		current = head;
	}	
}
template <class T>
void List<T>::remove(T dataToRemove){
	current = head;
	lastCurrent = nullptr;
	while (current != nullptr && current->getData() != dataToRemove) {
		lastCurrent = current;
		current = current->getNext();
	}
	if (current != nullptr && lastCurrent != nullptr) {
		//Node * temp = current->getNext();
		//lastCurrent->setNext(temp);
		
		lastCurrent->setNext(current->getNext());
		delete current;
	}
	else if (current != nullptr) {
		Node<T>* temp = head;
		head = head->getNext();
		delete temp;
	}
	else
		std::cout << dataToRemove << " not found \n";
}
template <class T>
void List<T>::addAtLast(T data) {
	if (head == nullptr) {
		head = new Node<T>(data);
		current = head;
		lastCurrent = head;
		return;
	}
	Node<T>* iterator = head;
	while (iterator->getNext() != nullptr)
		iterator = iterator->getNext();
	iterator->setNext(new Node<T>(data));
}
template <class T>
void List<T>::addAtFirstLocation(T data) {
	Node<T>* newNode = new Node<T>(data);
	newNode->setNext(head);
	head = newNode;
}
template <class T>
bool List<T>::find(T data) {
	Node<T>* iterator = head;
	lastCurrent = nullptr;
	current = head;
	while (iterator != nullptr) {
		if (iterator->getData() == data) {
			lastCurrent = current;
			current = iterator;
			return true;
		}
		iterator = iterator->getNext();
		lastCurrent = current;
		current = iterator;
	}
	return false;
}
template <class T>
void List<T> ::displayRLCList() {
	Node<T> *iterator = head;
	//int i = 0 ;
	std::cout << "|" << iterator->getData() << "|";
	iterator = iterator->getNext();
	std::cout << " -> ";
	std::cout << "|" << iterator->getData() << "|";
	iterator = iterator->getNext();
	cout << endl;
	while (iterator != nullptr) {
		//System.out.printf("|%d:%d|",++i,iterator.getData());
		if (iterator->getData() == -1) {
			std::cout << "|" << iterator->getData() << "|";
			iterator = iterator->getNext();
			cout << endl;
		}
		else {
			std::cout << "|" << iterator->getData() << "|";
			iterator = iterator->getNext();
			if (iterator != nullptr || iterator->getData() != -1)
				std::cout << " -> ";
		}
	}
	std::cout << std::endl;
}

template <class T>
void List<T> ::displayList() {
	Node<T>* iterator = head;
	while (iterator != nullptr) {
		std::cout << "|" << iterator->getData() << "|";
		iterator = iterator->getNext();
		if (iterator != nullptr)
			std::cout << " -> ";
	}
	std::cout << std::endl;
}