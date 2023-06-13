// who: <Austin Ngo - ango26>
// what: <header file for odiums_masion.cpp>
// why: <Project 2 Lab Exam, Odiums Mansion>
// when: <05/03/2022>
#ifndef ODIUMS_MANSION_H
#define  ODIUMS_MANSION_H

#define WINDOWS true  

#define ROWS 8
#define COLS 8
#define USER 8

enum GameState { INPLAY = 0, WON = 1, LOST = 0 };

void gameHeader();
void printBoard(std::string[ROWS][COLS][USER]);
char validInput(int, int, int, std::string[ROWS][COLS][USER]);
void userInput(char, int, int, int, std::string[ROWS][COLS], std::string[ROWS][COLS][USER]);
int randomRange(const int, const int);
int checkTile(std::string [ROWS][COLS], int, int);
void generatePits(std::string [ROWS][COLS]);
void generateGold(std::string [ROWS][COLS]);
void generateAldrac(std::string[ROWS][COLS]);
void generateBoard(std::string [ROWS][COLS]);
void printHazards(int, int, std::string[ROWS][COLS], std::string[ROWS][COLS][USER]);
void clearScreen();
void clearInstream();

#endif
