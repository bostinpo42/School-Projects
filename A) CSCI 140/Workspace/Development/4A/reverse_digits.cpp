// who: <Austin Ngo - ango26>
// what: <reverses the digits of an integer value>
// why: <Lab 3B Questions>
// when: <4/10/2022>

// includes go here
#include <iostream>

void printReverseDigits(const int&);

int main(int argc, char const *argv[]) {

	int n;

    std::cout << "Enter a number between 1 and 9999: ";
    std::cin >> n;

    while (n >= 1 && n <= 9999) {
        std::cout << "The number with its digits reversed is: ";
        printReverseDigits(n);

        std::cout << "\n\nEnter a number between 1 and 9999: ";
        std::cin >> n;
    }
	return 0;
}

void printReverseDigits(const int &n) {
      if (n < 10) {
        std::cout << n;
        return;
    }
    std::cout << (n % 10);
    printReverseDigits(n / 10);
}