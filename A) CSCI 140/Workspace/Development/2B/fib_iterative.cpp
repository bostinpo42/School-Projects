// who: <Austin Ngo - ango26>
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.

// includes go here
#include <iostream>

int main(int argc, char const *argv[])
{

	for ( size_t t{0}, l{1}, tmp{}, n{50} ; n > 0 ; tmp = l, l += t, t = tmp, --n )
    {
        if(n == 1)
        std::cout << t << std::endl;
    }
    
	
	return 0;
}