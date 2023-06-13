#include "personbag.h"
#include "floor.h"

#ifndef ELEVATOR_H
#define ELEVATOR_H

template<typename T>
struct Elevator {
    Elevator() : callSet[MAX_HEIGHT], CurrentFloor(0) {}

    bool isEmpty() {
        if(Elevator->Occupants->size() == 0) return true;
        else return false;
    }

    void moveUp() {
        if(CurrentFloor >= MAX_HEIGHT) throw std::range_error("Cannot move, max height reached!");
        CurrentFloor++;
    }

    void moveDown() {
        if(CurrentFloor <= 0) throw std::range_error("Cannot move, min height reached!");
        CurrentFloor--;
    }


    void dropOff(Person<T> person) {
        Elevator->Occupants->remove(person);
        FloorArray[Elevator->CurrentFloor]->add(person);
    }

    void fillElevator(Floor<T> floor) {
        if(isEmpty())  {
            for (size_t i{Elevator->Occupants->size()}; i <= MAX_CAP; i++) {
                Occupants->add(floor->ElevatorQueue->front())
                floor->ElevatorQueue->dequeue();
            }
        }
    }

    size_t floorIdx() {
        bool hasOccupants{false};
        size_t rtnIdx{-1};

        if (isEmpty()) {
            for (size_t i{MAX_HEIGHT}; i <= MAX_HEIGHT; i--) { 
                if(callSet[i] == true) {
                    hasOccupants = true;
                    rtnIdx = i;
                    break;
                }
            }  
        }
    }

    

    Floor<T> CurrentFloor{};
    bool callSet[]{};
    PersonBag<T> Occupants;
};

#endif