#include <iostream>

#ifndef TESTER_H
#define TESTER_H

class Tester {
public:
    Tester() {std::cout << "constructed\n";}
    ~Tester() {std::cout << "destructed\n";}
};

#endif