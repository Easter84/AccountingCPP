#pragma once
#include <string>


class AccountRepository
{
public:
	// All queries for the database are stored here
	static constexpr const char* CREATE_TABLE =
		"CREATE TABLE IF NOT EXISTS accounts ("
		"id INTEGER PRIMARY KEY AUTOINCREMENT,"
		"username TEXT UNIQUE NOT NULL,"
		"password_hash TEXT NOT NULL"
		");";

	static constexpr const char* INSET_ACCOUNT =
		"INSERT INTO accounts (username, password_hash) "
		"VALUES (?, ?);";

	static constexpr const char* GET_ACCOUNT_BY_USERNAME =
		"SELECT id, username, password_hash "
		"FROM accounts WHERE username = ?;";
};