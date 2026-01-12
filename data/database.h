#pragma once

#include <sqlite3.h>
#include <string>

class Database
{
private:
	sqlite3* db = nullptr; // makes a member variable, and assigns it to nullptr
	static int callback(
		void* userData,
		int columnCount,
		char** columnValues,
		char** columnNames
	);

public:
	Database() = default;
	explicit Database(const std::string& filename);

	// Db base manipulation
	bool open(const std::string& filename); // Creates the connection to the db if one not there it creates it
	void close(); // Destroys connection
	sqlite3* handle() const; // Allows for the sqlite to be used by other functions

	// DB CRUD Operations
	bool execute(const std::string& sql);
	bool query(const std::string& sql);

	~Database();
};