#include <stdexcept>
#include <functional>

#include "set.h"
#include "bucket.h"

#ifndef HASHSET_LP_H
#define HASHSET_LP_H

template<typename T>
class HashSetLP : public Set<T> {
public:
    HashSetLP(std::function<int(T)> hash) : store{new Bucket<T>[DEFAULT_SIZE]}, currentSize{DEFAULT_SIZE}, itemQty{0}, hash{hash} { }

    bool insert(const T& item) { 
        if(itemQty >= (currentSize * RESIZE_COND)) reSize(); 
        if(store[h2(hash(item))].item == item) { return false; } 
        if(store[h2(hash(item))].status == Occupied) { return insertProbe(item); }

        store[h2(hash(item))].item = item;
        store[h2(hash(item))].status = Occupied;
        ++itemQty;
        return true;
    }

    bool erase(const T& item) { 
        if(store[h2(hash(item))].status == Empty) return false; 
        if(store[h2(hash(item))].status == Available) return eraseProbe(item);

        store[h2(hash(item))].status = Available;
        return true;
    }

    const T* find(const T& item) {
        if(store[h2(hash(item))].status == Empty || store[h2(hash(item))].status == Available) { return findProbe(item); }

        if(store[h2(hash(item))].item == item) return &store[h2(hash(item))].item;
        
        return nullptr;
    }

    bool contains(const T& item) {
        if(store[h2(hash(item))].status == Empty || store[h2(hash(item))].status == Available) { return containsProbe(item); }

        if(store[h2(hash(item))].item == item) return true;

        return false;
     }

private:
    Bucket<T>* store; 
    size_t currentSize;
    size_t itemQty;

    std::function<int(T)> hash;

    int h2(int code) {
        int index{abs(code) % static_cast<int>(currentSize)};
        return index;
    }

    void reSize() {
        size_t newSize{currentSize * SCALING_FACTOR};
        Bucket<T>* newStore{new Bucket<T>[newSize]};

        for(size_t i{0}; i < itemQty; ++i) { newStore[i] = store[i]; }

        delete[] store;
        store = newStore;
        currentSize = newSize;
    }

    bool insertProbe(const T& item) {
        int count{0};
        int index{h2(hash(item))};

        while(store[ ++index % currentSize ].status == Occupied && count < MAX_PROBE_ATT) {
            ++count;
            if(store[index % currentSize].status == Available || store[index % currentSize].status == Empty) {
                store[index % currentSize].item = item;
                store[index % currentSize].status = Occupied;
                return true;
            }
        }
        return false;
    }

    bool eraseProbe(const T& item) {
        int count{0};
        int index{h2(hash(item))};

        while(count < MAX_PROBE_ATT) {
            ++count;
            ++index;
            if(store[index % currentSize].status == Occupied && store[index % currentSize].item == item) {
                store[index % currentSize].status = Available;
                return true;
            }
        }
        return false;
    }

    const T* findProbe(const T& item) {
        int count{0};
        int index{h2(hash(item))};

        while(count < MAX_PROBE_ATT) {
            ++count;
            ++index;
            if(store[index % currentSize].status == Occupied && store[index % currentSize].item == item) { return &item; }
        }
        return nullptr;
    }

    bool containsProbe(const T& item) {
        int count{0};
        int index{h2(hash(item))};

        while(count < MAX_PROBE_ATT) {
            ++count;
            ++index;
            if(store[index % currentSize].status == Occupied && store[index % currentSize].item == item) { return true; }
        }
        return false;
    }

};
#endif