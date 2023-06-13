#include "list.h"

#include <iostream>

int main(int argc, char const *argv[]){
	List<int> a;
	
    a.insertPos(5, 0);
    std::cout << a.front() << std::endl;

    a.insertPos(12, 0);
    std::cout << a.front() << std::endl;

    a.insertFront(6);
    std::cout << a.front() << std::endl;

    try
    {
        a.insertPos(19, 2);
        a.removePos(2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    a.print();


    // a.removeFront();
    // std::cout << a.front() << std::endl;

    // a.insertBack(27);
    // std::cout << a.back() << std::endl;

    // a.insertFront(16);

    // a.removeBack();
    // std::cout << a.back() << std::endl;

    // a.removeBack();
    // std::cout << a.back() << std::endl;

    // std::cout << std::boolalpha << a.contains(16);
 
    
	return 0;
}
