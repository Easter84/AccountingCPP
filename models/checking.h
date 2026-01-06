#pragma once
#include "accounts.h"


class CheckingAccount : public Account
{
public:
	// Public constructor for CheckingAccount
	CheckingAccount(const std::string& accountName, double startingBalance);

	// Override displayAccountInfo to show checking account details
	void displayAccountInfo() const override;
};