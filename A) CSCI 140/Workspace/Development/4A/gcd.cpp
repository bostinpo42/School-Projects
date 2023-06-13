// who: <Austin Ngo - ango26>
// what: <finds the GCD of two digits>
// why: <Lab 3B Questions>
// when: <4/10/2022>

// includes go here
#include <iostream>

int gcd(int, int);

int main(int argc, char const *argv[])
{
	int a = 1, b = 1;

    std::cout << "Enter 2 integers: ";
    std::cin >> a >> b;

    while (a != 0 && b != 0)
    {
        std::cout << "The greatest common divisor of " << a << " and " << b << " is " << gcd(a, b) << "\n\n";
        std::cout << "Enter 2 integers: ";
        std::cin >> a >> b;
    }
	return 0;
}

int gcd(int a, int b) {
    while (a != b) {
       if (a > b){ return gcd(a - b, b);}
       else return gcd(a, b - a);
    }
   return a; 
}