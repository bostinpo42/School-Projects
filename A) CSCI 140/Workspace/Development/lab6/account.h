// Account class with a constructor that initializes the account name.
#include <string>

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
public:
   // constructor initializes data member name with parameter accountName
   explicit Account(std::string accountName) : name{accountName} { // member initializer
      // empty body
   }

   Account(std::string accountName, double);

   // function to set the account name
   void setName(std::string accountName) {
      name = accountName;
   }

   // function to retrieve the account name
   std::string getName() const {
      return name;
   }

   //function to add credit to the account
   double credit(double);

   //function to debit from the account
   bool debit(double);

   //function to get the balance from the account
   double getBalance() const;
     
private:
   std::string name; // account name data member
   double balance;
};                   // end class Account

#endif