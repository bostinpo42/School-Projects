// who: <Austin Ngo - ango26>
// what: <Simulates a game of Muster.>
// why: <muster.cpp>
// when: <04/03/2022>

#include <iostream>
#include <iomanip>
#include <random>
#include <functional>
#include <string>

typedef std::function<int(const int, const int)> rndFunc;

void printRules();
void diceRoll(const int, rndFunc, int);
int randomRange(const int, const int);
void play();
int keepScore(int[], const int);
void printRollResult(const int[], const int);
void printScores(std::string, std::string, const int, const int);
int getValidCount(const int);

int main(int argc, char const *argv[])
{
	char beginGame {};

	printRules();	
	
	std::cout << "Would you like to play (Y/N) ? ";
	std::cin >> beginGame;

	if (beginGame == 'Y' || beginGame == 'y') {
		play();
		std::cout << "\n---- Hasta La Vista Baby ----\n";
	}

	else {
		std::cout << "\n---- Hasta La Vista Baby ----\n";
	}
	return 0;
}

void printRules() {
	std::cout << "Welcome to Muster!\n" << "The first player to reach 1000 points and exceed the other player's score wins.\n\n";
	std::cout << "Scoring: \n";
	std::cout << std::left << "     1" << std::setw(25) << std::right << "2 points\n";
	std::cout << std::left << "     5" << std::setw(25) << std::right << "5 points\n";
	std::cout << std::left << "     Three 1's" << std::setw(17) << std::right << "10 points\n";
	std::cout << std::left << "     Three 2's" << std::setw(17) << std::right << "20 points\n";
	std::cout << std::left << "     Three 3's" << std::setw(17) << std::right << "30 points\n";
	std::cout << std::left << "     Three 4's" << std::setw(17) << std::right << "40 points\n";
	std::cout << std::left << "     Three 5's" << std::setw(17) << std::right << "50 points\n";
	std::cout << std::left << "     Three 6's" << std::setw(17) << std::right << "60 points\n";
	std::cout << std::left << "     Three pairs" << std::setw(15) << std::right << "150 points\n";
	std::cout << std::left << "     1-2-3-4-5-6" << std::setw(16) << std::right << "300 points\n\n";
}

void diceRoll(int rollResult[], int dieTotal[], const int size, rndFunc rnd, int rollCount) {
	for (size_t i = 0; i <= rollCount; ++i){
		for (size_t j = 1; j < size + 1; ++j) rollResult[j] = randomRange(1,6);
	}
	for (size_t i = 0; i < size + 1; i++) dieTotal[i] = 0;
	for (size_t i = 1; i < size + 1; ++i) ++dieTotal[rollResult[i]];
}

int keepScore(int dieTotal[], const int size) {
	int score{0};
	while (true) {
		for (size_t i = 0; i < size + 1; ++i) {
			int count {0};
			if (dieTotal[i] == 1) {
			++count;
				if (count == 6) {
					score = 300;
					return score;
				}
			}
		}
		if ( (dieTotal[1] >= 4 || dieTotal[2] >= 4 || dieTotal[3] >= 4 || dieTotal[4] >= 4 || dieTotal[5] >= 4 || dieTotal[6] >= 4) &&
		     (dieTotal[1] == 2 || dieTotal[2] == 2 || dieTotal[3] == 2 || dieTotal[4] == 2 || dieTotal[5] == 2 || dieTotal[6] == 2) ) {
			score = 150;
			break;
		}
		if (dieTotal[1] == 6 || dieTotal[2] == 6 || dieTotal[3] == 6 || dieTotal[4] == 6 || dieTotal[5] == 6 || dieTotal[6] == 6) {
			score = 150;
			break;
		}
		for (size_t i = 0; i < size + 1; ++i) {
			int count {0};
			if (dieTotal[i] == 2) { 
				++count;
				if (count >= 3) {
					score = 150;
					return score;
				}
			}
		}
		if (dieTotal[6] >= 3) {
			score = 60;
			break;
		}
		if (dieTotal[5] >= 3) {
			score = 50;
			break;
		}
		if (dieTotal[4] >= 3) {
			score = 40;
			break;
		}
		if (dieTotal[3] >= 3) {
			score = 30;
			break;
		}
		if (dieTotal[2] >= 3) {
			score = 20;
			break;
		}
		if (dieTotal[1] >= 3) {
			score = 10;
			break;
		}
		if (dieTotal[5] >= 1) {
			score = 5;
			break;
		}
		if (dieTotal[1] >= 1) {
			score = 2;
			break;
		}
		else break;
	}
	return score;
}

