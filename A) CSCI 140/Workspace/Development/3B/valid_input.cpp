// who: <Austin Ngo - ango26>
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.>

// includes go here
#include <iostream>

int getValidInt(); // input value v such that 0 < v <= 10 

int main(int argc, char const *argv[])
{
	
    std::cout << getValidInt() << std::endl;
	return 0;
}

int getValidInt()
{
    int val{};
    std::cout << "Enter a value between 1 and 10: ";
    std::cin >> val;

    if(val < 1 || val > 10)
    {
        std::cout << "What are you, stupid?!!\n";
        return getValidInt(); 
    }

    return val;
}
