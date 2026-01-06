#include "checking.h"
#include <iostream>

// Constructor for CheckingAccount, calls the base class constructor
CheckingAccount::CheckingAccount(const std::string& accountName, double startingBalance)
	: Account(accountName, startingBalance)
{
}

void CheckingAccount::displayAccountInfo() const
{
	// Display checking account information
	std::cout << "Checking Account: " << name << ", Balance: $" << balance << std::endl;
}
