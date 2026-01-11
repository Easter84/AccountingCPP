#pragma once


class CheckingAccount;
class Savings;
class CreditAccount;
class Account;

void showMainMenu();
void showCheckingMenu(CheckingAccount& account);
void showSavingsMenu(Savings& account);
void showCreditMenu(CreditAccount& account);

void menuDelimiter(const Account& account);