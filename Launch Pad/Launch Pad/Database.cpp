#include "Database.h"
#include <iostream>

Database::Database(std::string filename)
{
	database = NULL;
	databasePath = filename;
	open(databasePath);
}

Database::~Database()
{
}
bool Database::open() 
{
	if (database == NULL) {

		if (sqlite3_open(databasePath.c_str(), &database) == SQLITE_OK)
			databaseOpen = true;
		return true;

		printf("Database failed to open\n");
		databaseOpen = false;
		return false;
	}

	return true;

}

bool Database::open(std::string filename)
{
	if (database == NULL) {

		if (sqlite3_open(filename.c_str(), &database) == SQLITE_OK)
			databaseOpen = true;
			return true;

		printf("Database failed to open\n");
		databaseOpen = false;
		return false;
	}
		
	return true;
}
std::vector<std::vector<std::string> > Database::query(char* passed_query)
{
	sqlite3_stmt *statement;
	//smart pointer here?
	std::vector<std::vector<std::string> > results;

	if (sqlite3_prepare_v2(database, passed_query, -1, &statement, 0) == SQLITE_OK)
	{
		int cols = sqlite3_column_count(statement);
		int result = 0;
		while (true)
		{
			result = sqlite3_step(statement);

			if (result == SQLITE_ROW)
			{
				std::vector<std::string> values;
				for (int col = 0; col < cols; col++)
				{
					values.push_back((char*)sqlite3_column_text(statement, col));
				}
				results.push_back(values);
			}
			else
			{
				break;
			}
		}

		sqlite3_finalize(statement);
	}

	std::string error = sqlite3_errmsg(database);
	if (error != "not an error")
	{
		std::cout << passed_query << " " << error << std::endl;

	}

	return results;
}

std::vector<std::vector<std::string> > Database::query(std::string query)
{
	sqlite3_stmt *statement;
	//smart pointer here?
	std::vector<std::vector<std::string> > results;

	if (sqlite3_prepare_v2(database, query.c_str(), -1, &statement, 0) == SQLITE_OK)
	{
		int cols = sqlite3_column_count(statement);
		int result = 0;
		while (true)
		{
			result = sqlite3_step(statement);

			if (result == SQLITE_ROW)
			{
				std::vector<std::string> values;
				for (int col = 0; col < cols; col++)
				{
					values.push_back((char*)sqlite3_column_text(statement, col));
					column_list.push_back(static_cast<const char*>((sqlite3_column_name(statement,col))));
				}
				results.push_back(values);
			}
			else
			{
				break;
			}
		}

		sqlite3_finalize(statement);
	}

	std::string error = sqlite3_errmsg(database);
	if (error != "not an error") std::cout << query << " " << error << std::endl;

	return results;
}

void Database::ClearColumnlist()
{

	if (!(column_list.empty()))
	{

		//one liner erase
		column_list.erase(column_list.begin(), column_list.begin() + (column_list.size()));
		/*
		while (!(column_list.empty()))
		{
			column_list.pop_back();
			//column_list.erase(column_list.begin())
		}
		*/
	}
}

void Database::close()
{		
	sqlite3_close(database);
	databaseOpen = false;
}