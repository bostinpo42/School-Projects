#include <stdexcept>

#ifndef STACK_H
#define STACK_H

template<typename T>
class Node {
private:
public:
    T val;
    Node* next;
    Node(T val, Node* next) : val{val}, next{next};
    ~Node();
};

template<typename T>
class Stack {
public:
    Stack() : head(nullptr) { }
    ~Stack() {clear();}
    bool isEmpty() {return head == nullptr;}
    void push(T val) { head = new Node<T>(val, head); }
    T peek() {
        if (isEmpty()) throw std::runtime_error("The stack is empty!");

        return head->val;
    }

    T pop(T val) { 
        if (isEmpty()) throw std::runtime_error("The stack is empty!");

        Node<T>* temp{head};
        T val{head->val};
        head = head->next;
        delete temp;
        return val;
    }

    void clear() {
        Node<T>* temp{};
        while(head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
private:
    T* head;

};

#endif