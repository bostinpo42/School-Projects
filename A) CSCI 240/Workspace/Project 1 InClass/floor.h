#include "person.h"
#include "array_bag.h"
#include "array_queue.h"

#ifndef FLOOR_H
#define FLOOR_H

class Floor {
public:
    bool update();
    void add(Person p);
    Person get();
    void addElevQueue(const Person&);
private:
    ArrayBag<person> occupants;
    ArrayQueue<Person> elevQueue;
};

#endif