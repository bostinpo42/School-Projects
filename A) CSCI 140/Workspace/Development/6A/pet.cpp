// who: <Austin Ngo - ango26>
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.>

// includes go here
#include <iostream>
#include <stdexcept>
#include "pet.h"


Pet::Pet(const std::string& type, const std::string& name) : Pet(type, breed, "") {}

Pet::Pet(const std::string& type, const std::string& breed, const std::string& name) : type{type}, name{name} {
    setBreed(breed);
} 

// std::string Pet::speak() const {return "";}  Because we set virtual = 0, we cannot have this base case.

std::string Pet::getType() const {return type;}

std::string Pet::getName() const {return name;}

std::string Pet::getBreed() const {return breed;}

void Pet::setType(const std::string& type) {this->type = type;}

void Pet::setName(const std::string& name) {this->name = name;}

void Pet::setBreed(const std::string& breed) {this->breed = breed;}

std::ostream& operator<<(std::ostream& os, const Pet& p) {
    os << p.getName() << " the " << p.getType() << " is a " << p.getBreed() 
                << " and says " << p.speak();

    return os;
}

void Pet::operator=(const Pet& p) {
    type = p.type;
    breed = p.breed;
    name = p.name;
}

