// who: <Austin Ngo - ango26>
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.>

// includes go here
#include <iostream>
#include <array>
#include <algorithm>

const size_t ARRAY_SIZE {4};

typedef std::array<int, ARRAY_SIZE> intarray;

template<typename T, size_t S>

void printArray(const T array) {
     for (size_t i = 0; i < S; i++) {
        std::cout << array.at(i) << std::endl;
    }
}

int main(int argc, char const *argv[]) {
    
	intarray array{5, 6, 7, 1};

    for(const int &v : array) {
        std::cout << v << std::endl;
    }

    std::cout << std::endl;

    std::sort(array.begin(), array.end());

    for(const int &v : array) {
        std::cout << v << std::endl;
    }

    if(std::binary_search(array.begin(), array.end(), 5)) {
        std::cout << "5 exists\n";
    }
   
	return 0;
}
