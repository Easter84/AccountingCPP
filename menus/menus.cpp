#include "../models/checking.h"
#include "../models/savings.h"
#include "../models/credit.h"
#include "menus.h"
#include <iostream>
#include "../utils/input_validation.h"

void showMainMenu()
{
	std::cout << "1. Checking Account\n2. Savings Account\n3. Credit Account\n4. Exit\n";
}

void showCheckingMenu(CheckingAccount& account)
{
	// Starts a while loop to keep the menu alive till the user ends it.
	bool running = true;
	while(running)
	{
		std::cout
			<< "1. Deposit\n"
			<< "2. Withdraw\n"
			<< "3. Check Balance\n"
			<< "4. Exit\n";

		int choice = get_int("Select an option: ");

		if (choice == 4)
			running = false;
		// Gets the correct methods from the declared Enum in the Checking Account Class
		account.handleMenuOption(
			static_cast<CheckingAccount::CheckingMenuOption>(choice)
		);
	}

}

void showSavingsMenu(Savings& account)
{
	bool running = true;
	while (running)
	{
		std::cout
			<< "1. Deposit\n"
			<< "2. Withdraw\n"
			<< "3. Balance\n"
			<< "4. Interest\n"
			<< "5. Exit";

		int choice = get_int("Select an option: ");

		if (choice == 5)
			running = false;
		// Create logic for menu in savings.cpp
	}
}

void showCreditMenu(CreditAccount& account)
{
	// Implment logic here
}
