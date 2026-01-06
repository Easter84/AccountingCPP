#pragma once
#include "accounts.h"

class CreditAccount : public Account
{
	// Adds a new attribute to the derived class, that the parent doesn't have
private:
	double creditLimit;

	// Constructor for derived class with attributes
public:
	CreditAccount(const std::string& accountName, 
		double startingBalance, 
		double limit);

	// Overriding parent methods
	bool withdraw(double amount) override;
	void displayAccountInfo() const override;
};
