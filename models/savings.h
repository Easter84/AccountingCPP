#pragma once
#include "accounts.h"

class Savings : public Account
{
public:
	// Public constructor for Savings account
	Savings(const std::string& accountName, double startingBalance);

	// Override displayAccountInfo to show savings account details
	void displayAccountInfo() const override;
};
