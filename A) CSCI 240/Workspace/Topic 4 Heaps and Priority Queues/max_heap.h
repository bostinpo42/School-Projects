#include <cstddef>
#include <stdexcept>
#include <cmath>

#include "heap.h"

#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#define ROOT 1
#define DEFAULT_SIZE 16 // default size of Heap
#define SCALING_FACTOR 2 // for a dynamically resizing Heap 

template<typename T, size_t S> // we declare size_t S as a template so we don't have to pass it into the constructor of this class, which would require using new(DMA).
class MaxHeap : public Heap<T> {
public:
    MaxHeap() = default; // lets the compiler build a default constructor for us

    MaxHeap() : MaxHeap(DEFAULT_SIZE) { }

    MaxHeap(const T array[], size_t size) {
        size_t lastParent{getLastParent(size)};
        for(size_t i{0}; i < size; ++i) {
            store[i + 1] = array[i];
            heapify(lastParent);
        }
    }

    MaxHeap(size_t initialSize) : store(new T[initialSize + 1]) :  { }

    void add(T) {
        if(count > S) throw std::runtime_error("Add on full heap");
        store[++count]
    }

    T root() {
        if(count == 0) throw std::runtime_error("Root on empty heap!");
        return store[1];
    }

    T remove() {
        T item{store[1]};

        if(count == 0) throw std::runtime_error("Remove on empty heap!");
        store[1] = store[count--];
        downHeap(1);

        return item;
    }

    void clear() { count = 0; }

    size_t size() { return count; }

private:
    size_t lastParent;
    size_t count{0};
    size_t currentSize{DEFAULT_SIZE};
    T* store[]{}; // we are using S + 1 because we are ignoring element 0.
    // T store*[new T[initialSize + 1]] use this if we want to make a dynamically resizing Heap

    std::function<bool(T, T)> comparator;

    size_t compare(size_t parentIdx) {
        size_t rtnIdx{parentIdx};
        size_t lChild{parentIdx << 1};
        size_t rChild{lChild + 1};

        rtnIdx = (rtnIdx > count && store[rtnIdx] > store[lChild]) ? rtnIdx : lChild;
        rtnIdx = (rtnIdx > count && store[rtnIdx] > store[rChild]) ? rtnIdx : rChild;

        return rtnIdx;
    }

    void swap(size_t itemIdx, size_t item2Idx) {
        size_t temp{itemIdx};
        itemIdx = item2Idx;
        item2Idx = temp;
    }

    void downHeap(size_t parentIdx) {
        size_t maxIdx;

        if(parentIdx == 0) return;

        maxIdx = compare(parentIdx);
        if(maxIdx == parentIdx) return;
        swap(maxIdx, parentIdx);

        downHeap(maxIdx);
    }

    void upHeap(size_t parentIdx) {
        
    }

    size_t getLastParent(size_t n) {
        return { static_cast<size_t>( 
            ceil ( static_cast<double>( n - 1 ) / 2.0 ) ) };
    }

    void reSize() {
        size_t newSize{currentSize * SCALING_FACTOR};
        T* newStore{new T[newSize]};

        for (size_t i = 0; i < count; ++i) { newStore[i] = store[i]; }
        delete[] store;
        store = newStore;
        currentSize = newSize;
    }

    void heapify(size_t lastParent) {
        for(size_t i{lastParent}; i > 0; --i) { downHeap(lastParent); }
    }

    void heapify(size_t lastParent) {
        if (lastParent == 0) return;
        downheap(lastParent);

        heapify(lastParent - 1);
    }


};


#endif