#include <sstream>
#include <iostream>
#include "building.h"
#include "position.h"
#include "aggressor.h"
#include "hyper.h"
#include "lounger.h"

Building::Building(){ srand(time(NULL)); init(); }

std::string getDivider() {
    std::stringstream ss;

    for (size_t i{0}; i < COL_QTY; ++i)
        ss << "----";
    ss << '-';

    return ss.str();
}

void Building::init() {
    initPercepts();
    int x{randomRange(4,5)};
    int y{randomRange(3,4)};
    specOp = new Uninfected(Position(0,0), 'O');
    scientist = new Uninfected(Position(x,y), 'S');
    percept[x][y][SCIENTIST_INDEX] = 'S';
    percept[0][0][SPEC_OP_INDEX] = 'O';
    hasScientist = false;
    state = IN_PLAY;

    initZombies();
}

void Building::initZombies() {
    initLoungers();
    initHypers();
    initAggressors();
}

void Building::initAggressors() {
    for (size_t i{0}; i < AGGRESSOR_QTY; ++i) {
        int x;
        int y;
        do {
            x = randomRange(0, ROW_QTY - 1);
            y = randomRange(0, COL_QTY - 1); 
        } while (x == 0 && y == 0);
        guards.push_back(new Aggressor(Position(x,y), *specOp));
        percept[x][y][AGGRESSOR_INDEX] = 'A';
    }
}

void Building::initLoungers() {
    for (size_t i{0}; i < LOUNGER_QTY; ++i) {
        int x;
        int y;
        do {
            x = randomRange(0, ROW_QTY - 1);
            y = randomRange(0, COL_QTY - 1);
        } while (x == 0 && y == 0);
        guards.push_back(new Lounger(Position(x,y)));
        percept[x][y][LOUNGER_INDEX] = 'L';
    }
}

void Building::initHypers() {
    for (size_t i{0}; i < HYPER_QTY; ++i) {
        int x;
        int y;
        do {
            x = randomRange(0, ROW_QTY - 1);
            y = randomRange(0, COL_QTY - 1);
        } while (x == 0 && y == 0);
        guards.push_back(new Hyper(Position(x,y)));
        percept[x][y][HYPER_INDEX] = 'H';
    }
}

void Building::initPercepts() {
    for (size_t rows{0}; rows < ROW_QTY; ++rows) 
        for (size_t cols{0}; cols < COL_QTY; ++cols) 
            percept[rows][cols] = "     ";
}

void Building::updateState() {
    if(hasScientist && specOp->getPosition().x == 0 && specOp->getPosition().y == 0 &&
       percept[specOp->getPosition().x][specOp->getPosition().y] == "OS   ") { 
        state = WIN;
        return;
    }
    if(percept[specOp->getPosition().x][specOp->getPosition().y] == "O    " 
    || percept[specOp->getPosition().x][specOp->getPosition().y] == "OS   ") {
        state = IN_PLAY;
        return;
    }
    state = LOSE;
}

int Building::randomRange(int min, int max) const { return rand() % ((max + 1) - min) + min; }

void Building::pickUp() {
    if(specOp->getPosition().x != scientist->getPosition().x && specOp->getPosition().y != scientist->getPosition().y) {
        throw "Scientist is not in this cell!\n";
        return;
    }
    hasScientist = true;
    return;
}

void Building::move(char move) {
    try {
        percept[specOp->getPosition().x][specOp->getPosition().y][SPEC_OP_INDEX] = ' ' ;
        specOp->move(toupper(move));
        updatePercepts();
        updateState();
        if (hasScientist == false && toupper(move) == 'C') {
            pickUp();
        }
        if (hasScientist == true) {
            percept[scientist->getPosition().x][scientist->getPosition().y][SCIENTIST_INDEX] = ' ';
            scientist->move(toupper(move));
        }
        for (size_t i = 0; i < guards.size(); ++i) {
            switch (guards[i]->getType()) {
                case 'L': percept[guards[i]->getPosition().x][guards[i]->getPosition().y][LOUNGER_INDEX] = ' ';
                    break;
                case 'H': percept[guards[i]->getPosition().x][guards[i]->getPosition().y][HYPER_INDEX] = ' ';
                    break;
                case 'A': percept[guards[i]->getPosition().x][guards[i]->getPosition().y][AGGRESSOR_INDEX] = ' ';
                    break;
            }
            guards[i]->move();
        }
        updatePercepts();
        updateState();
    }
    catch(const char* msg) {
        updatePercepts();
        updateState();
        std::cout << msg;
        return;
    }
}

std::string Building::toString() const{
    std::stringstream ss;

    ss << "Rescue mission in progress\n";

    for (size_t row{0}; row < ROW_QTY; ++row) {
        ss << getDivider() << std::endl;
        for (size_t col{0}; col < COL_QTY; ++col)
            ss << '|' << percept[row][col][LOUNGER_INDEX] << percept[row][col][HYPER_INDEX] << percept[row][col][AGGRESSOR_INDEX];
        ss << "|\n";

        for (size_t col{0}; col < COL_QTY; ++col)
            ss << "| " << percept[row][col][SPEC_OP_INDEX] << percept[row][col][SCIENTIST_INDEX];
        ss << "|\n";
    }

    ss << getDivider();

    ss << ((hasScientist) ? "\nYou are carrying the scientist!\n" : "\n");

    ss << "Your move [N,S,W,E,P,C]: ";

    if (state == LOSE) ss << "\nGame over. You have died!";
    if (state == WIN) ss << "\nYou have escaped with the scientist! Humanity is saved!";

    return ss.str();
}

void Building::updatePercepts() {
    percept[specOp->getPosition().x][specOp->getPosition().y][SPEC_OP_INDEX] = 'O';
    percept[scientist->getPosition().x][scientist->getPosition().y][SCIENTIST_INDEX] = 'S';

    for (size_t i{0}; i < guards.size(); ++i) {
        switch (guards[i]->getType()) {
            case 'L':
                percept[guards[i]->getPosition().x][guards[i]->getPosition().y][LOUNGER_INDEX] = 'L';
                break;
            case 'H':
                percept[guards[i]->getPosition().x][guards[i]->getPosition().y][HYPER_INDEX] = 'H';
                break;
            case 'A':
                percept[guards[i]->getPosition().x][guards[i]->getPosition().y][AGGRESSOR_INDEX] = 'A';
                break;
        }
    }
}   

std::ostream& operator<<(std::ostream& out, const Building& a) {
    return (out << a.toString());
}