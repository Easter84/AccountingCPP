#include "savings.h"
#include <iostream>

Savings::Savings(const std::string& accountName, double startingBalance)
	: Account(accountName, startingBalance)
{
}

void Savings::displayAccountInfo() const
{
	std::cout << "Savings Account: " << name << ", Balance: $" << balance << std::endl;
}
