#include <iostream>
#include <cstdlib>
#include <ctime>

#include "dungeon.h"
int main(int argc, char const *argv[])
{
	Dungeon d;

	//srand(time(NULL));
	std::cout << d.toString() << std::endl;
	return 0;
}