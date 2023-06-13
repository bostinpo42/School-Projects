#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

// void readFile(std::string, std::vector<int>);

int main(int argc, char const *argv[]){
	std::string fileName{"graph.dat"};
	std::vector<int> shortestPath{};

	std::ifstream in(fileName);

	std::string line{};
	int u; // source
	int v; //dst
	int c; //cost

	while(in){
		std::getline(in, line);
		std::stringstream ss{line};
		ss >> u ; 
		while(ss){
			ss >> v;
			ss >> c;
			std::cout << "from " << u << " to " << v << " with a cost of " << c << std::endl;
		}
	}

	// readFile(fileName, shortestPath);
	
	return 0;
}


