#include "Prime_Scene.h"
#include <iostream>
#include "sqlite3.h"
int Prime_Scene::VectorContentStringCount = 0;
Prime_Scene::Prime_Scene(CSDL_Setup* passed_setup)
{
	PrimeDB = new Database("databases/LaunchPad.db");

	databaseopen = false;
	csdl_setup = passed_setup;
	pMainEvent = csdl_setup->getMainEvent();
	pRenderer = csdl_setup->getRenderer();
	
	std::cout << "Prime_Scene obj created" << std::endl;
	//LoadContentValuesByID("manual");
	//LoadContentValuesByID("glass");


	LoadContentPackage("testScene");
	std::cout << "package loaded" << std::endl;
		//LoadFromDatabase("manual-img");

}


Prime_Scene::~Prime_Scene()
{
}

void Prime_Scene::SetContentValues()
{

}


void Prime_Scene::LoadContentValuesByID(std::string passed_ID)
{
		//replace with sqlite3 calls
	    

		// forgot to change SceneID to ContentID
		std::string setContentCall = "SELECT * FROM PrimeContent WHERE ContentID = \"" + passed_ID + "\"";
		const char* sql = setContentCall.c_str();
		// removed "/" in front of "databases"
		if (PrimeDB->GetOpenStatus() == false) 
		{
			PrimeDB->open("databases/LaunchPad.db");
		}
		
		//do queries returns vector of vectors
		
		std::vector<std::vector<std::string> > result = PrimeDB->query(setContentCall);
		for (std::vector<std::vector<std::string> >::iterator it = result.begin(); it < result.end(); ++it)
		{
			std::vector<std::string> row = *it;
			std::cout << "Values: " << row.at(0) << ", B= " << row.at(1) << ")" << std::endl;
		}

		PrimeDB->close();
		std::cout << "LoadContentValuesByID database closed" << std::endl;
	
}

void Prime_Scene::AddContents(Content passed_Content)
{

	//needs work

	prime_contents.push_back(passed_Content);

}
/*
Content Prime_Scene::GetContentByID(std::string passed_string)
{   // int value for changing iteration
	int iter = 0;
	for (std::vector<Content>::iterator content_iterator = prime_contents.begin(); content_iterator != prime_contents.end(); content_iterator++)
	{   //filter for disired content
		if (prime_contents[iter].GetContentID() == passed_string)
		{
			return prime_contents[iter];

		}
		iter++;
	}

}
*/
void Prime_Scene::clearTempContent()
{
	//temp_content.clearContent();

}

void Prime_Scene::LoadContentPackage(std::string passedPackageID)
{
	   

	std::string PackageCall = "SELECT * FROM PrimeScenes WHERE SceneID = \"" + passedPackageID + "\"";
	
	// removed "/" in front of "databases"

	//check if open?

	//use open method check if  database is open already
	if (PrimeDB->GetOpenStatus() == false)
	{
		PrimeDB->open("databases/LaunchPad.db");
	}

	//do queries returns vector of vectors
	std::vector<std::vector<std::string> > result = PrimeDB->query(PackageCall);
	for (std::vector<std::vector<std::string> >::iterator it = result.begin(); it < result.end(); ++it)
	{
		std::vector<std::string> row = *it;
		std::cout << "Row 0 values : " << row.at(0) << ", Row 1 = " << row.at(1) << std::endl;

		//std::string databasesList = row.at(1);
		//std::vector<string> filteredContents = FilterSceneContents(databasesList); //returns vector
		//loop load filteredContents
		
	}

	PrimeDB->close();
	
	
	
}

void Prime_Scene::PackageLoader(std::vector<std::string> passedStringPackage)
{

	// for loop each string using load by id
	Content* tempcontent = new Content;
	
	//lol forgot it was empty
	for (int i = 0; i < VectorContentStringCount;i++)
	{
		LoadContentValuesByID(passedStringPackage[i]);
		
	}
	delete tempcontent;
	std::cout << "PackageLoader end of method" << std::endl;
}


// make bool?
void Prime_Scene::LoadFromDatabase(std::string passedID)
{
	
	std::string call = "SELECT * FROM PrimeContent WHERE ContentID = \"" + passedID + "\"";

	
	// removed "/" in front of "databases"
	// check rc = sqlite3_open("databases/LaunchPad.db", &temp_db);
	if (PrimeDB->GetOpenStatus() == false)
	{
		PrimeDB->open("databases/LaunchPad.db");
	}

	//do queries

	PrimeDB->close();


}



