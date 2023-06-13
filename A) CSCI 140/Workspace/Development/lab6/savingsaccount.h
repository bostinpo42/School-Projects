#include "account.h"

class SavingsAccount : public Account {
public:
    //constructor for savings account, takes account name, balance, and interest rate
    SavingsAccount(std::string, double, double); // balance and interest rate

    //function which calculates the interest of the account 
    double calculateInterest() const;

private:
   double rate; //rate for interest
};