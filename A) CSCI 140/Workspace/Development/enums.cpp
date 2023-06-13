// who: <Austin Ngo - ango26>
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.>

// includes go here
#include <iostream>

enum class BPlayer {KING, QUEEN, BISHOP, ROOK, KNIGHT, PAWN};
enum class WPlayer {KING, QUEEN, BISHOP, ROOK, KNIGHT, PAWN};
enum Side {WHITE, BLACK};

void initBoard(WPlayer[8][8], WPlayer);

int main(int argc, char const *argv[])
{
	// your code goes here
	
	return 0;
}

void initBoard(WPlayer b[8][8], WPlayer p)
{
    for(size_t i = 0; i < 8; ++i)
        for(size_t j = 0; j < 8; ++j)
        b[i][j] = (p == WPlayer::KING) ? WPlayer::QUEEN : p;
}