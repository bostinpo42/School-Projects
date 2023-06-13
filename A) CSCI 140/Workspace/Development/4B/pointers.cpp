// includes go here
#include <iostream>

int main(int argc, char const *argv[])
{
    const int ARRAY_SZ{5};
    int array[ARRAY_SZ] {1,2,3,4,5};
    int* ptr{array};
   
    for (int i{0}; i < ARRAY_SZ; ++i)
    {
        std::cout << ptr[i] << " ";
    }
    std::cout << std::endl;


	// int a{20};
    // int b{30};

    // int* ptr{&a};
    // int* ptr2{&b};

    // std::cout << a  << " " << ptr << " " << *ptr << std::endl;
	
    // std::cout << abs(ptr - ptr2)  << std::endl;

	return 0;
}