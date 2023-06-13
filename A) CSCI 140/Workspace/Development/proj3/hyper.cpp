#include "hyper.h"

Hyper::Hyper(const Position& pos) : Infected(pos, 'H') { }

void Hyper::move(const char move) {
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

int Hyper::randomRange(int min, int max) { return rand() % (max + 1 - min) + min; }

