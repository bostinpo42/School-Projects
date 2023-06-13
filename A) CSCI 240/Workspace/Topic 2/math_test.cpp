#include <iostream>
#include "math.h"

int main(int argc, char const *argv[])
{
	long x{-25};
    long y{55};

    Math<long> m(x, y);

    std::cout << "The absolute value of x is: " << Math<long>::abs(x) << std::endl;
    std::cout << "Largest value of x and y: " << Math<long>::max(x, y) << std::endl;
    std::cout << "Smallest value of x and y: " << Math<long>::min(x, y) << std::endl;
	
    std::cout << "The area of x and y is: " << m.area() << std::endl;

	return 0;
}
