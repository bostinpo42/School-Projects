#include "personbag.h"
#include "personqueue.h"
#include <cstddef>

#ifndef FLOOR_H
#define FLOOR_H

template<typename T>
class Floor {
public:
    bool add(Person<T> person) {
        returnOoccupants->add(person);
    }

    bool remove(Person<T> person) {
        return Occupants->remove(person);
    }

    bool contains(Person<T> person) {
        return Occupants->contains(person);
    }

    size_t size() {
        return Occupants->size;
    }

    Person<T> grab() {
        return Occupants->grab();
    }

protected:
    PersonBag<T> Occupants{};
    PersonQueue<T> ElevatorQueue{};
};

#endif

