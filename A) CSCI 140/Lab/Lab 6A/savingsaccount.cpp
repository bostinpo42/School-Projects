#include "savingsaccount.h"

//constructor receives name, balance and interest rate
SavingsAccount::SavingsAccount(std::string name, double balance, double rate) : Account(name, balance), rate{rate} {}

//function to calculate the interest accrued by the account
double SavingsAccount::calculateInterest() const {
    double interest{}; // variable for accrued interest
    interest = rate * getBalance(); // calculates interest by multiplying the rate by the balance from the getBalance function
    return interest;
}