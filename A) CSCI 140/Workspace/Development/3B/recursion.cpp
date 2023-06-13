// who: <Austin Ngo - ango26>
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.>

// includes go here
#include <iostream>

unsigned long long fact(const int);
unsigned long long fib(unsigned int);

int main(int argc, char const *argv[])
{
	std::cout << fact(10) << std::endl;
    std::cout << fib(50) << std::endl;
	return 0;
}

/*unsigned long long fact(const int n)
{
   unsigned long long prod{1};
   int i{1};
   for(; i < n; ++i)
   {
       prod *= i;
   }
   return prod;
} */

unsigned long long fact(const int n)
{
    if( n == 1 ) return 1;
    return n * fact(n-1);
}

unsigned long long fib(unsigned int n)
{
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}