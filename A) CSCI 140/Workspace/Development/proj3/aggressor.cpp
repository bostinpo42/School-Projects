#include "aggressor.h"

Aggressor::Aggressor(Position const& pos, Uninfected const& hero) : Infected(pos, 'A'), hero(new Uninfected(hero)), hasSensed{false}  { }

void Aggressor::move(const char move) {
    int xdist = pos->x - hero->getPosition().x;
    int ydist = pos->y - hero->getPosition().y;

    if(!hasSensed && abs(xdist) + abs(ydist) <= 2) {
        hasSensed = true;
    }

    if(hasSensed) {
        if (abs(xdist) == 2 && ydist == 0) {
            if(xdist == -2) {
                pos->x += 1;
                return;
            }
                pos->x -= 1;
                return;
        }
    
        if (abs(ydist) == 2 && xdist == 0) {
            if(ydist == -2) {
                pos->y += 1;
                return;
            }
                pos->y -= 1;
                return;
        } 

        if (abs(xdist) == 1 && ydist == 0) {
            if(xdist == -1) {
                pos->x += 1;
                return;
            }
                pos->x -= 1;
                return;
        }

        if (abs(ydist) == 1 && xdist == 0) {
            if(ydist == -1) {
                pos->y += 1;
                return;
            }
                pos->y -= 1;
                return;
        } 

        if(xdist == 1 && ydist == 1) {
            randomRange(0,1) ? (pos->x-=1) : (pos->y -=1);
            return;
        }

        if(xdist == 1 && ydist == -1) {
            randomRange(0,1) ? (pos->x-=1) : (pos->y+=1);
            return;
        }

        if(xdist == -1 && ydist == 1) {
            randomRange(0,1) ? (pos->x+=1) : (pos->y-=1);
            return;
        }

        if(xdist == -1 && ydist == -1) {
            randomRange(0,1) ? (pos->x+=1) : (pos->y+=1);
            return;
        }
    }
    bool valid{false};
    do {
        switch (randomRange(0,3)) {
            case 1:
                if(pos->x != 0) {
                pos->x -= 1;
                valid = true;
                }
                break;
            case 2:
                if(pos->x != ROW_QTY - 1) {
                pos->x += 1;
                valid = true;
                }
                break;
            case 3:
                if(pos->y != 0) {
                pos->y -= 1;
                valid = true;
                }
                break;
            case 4:
                if(pos->y != COL_QTY - 1) {
                pos->y += 1;
                valid = true;
                }
                break;
        }
    } while (!valid);
}

int Aggressor::randomRange(int min, int max) { return rand() % (max + 1 - min) + min; }
