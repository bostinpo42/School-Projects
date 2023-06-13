#include<iostream>
// #include<tuple>

#include"test.h"
#include "keyvalue_pair.h"

int main(int argc, char const *argv[]){
	Tester<KVPair<int, int>> t([] (KVPair<int, int> l, KVPair<int, int> r) {return l.key < r.key; });
    // Tester<std::tuple<int, int>> t([ (std::tuple<int, int> l, std::tuple<int, int> r) { return l.key < r.key}]);

    std::cout << std::boolalpha;

    std::cout << t.compare({10, 20}, {5, 55}) << std::endl;
	
	return 0;
}