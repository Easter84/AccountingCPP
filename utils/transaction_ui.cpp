#include "transaction_ui.h"
#include <iostream>
#include "input_validation.h"

void handleDepositUI(Account& account)
{
	double amount = get_double("Enter deposit amount: ");
	auto result = account.deposit(amount);
	
	switch (result)
	{
		case Account::TransactionResult::SUCCESS:
			std::cout << "Deposit was successfull. New balance is: $"
				<< account.getBalance() << '\n';
			break;
		case Account::TransactionResult::INVALID_AMOUNT:
			std::cout << "Deposit must be greater than 0.\n";
			break;
		default:
			std::cout << "Deposit failed for unknown reason.\n";
	}
}

void handleWithdrawUI(Account& account)
{
	double amount = get_double("\nEnter amount to withdrawl: ");
	auto result = account.withdraw(amount);

	switch (result)
	{
		case Account::TransactionResult::SUCCESS:
			std::cout << "Withdrawl was successfull. New balance is: $"
				<< account.getBalance() << '\n';
			return;
		case Account::TransactionResult::INSUFFICIENT_FUNDS:
			std::cout << "Withdrawl failed due to insufficient funds\n";
			return;
		case Account::TransactionResult::INVALID_AMOUNT:
			std::cout << "Withdrawl failed, amount must be greater than 0.\n";
			return;
		default:
			std::cout << "Withdrawl failed due to unknown error.\n";
			return;
	}

	return;
}

void handleReturnMenuUI(Account& account)
{
	std::cout << "Returning to Main Menu.\n";
	return;
}