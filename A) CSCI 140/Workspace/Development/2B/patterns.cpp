// who: <Austin Ngo - ango26>
// what: <prints 4 seperate patterns of asterisks>
// why: <patterns.cpp>
// when: <03/20/2022>

// includes go here
#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout << "(a)\n";
	for(int i = 1; i <= 10; ++i)
    {
        for(int j = 1; j <= i; ++j)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    std::cout << "(b)\n";
    for(int k = 10; k >= 1; --k)
    {
        for(int l = 1; l <= k; ++l)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    std::cout << "(c)\n";
    for(int m = 10; m >= 1; --m)
    {
        for(int n = 0; n < 10 - m; ++n)
        {
            std::cout << " ";
        }
        for(int o = 1; o <= m; ++o)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    std::cout << "(d)\n";
    for(int p = 0; p <= 10; ++p)
    {
        for(int q = 0; q < 11 - p; ++q)
        {
            std::cout << " ";
        }
        for(int r = 0; r < p; ++r)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }

	
	return 0;
}