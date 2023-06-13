#include "floor.h"
#include "elevator.h"
#ifndef BUILDING_H
#define BUILDING_H

template<typename T>
class Building {
public:
    Building() : FloorArray[MAX_HEIGHT] {}
    ~Building();

    void setCallSet() {
        for(size_t i{0}; i <= MAX_HEIGHT; ++i) {
            if(FloorArray[i]->ElevatorQueue->count == 0) Elevator->callSet[i] = false;
            if(FloorArray[i]->ElevatorQueue->count > 0) Elevator->callSet[i] = true;
        }
    } 

private:
    Floor<T> FloorArray[]{};
    Floor<T> Lobby;
    Elevator<T> Elevator;
    
};

#endif