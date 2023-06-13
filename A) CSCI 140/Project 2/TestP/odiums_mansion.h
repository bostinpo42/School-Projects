// who: <Austin Ngo - ango26>
// what: <header file for odiums_masion.cpp>
// why: <Project 2 Lab Exam, Odiums Mansion>
// when: <05/03/2022>
#ifndef ODIUMS_MANSION_H
#define  ODIUMS_MANSION_H

#define WINDOWS true  

#define ROWS 8
#define COLS 8
#define USER 5

void gameHeader();
void printBoard(char[ROWS][COLS][USER]);
int randomRange(const int, const int);
int checkTile(char[ROWS][COLS], int, int);
void generateHazards(char[ROWS][COLS]);
void printHazards(int, int, char[ROWS][COLS], char[ROWS][COLS][USER]);
void clearScreen();
void clearInstream();

#endif
