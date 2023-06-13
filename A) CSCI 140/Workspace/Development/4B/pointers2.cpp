// includes go here
#include <iostream>
#include <iterator>

void printArray(const int*, const int);

int main(int argc, char const *argv[])
{
	int array[]{1,2,3,4,5};

	printArray(array, (sizeof array) / sizeof(int));

	return 0;
}

void printArray(const int array[], const int size) {
    for (size_t i = 0; i < size; ++i) 
        // std::cout << array[i] << " ";
        // std::cout << *(array + 1) << " ";
        std::cout << *(array++) << " ";
    
    std::cout << std::endl;
}