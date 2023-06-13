// who: <Austin Ngo - ango26>
// what: <implements the bucket class>
// why: <Lab 5: Classes>
// when: <05/10/2022>

#include "bucket.h"
#include <stdexcept>

Bucket::Bucket() : Bucket(DEFAULT_SIZE) {}

Bucket::Bucket(const size_t size) : itemCount{size} {
    items = new double[itemCount];
}

size_t Bucket::count() const {
    return itemCount;
}

bool Bucket::isEmpty() const { return itemCount == 0;}

void Bucket::add(const double item) {
   if (itop == itemCount - 1) resize();

   items[++itop] = item;
}

double Bucket::remove() {
    if (isEmpty()) throw std::runtime_error("Bucket is empty! Cannot remove item from an empty bucket!");

    double item = items[itemCount - 1];
    items[itemCount - 1] = 0;
    --itemCount;
    return item;
}

bool Bucket::remove(const double item) {
    int index{-1};
    for (size_t i = 0; i < itemCount; ++i) {
        if (items[i] == item) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        return false;
    }

    ++index;
    while (index < itemCount) {
        items[index - 1] = items[index];
        ++index;
    }

    -index;
    items[index] = 0;
    --itemCount;
    return true;
}

void Bucket::clear() {
    for (size_t i = 0; i < itemCount; ++i) {
        items[i] = 0;
    }
    itemCount = 0;  
}

size_t Bucket::getFrequency(const double item) const {
    size_t frequency{0};
    for (size_t i = 0; i < itemCount; ++i) {
        if (items[i] == item) {
            ++frequency;
        }
    }
    return frequency;
}

bool Bucket::contains(const double item) const {
    for (size_t i = 0; i < itemCount; ++i) {
        if (items[i] == item) {return true;}
    }
    return false;
}

void Bucket::resize() {
    size_t newItemCount { itemCount * SCALING_FACTOR };
    double* newItems { new double[newItemCount] };

    for (size_t i = 0; i < itemCount; ++i)
        newItems[i] = items[i];

    delete[] items;

    items = newItems;

    itemCount = newItemCount;
}