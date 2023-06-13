#include <iostream>

void swap(double& a, double& b);
void swap (const double&, const double&);
void swap(int& , int& );
void swap(std::string& , std::string& );

int main(int argc, char const *argv[]) // this program is to show that while this will compile, the compiler does not know which function to pass the values through.
{
    double a{};
    double b{};
	swap(a,b);
	
	return 0;
}

void swap(int& l, int& r)
{
    int temp{l};
    l = r;
    r = temp;
}