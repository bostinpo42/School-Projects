#include <cstddef>

#ifndef BAG_H
#define BAG_H

template<typename T>
class Bag {
public:
    Bag() : itemCount(0) { }
    ~Bag();
    virtual bool add(T item) = 0;
    virtual bool remove(T item) = 0;
    virtual bool contains(T item) = 0;
    virtual size_t size() = 0;
    virtual int grab() = 0;

protected:
    size_t itemCount{};

};

#endif