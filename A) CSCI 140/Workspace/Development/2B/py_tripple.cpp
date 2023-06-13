// who: <Austin Ngo - ango26>
// what: <lists all pythagorean tripples with a side 3 below 500.>
// why: <py_tripple.cpp>
// when: <03/20/2022>

// includes go here
#include <iostream>
#include <iomanip>

int main(int argc, char const *argv[])
{
    int count = 0;
	for (int a = 0; a <= 500; ++a)
    {
        for (int b = 0; b <= 500; ++b)
        {
            for (int c = 0; c <=500; ++c)
            {
                if ((a*a) + (b*b) == (c*c) && c <= 500 && a <= b && b < c)
                {
                    std::cout << a << "   " << b << "   " << c << "\n";
                    ++count;
                }
            }
        }
    }
std::cout << "A total of " << count << " triples were found.";

	return 0;
}