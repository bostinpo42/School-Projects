// who: <Austin Ngo - ango26>
// what: <main program for building_z>
// why: <Lab Exam 3>
// when: <05/29/2022>

// includes go here
#include <iostream>
#include "building.h"

#define WINDOWS true

void clearScreen()
{
    if(WINDOWS)
        system("CLS");
    else
        system("clear");
}
void clearInstream()
{
    std::cin.clear();
    // Wrong input remains on the stream, so you need to get rid of it
    std::cin.ignore(INT_MAX, '\n');
}

int main(int argc, char const *argv[])
{
	char input;
	Building a;

	std::cout << a << std::endl;

	do {
		std::cin >> input;
		clearScreen();
		a.move(input);
		std::cout << a << std::endl;
		clearInstream();
	} while (a.state == IN_PLAY);

	return 0;
}
