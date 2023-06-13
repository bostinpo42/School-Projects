// who: <Austin Ngo - ango26>
// what: <takes user input integers and uses a bit mask to determine if it is even>
// why: <Lab 3b Questions>
// when: <4/10/2020>

// includes go here
#include <iostream>

bool isEven(int);

int main(int argc, char const *argv[])
{
	int n{};
    while (n != -1)
    {
        std::cout << "Enter an integer (-1 to stop): ";
        std::cin >> n;
        std::cout << n << " is an " << (isEven(n) ? "odd" : "even" ) << " integer\n";
    }
    
	return 0;
}

bool isEven(int n) { return (n & 1 == 1); }