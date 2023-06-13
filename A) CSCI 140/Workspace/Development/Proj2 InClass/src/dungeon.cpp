#include <cstdlib>
#include <stdexcept>

#include "dungeon.h"
#include "position.h"

void Dungeon::init() {
    user = {0,0};
    hasGold = false;
    initPercept();
    initArtifact();
}

void Dungeon::initPercept() {
    for (size_t rows{0}; rows < ROW_QTY; ++rows) {
        for (size_t cols{0}; cols < COL_QTY; ++cols) {
            percept[rows][cols] = "     ";
        }
    }
}

void Dungeon::initArtifact() {
    Position p;
    initPits();
    p = getRandomPosition();
    artifacts[p.x][p.y] = ALDRAC;
    p = getRandomPosition();
    artifacts[p.x][p.y] = GOLD;

}

void Dungeon::initPits() {
    Position p {getRandomPosition()};
    for(size_t i{0}; i < PIT_QTY; ++i) {
        artifacts[p.x][p.y] = PIT;
    }
}

Position Dungeon::getRandomPosition() {
    int count{0};
    int px;
    int py;

    do {
        px = randomRange(0, ROW_QTY);
        py = randomRange(0, COL_QTY);
        artifacts[px][py] = PIT;
    } while (artifacts[px][py] != EMPTY || px + py <= 1);

    return {px, py};
}

int Dungeon::randomRange(int start, int end) { return rand() % (end - start) + start; }

bool Dungeon::isValidMove(const Position& dest) {
    return (abs(user.x - dest.x) + abs(user.y - dest.y)) < 2 
        && dest.x >= 0 && dest.y >= 0
        && dest.x < ROW_QTY && dest.y < COL_QTY;
}

void Dungeon::move(const Position& dest) {
    if (!isValidMove(dest)) {
        throw std::invalid_argument("Invalid move!");
    }
    else
        user == dest;
}

void Dungeon::pickUp() {
    if(artifacts[user.x][user.y] != GOLD)
        throw std::invalid_argument("Gold is not in this cell!");
    hasGold = true;
}