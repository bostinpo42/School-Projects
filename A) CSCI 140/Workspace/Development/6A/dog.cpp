#include "dog.h"

Dog::Dog(const std::string& breed) : Dog(breed, "") {}

Dog::Dog(const std::string& breed, const std::string& name) : Pet("Dog", breed, name) { }

std::string Dog::speak() const {return "Woof";}