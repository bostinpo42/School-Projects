#include <stdexcept>

#ifndef STACK_H
#define STACK_H

#define DEFAULT_SIZE 10
#define SCALING_FACTOR 2

class Stack {
private:
    int top{-1};
    size_t currentSize;
    int* stack;

    void resize();

public:
    Stack();
    Stack(const size_t);

    ~Stack();

    void push(const int);
    int pop();
    int peek();
    bool isEmpty();

};

#endif 