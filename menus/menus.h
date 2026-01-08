#pragma once


class CheckingAccount;
class Savings;
class CreditAccount;

void showMainMenu();
void showCheckingMenu(CheckingAccount& account);
void showSavingsMenu(Savings& account);
void showCreditMenu(CreditAccount& account);