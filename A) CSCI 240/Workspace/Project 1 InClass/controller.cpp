#include "controller.h"
#include "common.h"

Controller::Controller() : nextId{0} { }

void Controller::start() {
    while(true) {
        if(isProbable(NEW_PERSON_PROBABILITY)) {
            building.add({nextId++, randRange(1, FLOOR_QTY - 1)});
        }
        building.update();
    }
}

