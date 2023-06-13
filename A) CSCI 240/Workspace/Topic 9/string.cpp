#include <iostream>
#include <cstring>

void printString(const std::string& str) {
    std::cout << str << std::endl;
}

int main(int argc, char const *argv[]){
	const char* str("these characterrs");
    size_t strSize{strlen(str)}; // strlen is a part of the c-string header.
	
    std::string str2{str}; // stl strings cannot be initialized with a single character from a c-style string, but may be initialized with a c-style string if it is >1.
    str2[8] = 'r'; // we can use subscripts on stl strings, just like an array.
    std::cout << str2.find("rr") << std::endl;

    const char* str3{str2.c_str()};
    std::cout << str3 << std::endl;

    std::cout << str2 + str3 << std::endl; // we can add strings together provided they are stl strings, however, you can add a stl string with a c-style string,
                                           // given the stl string is on the left.

    printString("test");

	return 0;
}
