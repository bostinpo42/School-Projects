// includes go here
#include <iostream>

#include "stack.h"

int main(int argc, char const *argv[])
{
	push("bottom of the stack");
    push("part 2 of the stack");
	push("part 3 of the stack");
    push("part 4 of the stack");
    push("part 5 of the stack");
    push("top of the stack");

    while(!isEmpty()) {
        std::cout << pop() << std::endl;
    }
	return 0;
}