#include <stdexcept>
#include <sstream>

#include "account.h"
#include "test.h"

std::string Account::getName() {
    logEvent("Quered name. Returned " + name);
    return name; 
}

void Account::setName(const std::string& name) {
    if(name.empty())
        throw std::invalid_argument("Name cannot be empty");

    logEvent("changed name to '" + name + "'");
    
    this->name = name; // this-> allows us to refer to an object, it is a pointer to an object
}

double Account::getBalance() { 
    std::stringstream ss;
    ss << "Queried balance. Returned " << balance;
    logEvent(ss.str());
    return balance; 
}

void Account::setBalance(const double balance) {
    std::stringstream ss;
    if(balance < 0)
        throw std::invalid_argument("Balance cannot be negative!");

    ss << "changed balance to '" << balance << "'";
    logEvent(ss.str());

    this->balance = balance;
}

std::string Account::getEvents() {
    std::string out;
    for (const std::string &s : *(log))
        out += s + "\n";
    return out;
}

Account::Account() : log{new std::vector<std::string>}, t{new Tester} {
    balance = 0;
}

Account::Account(const std::string& name) : Account(name, 0) { }

Account::Account(const std::string& name, const double balance) : log{new std::vector<std::string>}, t{new Tester} {
    setName(name);
    setBalance(balance);
}

void Account::logEvent(const std::string& event) {
    log->push_back(event);
}

Account::~Account() {
    delete log;
    delete t;
}