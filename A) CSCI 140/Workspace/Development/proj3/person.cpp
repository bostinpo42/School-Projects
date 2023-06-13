
#include "person.h"

Person::Person(const Position& pos, char type) {
    this->pos = new Position(pos.x, pos.y);
    this->type = type;
}

Position Person::getPosition() const { return *this->pos; }

char Person::getType() const { return type; }

bool Person::operator==(const Person& other) const { return (pos->x == other.pos->x && pos->y == other.pos->y); }

bool Person::operator!=(const Person& other) const { return !(*this == other); }