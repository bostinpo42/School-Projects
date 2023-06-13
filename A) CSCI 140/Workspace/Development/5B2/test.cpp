#include <iostream>

#include "student.h"

int main(int argc, char const *argv[]) {
    std::cout << Student::getCount() << std::endl;

    Student s1;

    std::cout << Student::getCount() << std::endl;
}