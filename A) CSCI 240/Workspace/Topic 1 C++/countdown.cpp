// who: <Austin Ngo>
// what: <Test Loop Structures>
// why: <Loop Structures>
// when: <>

// includes go here
#include <iostream>

int main(int argc, char const *argv[])
{
	// std::cout << argc << "  " << argv[0] << std::endl;

	for (size_t i = 0; i < argc; ++i) {
		std::cout << argv[i] << std::endl;
	}
	
	std::cout << sizeof(argc) << " " << sizeof(argv) << std::endl; // sizeof can be used with or without parenthesis

	return 0;
}
