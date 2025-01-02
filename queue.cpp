#include "queue.h"
template <class T>
queue<T>::queue()
{
    size = 0;
    front = nullptr;
    rear = nullptr;
   
}
template <class T>
queue<T>::~queue()
{
}

template <class T>
T queue<T>::dequeue()
{
    if (front == nullptr) {
        cout << "Qeueue is empty" << endl;
        return -1;
}
    else {
        T x = front->getData();

        Node<T>* p = front;

        front = front->getNext();

        delete p;

        return x;
    }
}

template <class T>
void queue<T>::enqueue(T x)
{
    if (front == nullptr) {
        front = new Node<T>(x);
        rear = front;
    }
    else
    {
        Node<T>* newNode = new Node<T>(x);


        newNode->setNext(NULL);

        rear->setNext(newNode);

        rear = newNode;
    }

}


template <class T>
void queue<T>::display()
{
    Node<T>* p = front;
    if (front == NULL)
    {
        cout << "\nQueue is Empty\n";
        return;
    }
    while (p != NULL)
    {

        cout << p->getData() << " ";

        p = p->getNext();

    }
    cout << endl;
    delete p;
}
template <class T>
bool queue<T>::isEmpty()
{
    if (front == nullptr || rear == nullptr) {
        cout << "\nQueue is Empty\n";
        return true;
    }
    else {
        cout << "\nWAIT. Queue is NOT Empty\n";
        return false;
    }
}
template <class T>
bool queue<T>::isFull()
{
    return false;
}

