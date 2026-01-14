#pragma once
#include "database.h"
#include "../models/accounts.h"
#include <vector>
#include <optional>

class AccountRepository
{
public:
	explicit AccountRepository(Database& db);

	bool createAccount(
		const std::string& username,
		const std::string& passwordHash
	);

	void createAccountTable();

	std::vector<AccountRecord> getAllAccounts();

	std::optional<AccountRecord> findByUsername(
		const std::string& username
	);

private:
	Database& database;

	static constexpr const char* INSERT_SQL =
		"INSERT INTO accounts (username, password_hash) VALUES (?, ?);";

	static constexpr const char* SELECT_ALL_SQL =
		"SELECT id, username, password_hash FROM accounts;";

	static constexpr const char* FIND_BY_USERNAME_SQL =
		"SELECT id, username, password_hash FROM accounts WHERE username = ?;";
};