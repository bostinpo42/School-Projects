// who: <Austin Ngo - ango26>
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.>

// includes go here
#include <iostream>
#include <random>
#include <cstdlib>

int randRange(const int, const int);

int main(int argc, char const *argv[])
{
    std::random_device rd;
    std::mt19937_64 rndEng(rd());
    std::uniform_int_distribution<int> uniform_dist(1, 6);

    for(size_t i = 0; i < 100; ++i)
        //  std::cout << uniform_dist(rndEng) << std::endl;
        std::cout << randRange(1, 6) << std::endl;
	
	return 0;
}

int randRange(const int start, const int end)
{
    return rand() % (end - start + 1) + start;
}