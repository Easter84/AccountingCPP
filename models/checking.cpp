#include "checking.h"
#include <iostream>
#include "../utils/input_validation.h"
#include "../utils/transaction_ui.h"

// Constructor for CheckingAccount, calls the base class constructor
CheckingAccount::CheckingAccount(const std::string& accountName, double startingBalance)
	: Account(accountName, AccountType::Checking, startingBalance)
{
}

void CheckingAccount::displayAccountInfo() const
{
	// Shows an easy to read summary of the account
	std::cout << this->getType() << '\n' 
		<< getName() 
		<< "\nBalance: $" << getBalance() 
		<< std::endl;
}


void CheckingAccount::handleMenuOption(CheckingMenuOption option)
{
	switch (option)
	{
		default:
			std::cout << "Invalid menu option.\n";
			return;

		case CheckingMenuOption::Deposit:
		{
			handleDepositUI(*this);
			return;
		}

		case CheckingMenuOption::Withdraw:
		{
			handleWithdrawUI(*this);
			return;
		}

		case CheckingMenuOption::Balance:
		{
			this->displayAccountInfo();
			return;
		}
		case CheckingMenuOption::Exit:
		{
			handleReturnMenuUI(*this);
			return;
		}
	};
}

