#ifndef __DATABASE_H__
#define __DATABASE_H__

#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include "sqlite3.h"

//Do not close until the program needs to be closed

class Database
{
public:
	Database(std::string filename);
	~Database();
	bool open();
	bool open(std::string filename);
	std::vector<std::vector<std::string> > query(std::string query);
	std::vector<std::vector<std::string> > query(char* passed_query);
	std::string GetColumnName() { return column_name; }
	std::vector<std::string> GetColumnList() { return column_list; }
	//clears column name list
	void ClearColumnlist();
	bool GetOpenStatus() { 	return databaseOpen; }
	void close();

private:
	sqlite3 *database;
	std::string databasePath;
	std::vector<std::string> column_list;
	std::string column_name;
	bool databaseOpen;
};

#endif
