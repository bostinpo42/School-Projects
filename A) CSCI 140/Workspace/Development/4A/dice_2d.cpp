// who: <Austin Ngo - ango26>
// what: <shows the results of summing 2 dice>
// why: <Lab 4A Questions>
// when: <04/15/2022>

// includes go here
#include <iostream>
#include <iomanip>
#include <array>

int main(int argc, char const *argv[])
{
    const int ARRAY_SIZE{6};
	int rollCount{600'000};
    int die1{};
    int die2{};

    std::array<int, ARRAY_SIZE> arr{0};
    std::array<std::array<int,ARRAY_SIZE>,ARRAY_SIZE> dieCount{arr, arr, arr, arr, arr, arr};

    while(rollCount > 0) {
        die1 = 1 + (rand() % 6);
        die2 = 1 + (rand() % 6);
        ++dieCount[die1 - 1][die2 - 1];
        --rollCount;
    }

    for (size_t i = 0; i <= 6 ; ++i) {
        if (i == 0) { std::cout << "        "; }
        else std::cout << i << "            ";
    }

    std::cout << std::endl;

    for (size_t i = 0; i < 6; ++i) {
        std::cout << i + 1;

        for (size_t j = 0; j < 6; ++j){
            std::cout << std::setw(10) << dieCount.at(i).at(j) << std::setw(3) << " ";
        }
        std::cout << std::endl;
    }
	
	return 0;
}