int randomRange(const int start, const int end) {
    static std::random_device rd;
    static std::default_random_engine rndEng(time(0));
    static std::uniform_int_distribution<int> uniformDist(start, end);
    return uniformDist(rndEng);
}

void play() {
	std::string player1;
	std::string player2;
	const int MAX_SCORE{1'000};
	const int FACE_QTY{6};
	int turnCount{1};
	int rollCount;
	int prevScore{0};
	int p1Score{0};
	int p2Score{0};
	int rollResult[FACE_QTY];
	int dieTotal[FACE_QTY];
	char contGame{};
	
	std::cout << "\nEnter the first player's name: ";
	std::cin >> player1;
	std::cout << "Enter the second player's name: ";
	std::cin >> player2;
	std::cout << std::endl;

	while(p1Score <= MAX_SCORE && p2Score <= MAX_SCORE) {
		printScores(player1, player2, p1Score, p2Score);
		std::cout << "Turn " << turnCount << std::endl << "------\n";
		std::cout << "     How many times would " << player1 << " like to shake the dice? (1 - 1000) ";
		rollCount = getValidCount(MAX_SCORE);
		diceRoll(rollResult, dieTotal, FACE_QTY, randomRange, rollCount);
		printRollResult(rollResult, FACE_QTY);
		prevScore = keepScore(dieTotal, FACE_QTY);
		p1Score += prevScore;
		std::cout << std::setw(11) << std::right << player1 << " earns " << prevScore << " point(s)\n\n";

		rollCount = 0;
		for (size_t i = 0; i < FACE_QTY + 1; ++i){
			rollResult[i] = 0;
			dieTotal[i] = 0;
		}
	
		std::cout << "     How many times would " << player2 << " like to shake the dice? (1 - 1000) ";
		rollCount = getValidCount(MAX_SCORE);
		diceRoll(rollResult, dieTotal, FACE_QTY, randomRange, rollCount);
		printRollResult(rollResult, FACE_QTY);
		prevScore = keepScore(dieTotal, FACE_QTY);
		p2Score += prevScore;
		std::cout << std::setw(11) << std::right << player2 << " earns " << prevScore << " point(s)\n\n";
		++turnCount;
	}

	printScores(player1, player2, p1Score, p2Score);
	if (p1Score >= MAX_SCORE && p1Score > p2Score) {
	 std::cout << player1 << " Wins! \n\n";
	}
	else std::cout << player2 << " Wins! \n\n";

	std::cout << "Would you like to play again (Y/N) ? ";
	std::cin >> contGame;

	if (contGame == 'Y' || contGame == 'y') {
		play();
	}
	
}

void printRollResult(const int rollResult[], const int size) {
	std::cout << "     The roll is: ";
	for (size_t i = 1; i <= size; ++i)
		std::cout << rollResult[i] << " ";
	std::cout << std::endl;
}

void printScores(std::string player1, std::string player2, const int p1Score, const int p2Score) {
	std::cout << "The scores are: \n";
	std::cout << std::setw(10) << player1 << " : " << std::setw(15) << std::right << p1Score << std::endl;
	std::cout << std::setw(10) << player2 << " : " << std::setw(15) << std::right << p2Score << std::endl << std::endl;
}

int getValidCount(const int maxScore) {
    int val{0};
    std::cin >> val;

    if(val < 1 || val > maxScore) {
        std::cout << "Please enter a value between 1 and 1000: \n";
        return getValidCount(maxScore); 
    }
    return val;
}

