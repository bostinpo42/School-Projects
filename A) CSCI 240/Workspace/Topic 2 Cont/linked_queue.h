#include <stdexcept>
#include "queue.h"
#include "node.h"

#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

template<typename T>
class LinkedQueue : public Queue<T> {
public:
    LinkedQueue() : frontPtr{nullptr}, backPtr{nullptr} { }

    void enqueue(T item){
        (isEmpty() ? backPtr : backPtr->next) = new Node<T>(item);

        if(isEmpty()) 
            frontPtr = backPtr;
        else 
            backPtr = backPtr->next;
    }

    T dequeue(){
        Node<T>* temp{frontPtr};
        T rtrnItem{};

        if(isEmpty()) throw std::runtime_error("Dequeue on empty queue!"); 

        rtrnItem = frontPtr->item;
        frontPtr = frontPtr->next;
        delete temp;

        if(isEmpty()) backPtr = nullptr; 

        return rtrnItem;
    }

    T front(){
        if(isEmpty()) throw std::runtime_error("Front called on empty queue!"); 
        return frontPtr->item;
    }

    bool isEmpty(){ return frontPtr == nullptr; }

    void clear(){
        Node<T>* temp{frontPtr};
        while(frontPtr != nullptr) {
            frontPtr = frontPtr->next;
            delete temp;
            temp = frontPtr;
        }
        backPtr = nullptr;
    }

private:
    Node<T>* frontPtr{};
    Node<T>* backPtr{};

};

#endif