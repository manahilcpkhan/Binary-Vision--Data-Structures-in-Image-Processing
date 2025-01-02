#pragma once
#include <iostream>
#include "Hash.h"

using namespace std;

template <class T>
class queue
{
private:
   
    int size;
    Node<T>* front;
    Node<T>* rear;
    
public:
    queue();
    ~queue();
    void enqueue(T x);
    T dequeue();
    void display();
    bool isEmpty();
    bool isFull();
};

