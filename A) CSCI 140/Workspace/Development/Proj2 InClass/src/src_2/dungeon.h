#include <string>

#include "position.h"

#ifndef DUNGEON_H
#define DUNGEON_H

#define ROW_QTY 8
#define COL_QTY 8
#define GOLD_QTY 1
#define ALDRAC_QTY 1
#define PIT_QTY 0.1875 * ROW_QTY * COL_QTY // we are using probability so that if we modify the size of the dungeon there should be  
                                           // an equivalent amount of pits relative to the size of the dungeon

enum Artifact : unsigned char {ALDRAC = 0b0001, PIT = 0b0010, GOLD = 0b0100, EMPTY = 0b0000};
enum GameStates {IN_PLAY, WIN, LOSE};

class Dungeon {
    friend std::ostream& operator<<(std::ostream, const Dungeon&);

private:
    std::string percept[ROW_QTY][COL_QTY]{};
    Artifact artifacts[ROW_QTY][COL_QTY]{};
    Position user;
    GameStates state;
    bool hasGold;

    void init();
    void initPercept();
    void initArtifact();
    void initPits();
    void update();
    void initDungeon();
    void updateState();
    void updatePercepts();

    int randomRange(int, int) const; // not including end
    Position getRandomPosition() const;
    bool isValidMove(const Position&) const;

public:
    Dungeon();
    std::string toString() const;
    void move(const Position&);
    void pickUp();
};

#endif