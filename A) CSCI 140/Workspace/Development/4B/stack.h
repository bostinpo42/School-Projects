#include <string>
#include <stdexcept>

#ifndef STACK_H
#define STACK_h

struct Node
{
    std::string data;
    Node* next;

    Node()
    {
        data = "";
        next = nullptr;
    }

    Node(std::string data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

Node* top{nullptr};

// isEmpty
bool isEmpty() { return top == nullptr; } 

// push
void push(std::string str)
{
    top = new Node(str, top);
}

// pop
std::string pop()
{
    Node* tmpNode{top};
    if(isEmpty())
        throw std::range_error("stack is empty");

    std::string tmp(top->data);

    top = top->next;

    delete tmpNode;

    return tmp;
}

// peek
std::string peek()
{
    if(isEmpty())
        throw std::range_error("stack is empty");

    return top->data; // equivalent to (*top).data
}

#endif