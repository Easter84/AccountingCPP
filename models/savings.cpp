#include "savings.h"
#include <iostream>

Savings::Savings(const std::string& accountName)
	: Account(accountName)
{
}

void Savings::displayAccountInfo() const
{
	std::cout << "Savings Account: " << name << ", Balance: $" << balance << std::endl;
}
