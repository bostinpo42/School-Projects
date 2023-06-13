// who: <Austin Ngo - ango26>
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.>

// includes go here
#include <random>
#include <iomanip>
#include <climits>
#include <string>
#include "muster.h"

int main(int argc, char const *argv[]) {
	bool playAgain {};
	printGreeting();
	printRules();

	playAgain = wantToPlay("Would you like to play (Y/N)? ");

	while (playAgain)
	{
		play();
		playAgain = wantToPlay("Would you like to play again (Y/N)? ");
	}

	return 0;
}

bool wantToPlay(const std::string& prompt) {
	char choice { tolower(getUserInput<char>(prompt)) };

	if (choice == 'y' || choice == 'n')
		return (choice == 'y');

	std::cout << "\n Invalid choice!\nPlease try again.\n";

	return wantToPlay(prompt);
}

void play() {
	size_t player1Score{};
	size_t player2Score{};
	std::string player1Name{ getString("Enter the first player's name: ") };
	std::string player2Name{ getString("Enter the second player's name: ") };

	while( (player1Score < WINNING_SCORE && player2Score < WINNING_SCORE) || player1Score != player2Score ) {
		printScores(player1Name, player1Score, player2Name, player2Score);

		playRound(player1Name, player1Score, player2Name, player2Score);
	}

}

void printWelcome() {
	std::cout << "Welcome to Muster!\n" 
		<< "The first player to reach 1000 points and exceed the other player's score wins.\n\n";
	
}

void playRound(const std::string& player1Name, size_t& player1Score, const std::string& player2Name, size_t& player2Score) {
	int p1ShakeCount{};
	int p2ShakeCount{};
	int dice[6]{0};

	p1ShakeCount = getUserInput<int>("How many times would " + player1Name + " like to shake the dice? ");
	shakeDice(p1ShakeCount);
	rollDice(dice, DICE_COUNT);
	printRoll(dice, DICE_COUNT);
	player1Score += getScore(dice, DICE_COUNT);

	p2ShakeCount = getUserInput<int>("How many times would " + player2Name + " like to shake the dice? ");
	shakeDice(p2ShakeCount);
	rollDice(dice, DICE_COUNT);
	printRoll(dice, DICE_COUNT);
	player2Score += getScore(dice, DICE_COUNT);
}

void printGreeting() {
	std::cout << "Welcome to Muster!\n"
			  << "The first player to reach 1000 and exceed the other player's score wins.\n\n";
}

void printRules() {
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

std::string getString(const std::string& prompt) {
	std::string name{};
	std::cout << prompt;
	std::getline(std::cin, name);
	return name;
}

char getChoice(const std::string& prompt) {
	char choice = tolower(getUserInput<char>("Would you like to play (Y/N)? "));
	while (choice != 'n' && choice != 'y') {
		std::cout << "Invalid choice!\n";
		choice = tolower(getUserInput<char>("Would you like to play (Y/N)? "));
	}
	return choice;
}

void clearArray(int array[], const int size) {
	for (size_t i = 0; i < size; ++i) array[i] = 0;
}

void printScores(const std::string& player1Name, const size_t& player1Score, const std::string& player2Name, const size_t& player2Score) {
	std::cout << "The scores are: \n"
	<< "\t" << std::left << std::setw(10) << player1Name + ":" << std::right << std::setw(5) << player1Score << std::endl
	<< "\t" << std::left << std::setw(10) << player2Name + ":" << std::right << std::setw(5) << player2Score << std::endl;
}

void shakeDice(const int count) {
	for (size_t i = 0; i < count; ++i)
		for(int j = 0; j < 6; ++j)
		randomRange(0, 5);
}

void rollDice(int dice[], const int size) {
	clearArray(dice, size);

	for (size_t i = 0; i < size; ++i) {
		++dice[randomRange(0,5)];
	}
}

int getScore(const int dice[], const int size) {
	bool isStraight{true};
	bool has1{dice[0]};
	bool has5{dice[4]};
	int threeOfKindFace{-1};
	int pairCounter{0};

	for (size_t i = 0; i < size; ++i)
	{
		if(dice[i] != 1) isStraight = false;
		if(dice[i] >= 3) threeOfKindFace = 1;
		pairCounter += dice[i] / 2;
	}
	
	if (isStraight) return static_cast<int>(STRAIGHT);
	if (pairCounter >= 3) return THREE_PAIR;
	if (threeOfKindFace > -1) return 10 * (threeOfKindFace + 1);
	if (has5) return FIVE;
	return (has1) ? ONE : ZERO;
}

void printRoll(const int dice[], const int size) {
	std::cout << "The roll is: ";
	for (size_t i = 0; i < size; ++i)
		for (int j = 0; j < dice[i]; ++j)
		std::cout << " " << i + 1;
}

int randomRange(const int start, const int end) {
    static std::random_device rd;
    static std::default_random_engine rndEng(time(0));
    static std::uniform_int_distribution<int> uniformDist(start, end);
    return uniformDist(rndEng);
}

void clearInstream(std::istream& inStream) {
	inStream.clear();
	inStream.ignore(INT_MAX, '\n');
}



