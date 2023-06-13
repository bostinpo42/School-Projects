#include <iostream>

void swap(int& , int& );

void printIntAndInc(const int&);

int main(int argc, char const *argv[]) // this program is to show that while this will compile, the compiler does not know which function to pass the values through.
{
    int a{10};
    int b{20};

    std::cout << "a = " << a << " and b = " << b << std::endl;

    swap(a,b);

    std::cout << "after the swap a = " << a << " and b = " << b << std::endl;

    printIntAndInc(15);
	return 0;
}

void swap(int& l, int& r)
{
    l ^= r;
    r ^= l;
    l ^= r;
}

void printIntAndInc(const int& i) { std:: cout << i << std::endl; }