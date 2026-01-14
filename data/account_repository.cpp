#include "account_repository.h"

AccountRepository::AccountRepository(Database& db)
	: database(db)
{
	createAccountTable(); // Creates the table automaticaly if not already there
}

bool AccountRepository::createAccount(
	const std::string& username, 
	const std::string& passwordHash)
{
	return database.executePrepared(
		INSERT_SQL, 
		{ username, passwordHash }
	);
}

void AccountRepository::createAccountTable()
{
	database.execute(
		"CREATE TABLE IF NOT EXISTS accounts ("
		"id INTEGER PRIMARY KEY AUTOINCREMENT, "
		"username TEXT UNIQUE NOT NULL, "
		"password_hash TEXT NOT NULL"
		");"
	);
}

std::vector<AccountRecord> AccountRepository::getAllAccounts()
{
	std::vector<AccountRecord> accounts;

	auto rows = database.query(SELECT_ALL_SQL);
	
	for (const auto& row : rows)
	{
		AccountRecord account; // I am getting a purley virtual error here
		account.id = std::stoi(row.at("id"));
		account.username = row.at("username");
		account.passwordHash = row.at("password_hash");

		accounts.push_back(account);
	}

	return accounts;
}

std::optional<AccountRecord> AccountRepository::findByUsername(
	const std::string& username
)
{
	auto rows = database.query(
		std::string(FIND_BY_USERNAME_SQL)
	);

	if (rows.empty())
		return std::nullopt;

	const auto& row = rows.front();

	AccountRecord account;
	account.id = std::stoi(row.at("id"));
	account.username = row.at("username");
	account.passwordHash = row.at("password_hash");

	return account;
}
