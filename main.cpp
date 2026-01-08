// This will be the main entry point for the application.
#include <iostream>
#include "menus/menus.h"
#include "utils/input_validation.h"
#include "models/checking.h"
#include "models/savings.h"
#include "models/credit.h"

int main() {

	CheckingAccount checking;
	Savings savings;
	CreditAccount credit;

	bool running = true;

	while (true)
	{
		showMainMenu();
		int choice = get_int("Select Option: ");
		switch (choice)
		{
			case 1:
				showCheckingMenu(checking);
				break;
			case 2:
				showSavingsMenu(savings);
				break;
			case 3:
				showCreditMenu(credit);
				break;
			case 4:
				running = false;
				std::cout << "Exiting application. Goodbye!" << std::endl;
				break;
			default:
				std::cout << "Invalid option. Please try again." << std::endl;
		}
	}
	return 0;

}