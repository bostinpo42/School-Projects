#include <iostream>

#include "account.h"

int main(int argc, char const *argv[]) {
    {
        Account fredsAccount("Fred Sanford", 50.0);

        std::cout << fredsAccount.getName() << "\n\t$" << fredsAccount.getBalance() << std::endl;

        std::cout << fredsAccount.getEvents() << std::endl;
    }

    return 0;
}
