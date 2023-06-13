#include "node.h"
#include "queue.h"
#include <stdexcept>

#ifndef LINKED_QUEUE
#define LINKED_QUEUE

template<typename T>
struct WQueue : public Queue<T> {
    WQueue() : head(nullptr) { }

    void enqueue(T item){
        head = new Node<T>(item, head);
    } 

    T dequeue(){
        Node<T>* start{head};
        T value{front()};

        if(start->next == nullptr) delete start;
        while(start->next->next != nullptr) {
            start = start->next;
        }
        delete start->next;
        return value;
    }

    T front(){
        Node<T>* start{head};
        if (isEmpty() || start->next == nullptr){
            throw std::runtime_error("Queue is empty! There is no head.");
        }
        while(start->next->next != nullptr) {
            start = start->next;
        }
        start->next = nullptr;
        return start->next->item;
    }

    bool isEmpty(){
        return head == nullptr;
    }

    void clear(){
        if (isEmpty()){
            throw std::runtime_error("Queue is empty! There is nothing to clear.");
            return;
        }
        Node<T>* temp{};
        while(head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
private:
    Node<T>* head{};
};

#endif
