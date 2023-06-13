#include <string>
#include <vector>

#include "test.h"

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
private: 
    std::string name;
    double balance;
    std::vector<std::string>* log;
    void logEvent(const std::string&);
    Tester* t;

public:
    Account();                                  // constructor
    Account(const std::string&);                // constructor  
    Account(const std::string&, const double);  // constructor

    ~Account();                                 // destructor

    std::string getName();                      // accessor, gets access to data
    void setName(const std::string&);           // mutator, changes data

    double getBalance();
    void setBalance(const double);

    std::string getEvents();
};

#endif