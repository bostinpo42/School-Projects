#include "cat.h"

Cat::Cat(const std::string& breed) : Cat(breed, "") {}

Cat::Cat(const std::string& breed, const std::string& name) : Pet("Cat", breed, name) { }

std::string Cat::speak() const {return "Hiss";}