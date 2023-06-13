#include "person.h"
#include "floor.h"
#include "common.h"

#ifndef ELEVATOR_H
#define ELEVATOR_H

enum State { IDLE, DELIVER, PICKUP };
enum Direction { STILL, UP, DOWN };

class Elevator{
public:
    Elevator(Floor[], bool[]);
    void update();
private:
    State currentState;
    Direction currentDir;
    bool* callSet;
    Floor* floors;
    size_t currentFloor;

    void idle();
    void deliver();
    void pickup();
    int waiting(size_t);
    int waiting(size_t, size_t);
    bool noneWaiting();
    bool nonLobbyWaiting();
};

#endif
