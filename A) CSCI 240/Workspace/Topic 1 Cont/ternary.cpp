#include <iostream>

int main(int argc, char const *argv[])
{
	int left{0};
    int right{1};

    ((right > left) ? right : left) = 5;
	
	return 0;
}
