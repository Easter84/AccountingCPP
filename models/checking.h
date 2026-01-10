#pragma once
#include "accounts.h"
#include "../utils/menu_ui.h"
#include <vector>
#include <iostream>


class CheckingAccount : public Account
{
public:
	// Public constructor for CheckingAccount
	CheckingAccount(const std::string& accountName = "Checking");

	// Enum for checking account menu options
	enum class CheckingMenuOption
	{
		Deposit = 1,
		Withdraw = 2,
		Balance = 3,
		Exit = 4
	};

	static inline const std::vector<MenuItem<CheckingMenuOption>> CheckingMenu =
	{
		{ CheckingMenuOption::Deposit, "Deposit" },
		{ CheckingMenuOption::Withdraw, "Withdraw" },
		{ CheckingMenuOption::Balance, "Balance" },
		{ CheckingMenuOption::Exit, "Exit"}
	};

	// Override displayAccountInfo to show checking account details
	void displayAccountInfo() const override;
	void handleMenuOption(CheckingMenuOption option);
};