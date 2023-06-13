// who: <Austin Ngo - ango26>
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.

// includes go here
#include <iostream>

int max(int a, int b, int c);

int main(int argc, char const *argv[])
{
	int x{20};
    int y{10};
    int z{40};

    //(z = (x < y) ? z : x) = 60;

    std::cout << max(y,z,x) << std::endl;
	return 0;
}


int max(int a, int b, int c) // max function with 3 variables
{
    int max{a};

    max = ( b > max ) ? b : max;
    max = ( c > max ) ? c : max;

    return max;
}