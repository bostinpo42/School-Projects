// who: <Austin Ngo - ango26>
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.>

// includes go here
#include <iostream>
#include <cstdlib>
#include <ctime>



int main(int argc, char const *argv[])
{
    srand(static_cast<unsigned int>(time(NULL)));

    for(int i = 0; i < 10; ++i) {
        std::cout << rand() << std::endl;

    }

	rand();
	
	return 0;
}