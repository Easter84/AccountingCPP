#pragma once
#include "accounts.h"


class CheckingAccount : public Account
{
public:
	// Public constructor for CheckingAccount
	CheckingAccount(const std::string& accountName = "Checking");

	// Enum for checking account menu options
	enum class CheckingMenuOption
	{
		Deposit = 1,
		Withdraw,
		Balance,
		Exit
	};

	// Override displayAccountInfo to show checking account details
	void displayAccountInfo() const override;
	void handleMenuOption(CheckingMenuOption option);
};