#include "savings.h"
#include "../utils/input_validation.h"
#include "../utils/menu_ui.h"
#include "../utils/transaction_ui.h"
#include <iostream>

Savings::Savings(
	const std::string& accountName,
	double interestRate,
	double startingBalance
)
	:Account(accountName, AccountType::Savings, startingBalance),
	yearlyInterestRate(interestRate)
{
}

void Savings::displayAccountInfo() const
{
	std::cout << "Savings Account: " << this->name 
		<< this->getType()
		<< "\nBalance: $" << this->balance 
		<< "\nInterest Rate: " << this->yearlyInterestRate << std::endl;
}

void Savings::handleMenuOption(SavingsMenuOption option)
{
	switch (option)
	{

		case SavingsMenuOption::Deposit:
			handleDepositUI(*this);
			return;

		case SavingsMenuOption::Withdraw:
			handleWithdrawUI(*this);
			return;

		case SavingsMenuOption::ViewInterest:
			std::cout << "Current yearly interest rate: " 
				<< this->getInterestRate() << "%\n";
			return;

		case SavingsMenuOption::Balance:
			this->displayAccountInfo();
			return;

		case SavingsMenuOption::Exit:
			handleReturnMenuUI(*this);
			return;
	}
}

double Savings::getInterestRate() const
{
	return this->yearlyInterestRate;
}

void Savings::setInterestRate(double rate)
{
	if (rate < 0)
		return;

	yearlyInterestRate = rate;
}