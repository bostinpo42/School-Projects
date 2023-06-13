#include <iostream>

void func(long long a) {

}

int main(int argc, char const *argv[])
{
	int left {0};
    long long down{};

    func(left); // we can cast an int into a long long explicitly by calling a function which takes a long long

    down = static_cast<long long> (left);
	
	return 0;
}
