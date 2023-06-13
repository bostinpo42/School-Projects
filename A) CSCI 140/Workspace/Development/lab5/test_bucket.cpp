// who: <Austin Ngo - ango26>
// what: <Tests the implementation of bucket>
// why: <Lab 5: Classes>
// when: <05/10/2022>

// includes go here
#include "bucket.h"
#include <iostream>
#include <iomanip>

int main(int argc, char const *argv[])
{
	Bucket bucket;

    std::cout << "Items in bucket: " << bucket.count() << std::endl;
    std::cout << "1 if bucket is empty, 0 if bucket contains items: " << bucket.isEmpty() << std::endl;

    bucket.add(1);
    bucket.add(2);
    bucket.add(1);
    bucket.add(4);
    bucket.add(5);

    std::cout << "1 if bucket contains 1: " << bucket.contains(1) << std::endl;
    std::cout << "1 if bucket contains 2: " << bucket.contains(2) << std::endl;
    std::cout << "1 if bucket contains 6: " << bucket.contains(6) << std::endl;

    std::cout << "Frequency of 1 in bucket: " << bucket.getFrequency(1) << std::endl;
    std::cout << "Frequency of 2 in bucket: " << bucket.getFrequency(2) << std::endl;
    std::cout << "Frequency of 6 in bucket: " << bucket.getFrequency(6) << std::endl;

    bucket.remove();
    std::cout << "Items in bucket (after remove): " << bucket.count() << std::endl;

    bucket.remove(1);
    std::cout << "Frequency of 1 in bucket (after remove): " << bucket.getFrequency(1) << std::endl;

    std::cout << "Items in bucket: " << bucket.count() << std::endl;

    bucket.clear();

    std::cout << "Items in bucket after clear: " << bucket.count() << std::endl;
    std::cout << "1 if bucket is empty, 0 if bucket contains items: " << bucket.isEmpty() << std::endl;
    bucket.remove();

    //bucket.remove();
	
	return 0;
}