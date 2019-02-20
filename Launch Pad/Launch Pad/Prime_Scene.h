#pragma once
#include "SDLSetup.h"
#include "CoreScene.h"
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
class Prime_Scene :	public Scene
{
public:
	Prime_Scene(CSDL_Setup* passed_setup);
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
	 int c_primeCallback(void *param, int argc, char **argv, char **azColName)
	{
		Prime_Scene* prime = reinterpret_cast<Prime_Scene*>(param);
		std::cout << "returning c_primeCallback" << std::endl;
		return callback(argc, argv, azColName);

	}

	 int c_primeSettingCallBack(void *param, int argc, char **argv, char **azColName)
	{
		//Prime_Scene* prime = reinterpret_cast<Prime_Scene*>(param);
		std::cout << "returning c_primeSettingCallBack" << std::endl;
		return SettingCallback(argc, argv, azColName);

	}

	 int c_primePackageCallBack(void *param, int argc, char **argv, char **azColName)
	{
		Prime_Scene* prime = reinterpret_cast<Prime_Scene*>(GetSetup());
		std::cout << "returning c_primePackageCallBack" << std::endl;
		return prime->PackageCallback(argc, argv, azColName);

	}

	 int GetHello() { return hello.x; }
private:
	CSDL_Setup* csdl_setup;
	SDL_Event* pMainEvent;
	SDL_Renderer* pRenderer;
	struct Hi {

		int x;
	}hello;
	
	//[position of content].place of vector eg begin
	std::vector<Content> prime_contents;
};

#ifndef C_PRIMECALLBACK 
#define C_C_PRIMECALLBACK 

#endif //C_C_PRIMECALLBACK 