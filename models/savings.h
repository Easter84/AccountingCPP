#pragma once
#include "accounts.h"

class Savings : public Account
{
public:
	// Public constructor for Savings account
	Savings(const std::string& accountName = "Savings");

	// Override displayAccountInfo to show savings account details
	void displayAccountInfo() const override;

	// Enum for Savings account menu options
	enum class SavingsMenuOption
	{
		Deposit = 1,
		Withdraw,
		Balance,
		ViewInterest,
		Exit
	};
};
