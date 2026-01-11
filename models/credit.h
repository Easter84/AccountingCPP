#pragma once
#include "accounts.h"
#include "../utils/menu_ui.h"

class CreditAccount : public Account
{
	// Adds a new attribute to the derived class, that the parent doesn't have
private:
	double creditLimit;

	// Constructor for derived class with attributes
public:
	CreditAccount(
		const std::string& accountName,
		double currentBalance = 0.0,
		double limit = 1000.0
	);

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

	static inline const std::vector<MenuItem<CreditAccount::CreditMenuOption>> CreditMenu =
	{
		{ CreditAccount::CreditMenuOption::Deposit, "Deposit"},
		{ CreditAccount::CreditMenuOption::Withdraw, "Withdrawl"},
		{ CreditAccount::CreditMenuOption::Balance, "Balance"}, 
		{ CreditAccount::CreditMenuOption::ViewInterest, "Yearly APR"},
		{ CreditAccount::CreditMenuOption::Exit, "Go back"}
	};

	void handleMenuOption(CreditMenuOption opiton);
};