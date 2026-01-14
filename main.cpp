//// This will be the main entry point for the application.
//#include <iostream>
//#include "menus/menus.h"
//#include "utils/input_validation.h"
//#include "models/checking.h"
//#include "models/savings.h"
//#include "models/credit.h"
//
//int main() {
//
//	CheckingAccount checking("Timothy", 0.0);
//	Savings savings("Timothy", 0.0);
//	CreditAccount credit("Timothy", 0.0);
//
//	bool running = true;
//
//	while (running)
//	{
//		showMainMenu();
//		int choice = get_int("\nSelect Option: ");
//		switch (choice)
//		{
//			case 1:
//				showCheckingMenu(checking);
//				break;
//			case 2:
//				showSavingsMenu(savings);
//				break;
//			case 3:
//				showCreditMenu(credit);
//				break;
//			case 4:
//				running = false;
//				std::cout << "\nExiting application. Goodbye!" << std::endl;
//				break;
//			default:
//				std::cout << "\nInvalid option. Please try again." << std::endl;
//		}
//	}
//	return 0;
//
//}

#include "data/database.h"
#include "data/account_repository.h"
#include <iostream>

int main()
{
    Database db("test.db");

    AccountRepository repo(db);

    repo.createAccount("tim", "hash123");

    auto accounts = repo.getAllAccounts();

    for (const auto& account : accounts)
    {
        std::cout
            << account.id << " | "
            << account.username << " | "
            << account.passwordHash << "\n";
    }

    return 0;
}
