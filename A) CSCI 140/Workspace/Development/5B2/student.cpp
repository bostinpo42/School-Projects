#include "student.h"

int Student::count = 0;

int Student::getCount() { return Student::count; }

Student::Student() { ++count }
Student::~Student() { --count }