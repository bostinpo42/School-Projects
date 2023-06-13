// includes go here
#include <iostream>

void printString(char* s){
    std::cout << s << std::endl;
}

int main(int argc, char const *argv[])
{
	// char s[] {"string array"};

    printString("test");
	
	return 0;
}