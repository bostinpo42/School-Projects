// includes go here
#include <iostream>
#include <memory> // enables the use of smart pointers

struct widget {
    widget(int c) { std::cout << "CONSTRUCTED\n"; }
    ~widget() { std::cout << "DESTRUCTED\n"; }
};

void takeWidget(const std::unique_ptr<widget>& w);
// void takeWidget(std::shared_ptr<widget> w);

int main(int argc, char const *argv[])
{

    std::shared_ptr<widget> w = std::make_shared<widget>(10);

    {
    //     widget* w = new widget[10]{};
    //     // insert cool code here
    //     delete[] w;
        std::unique_ptr<widget> w = std::make_unique<widget>(10); // smart pointer
        takeWidget(std::move(w));
        // takeWidget(w);
        // std::shared_ptr<widget> w = std::make_shared<widget>(10);

    //    std::shared_ptr<widget> x = w;
    //    takeWidget(w);
    }

	std::cin.get();
	
	return 0;
}