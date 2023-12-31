#include "common.h"
#include "floor.h"

bool Floor::update() {
    if(isProbable(EXIT_PROBABILITY)) {
        Person p = occupants.grab();
        occupants.remove(p);
        elevQueue.enqueue(p);
    }

    return !elevQueue.empty();
}

void Floor::addElevQueue(const Person& p) {

}

void Floor::add(Person p) { occupants.add(p); }

Person Floor::get() { return elevQueue.dequeue(); }