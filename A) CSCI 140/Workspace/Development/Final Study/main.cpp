#include "random.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char const *argv[])
{
    std::fstream src;

    src.open("file.txt", std::ios::out);
    
    if(!src)(EXIT_FAILURE);

	RandomNumberGenerator a;
    RandomNumberGenerator b;
    RandomNumberGenerator c;
    RandomNumberGenerator d;
    RandomNumberGenerator e;

    while(src) {
       src.write(); 
    }

    std::cout << a.generateRandomInt(0,10) << ' ' << b.generateRandomInt(0,10) << ' ' << c.generateRandomInt(0,10) << ' '
              << d.generateRandomInt(0,10) << ' ' << e.generateRandomInt(0,10) << ' ' << std::endl;

    for (size_t i = 0; i < 10; ++i) {
        std::cout << a.generateRandomInt(0,10) << std::endl;
    }
    

	return 0;
}