#include <iostream>
#include <array>

// void printArray(int a[]) {
//     std::cout << "[";
//     for (size_t i = 0; i < 20; i++) {
//         std::cout << a[i] << ", "; 
//     }
//     std::cout << "] ";
// }

void printArray(std::array<int, 10>& a) {
    std::cout << "[";
    for (size_t i = 0; i < a.size(); i++) {
        std::cout << a[i] << ", "; 
    }
    std::cout << "] ";
}

int main(int argc, char const *argv[])
{
	int array[20]{1, 2, 3, 4};

    std::array<int, 10> brray{1, 2, 3, 4}; 

    // std::cout << sizeof array << std::endl; 
	
    printArray(brray);

	return 0;
}
