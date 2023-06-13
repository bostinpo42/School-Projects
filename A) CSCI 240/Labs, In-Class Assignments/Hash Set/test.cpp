#include <iostream>

#include "hashset_lp.h"
#include "hashset_qp.h"

int memHash(int);
int stringHash(std::string);
int cycleHash(std::string);

const std::string s1{"poop"};

int main(int argc, char const *argv[]){
	HashSetLP<int> LP(memHash);
	HashSetQP<int> QP(memHash);

	for(size_t i{0}; i < 160; ++i) {
		std::cout << "Inserting: " << i << std::endl;
		LP.insert(i);
	}

	for(size_t i{0}; i < 160; ++i) {
		std::cout << "Searching Address: " << LP.find(i) << std::endl;
	}

	for(size_t i{0}; i < 160; ++i) {
		std::cout << "Searching : " << std::boolalpha << LP.contains(i) << std::endl;
	}

	for(size_t i{0}; i < 160; ++i) {
		LP.erase(i);
	}
	
	for(size_t i{0}; i < 160; ++i) {
		std::cout << "Searching Address: " << LP.find(i) << std::endl;
	}

	for(size_t i{0}; i < 160; ++i) {
		std::cout << "Inserting: " << i << std::endl;
		QP.insert(i);
	}

	for(size_t i{0}; i < 160; ++i) {
		std::cout << "Searching Address: " << QP.find(i) << std::endl;
	}

	for(size_t i{0}; i < 160; ++i) {
		std::cout << "Searching : " << std::boolalpha << QP.contains(i) << std::endl;
	}

	for(size_t i{0}; i < 160; ++i) {
		QP.erase(i);
	}
	
	for(size_t i{0}; i < 160; ++i) {
		std::cout << "Searching Address: " << QP.find(i) << std::endl;
	}
	
	return 0;
}

int memHash(int item) {
	return item;
}

int stringHash(std::string s) {
	int hash{0};

		for (size_t i = 0; i < s.length(); ++i) {
			hash = 31 * hash + s[i];
		}
		
		return hash;
}

int cycleHash(std::string s) {
	int hash{0};
	for(size_t i = 0; i < s.length(); ++i) {
		hash += static_cast<int>(s[i]);
		hash = (hash << 5) | (hash >> 27);
	}
	return hash;
}


