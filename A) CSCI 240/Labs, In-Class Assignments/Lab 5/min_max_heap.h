#include <cstddef>
#include <stdexcept>
#include <cmath>
#include <functional>
#include <iostream>

#include "heap.h"

#ifndef MINMAX_HEAP_H
#define MINMAX_HEAP_H

#define ROOT 1
#define DEFAULT_SIZE 15
#define SCALING_FACTOR 2 

template<typename T> 
class MinMaxHeap : public Heap<T> {
public:
    MinMaxHeap(std::function<bool(size_t, size_t)> comparator) : MinMaxHeap(DEFAULT_SIZE + 1, comparator) { }
    // Default constructor for MinMaxHeap, it only takes in the lambda function for our comparator as an argument.
    // We use list initialization to initialize our heap to DEFAULT_SIZE + 1, to accomodate the offset of the internal array, and we also initialize the comparator function.
    // The initialization of the other members of our objects will be delegated to the other constructors as needed.

    MinMaxHeap(size_t initialSize, std::function<bool(size_t, size_t)> comparator) : store{new T[initialSize + 1]}, itemQty{0}, currentSize{initialSize}, comparator{comparator} { }
    // Constructor for MinMaxHeap which takes the lambda function for the comparator as well as the heap's initial maximum size as an argument.
    // We initialize the heap's internal array to initialSize + 1, because we are offsetting the internal array. We also initialize itemQty to 0, as we have not added any items yet.
    // currentSize gets initialized to initialSize, which will determine the initial size of our heap.

    MinMaxHeap(const T array[], size_t size, std::function<bool(size_t, size_t)> comparator) : store{new T[size + 1]}, itemQty{size}, currentSize{size}, comparator{comparator} {
        size_t lastParent{getLastParent(size)};
        
        for(size_t i{0}; i < size; ++i) {
            store[i + 1] = array[i];
        }
        heapify(lastParent);
    }
    // This constructor takes an array and its size as an arugment, it initializes our object's members with the arguments passed through the constructor. With this we can initialize our heap given an array.

    void add(T item) {
        if(itemQty == currentSize) reSize();
        store[itemQty + 1] = item;
        ++itemQty;

        upHeap(itemQty >> 1);
    }
    // Our add function is simple. First we do a check to ensure our heap is full. If itemQty reaches currentSize, our heap is full, and therefore we need to reSize.
    // After our check, we assign the added item to the next element in the array, and then we increment the item count.
    // Finally, we call upheap on the added item's parent to rearrange our heap back into order.

    T root() {
        if(itemQty == 0) throw std::runtime_error("Root on empty heap!");
        return store[ROOT];
    }
    // Root simply returns the first item in the heap. If it is empty then it will throw an exception.

    T remove() {
        T item{store[ROOT]};

        if(itemQty == 0) throw std::runtime_error("Remove on empty heap!");
        store[ROOT] = store[itemQty];
        --itemQty;
        downHeap(ROOT);

        return item;
    }
    // Our remove function first initializes our return variable with the first element in our heap. We then check to see if our heap is empty, and throw an error if so.
    // Then, we assign the root value of the heap to the last item of the heap, and decrement the current count of our heap. This effectively removes the last element.
    // Finally, we call downheap on the root to keep our heap in order.

    void clear() { itemQty = 0; }

    size_t size() { return itemQty; }

private:
    size_t itemQty;
    size_t currentSize;
    T* store;

    std::function<bool(size_t, size_t)> comparator;

    size_t compare(size_t parentIdx) {
        size_t rtnIdx{parentIdx};
        size_t lChild{parentIdx << 1};
        size_t rChild{lChild + 1};

        if(lChild <= itemQty) {
        rtnIdx = (comparator(store[rtnIdx], store[lChild])) ? rtnIdx : lChild;
        }
        if(rChild <= itemQty) {
        rtnIdx = (comparator(store[rtnIdx], store[rChild])) ? rtnIdx : rChild;
        }
        return rtnIdx;
    }
    // For our compare function we first create a return index initialized to the parent index of the items we are comparing. We also create a left and right child index of our parent child.
    // The left child index should simply be the parent index divided by two. The right child is simply the left child + 1.
    // We need two comparisons for our compare function, as we are comparing the parent with its two children. Before we make our comparison we should do bounds checking to ensure that the indices
    // of our left and right children are within the bounds of our heap. Once that has been checked we can compare the parent index with its left and right child, respectively.
    // depending on the comparator function passed through, the return index will either be the greatest or least of the three.

    void heapify(size_t idx) {
        for(size_t i{idx}; i > 0; --i) { downHeap(i); }
    }
    // heapify is used when we are constructing our object with an array. Heapify simply calls downheap on the heap for each element of the array added, ensuring that our heap is in order after construction.

    void swap(size_t idx1, size_t idx2) {
        T temp{store[idx1]};
        store[idx1] = store[idx2];
        store[idx2] = temp;
    }

    void downHeap(size_t parentIdx) {
        size_t maxIdx;

        if(parentIdx >= itemQty) return;

        maxIdx = compare(parentIdx);
        if(maxIdx == parentIdx) return;
        swap(maxIdx, parentIdx);

        downHeap(maxIdx);
    }
    // downheap's purpose is to work downwards on the heap and ensuring that it stays in order. First, we do a check to ensure that the parent index is greater or equal to our heap's size.
    // we then set our variable equal to the largest, or smallest value as a result of our call to the compare function. if the variable is already equal to our parent index, that means our heap
    // is already in order and we can just return. If not, then we swap the values to order our heap, and recursively call downheap on the max index to order our heap.

    void upHeap(size_t parentIdx) {
        size_t maxIdx;

        if(parentIdx == 0) return;

        maxIdx = compare(parentIdx);
        if(maxIdx == parentIdx) return;
        swap(maxIdx, parentIdx);

        upHeap(parentIdx >> 1);
    }
    // upheap works very similarly to downheap, except that it must work in the opposite direction of downheap. If downheap is supposed to go from the top to bottom, then upheap works its way from
    // the bottom of the heap to the top. The main difference between down and upheap is it's recursive call. Rather than calling upHeap on the max index, we call upheap on the parent index's parent
    // thus working our way up the heap.

    size_t getLastParent(size_t n) {
        return { static_cast<size_t>( 
            ceil( static_cast<double>( ( n - 1 ) / 2.0 ) ) ) };
    }

    void reSize() {
        size_t newSize{currentSize * SCALING_FACTOR};
        T* newStore{new T[newSize]};

        for (size_t i{1}; i < itemQty; ++i) { newStore[i] = store[i]; }
        delete[] store;
        store = newStore;
        currentSize = newSize;
    }

};


#endif