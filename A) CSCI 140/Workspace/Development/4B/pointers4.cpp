#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
	std::string* s {new std::string("testing")};

    (*s).length();
    s->length();
	
	return 0;
}