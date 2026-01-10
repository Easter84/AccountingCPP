#include "accounts.h"
#include <iostream>

// Constructor for Parent class with attributes
Account::Account(const std::string& accountName, double startingBalance)
	: name(accountName), balance(startingBalance)
{
}

Account::TransactionResult Account::deposit(double amount)
{
	// Checks to ensure the amount deposited is greater than zero
	if (amount <= 0)
	{
		return TransactionResult::INVALID_AMOUNT;
	}
	// Deposits set amount
	balance += amount;
	return TransactionResult::SUCCESS;	
}

Account::TransactionResult Account::withdraw(double amount)
{
	// Prevent overdrafts adn nonsensical withdrawals
	if (amount <= 0)
		return TransactionResult::INVALID_AMOUNT;

	if (amount > balance)
		return TransactionResult::INSUFFICIENT_FUNDS;

	balance -= amount;
	return TransactionResult::SUCCESS;
}

double Account::getBalance() const
{
	return balance;
}

const std::string& Account::getName() const
{
	return name;
}
