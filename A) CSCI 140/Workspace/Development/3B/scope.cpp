// who: <Austin Ngo - ango26>
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.>

// includes go here
#include <iostream>

static int val{20}; // int val exists across this entire .cpp file

int main(int argc, char const *argv[])
{
	int val{1}; // int val exists only within the main function

    std::cout << "The value of local val is: " << val << std::endl;
    std::cout << "The value of global val is: " << ::val << std::endl;

    if (val > 0)
    {
        int j{50}; // int j exists only within this if statement, but val is available to this if statement
        int val = j; // there is no way to access this val outside of this if statement
        std::cout << "The value of local nested val is: " << val << std::endl;
    }
	
    {
        int k{12}; // int k exists only within these curly braces.
    }

    for (size_t i = 0; i < 5; i++)
    {
        // size_t i exists only within this for loop
    }
    
	return 0;
}
