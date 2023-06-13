#include "account.h"

class CheckingAccount : public Account {
public:
    //constructor recieves name, balance, and fees associated with account
    CheckingAccount(std::string, double, double); // initial balance and fee
    
    //function which redefines credit function from account by adding a fee per transaction
    double credit(double);
    //function which redefines debit function from account by adding a fee per transaction
    double debit(double);

private:
    double fee; // variable for fee
};