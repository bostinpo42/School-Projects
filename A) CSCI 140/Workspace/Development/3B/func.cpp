// who: <Austin Ngo - ango26>
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.>

// includes go here
#include <iostream>

int sum(int = 10, int = 20); // the rightmost parameters must be the ones given a value

int diff(int, int);

int diff(int);

int diff();

int main(int argc, char const *argv[])
{
    int x{10};
    int y{20};

	std::cout << sum(x) << std::endl;
    std::cout << diff() << std::endl;
    std::cout << diff(y) << std::endl;
    std::cout << diff(x, y) << std::endl;
	
	return 0;
}

int diff(int a, int b) { return a - b; }

int diff(int b) { diff(10, b); }

int diff() { diff(10, 20);}

int sum(int a, int b) { return a + b; }