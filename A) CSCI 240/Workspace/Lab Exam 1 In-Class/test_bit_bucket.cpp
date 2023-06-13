#include <iostream>

#include "bit_bucket.h"

int main(int argc, char const *argv[]){
	BitBucket<1000> bb;

    for (size_t i = 0; i < 1000; ++i) {
        if(bb.at(i)) {
            std::cout << "Got a problem with this here bucket!\n";
        }
    }

    bb.set(120);

    for (size_t i = 0; i < 1000; ++i) {
        if(bb.at(i)) {
            std::cout << "Has a bit set at : " << i << std::endl;
        }
    }    
    
    bb.unSet(120);

     for (size_t i = 0; i < 1000; ++i) {
        if(bb.at(i)) {
            std::cout << "Has a bit set at : " << i << std::endl;
        }
    }

    try
    {
        bb.at(10000);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
      
	
	return 0;
}
