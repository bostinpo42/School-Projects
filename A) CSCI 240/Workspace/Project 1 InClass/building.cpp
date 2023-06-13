#include "common.h"
#include "building.h"


Building::Building() : callset{}, elevator(floors, callset) { }

void Building::update() {
    for(size_t i = 0; i < FLOOR_QTY; ++i) {
        callset[i] = floors[i].update();
    }
    elevator.update();
}

void Building::add(const Person& p) {
    floors[LOBBY].addElevQueue(p);
}