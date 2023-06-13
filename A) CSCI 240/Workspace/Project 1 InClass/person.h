
#ifndef PERSON_H
#define PERSON_H

class Person {
public:
    Person(size_t id, size_t dest) : id{id}, dest{dest} {}

private:
    size_t id;
    size_t dest;
};

#endif