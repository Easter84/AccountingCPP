#include "credit.h"
#include <iostream>

CreditAccount::CreditAccount(const std::string& accountName, double startingBalance, double limit)
	: Account(accountName, startingBalance), creditLimit{limit}
{
}

Account::TransactionResult CreditAccount::withdraw(double amount)
{
	if (amount <= 0 || balance - amount < -creditLimit)
		return TransactionResult::OVER_CREDIT_LIMIT;

	balance -= amount;
	return TransactionResult::SUCCESS;
}

void CreditAccount::displayAccountInfo() const
{
	std::cout << "Account Type: " << name
		<< "\nBalance: $" << balance
		<< "\nCredit Limit: $" << creditLimit
		<< '\n';
}