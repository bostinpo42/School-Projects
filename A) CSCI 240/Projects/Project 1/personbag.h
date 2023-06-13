#include <cstddef>
#include "person.h"

#ifndef PERSONBAG_H
#define PERSONBAG_H

template<typename T>
class PersonBag {
public:
    PersonBag() : personArray[MAX_CAP], personCount(0) { }
    ~PersonBag();

    bool add(Person<T> person) {
        if(personCount >= MAX_CAP) { throw std::out_of_range("Cannot add! At capacity! \n"); }
        personArray[personCount] = person;
        personCount++;
    }

    bool remove(Person<T> person) {
        int i{indexOf(person)};

        if(personCount <= 0) { throw std::out_of_range("Cannot remove! Empty! \n"); }
        if (i >= 0) {
            personArray[i] = personArray[--personCount];
            return true;
        }
        return false;
    }

    bool contains(Person<T> person) { return indexOf(person) >= 0; }

    size_t size() { return personCount; }

    int grab() {
        if (personCount == 0) throw std::runtime_error("Grab on empty bag! \n");
        return store[0];
    }

protected:
    Person<T> personArray[];
    Person<T> personCount{};

    size_t indexOf(Person<T> person) {
        int index{-1};
        for (size_t i = 0; i < personCount; ++i) {
            if(personArray[i] == person) return i;
        }
        return -1;
    }

};

#endif