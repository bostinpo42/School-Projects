
#include "person.h"

#ifndef PERSONQUEUE_H
#define PERSONQUEUE_H

#define DEFAULT_SIZE 16
#define SCALING_FACTOR 2

template<typename T>
class PersonQueue {
public:
     PersonQueue() 
        : frontIdx{-1}, backIdx{-1}, store{Person<T>[DEFAULT_SIZE]}, currentSize{DEFAULT_SIZE}, count{0} { }


    void enqueue(Person<T> item){
        if(count == currentSize) reSize();

        ++backIdx;
        backIdx %= currentSize;
        store[backIdx] = item;
        ++count;

        if(frontIdx == -1) frontIdx = backIdx;
    }

    Person<T> dequeue(){
        if(isEmpty()) throw std::runtime_error("Dequeue on empty queue!");
        
        Person<T> rtrnValue{store[frontIdx++]};

        frontIdx %= currentSize;

        --count;
        return rtrnValue;
    }

    Person<T> front(){
        if(isEmpty()) throw std::runtime_error("Front on empty queue!");
        return store[frontIdx];
    }

    bool isEmpty() { return count == 0; }

    void clear(){
        count = 0;
        frontIdx = backIdx = -1;
    }


private:
    size_t currentSize;
    size_t count;
    int frontIdx;
    int backIdx;

    Person<T> store;

    void reSize() {
        size_t newSize{currentSize * SCALING_FACTOR};
        T newStore{T[newSize]};

        for (size_t i {0}; i < count; ++i) {
            newStore[i] = store[frontIdx];
            ++frontIdx;
            frontIdx %= currentSize;
        }
        delete[] store;
        store = newStore;
        frontIdx = 0;
        currentSize = newSize;
    }

};

#endif