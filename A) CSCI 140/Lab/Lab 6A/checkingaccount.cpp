#include "checkingaccount.h"
#include <stdexcept>

//constructor recieves name, balance, and fee amount
CheckingAccount::CheckingAccount(std::string name, double balance, double fee) : Account(name, balance), fee{fee} {}

//function which invokes credit function from Account but redefines it by adding a fee associated with each successful transaction
double CheckingAccount::credit(double deposit) {
    return (Account::credit(deposit) - fee);
}

//function which invokes debit function from account but redefines it by adding a fee associated with each successful transaction
double CheckingAccount::debit(double withdrawal) {
    if(Account::debit((withdrawal + fee)) == true) {
        return Account::getBalance() - fee;
    }
    return Account::getBalance();
}