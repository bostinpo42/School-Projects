// Austin Ngo
// 

#include <iostream>
#include "skiplist.h"

int main(int argc, char const *argv[]){
	Skiplist<int> s([] (size_t l, size_t r) { return l < r; });

    s.add(1);
    s.add(2);
    s.add(3);
    s.add(4);
    s.add(5);
    s.add(6);
    std::cout << s.size();
    std::cout << std::boolalpha << s.contains(4);
	
	return 0;
}
