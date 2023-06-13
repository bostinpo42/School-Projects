// iostream is only used for the operator<< function.
// Do not print anything directly to cout from this or any other class
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

#include "uninfected.h"
#include "infected.h"
#include "position.h"
#include "person.h"

#ifndef BUILDING_H
#define BUILDING_H

#define ROW_QTY 10
#define COL_QTY 8
#define ZOMBIE_QTY 12
#define LOUNGER_QTY 6
#define HYPER_QTY 4
#define AGGRESSOR_QTY 2
#define SPEC_OP_INDEX 0
#define SCIENTIST_INDEX 1
#define AGGRESSOR_INDEX 4
#define HYPER_INDEX 3
#define LOUNGER_INDEX 2

enum GameState {IN_PLAY, WIN, LOSE};

// this class does not provide UI nor does it contain main. 
class Building {
    /** stream insertion operator overload */
    friend std::ostream& operator<<(std::ostream&, const Building&);  
    
public:
    /** Building constructor. Initializes the Building */ 
    Building();

    /** move the position of the spec-op
     @ parameter move the direction in which the spec-op must move: must be a valid move
     @ throws invalid_argument exception if move is invalid */ 
    void move(char move);

    /** Building destructor. Deletes all heap based objects (including guards) */
    ~Building(){ 
        for (size_t i = 0; i < guards.size(); ++i) {
            delete guards[i]; 
        }
        delete specOp;
        delete scientist; 
    }

    GameState state;
private:
    std::vector<Infected*> guards;
    Uninfected* specOp;
    Uninfected* scientist;

    std::string percept[ROW_QTY][COL_QTY] {};
    bool hasScientist;

    void init();
    void initOccupants();
    void initZombies();
    void initAggressors();
    void initLoungers();
    void initHypers();
    void initBuilding();
    void initPercepts();
    void updateState();
    void updatePercepts();
    
    int randomRange(int, int) const;
    void pickUp();
    std::string toString() const;
};

#endif