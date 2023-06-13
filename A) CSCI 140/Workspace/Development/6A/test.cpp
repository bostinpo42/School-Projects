#include <iostream>
#include <vector>
#include "dog.h"
#include "cat.h"

int main(int argc, char const *argv[])
{
    std::vector<Pet*> pets {new Dog("Shitpoo", "Milo"), new Cat("Calico", "Black")};

    Pet* d1(new Dog{""});

    *d1 = *pets[0];

    // Pet* p1 {d1};

    for(const Pet* p : pets) {
        std::cout << *p << std::endl;
    }

    std::cout << *d1 << std::endl;
    
    // for(const Pet* p : pets) {
    //     std::cout << p->getName() << " the " << p->getType() << " is a " << p->getBreed() 
    //             << " and says " << p->speak() << std::endl;
    // }


    //std::cout << c1.getName() << " the " << c1.getType() << " is a " << c1.getBreed()
    //            << " and says " << c1.speak() << std::endl;
	
	return 0;
}