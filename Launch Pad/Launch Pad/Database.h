#ifndef __DATABASE_H__
#define __DATABASE_H__

#include <string>
#include <vector>
#include <cstring>
#include "sqlite3.h"



class Database
{
public:
	Database(std::string filename);
	~Database();
	bool open();
	bool open(std::string filename);
	std::vector<std::vector<std::string> > query(std::string query);
	bool GetOpenStatus() { 	return databaseOpen; }
	void close();

private:
	sqlite3 *database;
	std::string databasePath;
	bool databaseOpen;
};

#endif
