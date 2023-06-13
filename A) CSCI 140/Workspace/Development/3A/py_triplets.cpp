// who: <Austin Ngo - ango26>
// what: <the function of this program>
// why: <the name of the lab>
// when: <03/21/2022>

// includes go here
#include <iostream>
#include <iomanip>
#include <cmath>

#include "py_triplets.h"

int main(int argc, char const *argv[])
{
    std::cout << std::left
              << std::setw(10) << "a" << std::setw(10) << "b" << "c\n"; 

    generateTriplets(1000);	
	return 0;
}

void generateTriplets(const int maxSize)
{
    int a{1};

    for(; a < maxSize - 1; ++a)
        if (generateSideB(a, maxSize) == a + 1) break;
}

int generateSideB(const int a, const int maxSize)
{
    int b{};
    double c{};

    for(b = a + 1; b < maxSize; ++b)
        {
            c = sqrt(a*a + b*b);
            if(c > maxSize) break;

            if(floor(c) == c) printTriplet(a, b, c);
        }
    return b;
}

void printTriplet(const int a, const int b, const int c)
{
    std::cout << std::setw(10) << a << std::setw(10) << b << c << std::endl; 
}