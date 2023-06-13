#include <iostream>

#ifndef MUSTER_H // if MUSTER_H is not defined then do the following
#define MUSTER_H // define MUSTER_H

#define DICE_COUNT 6
#define WINNING_SCORE 1000

enum Scores{ ZERO = 0, ONE = 2, FIVE = 5, THREE_1 = 10, THREE_2 = 20, THREE_3 = 30,
             THREE_4 = 40, THREE_5 = 50, THREE_6 = 60, THREE_PAIR = 150, STRAIGHT = 300 };

int randomrange(const int, const int);

void play();

bool wantToPlay(const std::string&);

void printGreeting();

void printRules();

std::string getString(const std::string&);

void clearInstream(std::istream&);

void printRoll(const int[], const int);

template<typename T>

T getUserInput(const std::string& prompt)
{
    T input;
    std::cout << prompt;
    std::cin >> input;
    return input;
}

void printScores(const std::string&, const size_t, const std::string&, const size_t);

void playRound(const std::string&, size_t&, const std::string&, size_t&);

void shakeDice(const int);

void rollDice(int[], const int);

void clearArray(int[], const int);

int getScore(const int[], const int);

#endif