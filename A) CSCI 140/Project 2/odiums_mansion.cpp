// who: <Austin Ngo - ango26>
// what: <Simulates a game of Odiums Mansion>
// why: <Project 2 Lab Exam, Odiums Mansion>
// when: <05/03/2022>

#include <iostream>
#include <random>
#include <ctime>

#include "odiums_mansion.h"

int main(int argc, char const *argv[]) {
    std::string display[ROWS][COLS]{" ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "};
    std::string history[ROWS][COLS][USER]{" ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "};
    int gameState{GameState::INPLAY};
    char input;
    int valid{0};
    int rows{0};
    int cols{0};

    generateBoard(display);

    while(gameState == GameState::INPLAY) {
        history[rows][cols][0] = "U";
        clearScreen();
        gameHeader();
        printHazards(rows, cols, display, history);
        printBoard(history);
        clearInstream();
    }

    return 0;
}

void gameHeader() {
    std::cout << "Aldrac Dungeon Simulator\n" << "Avoid at all costs the pits and the evil Aldrac, cursed be his name!\n";
}

void printBoard(std::string history[ROWS][COLS][USER]) {
    for (size_t i = 0; i < ROWS; ++i) {
            std::cout << "-------------------------------------------------\n";
        for (size_t j = 0; j < COLS; ++j) {
            std::cout << "|" << "     ";
        }
            std::cout << "|\n";
        for (size_t j = 0; j < COLS; ++j) {
            std::cout << "|" << history[i][j] << "    ";
        }
            std::cout << "|\n";
    }
    std::cout << "-------------------------------------------------\n";
}

char validInput(int valid, int rows, int cols, std::string history[ROWS][COLS][USER]) {
    char input;
    if (valid == 1)
        {
            std::cout << "Invalid input" << std::endl;
            valid = 0;
        }
        else if (valid == 2)
        {
            std::cout << "picked up the gold" << std::endl;
            valid = 3;
            history[rows][cols][0] = " ";
            rows = 0;
            cols = 0;
        }
        else if (valid == 3)
        {
            std::cout << "You have found the gold" << std::endl;
            exit(0);
        }
        std::cout << "Enter your move" << std::endl
             << "(R)ight (L)eft (U)p (D)own (P)ick up gold" << std::endl;
        std::cin >> input;
    return input;
}

void userInput(char input, int valid, int rows, int cols, std::string display[ROWS][COLS], std::string history[ROWS][COLS][USER]) {
    switch (toupper(input))
        {
        case 'D':
            if (rows + 1 >= ROWS)
                valid = 1;
            else
            {
                history[rows][cols][0] = " ";
                ++rows;
            }
            break;
        case 'U':
            if (rows - 1 < 0)
                valid = 1;
            else
            {
                history[rows][cols][0] = " ";
                --rows;
            }
            break;
        case 'L':
            if (cols - 1 < 0)
                valid = 1;
            else
            {
                history[rows][cols][0] = " ";
                --cols;
            }
            break;
        case 'R':
            if (cols + 1 >= COLS)
                valid = 1;
            else
            {
                history[rows][cols][0] = " ";
                ++cols;
            }
            break;
        case 'P':
            if (display[rows][cols] == "G")
                valid = 2;
            else
                valid = 1;
            break;
        default:
            valid = 1;
        }
}

int randomRange(const int start, const int end) {
    static std::random_device rd;
    static std::default_random_engine rndEng(time(0));
    static std::uniform_int_distribution<int> uniformDist(start, end);
    return uniformDist(rndEng);
}

int checkTile(std::string display[ROWS][COLS], int rows, int cols) {
    if (display[rows][cols] != " ")
        return 0;
    if ((rows - 1 >= 0) && (display[rows - 1][cols] != " "))
        return 0;
    if ((rows + 1 < ROWS) && (display[rows + 1][cols] != " "))
        return 0;
    if ((cols - 1 >= 0) && (display[rows][cols - 1] != " "))
        return 0;
    if ((cols + 1 < COLS) && (display[rows][cols + 1]!= " "))
        return 0;
    return 1;
}

void generatePits(std::string display[ROWS][COLS]) {    
    int pitCount{12};
    int rows{0};
    int cols{0};

    for (size_t i = 0; i <= pitCount; ++i) {
        rows = randomRange(1,8);
        cols = randomRange(1,8);
        if ((rows <= 1 && cols <= 1) && (rows != 1 || cols != 1))
            continue;
        if (display[rows][cols] == " ")
        {
            display[rows][cols] = "B";
            break;
        }
    }
}

void generateGold(std::string display[ROWS][COLS]) {
    int rows{0};
    int cols{0};

    for(size_t i = 0; i < ROWS; ++i) {
        rows = randomRange(1,8);
        cols = randomRange(1,8);

        if ((rows <= 1 && cols <= 1) && (rows != 1 || cols != 1)) {
            --i;
            continue; 
            }
        if (checkTile(display, rows, cols) == 1) {
            display[rows][cols] = "G";
            break;
        }
        else {
            --i;
            continue;
        }
    }    
}

void generateAldrac(std::string display[ROWS][COLS]) {
    int rows{0};
    int cols{0};
    for(size_t i = 0; i < ROWS; ++i) {
        rows = randomRange(1,8);
        cols = randomRange(1,8);

        if ((rows <= 1 && cols <= 1) && (rows != 1 || cols != 1)) {
            --i;
            continue; 
            }
        if (checkTile(display, rows, cols) == 1) {
            display[rows][cols] = "A";
        }
        else {
            --i;
            continue;
        }
    }    
}

void generateBoard(std::string display[ROWS][COLS]) {
    generatePits(display);
    generateGold(display);
    generateAldrac(display);
}

void printHazards(int rows, int cols, std::string display[ROWS][COLS], std::string history[ROWS][COLS][USER])
{
    if (display[rows][cols] == "G")
        history[rows][cols][1] = "G";
    if ((display[rows][cols] == "B") || (history[rows][cols][1] == "A")) {
        std::cout << "GAME OVER" << std::endl;
        exit(0);
    }
    if (rows - 1 >= 0) {
        if (display[rows - 1][cols] == "A")
            history[rows][cols][2] = "B";
        if (display[rows - 1][cols] == "B")
            history[rows][cols][3] = "S";
    }
    if (rows + 1 < 4) {
        if (display[rows + 1][cols] == "A")
            history[rows][cols][2] = "B";
        if (display[rows + 1][cols] == "B")
            history[rows][cols][3] = "S";
    }
    if (cols - 1 >= 0) {
        if (display[rows][cols - 1] == "A")
            history[rows][cols][2] = "B";
        if (display[rows][cols - 1] == "B")
            history[rows][cols][3] = "S";
    }
    if (cols + 1 < 4) {
        if (display[rows][cols + 1] == "A")
            history[rows][cols][2] = "B";
        if (display[rows][cols + 1] == "B")
            history[rows][cols][3] = "S";
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




