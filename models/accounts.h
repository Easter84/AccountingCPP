#pragma once
#include "account_enum.h"
#include <string>

class Account
{
	// Private constructor with attributes
protected:
	std::string name;
	double balance;

	// Public interface
public:
	Account(const std::string& accountName, double startingBalance);

	// Virtual destructor for proper cleanup of derived classes
	virtual ~Account() = default;

	// Shared behavior
	virtual bool deposit(double amount);
	virtual bool withdraw(double amount);

	// Behavior that varies by account type
	virtual void displayAccountInfo() const = 0;

	// Concret method implementation, retrieves the current balance and is never overridden
	double getBalance() const;
};