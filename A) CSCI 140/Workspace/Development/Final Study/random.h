
#ifndef RANDOM_H
#define RANDOM_H

class RandomNumberGenerator {

private:

public:
    RandomNumberGenerator();

    ~RandomNumberGenerator();

    int generateRandomInt(const int&, const int&);

    double generateRandomDouble(const double&, const double&);
};

#endif