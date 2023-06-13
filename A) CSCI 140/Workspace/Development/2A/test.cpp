#include <iostream>

int main(int argc, char const *argv[])
{
    int count{20};

    int num1{0};
    int num2{0};
    int num3{0};

    std::cout << "Please enter threee intergers: ";
    std::cin >> num1 >> num2 >> num3;

    if((num1 + num2 + num3) > 100)
    {
        std::cout << "Sum > 100: \n";
    }
    else
    {
        std::cout << "Sum < 100: \n";
    }

    if (count)
    {
        std::cout << "returned true\n";
    }
    else
    {
        std::cout << "returned false\n";
    }
}    
bool notEqual(int a, int b)
{
    
    return a == b;
}

