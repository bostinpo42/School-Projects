#include <iostream>
#include "pet.h"

int main(int argc, char const *argv[])
{
	Pet p1("Dog", "German Shepherd");

    Pet p2("Cat", "Who the hell cares", "fluffy");

    std::cout << p2.getName() << " the " << p2.getType() << " is a " << p2.getBreed() << std::endl;

    std::cout << p1.getName() << " the " << p1.getType() << " is a " << p1.getBreed() << std::endl;
	
	return 0;
}