int Prime_Scene::callback(int argc, char **argv, char **azColName)
{
	int i;
	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");

	}

	//create setting callback

	return 0;
}
// needs to be edited
int Prime_Scene::SettingCallback(int argc, char **argv, char **azColName)
{
	int i;
	std::string column_name;
	Content* tempContent = new Content;
	for (i = 0; i < argc; i++) 
	{
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");

		column_name = azColName[i];

		if (column_name == "ContentID") {

			// add if null case
			tempContent->SetContentID(argv[i]);
			std::cout << "Content ID #" << i <<" set"<< std::endl;
		}
		else if(column_name == "ContentType")
		{ 
			tempContent->SetContentType(argv[i]);

		}

		else if (column_name == "ContentPath")
		{
			tempContent->SetContentPath(argv[i]);

		}
		else if (column_name == "ContentRect")
		{
			tempContent->SetContentRect(argv[i]);
			//tempContent->SetContentRect(0,0,0,0);
			std::cout << "Content Rect set" << std::endl;
		}

		else
		{
			std::cout << "Error: SettingCallback unknown column." << std::endl;

			return 1;
		}
		
	}
	
	std::cout << tempContent->GetContentID() << std::endl;
	std::cout << tempContent->GetContentPath() << std::endl;
	std::cout << tempContent->GetContentType() << std::endl;

	std::cout << tempContent->GetContentRect().x << std::endl;
	std::cout << "Prime Contents capacity = "<< prime_contents.capacity() << std::endl;
	std::cout << "Content Pushing" << std::endl;
	//fails here
	AddContents(*tempContent);
	std::cout << "Content Pushed" << std::endl;
	delete tempContent;
	//create setting callback

	return 0;
}

int Prime_Scene::PackageCallback(int argc, char **argv, char **azColName)
{
	int i;
	
	std::vector<std::string> *filteredContentList = new std::vector<std::string>;
	
	std::string col_name;
	for (i = 0; i < argc; i++)
	{
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
		//filter text

		std::cout << "Col name = " << azColName[i] << std::endl;
		col_name = azColName[i];
		if (col_name == "SceneContents")
		{

			// method that returns std::vector<std::string> filteredList

			std::string databasesList = argv[i];

			std::cout << "datalist = " << databasesList << std::endl;

			*filteredContentList = FilterSceneContents(databasesList);
		}

	}

	//set and push Content list 
	PackageLoader(*filteredContentList);

	delete filteredContentList;
	std::cout << "PackageLoader Called" << std::endl;
	
	//create setting callback

	return 0;


}


std::vector<std::string> Prime_Scene::FilterSceneContents(std::string passedSceneList)
{
	std::vector<std::string> filteredList;
	std::string collect;

	for (int m = 0; m != passedSceneList.length(); ++m)
	{
		if (passedSceneList[m] != ',')
		{

			//	std::cout << databasesList[m];

			collect += passedSceneList[m];

			if (m == passedSceneList.length() - 1)
			{

				filteredList.push_back(collect);
				std::cout << "max reached" << std::endl;

				std::cout << collect << std::endl;
			}
		}
		else
		{
			std::cout << std::endl;
			filteredList.push_back(collect);
			collect = "";
			std::cout << "collect cleared" << std::endl;
		}

	}


	//std::cout << std::endl << databasesList[databasesList.length() -1] << std::endl;


	int it = 0;

	for (auto a : filteredList)
	{
		std::cout << it << ". " << a << std::endl;
		it++;
		VectorContentStringCount++;
	}
	return filteredList;
}





void Prime_Scene::LoadManualImageContent()
{
	Content* temp_content = new Content;

	temp_content->SetContentID("manual-img");
	temp_content->SetContentPath("Debug/resources/images/solo.jpg");
	temp_content->SetContentType('t');
	temp_content->SetContentRect(0, 0, 100, 100);
	prime_contents.push_back(*temp_content);

	std::cout << "Manual content pushed to prime contents" << std::endl;
	delete temp_content;
}

void Prime_Scene::LoadGlassImageContent()
{
	Content* temp_content = new Content;

	temp_content->SetContentID("glass-img");
	temp_content->SetContentPath("Debug/resources/images/glass.jpg");
	temp_content->SetContentType('t');
	temp_content->SetContentRect(20, 20, 100, 100);
	prime_contents.push_back(*temp_content);

	std::cout << "Glass content pushed to prime contents" << std::endl;
	delete temp_content;
}