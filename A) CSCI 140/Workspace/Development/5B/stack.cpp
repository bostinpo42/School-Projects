#include "stack.h"

Stack::Stack() : Stack(DEFAULT_SIZE) {}

Stack::Stack(const size_t size) : currentSize{size} {
    stack = new int[currentSize];
}

Stack::~Stack() { delete[] stack; }

void Stack::push(const int value) {
    if(top == currentSize - 1) 
        resize();

    stack[++top] = value;
}

int Stack::pop() {
    if (isEmpty()) throw std::runtime_error("stack is empty!");

    return stack[top--];    
}

int Stack::peek() {
    if (isEmpty()) throw std::runtime_error("stack is empty!");

    return stack[top]; 
}

bool Stack::isEmpty() { return top == -1; }

void Stack::resize() {
    size_t newSize { currentSize * SCALING_FACTOR };
    int* newStack { new int[newSize] };

    for (size_t i = 0; i < currentSize; ++i)
        newStack[i] = stack[i];

    delete[] stack;

    stack = newStack;

    currentSize = newSize;
}