// who: <Austin Ngo - ango26>
// what: <shows the results of summing 2 dice>
// why: <Lab 4A Questions>
// when: <04/15/2022>

// includes go here
#include <iostream>
#include <iomanip>
#include <random>
#include <array>

int main(int argc, char const *argv[])
{
    const int ARRAY_SIZE{13};
	int rollCount{600'000};
    int die1{};
    int die2{};

    std::array<int, ARRAY_SIZE> dieSum{0};
    std::array<float, ARRAY_SIZE> expected{0,0,2.778,5.556,8.333,11.111,13.889,16.667,13.889,11.111,8.333,5.556,2.778};

    while(rollCount > 0) {
        die1 = 1 + (rand() % 6);
        die2 = 1 + (rand() % 6);
        ++dieSum[die1 + die2];
        --rollCount;
    }

    std::cout << "Sum    " << "Total    " << "Expected    " << "Actual    " << std::endl;

    for (size_t i = 2; i < 13; ++i)
    {
        float actual = ( (float)dieSum.at(i) / (float)600'000 ) * 100; 
        std::cout << std::right << std::fixed << std::setprecision(3) << std::setw(2) << i << std::setw(10) << dieSum.at(i) 
                  << std::setw(10) << expected.at(i) << "%"  << std::setw(10) << actual << "%" << std::endl;
    }
	
	return 0;
}


