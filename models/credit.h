#pragma once
#include "accounts.h"

class CreditAccount : public Account
{
	// Adds a new attribute to the derived class, that the parent doesn't have
private:
	double creditLimit;

	// Constructor for derived class with attributes
public:
	CreditAccount(const std::string& accountName = "Credit",
		double startingBalance = 0.0, 
		double limit = 0.0);

	// Overriding parent methods
	TransactionResult withdraw(double amount) override;
	void displayAccountInfo() const override;

	// Enum for Credit account menu options
	enum class CreditMenuOption
	{
		Deposit = 1,
		Withdraw,
		Balance,
		ViewInterest,
		Exit
	};
};
