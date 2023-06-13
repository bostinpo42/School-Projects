#include "random.h"
#include <cstdlib>
#include <ctime>

RandomNumberGenerator::RandomNumberGenerator() { srand(time(NULL)); }

RandomNumberGenerator::~RandomNumberGenerator() {}

int RandomNumberGenerator::generateRandomInt(const int& min, const int& max) {
    return rand() % (max + 1 - min) + min;
}

double RandomNumberGenerator::generateRandomDouble(const double& min, const double& max) {
    return min + (double)(rand()) / ((double)(RAND_MAX/(max - min)));
}

