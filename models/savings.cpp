#include "savings.h"
#include "../utils/input_validation.h"
#include "../utils/menu_ui.h"
#include "../utils/transaction_ui.h"
#include <iostream>

Savings::Savings(
	const std::string& accountName,
	double currentBalance
)
	:Account(accountName, AccountType::Savings, currentBalance, 3.0)
{
}

void Savings::displayAccountInfo() const
{
	std::cout << this->getType() << ": " << getName()
		<< "\nBalance: $" << getBalance()
		<< "\nInterest Rate: " << this->interestRate << "%\n";
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