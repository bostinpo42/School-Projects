#include <iostream> // include BEFORE fstream
#include <fstream>  // allows us to use filestream
#include <cstdlib> // allows us to use exit

#define BUFFER_SZ 8196

int main(int argc, char const *argv[])
{
    char buffer[BUFFER_SZ];
    int qty;
	std::ifstream src("test.iso", std::ios::in | std::ios::binary);
    std::ofstream dst("test2.iso", std::ios::out | std::ios::binary);
	
    if(!src || !dst) exit(EXIT_FAILURE);

    while (src) {   // while src has bytes to read
        src.read(buffer, BUFFER_SZ);
        qty = src.gcount();
        dst.write(buffer, qty);
    }

	return 0;
}

