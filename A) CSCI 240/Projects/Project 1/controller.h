#include <iostream>
#include "building.h"

#ifndef CONTROLLER_H
#define CONTROLLER_H

template<typename T>
class Controller {
public:
    Controller() : Medford{new Building}, idCount(0) { }
    ~Controller() { }
    
    void createPerson() {
        if(randRange(1, 1000) <= 35) Medford->Lobby->elevatorQueue->enqueue(new Person<T>(++idCount, randRange(1,50)))
    }

    void removePerson() {
        if(randomRange(1, 1000) <= 15) Medford->Lobby->elevatorQueue->dequeue();
    }

    void buildingLoop() {
        while(true) {
            Medford->createPerson();
 
        }
    }

private:
    size_t idCount;
    Building<T> Medford;

    size_t randRange(size_t start, size_t end) { return (rand() % (end - start + 1) + start); }

};

#endif