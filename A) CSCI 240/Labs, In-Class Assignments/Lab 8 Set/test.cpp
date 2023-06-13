#include <iostream>
#include "set.h"

#include <iostream>

const size_t ASIZE = 20;
const size_t TARRAY[] {5, 10, 25, 15, 55, 35, 75, 99, 32, 65, 31, 42, 3, 88, 1, 100, 57, 33, 96, 26};

int main(int argc, char const *argv[]){
	Set<size_t> s1([] (size_t l, size_t r) { return l > r; });

    std::cout << std::boolalpha << "Is the set empty? " << s1.isEmpty() << std::endl;

    for(size_t i{0}; i <= ASIZE; ++i) {
        s1.insert(i);
    }


    std::cout << std::boolalpha << "Is the set empty? (after insert) " << s1.isEmpty() << std::endl;

    std::cout << "Number of items in the set: " << s1.size() << std::endl;

    std::cout << std::boolalpha << "Erasing: " << s1.erase(5) << std::endl;
    std::cout << std::boolalpha << "Erasing: " << s1.erase(55) << std::endl;
    std::cout << std::boolalpha << "Erasing: " << s1.erase(75) << std::endl;

    std::cout << "Number of items in the set after erase: " << s1.size() << std::endl;

    s1.toSequence();

	return 0;
}


