#include "../models/checking.h"
#include "../models/savings.h"
#include "../models/credit.h"
#include "menus.h"
#include <iostream>
#include "../utils/input_validation.h"
#include "../utils/menu_ui.h"

void showMainMenu()
{
	std::cout 
		<< "===== Accounting Main Menu =====\n\n"
		<< "1. Checking Account\n" 
		<< "2. Savings Account\n"
		<<"3. Credit Account\n" 
		<< "4.Exit\n";
}

void showCheckingMenu(CheckingAccount& checking)
{
	while (true)
	{
		showMenu(checking.CheckingMenu);
		int choice = get_int("\nSelect Option: ");

		if (choice < 1 || choice > 4)
		{
			std::cout << "Invalid option. Try again.\n";
			continue;
		}

		CheckingAccount::CheckingMenuOption option =
			static_cast<CheckingAccount::CheckingMenuOption>(choice);

		if (option == CheckingAccount::CheckingMenuOption::Exit)
			break;

		checking.handleMenuOption(option);
	}
}

void showSavingsMenu(Savings& savings)
{
	while (true)
	{
		showMenu(savings.SavingsMenu);
		int choice = get_int("\nSelect Option: ");

		if (choice < 1 || choice > 5)
		{
			std::cout << "Invalid option. Try again.\n";
			continue;
		}

		Savings::SavingsMenuOption option =
			static_cast<Savings::SavingsMenuOption>(choice);

		if (option == Savings::SavingsMenuOption::Exit)
			break;

		savings.handleMenuOption(option);
	}
}

void showCreditMenu(CreditAccount& credit)
{
	while (true)
	{
		showMenu(credit.CreditMenu);
		int choice = get_int("\nSelect Option: ");

		if (choice < 1 || choice > 5)
		{
			std::cout << "Invalid option. Try again.\n";
			continue;
		}

		CreditAccount::CreditMenuOption option =
			static_cast<CreditAccount::CreditMenuOption>(choice);

		if (option == CreditAccount::CreditMenuOption::Exit)
			break;

		credit.handleMenuOption(option);
	}
}
