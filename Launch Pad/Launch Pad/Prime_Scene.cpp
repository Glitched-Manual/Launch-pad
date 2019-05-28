#include "Prime_Scene.h"
#include <iostream>
#include "sqlite3.h"

Prime_Scene::Prime_Scene(CSDL_Setup* passed_setup, Database* passed_database)
{
	PrimeDB = passed_database;

	databaseopen = false;
	csdl_setup = passed_setup;
	pMainEvent = csdl_setup->getMainEvent();
	pRenderer = csdl_setup->getRenderer();
	prime_contents = new std::vector<Content*>;
	std::cout << "Prime_Scene obj created" << std::endl;
	//LoadContentValuesByID("manual");
	//LoadContentValuesByID("glass");

     // LoadContentValuesByID("manual-img");
	LoadContentPackage("testScene");
	std::cout << "package loaded" << std::endl;
		//LoadFromDatabase("manual-img");
	//LoadTestAudioContent();
	//std::cout << "LoadTestAudioContent call complete" << std::endl;

}


Prime_Scene::~Prime_Scene()
{
	delete csdl_setup;
	delete pMainEvent;
	delete pRenderer;
	delete PrimeDB;

}
//pure virtual for scene
void Prime_Scene::SetContentValues()
{

}

//pure virtual for scene
void Prime_Scene::LoadContentValuesByID(std::string passed_ID)
{
		//replace with sqlite3 calls
	    

		// forgot to change SceneID to ContentID
		std::string setContentCall = "SELECT * FROM PrimeContent WHERE ContentID = \"" + passed_ID + "\";";
		//const char* sql = setContentCall.c_str();
		// removed "/" in front of "databases"
		Content* tempContent = new Content;
		std::string column_name;
		//do queries returns vector of vectors
		//clear previous list
		PrimeDB->ClearColumnlist();
		std::vector<std::vector<std::string> > result = PrimeDB->query(setContentCall);
		if (!(result.empty())) 
		{
					   			
			for (std::vector<std::vector<std::string> >::iterator it = result.begin(); it < result.end(); ++it)
			{
				std::vector<std::string> row = *it;
				//no value error row.at(1)
				for (unsigned int count = 0; count < row.size(); count++)
				{
					std::cout << "Column: " << PrimeDB->GetColumnList().at(count) <<std::endl;
					std::cout << "Values: " << row.at(count) << std::endl;
					//use content setting algorithm 

					column_name = PrimeDB->GetColumnList().at(count);

					if (column_name == "ContentID") {

						// add if null case
						tempContent->SetContentID(row.at(count));
						std::cout << "Content ID set" << std::endl;
					}
					else if (column_name == "ContentType")
					{
						tempContent->SetContentType(row.at(count));

					}

					else if (column_name == "ContentPath")
					{
						tempContent->SetContentPath(row.at(count));

					}
					else if (column_name == "ContentRect")
					{
						tempContent->SetContentRect(row.at(count));
						//tempContent->SetContentRect(0,0,0,0);
						std::cout << "Content Rect set" << std::endl;
					}

					else
					{
						
						std::cout << "Error: SettingCallback unknown column : " << column_name << std::endl;

					}
				}
			
			}
		}
		//clears column name list
		prime_contents->push_back(tempContent);
		delete tempContent;
		std::cout << "LoadContentValuesByID: loading complete" << std::endl;
	
}
//pure virtual for scene
void Prime_Scene::AddContents(Content* passed_Content)
{

	//needs work

	prime_contents->push_back(passed_Content);

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
//pure virtual for scene
void Prime_Scene::LoadContentPackage(std::string passedPackageID)
{
	   

	std::string PackageCall = "SELECT * FROM PrimeScenes WHERE SceneID = \"" + passedPackageID + "\";";
	std::string databasesList;
	// removed "/" in front of "databases"

	//check if open?

	//use open method check if  database is open already
	

	//do queries returns vector of vectors
	std::vector<std::vector<std::string> > result = PrimeDB->query(PackageCall);
	for (std::vector<std::vector<std::string> >::iterator it = result.begin(); it < result.end(); ++it)
	{
		std::vector<std::string> row = *it;
		std::cout << "Row 0 values : " << row.at(0) << ", Row 1 = " << row.at(1) << std::endl;

		databasesList = row.at(1);
		
		//loop load filteredContents
		
	}

	
	
	std::vector<std::string> *filteredContents = new std::vector<std::string>;
		
		*filteredContents = FilterSceneContents(databasesList); //returns vector
	
	

		PackageLoader(*filteredContents);

		delete filteredContents;
}

void Prime_Scene::PackageLoader(std::vector<std::string> passedStringPackage)
{

	// for loop each string using load by id
	Content* tempcontent = new Content;
	
	//lol forgot it was empty
	if (!(passedStringPackage.empty()))
	{

		for (unsigned int i = 0; i < passedStringPackage.size(); i++)
		{
			LoadContentValuesByID(passedStringPackage[i]);

		}
	}
	else
	{
		std::cout << "Prime_Scene::PackageLoader error : passedStringPackage is empty" << std::endl;
	}
	delete tempcontent;
	std::cout << "PackageLoader end of method" << std::endl;
}


// make bool?
void Prime_Scene::LoadFromDatabase(std::string passedID)
{
	
	std::string call = "SELECT * FROM PrimeContent WHERE ContentID = \"" + passedID + "\";";

	
	// removed "/" in front of "databases"
	// check rc = sqlite3_open("databases/LaunchPad.db", &temp_db);
	

	//do queries


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
	std::cout << "Prime Contents capacity = "<< prime_contents->capacity() << std::endl;
	std::cout << "Content Pushing" << std::endl;
	//fails here
	AddContents(tempContent);
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
	prime_contents->push_back(temp_content);

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
	prime_contents->push_back(temp_content);

	std::cout << "Glass content pushed to prime contents" << std::endl;
	delete temp_content;
}

void Prime_Scene::LoadTestAudioContent()
{
	Content* temp_content = new Content;

	temp_content->SetContentID("freeze-mus");
	temp_content->SetContentPath("Debug/resources/audio/Freeze Me.mp3");
	temp_content->SetContentType("music");
	temp_content->SetContentRect(0, 0, 0, 0);
	prime_contents->push_back(temp_content);

	std::cout << "freeze-mus content pushed to prime contents" << std::endl;
	delete temp_content;
}