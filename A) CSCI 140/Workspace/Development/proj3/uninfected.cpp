#include <cstdlib>
#include <stdexcept>
#include "uninfected.h"
#include "position.h"   

#define ROW_QTY 10
#define COL_QTY 8

Uninfected::Uninfected(const Position& pos, char type) : Person(pos, type) {}

void Uninfected::move(const char move) {
    switch (move) {
        case 'N':
            if(pos->x != 0) {
            pos->x = pos->x-1;
            }
            else { throw "Invalid move!\n"; }
            break;
        case 'S':
            if(pos->x != ROW_QTY - 1) {
            pos->x = pos->x+1;
            }
            else { throw "Invalid move!\n"; }
            break;
        case 'W':
            if(pos->y != 0) {
            pos->y = pos->y-1;
            }
            else { throw "Invalid move!\n"; }
            break;
        case 'E': 
            if(pos->y != COL_QTY - 1) {
            pos->y = pos->y+1;
            }
            else { throw "Invalid move!\n"; }
            break;
        case 'P':
            break;
        case 'C':
            break;
        default:
            throw "Invalid move!\n";
            break;
    }
}


