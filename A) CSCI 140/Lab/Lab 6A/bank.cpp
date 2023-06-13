// who: <Austin Ngo - ango26>
// what: <test account.h>
// why: <Lab 6A>
// when: <05/15/2022>

#include <iostream>

#include "savingsaccount.h"
#include "checkingaccount.h"

int main(int argc, char const *argv[])
{
	Account a1("James Burdolph", 100);
	std::cout << a1.getName() << "'s balance: " << a1.getBalance() << std::endl;
	a1.credit(50);
	std::cout << a1.getName() << "'s balance after deposit: " << a1.getBalance() << std::endl;
	try
	{
		a1.debit(200);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	a1.debit(25);
	std::cout << a1.getName() << "'s balance after debit: " << a1.getBalance() << std::endl;

	SavingsAccount s1("Nicolas Moran", 500, .05);
	std::cout << s1.getName() << "'s initial balance: " << s1.getBalance() << std::endl;
	std::cout << s1.getName() << "'s balance after accrued interest: " << s1.credit(s1.calculateInterest()) << std::endl;

	CheckingAccount c1("Alexei Virmoff", 250, 10);
	std::cout << c1.getName() << "'s initial balance: " << c1.getBalance() << std::endl;
	std::cout << c1.getName() << "'s balance after deposit: " << c1.credit(25) << std::endl;
	std::cout << c1.getName() << "'s balance after withdrawal: " << c1.debit(200) << std::endl;

	try
	{
		c1.debit(245);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}