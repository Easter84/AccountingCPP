#include "credit.h"
#include "../utils/transaction_ui.h"
#include <iostream>

CreditAccount::CreditAccount(
	const std::string& accountName,
	double startingBalance,
	double limit,
	double apr
)
	:Account(accountName, AccountType::Credit, startingBalance),
	creditLimit(limit),
	interestRate(apr)
{
}

Account::TransactionResult CreditAccount::withdraw(double amount)
{
	if (amount <= 0 || balance > balance + creditLimit)
		return TransactionResult::OVER_CREDIT_LIMIT;

	balance -= amount;
	return TransactionResult::SUCCESS;
}

void CreditAccount::displayAccountInfo() const
{
	std::cout << "Account Type: " << name
		<< this->getType()
		<< "\nBalance: $" << balance
		<< "\nCredit Limit: $" << creditLimit
		<< '\n';
}

void CreditAccount::handleMenuOption(CreditMenuOption option)
{
	switch (option)
	{
		default:
			std::cout << "Invalid menu option.\n";
			return;

	case CreditMenuOption::Deposit:
		handleDepositUI(*this);
		return;

	case CreditMenuOption::Withdraw:
		handleWithdrawUI(*this);
		return;

	case CreditMenuOption::Balance:
		this->displayAccountInfo();
		return;

	case CreditMenuOption::ViewInterest:
		std::cout << "Current APR: "
			<< this->getInterestRate() << "%\n";
		return;

	case CreditMenuOption::Exit:
		handleReturnMenuUI(*this);
		return;
	}
}

double CreditAccount::getInterestRate() const
{
	return this->interestRate;
}
