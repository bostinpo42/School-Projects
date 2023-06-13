#include <stdexcept>
#include "queue.h"

#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#define DEFAULT_SIZE 10
#define SCALING_FACTOR 2

template<typename T>
class ArrayQueue : public Queue<T> {
public:
    ArrayQueue() : store(new T[DEFAULT_SIZE]), currentSize(DEFAULT_SIZE) { }
    ~ArrayQueue() {
        delete[] store;
    }

    void enqueue(T item){
        if (this->count >= currentSize) reSize();
        store[this->count++] = item;
        return;
    } 

    T dequeue(){
        T temp{store[head]};
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty! Cannot dequeue.");
            return false;
        }
        for (size_t i = 0; i < this->count; ++i){
            store[i] = store[i + 1];
            this->count--;
            return true;
        }
        return temp;
    }

    T front(){
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty! There is no front.");
        }
        return store[head];
    }

    bool isEmpty(){
        if (this->count == 0) return true;
        return false;
    }

    void clear(){
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty! There is nothing to clear.");
            return;
        }
        this->count = 0;
    }

private:
    T* store;
    size_t currentSize{};
    size_t head{0};

    void reSize() {
        currentSize *= SCALING_FACTOR;
        T* newStore(new T[currentSize]);
        for (size_t i = 0; i < this->count; ++i) newStore[i] = store[i];
        delete[] store;
        store = newStore;
    }
};

#endif