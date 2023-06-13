// Austin Ngo
// Project 1
// Elevator Simulator
// 9/26/2022

#include <iostream>
#include <time.h>

#include "controller.h"

template<typename T>
int main(int argc, char const *argv[]){
	srand(time(nullptr));

	Controller<T> brain();
	
	return 0;
}
