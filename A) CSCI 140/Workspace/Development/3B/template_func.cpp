// who: <Austin Ngo - ango26>
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.>

// includes go here
#include <iostream>

template<typename T>
T sum(T a, T b) { return a + b; }

int main(int argc, char const *argv[])
{
	std:: cout << sum<int>(10, 20) << std::endl;
	std:: cout << sum<double>(10.0, 20.0) << std::endl;
	std:: cout << sum<char>('A', 3) << std::endl;
	return 0;
}