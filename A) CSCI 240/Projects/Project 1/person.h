#include <cstddef>

#ifndef PERSON_H
#define PERSON_H

#define MAX_CAP 6
#define MAX_HEIGHT 50

template<typename T>
class Person {
public:
    Person(size_t idNumber, size_t floorNumber) : idNumber{idNumber}, floorNumber{floorNumber} {}

    bool operator==(const Person& lhs, const Person& rhs) const {
        return lhs.idNumber == rhs.idNumber;
    }

    void setId(size_t number) { idNumber = number; }

    void setFloor(size_t number) { floorNumber = number;}
    
private:
    size_t idNumber{};
    size_t floorNumber{};
};

#endif