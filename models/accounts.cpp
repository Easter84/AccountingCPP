#include "accounts.h"
#include <iostream>

// Constructor for Parent class with attributes
Account::Account(const std::string& accountName,
	AccountType accountType, double currentBalance, double interestRate)
		: name(accountName), type(accountType),	balance(currentBalance), interestRate(interestRate)
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
	return this->balance;
}

const std::string& Account::getName() const
{
	return name;
}

const std::string Account::getType() const
{
	switch (type)
	{
		case AccountType::Checking:
			return "Checking";
		case AccountType::Savings:
			return "Savings";
		case AccountType::Credit:
			return "Credit";
		default:
			return "Unknown";
	};
}

double Account::getInterestRate() const
{
	return this->interestRate;
}

void Account::setInterestRate(double rate)
{
	if (rate < 0)
		return;
	this->interestRate = rate;
}
