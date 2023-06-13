// who: <Austin Ngo - ango26>
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.>

// includes go here
#include <iostream>
#include <iomanip>
#include <random>
#include <cstdlib> 
#include <ctime>
#include <functional>

typedef std::function<int(const int, const int)> rndFunc;

void testRand(int[], const int, const int);
void testRandom(int[], const int, const int);
int randomRange(const int, const int);
int randRange(const int, const int);
void test(int[], const int, const int, rndFunc);
void printTestResults(const int[], const int, const int);

int main(int argc, char const *argv[])
{
    const int TEST_QTY{600'000};
    const int FACE_QTY{6};
    int rollCount[FACE_QTY] {};

    std::cout << std::fixed << std::setprecision(5);


    testRand(rollCount, FACE_QTY, TEST_QTY);

    for(size_t i = 0; i < FACE_QTY; ++i) rollCount[i] = {0};

    std::cout << std::endl;
 
	testRandom(rollCount, FACE_QTY, TEST_QTY);

	return 0;
}

void testRand(int count[], const int size, const int testQty)
{
    std::cout << "Testing " << testQty << " rolls using the rand function\n\n";

    test(count, size, testQty, randRange);

    printTestResults(count, size, testQty);
}

void testRandom(int count[], const int size, const int testQty)
{
    std::cout << "Testing " << testQty << " rolls using the random function\n\n";

    test(count, size, testQty, randomRange);

    printTestResults(count, size, testQty);
}

int randomRange(const int start, const int end)
{
    static std::random_device rd;
    static std::default_random_engine rndEng(rd());
    static std::uniform_int_distribution<int> uniformDist(start, end);
    return uniformDist(rndEng);
}

int randRange(const int start, const int end)
{
    return rand() % (end - start + 1);
}

void test(int count[], const int size, const int testQty, rndFunc rnd)
{
    for(size_t i = 0; i < testQty; ++i)
    {
        ++count[rnd(0, size - 1)];
    }
}

void printTestResults(const int count[], const int size, const int testQty)
{
    std::cout << std::left << std::setw(10) << "Face" << "% of rolls\n";
    for(size_t i = 0; i < size; ++i)
    {
        std::cout << std::setw(10) << i + 1 << static_cast<double>(count[i]) / testQty * 100 << std::endl;
    }
}
