#include "accounts.h"
#include <iostream>

// Constructor for Parent class with attributes
Account::Account(const std::string& accountName, double startingBalance)
	: name(accountName), balance(startingBalance)
{
}

bool Account::deposit(double amount)
{
	// If the deposit amount is positive, add it to the balance and return true
	if (amount > 0)
	{
		balance += amount;
		return true;
	}

	// Invalid deposit amount
	return false;
	
}

bool Account::withdraw(double amount)
{
	// Checks if the withdrawal amount is valid and within available balance
	if (amount > balance || amount <= 0)
	{
		return false; // Insufficient funds or invalid amount
	}

	// Deduct the amount from the balance and return true
	balance -= amount;
	return true;
}

// Returns the current account balance
double Account::getBalance() const
{
	// Retrieves the current account balance
	return balance;
}

const std::string& Account::getName() const
{
	return name;
}
