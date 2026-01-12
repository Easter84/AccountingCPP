#pragma once
#include <sqlite3.h>
#include <string>


class AccountDatabase
{
private:
	sqlite3* db = nullptr;
	std::string databaseFile;
	

public:
	AccountDatabase() = default;
	explicit AccountDatabase(const std::string& file);

	bool openDB(const std::string& file);
	bool executeQuery(std::string query);
	bool readDB(const std::string& query);
	void closeDB();
	static int myCallback(
		void* userData, 
		int columnCount,
		char** columnValues,
		char** columnNames
	);

	~AccountDatabase();

};