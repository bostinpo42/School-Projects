#include <iostream>
#include <fstream>


void logStdOut(const std::string& msg) {
    std::cout << msg;
}

void logToFile(const std::string& msg) {
    std::ofstream file;

    file.open("log.txt", std::ios::app);

    file << msg;

    file.close();
}




