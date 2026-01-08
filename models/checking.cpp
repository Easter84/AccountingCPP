#include "checking.h"
#include <iostream>
#include "../utils/input_validation.h"

// Constructor for CheckingAccount, calls the base class constructor
CheckingAccount::CheckingAccount(const std::string& accountName)
	: Account(accountName)
{
}

void CheckingAccount::displayAccountInfo() const
{
	// Display checking account information
	std::cout << "Checking Account: " << getName() << ", Balance: $" << getBalance() << std::endl;
}

void CheckingAccount::handleMenuOption(CheckingMenuOption option)
{
	switch (option)
	{
		case CheckingMenuOption::Deposit:
		{
			double amount = get_double("Enter deposit amount: ");
			if ((amount) <= 0)
			{
				std::cout << "Amount can not be negative";
			}

			deposit(amount);
			return;
		}
		case CheckingMenuOption::Withdraw:
		{
			// logic here
			return;
		}
		case CheckingMenuOption::Balance:
		{
			displayAccountInfo();
			return;
		}
		case CheckingMenuOption::Exit:
		{
			std::cout << "Returning to main menu";
			return;
		}
	};
}

