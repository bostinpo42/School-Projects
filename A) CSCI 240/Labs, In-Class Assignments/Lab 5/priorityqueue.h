
#include"queue.h"
#include"min_max_heap.h"

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

template<typename T>
class PQueue : public Queue<T> {
public:
    PQueue(std::function<bool(size_t, size_t)> comparator) : Heap(comparator) { }

    PQueue(size_t initialSize, std::function<bool(size_t, size_t)> comparator) : Heap(initialSize, comparator) { }

    PQueue(const T array[], size_t size, std::function<bool(size_t, size_t)> comparator) : Heap(array, size, comparator){ }

    void enqueue(T item) {
        Heap.add(item);
    }

    T dequeue() {
        return Heap.remove();
    }

    T front() {
        return Heap.root();
    }

    bool isEmpty() {
        if(Heap.size() == 0) return true;
        return false;
    }

    void clear() {
        Heap.clear();
    }

private:
    MinMaxHeap<T> Heap;
    
    std::function<bool(size_t, size_t)> comparator;
};

#endif