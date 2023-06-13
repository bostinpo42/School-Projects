#include <stdexcept>
#include "account.h"

//constructor which recieves account name and initial balance, throws exception if balance <= 0
Account::Account(std::string accountName, double balance) : name{accountName}, balance{balance} {
    if (balance <= 0) {
        throw std::invalid_argument("Initial balance invalid!");
    }
}

//function which adds credit to the balance of the account
double Account::credit(double deposit) {
    balance += deposit;
    return balance;
}

//function which debits from the balance of the account, throws exception if withdrawal > balance
bool Account::debit(double withdrawal) {
    if (balance > withdrawal) {
        balance -= withdrawal;
        return true;
    }
    throw std::out_of_range("Withdrawal amount exceeds balance!");
    return false;
}

//function which gets and returns the balance of the account
double Account::getBalance() const {
    return balance;
}