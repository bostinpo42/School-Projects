#include "bag.h"
#include <stdexcept>

#ifndef ARRAY_BAG
#define ARRAY_BAG

#define DEFAULT_SIZE 10
#define SCALING_FACTOR 2

template<typename T>
class ArrayBag : public Bag<T> {
public:
    ArrayBag() : store(new T[DEFAULT_SIZE]), currentSize(DEFAULT_SIZE) { }
    ~ArrayBag();

    bool add(T item) {
        if (itemCount >= currentSize) reSize();
        store[itemCount++] = item;
        return true;
    }
    bool remove(T item) {
        int i{indexOf(item)};
            if (i >= 0) {
                store[i] = store[--itemCount];
                return true;       
            }
        return false;
    }
    bool contains(T item) {
        return indexOf(item) >= 0;
    }
    size_t size() { return count; }

    int grab() {
        if (count == 0) throw std::runtime_error("Grab on empty bag! \n");
        return store[0];
    }
private:
    T store*;
    size_t currentSize{};
    
    void reSize() {
        currentSize *= SCALING_FACTOR
        T *newStore(new T[currentSize]);
        for (size_t i = 0; i < itemCount; ++i) newStore[i] = store[i];
        delete[] store;
        store = newStore;
    }
    int indexOf(T item) {
        int index{-1};
        for (size_t i = 0; i < itemCount; ++i) {
            if(store[i] == item) return i;
        }
        return -1;
    }
};

#endif