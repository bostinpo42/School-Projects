#include <iostream>
#include <array>

using namespace msac;

namespace msac{
    void printArray(std::array<int, 4> a) {
    std::cout << "[";
    for (size_t i = 0; i < a.size(); i++) {
        std::cout << a[i] << ", "; 
    }
    std::cout << "] ";
    }
}

int main(int argc, char const *argv[])
{
	std::array<int,4> array{1,2,3,4};

    // msac::printArray(array); // we only need to use the scope resolution modifier if we don't have 'using namespace msac'
    printArray(array);
	
	return 0;
}
