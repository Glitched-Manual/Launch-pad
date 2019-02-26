#pragma once
#include "SDLSetup.h"
#include "CoreScene.h"
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include "Database.h"
class Prime_Scene :	public Scene
{
public:
	Prime_Scene(CSDL_Setup* passed_setup,Database* passed_database);
	~Prime_Scene();
	void SetContentValues();
	void AddContents(Content passed_Content);
	void LoadContentValuesByID(std::string passed_ID);
	std::vector<Content>* GetSceneContents() { return &prime_contents; }
	//Content GetContentByID(std::string passed_string);
	void clearTempContent();
	void LoadManualImageContent();
	void LoadGlassImageContent();
	void LoadContentPackage(std::string passedPackageID);
	void PackageLoader(std::vector<std::string> passedStringPackage);
	void LoadFromDatabase(std::string passedID);

	std::vector<std::string> FilterSceneContents(std::string passedSceneList);

	int callback(int argc, char **argv, char **azColName);
	int SettingCallback(int argc, char **argv, char **azColName);
	int PackageCallback(int argc, char **argv, char **azColName);

	CSDL_Setup* GetSetup() { return csdl_setup; }

	static int VectorContentStringCount;
	//callbacks must c type be structs
	

	 
private:
	CSDL_Setup* csdl_setup;
	SDL_Event* pMainEvent;
	SDL_Renderer* pRenderer;
	Database* PrimeDB;
	bool databaseopen;
	
	//[position of content].place of vector eg begin
	std::vector<Content> prime_contents;
};
