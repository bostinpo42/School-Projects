#include <iostream>

#include "func.h"

int compute(int, int, int (*computer)(int, int));

void func(double, double, void (*)(const std::string&) );

int add(int a, int b) { return a + b; }

int mult(int a, int b) { return a * b; }

int divide(int a, int b) { return a / b; }

int main(int argc, char const *argv[])
{
	// int a{20};
    // int b{30};

    func(10, 20, logStdOut);

    // std::cout << compute(a, b, add) << std::endl;
    // std::cout << compute(a, b, mult) << std::endl;
    // std::cout << compute(a, b, divide) << std::endl;
	
	return 0;
}

int compute(int x, int y, int (*computer)(int, int)) {
    return computer(x, y);
}

void func(double d1, double d2, void (*logger)(const std::string&)) {
    // processes data and then logs it
    logger("Took in two doubles\n");
}