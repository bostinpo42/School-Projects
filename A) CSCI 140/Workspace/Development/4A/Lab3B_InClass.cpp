// who: <Austin Ngo - ango26>
// what: <the function of this program>
// why: <the name of the lab>
// when: <04/11/2022>

// includes go here
#include <iostream>

bool isEven(int val) { return !(val & 1); }

void printReverseDigits (int val) {
	if (val == 0) {
		std::cout << std::endl;
		return;
	}
	std::cout << val % 10;
	printReverseDigits(val / 10);
}

int gcd(int a, int b) {
	int t;
	if (b == 0) {return a;}
	t = b;
	b = a % b;
	a = t;

	return gcd(a,b);
}

int main(int argc, char const *argv[])
{
	std::cout << gcd(731, 8);
	
	return 0;
}