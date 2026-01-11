#pragma once
#include "accounts.h"
#include "../utils/menu_ui.h"



class Savings : public Account
{
private:
	double yearlyInterestRate;

public:
	// Public constructor for Savings account
	Savings(const std::string& accountName,
		double startingBalance,
		double interestRate = 3.0
	);

	// Enum for Savings account menu options
	enum class SavingsMenuOption
	{
		Deposit = 1,
		Withdraw = 2,
		Balance = 3,
		ViewInterest = 4,
		Exit = 5
	};

	static inline const std::vector<MenuItem<Savings::SavingsMenuOption>> SavingsMenu =
	{
		{ Savings::SavingsMenuOption::Deposit, "Deposit" },
		{ Savings::SavingsMenuOption::Withdraw, "Withdrawl" },
		{ Savings::SavingsMenuOption::Balance, "View Balance" },
		{ Savings::SavingsMenuOption::ViewInterest, "Yearly Interest" },
		{ Savings::SavingsMenuOption::Exit, "Go back" }
	};

	// Override displayAccountInfo to show savings account details
	void displayAccountInfo() const override;
	void handleMenuOption(SavingsMenuOption option);

	double getInterestRate() const;
	void setInterestRate(double rate);
};
