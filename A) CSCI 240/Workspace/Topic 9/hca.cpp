#include <iostream>
#include <unordered_map>

int main(int argc, char const *argv[]) {
    std::unordered_map<char, uint32_t> map;
    std::string S {"ABCCADEEABCDEAEE"};

    // std::unordered_map<char, uint32_t> map{
    //     {'A', 0}, {'B', 0}, {'C', 0}, {'D', 0}, {'E', 0}
    // };

    for(size_t c{'A'}; c <= 'Z'; ++c) {
        map[c] = 0; 
    }

    for(char c : S){
        ++map[c];
    }
    for(std::pair<char, uint32_t> i : map){
        if(i.second > 0) std::cout << i.first << " = " << i.second << std::endl;
    }

    return 0;
}