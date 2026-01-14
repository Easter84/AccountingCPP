#pragma once

#include <sqlite3.h>
#include <string>
#include <vector>
#include <unordered_map>


using Row = std::unordered_map<std::string, std::string>;  // This is column name -> value

class Database
{
private:
	sqlite3* db = nullptr; // makes a member variable, and assigns it to nullptr
	
	// This is the required callback function for reading SQLite Data
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

	// This will handle INSET UPDATE and DELETE operations
	bool executePrepared(
		const std::string& sql,
		const std::vector<std::string>& params
	);

	// DB CRUD Operations
	bool execute(const std::string& sql);
	std::vector<Row>query(const std::string& sql);

	~Database();
};