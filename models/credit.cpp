#include "credit.h"
#include "../utils/transaction_ui.h"
#include <iostream>

CreditAccount::CreditAccount(
	const std::string& accountName,
	double currentBalance,
	double limit
)
	:Account(accountName, AccountType::Credit, currentBalance, 15.0),
	creditLimit(limit)
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
	std::cout << this->getType() << ": " << getName()
		<< "\nBalance: $" << getBalance()
		<< "\nCredit Limit: $" << this->creditLimit
		<< "\n APR: " << this->interestRate << "%\n";
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
