// who: <Austin Ngo - ango26>
// what: <simulates a game of craps>
// why: <craps.cpp>
// when: <03/27/2022>

// includes go here
#include <iostream>
#include <iomanip>
#include <random>
#include <functional>

typedef std::function<int(const int, const int)> rndFunc;

int diceRoll(rndFunc);
int randomRange(const int, const int);

int main(int argc, char const *argv[]) {
    enum class Status { KEEPROLLING, LOSS, WIN }; 
	const int FACE_QTY{6};
    int rollSum{diceRoll(randomRange)};
    int playerPoint{0};
    Status gameState;
    int start{0};

    std::cout << "Welcome to the Craps Simulator! To begin please press '1'\n";
    std::cin >> start;

    while(start == 1) {
        switch (rollSum) {
            case 7:
            case 11:
                gameState = Status::WIN;    
                break;
            case 2:
            case 3:
            case 12:
                gameState = Status::LOSS;
                break;
            default:
                gameState = Status::KEEPROLLING;
                playerPoint = rollSum;
                std::cout << "Player 'Point' is : " << rollSum << std::endl;
                break;
        }

        do {
            rollSum = diceRoll(randomRange);
            if (rollSum == playerPoint) {
                gameState = Status::WIN;
            }
            else if (rollSum == 7) {
            gameState = Status::LOSS;
            }
        } while (Status::KEEPROLLING == gameState);
    
        
        if (Status::WIN == gameState) {
            std::cout << "Player wins! Congratulations!\n";
        }
        else {
            std::cout << "Player loses. Better luck next time!\n";
        }

        std::cout << "Continue? (1 to continue)\n";
        std::cin >> start;
    }   

	return 0;
}

int diceRoll(rndFunc rnd) {
    int roll1{randomRange(1, 6)};
    int roll2{randomRange(1, 6)};
    int rollsum{roll1 + roll2};

    std::cout << "Roll result: " << roll1 << " + " << roll2 << " = " << rollsum << "\n";

    return rollsum;
}

int randomRange(const int start, const int end) {
    static std::random_device rd;
    static std::default_random_engine rndEng(time(0));
    static std::uniform_int_distribution<int> uniformDist(start, end);
    return uniformDist(rndEng);
}