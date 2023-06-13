// who: <Austin Ngo - ango26>
// what: <test the uniformity of the random number distribution of the rand and generators from the random header>
// why: <rand_uniformity.cpp>
// when: <03/23/2022>

// includes go here
#include <iostream>
#include <iomanip>
#include <random>
#include <cstdlib>


void randTest();
void randomTest();

int main(int argc, char const *argv[])
{
	randTest();
    randomTest();
	return 0;
}

void randTest()
{
    int quant{0};
    int rcount[6] = {0};

    std::cout << "Please enter the amount of rolls (1-600000): ";
    std::cin >> quant;

    for(int i{1}; i <= quant; ++i)
    {
        int result = (rand() % 6) + 1;
        ++rcount[result];
    }

    std::cout << "rand's Simulation (" << quant << " rolls) \n";

    for(int i{1}; i <= 6; ++i)
    {
        std::cout << std::setw(5) << std::setprecision(5) << std::fixed << std::left << i << float(rcount[i]) / quant * 100 << "%\n";
    }

}

void randomTest()
{ 
    int quant{0};
    int rcount[7] = {0};
   
    std::cout << "Please enter the amount of rolls (1-600000): ";
    std::cin >> quant;

    std::random_device rd;  
    std::mt19937_64 rndEng(rd());   
    std::uniform_int_distribution<int> uniform_dist(1, 6); 

    for(int i{1}; i <= quant; ++i)
    {
        int result = uniform_dist(rndEng);
        ++rcount[result];
    }

    std::cout << "Random Header's Simulation (" << quant << " rolls) \n";

    for(int i{1}; i <= 6; ++i)
    {
        std::cout << std::setw(5) << std::setprecision(5) << std::fixed << std::left << i << double(rcount[i]) / quant * 100  << "%\n";
    }

}