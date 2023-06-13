// who: <your name and Mt SAC username goes here>
// what: <the function or purpose of this program>
// why: <the name of the lab>
// when: <the due date of this lab>

// includes go here
#include <iostream>
#include <vector>
#include <string>
#define VAL 10 // defining a constant in such a way actually doesn't take up memory, rather, 
               // in any instance the compiler finds 'VAL' it will replace it with the value 10.
int main(int argc, char const *argv[])
{
	int i{};
    std::string s{};

    // std::cout << "Please enter an integer greater than 0: ";
    // std::cin >> i;

    std::cout << "Please enter a string: ";
    std::cin >> s;

    std::cout << s;

    // i <<= 1; // the '<<' bitwise shift operator will perform a bitwise shift, effectively multiplying by a power of 2.

    // std::vector<int> v {1, 2, 3, 4, 5, i};

    // for(int &i : v) i = 20; // this reassigns every element in the vector to i.

    // v.push_back(55);

    // for (size_t i = 0; i < v.size(); ++i) { // this loop iterates through the vector like an array
    //    std::cout << v[i] << std::endl;
    // } 

    // for (int i : v) std::cout << i << std::endl;
    
	return 0;
}
