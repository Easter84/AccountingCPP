#include "database.h"
#include <iostream>
#include <sqlite3.h>
/*
* This Method is used to callback data from a Sqlite3 database and it is required by SQLite3
*/
int Database::callback(
	void* userData, 
	int columnCount, 
	char** columnValues, 
	char** columnNames
)
{
	auto* rows = static_cast<std::vector<Row>*>(userData);

	Row row;

	for (int i = 0; i < columnCount; i++)
	{
		std::string key = columnNames[i];
		std::string value = columnValues[i] ? columnValues[i] : "";

		row[key] = value;
	}

	rows->push_back(row);
	return 0;
}

Database::Database(const std::string& filename)
{
	open(filename);
}

bool Database::open(const std::string& filename)
{
	if (db != nullptr)  
	{
		return true; 
	}

	int rc = sqlite3_open(filename.c_str(), &db);  
	if (rc != SQLITE_OK)
	{
		std::cerr << "Failed to open database: "
			<< sqlite3_errmsg(db) << "\n";
		db = nullptr;
		return false;
	}

	return true;
}

void Database::close()
{
	if (db) 
	{
		sqlite3_close(db);
		db = nullptr;
	}
}

sqlite3* Database::handle() const
{
	return db;
}

// Used to run complex prepared SQL statements, and can return data.
bool Database::executePrepared(
	const std::string& sql, 
	const std::vector<std::string>& params)
{
	// If no database fail
	if (!db)
		return false;

	sqlite3_stmt* stmt = nullptr; // Creating a pointer to the statement

	// Declares the paramaters for the statment?
	int rc = sqlite3_prepare_v2(
		db,
		sql.c_str(),
		-1, // Determines the length of the string
		&stmt, // pointer to statement memory location?
		nullptr
	);

	// If there is an return code that isn't all green report the error and fail
	if (rc != SQLITE_OK)
	{
		std::cerr << "Prepare failed: "
			<< sqlite3_errmsg(db) << "\n";
		if (stmt)
			sqlite3_finalize(stmt);
		return false;
	}

	for (size_t i = 0; i < params.size(); i++)
	{
		sqlite3_bind_text(
			stmt,
			static_cast<int>(i + 1), // SQLite is not 0 based but 1 based must offset that by adding 1
			params[i].c_str(),
			-1,
			SQLITE_TRANSIENT // Ensures the pointer used in params is destroyed
		);
	};

	rc = sqlite3_step(stmt);
	if (rc != SQLITE_DONE)
	{
		std::cerr << "Execution failed: "
			<< sqlite3_errmsg(db) << "\n";
		sqlite3_finalize(stmt);
		return false;
	}

	sqlite3_finalize(stmt);
	return true;
}

// Used for none return SQL statements such as Creat, Update Drop etc...
bool Database::execute(const std::string& sql)
{
	if (!db)
		return false;

	char* errorMsg = nullptr;

	int rc = sqlite3_exec(
		db,                // open database
		sql.c_str(),       // SQL text
		nullptr,           // no callback
		nullptr,           // no user data
		&errorMsg          // error message output
	);

	if (rc != SQLITE_OK)
	{
		std::cerr << "SQL error: " << errorMsg << "\n";
		sqlite3_free(errorMsg);
		return false;
	}

	return true;
}

// Used for SQL queries that may return data.
std::vector<Row> Database::query(const std::string& sql)
{
	std::vector<Row> rows;

	if (!db)
		return rows;

	char* errorMsg = nullptr;

	int rc = sqlite3_exec(
		db,
		sql.c_str(),
		callback,
		&rows, // <- userData
		&errorMsg
	);

	if (rc != SQLITE_OK)
	{
		std::cerr << "SQL error: " << errorMsg << "\n";
		sqlite3_free(errorMsg);
	}
	return rows;
}

Database::~Database()
{
	close();
}
