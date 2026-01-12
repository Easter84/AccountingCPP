#include "db_control.h"
#include <iostream>

AccountDatabase::AccountDatabase(const std::string& file)
{
	openDB(file);
}

bool AccountDatabase::openDB(const std::string& file)
{
	databaseFile = file;
	return sqlite3_open(file.c_str(), &db) == SQLITE_OK;
}

bool AccountDatabase::executeQuery(std::string query)
{
	char* errorMsg = nullptr;
	int rc = sqlite3_exec(
		db,
		query.c_str(),
		myCallback,
		nullptr,
		&errorMsg
	);

	if (rc != SQLITE_OK) {
		std::cerr << "SQlite error: " << errorMsg << "\n";
		sqlite3_free(errorMsg);
		return false;
	}

	return true;
}

bool AccountDatabase::readDB(const std::string& query)
{
	return false;
}

void AccountDatabase::closeDB()
{
	if (db) {
		sqlite3_close(db);
		db = nullptr;
	}
}

int AccountDatabase::myCallback(
	void* /*userData*/,
	int columnCount,
	char** columnValues,
	char** columnNames
)
{
	for (int i = 0; i < columnCount; i++)
	{
		std::cout << columnNames[i] << ": "
			<< (columnValues[i] ? columnValues[i] : "NULL")
			<< "\n";
	}
	std::cout << "-------\n";
	return 0;
}

AccountDatabase::~AccountDatabase()
{
	closeDB();
}
