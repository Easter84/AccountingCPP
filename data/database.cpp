#include "database.h"
#include <iostream>

int Database::callback(
	void*, 
	int columnCount, 
	char** columnValues, 
	char** columnNames
)
{
	for (int i = 0; i < columnCount; i++)
	{
		std::cout
			<< columnNames[i]
			<< " = "
			<< (columnValues[i] ? columnValues[i] : "NULL")
			<< "\n";
	}
	std::cout << "----\n";
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
bool Database::query(const std::string& sql)
{
	if (!db)
		return false;

	char* erroMsg = nullptr;

	int rc = sqlite3_exec(
		db,
		sql.c_str(),
		callback,
		nullptr,
		&erroMsg
	);

	if (rc != SQLITE_OK)
	{
		std::cerr << "SQL error: " << erroMsg << "\n";
		sqlite3_free(erroMsg);
		return false;
	}
	return true;
}

Database::~Database()
{
	close();
}
