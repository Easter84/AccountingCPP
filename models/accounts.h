#pragma once
#include <string>

class Account
{
	// Private constructor with attributes
protected:
	std::string name;
	double balance;

	// Public interface
public:
	Account(const std::string& accountName, double startingBalance = 0.0);

	// Added these enums to get away from basic boolean logic and allow for expanded error handling
	enum class TransactionResult
	{
		SUCCESS,
		INSUFFICIENT_FUNDS,
		INVALID_AMOUNT,
		OVER_CREDIT_LIMIT,
	};

	// Virtual destructor for proper cleanup of derived classes
	virtual ~Account() = default;

	// Shared behavior
	virtual TransactionResult deposit(double amount);
	virtual TransactionResult withdraw(double amount);

	// Behavior that varies by account type
	virtual void displayAccountInfo() const = 0;

	// Concret method implementation, retrieves the current balance and is never overridden
	double getBalance() const;
	const std::string& getName() const;
};