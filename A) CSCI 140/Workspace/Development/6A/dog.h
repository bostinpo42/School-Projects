#include "pet.h"

#ifndef DOG_H
#define DOG_H

class Dog : public Pet {
public:
    Dog(const std::string&); // breed
    Dog(const std::string&, const std::string&); //breed and name

    std::string speak() const;
private:

};

#endif