// who: <Austin Ngo - ango26>
// what: <Simulates a game of Odiums Mansion>
// why: <Project 2 Lab Exam, Odiums Mansion>
// when: <05/03/2022>

#include <iomanip>
#include <iostream>
#include <random>
#include <ctime>
#include <cstring>

#include "odiums_mansion.h"

int main(int argc, char const *argv[]) {
    char display[ROWS][COLS];
    char history[ROWS][COLS][USER];
    char input;
    int valid{0};
    int rows{0};
    int cols{0};

    memset(display[0], ' ', 64);
    memset(history[0][0], ' ', 320);

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            history[i][j][USER] = '\0';

    generateHazards(display);
    
    while(true) {
        clearScreen();
        gameHeader();
        history[rows][cols][0] = 'U';
        printHazards(rows, cols, display, history);
        printBoard(history);

        if (valid == 1) {
            std::cout << "Invalid input!" << std::endl;
            valid = 0;
        }
        else if (valid == 2) {
            std::cout << "Picked up the gold" << std::endl;
            valid = 3;
            history[rows][cols][0] = ' ';
            rows = 0;
            cols = 0;
        }
        else if (valid == 3 && history[0][0][0]) {
            std::cout << "You have escaped with the gold!" << std::endl;
            exit(0);
        }
        std::cout << "Enter your move" << std::endl
            << "(R)ight (L)eft (U)p (D)own (P)ick up gold" << std::endl;
        std::cin >> input;

        switch (toupper(input)) {
        case 'D':
            if (rows + 1 >= 8) valid = 1;
            else {
                history[rows][cols][0] = ' ';
                rows++;
            }
            break;
        case 'U':
            if (rows - 1 < 0) valid = 1;
            else {
                history[rows][cols][0] = ' ';
                rows--;
            }
            break;
        case 'L':
            if (cols - 1 < 0) valid = 1;
            else {
                history[rows][cols][0] = ' ';
                cols--;
            }
            break;
        case 'R':
            if (cols + 1 >= 8) valid = 1;
            else {
                history[rows][cols][0] = ' ';
                cols++;
            }
            break;
        case 'P':
            if (display[rows][cols] == 'G') valid = 2;
            else valid = 1;
            break;
        default:
            valid = 1;
        }

    clearScreen();
    clearInstream();

    }
    
    return 0;
}

void gameHeader() {
    std::cout << "Aldrac Dungeon Simulator\n" << "Avoid at all costs the pits and the evil Aldrac, cursed be his name!\n";
}

void printBoard(char history[ROWS][COLS][USER]) {
    for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++)
                printf("---------");
            printf("\n");
            printf("|");
            for (int j = 0; j < COLS; j++)
                printf("%8s|", history[i][j]);
            printf("\n");
            printf("|");
            for (int j = 0; j < COLS; j++)
                printf("        |");
            printf("\n");
        }
        for (int j = 0; j < COLS; j++)
            printf("---------");
        printf("\n");
}

int randomRange(const int start, const int end) {
    static std::random_device rd;
    static std::default_random_engine rndEng(time(0));
    static std::uniform_int_distribution<int> uniformDist(start, end);
    return uniformDist(rndEng);
}

int checkTile(char display[ROWS][COLS], int rows, int cols) {
    if (display[rows][cols] != ' ')
        return 0;
    if ((rows - 1 >= 0) && (display[rows - 1][cols] != ' '))
        return 0;
    if ((rows + 1 < ROWS) && (display[rows + 1][cols] != ' '))
        return 0;
    if ((cols - 1 >= 0) && (display[rows][cols - 1] != ' '))
        return 0;
    if ((cols + 1 < COLS) && (display[rows][cols + 1]!= ' '))
        return 0;
    return 1;
}

void generateHazards(char display[ROWS][COLS]) {
    int pitCount{12};
    int rows;
    int cols;
    for (int i = 0; i < pitCount ; ++i) {
        rows = randomRange(1,8);
        cols = randomRange(1,8);
        if ((rows <= 1 && cols <= 1) && (rows != 1 || cols != 1)) {
            i--;
            continue;
        }
        if (checkTile(display, rows, cols) == 1)
            display[rows][cols] = 'A';
        else {
            i--;
            continue;
        }
    }
    while (1) {
        rows = randomRange(1,8);
        cols = randomRange(1,8);
        if ((rows <= 1 && cols <= 1) && (rows != 1 || cols != 1))
            continue;
        if (display[rows][cols] == ' ') {
            display[rows][cols] = 'B';
            break;
        }
    }
    while (1) {
        rows = randomRange(1,8);
        cols = randomRange(1,8);
        if ((rows <= 1 && cols <= 1) && (rows != 1 || cols != 1))
            continue;
        if (display[rows][cols] == ' ') {
            display[rows][cols] = 'G';
            break;
        }
    }
}

void printHazards(int rows, int cols, char display[ROWS][COLS], char history[ROWS][COLS][USER])
{
    if (display[rows][cols] == 'G')
        history[rows][cols][1] = 'G';
    if ((display[rows][cols] == 'B') || (history[rows][cols][1] == 'A')) {
        std::cout << "GAME OVER" << std::endl;
        exit(0);
    }
    if (rows - 1 >= 0) {
        if (display[rows - 1][cols] == 'A')
            history[rows][cols][2] = 'B';
        if (display[rows - 1][cols] == 'B')
            history[rows][cols][3] = 'S';
    }
    if (rows + 1 < 8) {
        if (display[rows + 1][cols] == 'A')
            history[rows][cols][2] = 'B';
        if (display[rows + 1][cols] == 'B')
            history[rows][cols][3] = 'S';
    }
    if (cols - 1 >= 0) {
        if (display[rows][cols - 1] == 'A')
            history[rows][cols][2] = 'B';
        if (display[rows][cols - 1] == 'B')
            history[rows][cols][3] = 'S';
    }
    if (cols + 1 < 8) {
        if (display[rows][cols + 1] == 'A')
            history[rows][cols][2] = 'B';
        if (display[rows][cols + 1] == 'B')
            history[rows][cols][3] = 'S';
    }
}

void clearScreen() {
    if(WINDOWS)
        system("CLS");
    else
        system("clear");
}

void clearInstream() {
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
}




