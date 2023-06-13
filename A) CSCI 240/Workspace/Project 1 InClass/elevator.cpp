#include "elevator.h"

Elevator::Elevator(Floor floors[], bool callSet[])
    : floors{floors}, callSet{callSet}, currentFloor{LOBBY}, currentDir{STILL}, currentState{IDLE} 
    {

}

void Elevator::update() {
    switch (currentState)
    {
    case IDLE:
        idle();
        break;
    case DELIVER:
        deliver();
        break;
    case PICKUP:
        pickup();
    }
}

void Elevator::idle() {
    if(noneWaiting()) return;

    if(currentFloor == LOBBY)
        currentState = (callSet[LOBBY]) ? DELIVER : PICKUP;
    else 
        currentState = (nonLobbyWaiting()) ? PICKUP : DELIVER;
}

int Elevator::waiting(size_t floor) {return (callSet[floor] ? floor : -1); }

int Elevator::waiting(size_t start, size_t end) {
    int step = (start > end) ? -1 : 1;

    while(start != end + start) {
        if(callSet[start]) return start;
        start += step;
    }

    return (callSet[start]) ? start : -1;
}

void Elevator::deliver() {
    
}

void Elevator::pickup() {

}

bool Elevator::noneWaiting() {
    for (size_t i{0}; i < FLOOR_QTY; ++i) {
        if(callSet[i]) return false;
    }
    return true;
}

bool Elevator::nonLobbyWaiting() {
    for(size_t i{LOBBY+1}; i < FLOOR_QTY; ++i) {
        if(callSet[i]) return true;
    }
    return false;
}