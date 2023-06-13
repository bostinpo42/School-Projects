#include <iostream>

int main(int argc, char const *argv) {
    while(std::cin.peek() != '\n') {
        std::cout << static_cast<char>(std::cin.get());
    }
    return 0;
}