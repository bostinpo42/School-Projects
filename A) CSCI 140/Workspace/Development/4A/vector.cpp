// who: <Austin Ngo - ango26>
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.>

// includes go here
#include <iostream>
#include <vector>
#include <stdexcept>

void printIntVector (const std::vector<int>&);

int main(int argc, char const *argv[])
{
	std::vector<int> v(20);

    for (size_t i = 10; i < 21; ++i) {
        v.emplace_back(i);
    }
    
    printIntVector(v);
	
	return 0;
}

void printIntVector (const std::vector<int>& vect) {
    std::cout << "{ ";

    try {
    for(int i {0}; i <= vect.size(); ++i) 
        std::cout << vect.at(i) << " ";
    } catch(std::out_of_range e) {std::cout << "some ugly number";}

    std::cout << "}";
}