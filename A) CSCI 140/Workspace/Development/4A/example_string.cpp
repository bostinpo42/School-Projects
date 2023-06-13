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
    
    std::string s{"This is a string"};
	
    std::cout << s << std::endl;

    std::sort(s.begin(), s.end());

    std::cout << s << std::endl;

    if(std::binary_search(s.begin(), s.end(), 'r')) {
        std::cout << "r exists \n";
    }

	return 0;
}
