#pragma once
#include "SDLSetup.h"
#include "CoreScene.h"
class Prime_Scene :	public Scene
{
public:
	Prime_Scene(CSDL_Setup* passed_setup);
	~Prime_Scene();
	void SetContentValues();
	void AddContents(Content passed_Content);
	void SetContentValuesByID(std::string passed_ID);
	std::vector<Content>* GetSceneContents() { return &prime_contents; }
	//Content GetContentByID(std::string passed_string);
	void clearTempContent();
	void LoadManualImageContent();
	void LoadGlassImageContent();
	
	
private:
	CSDL_Setup* csdl_setup;
	SDL_Event* pMainEvent;
	SDL_Renderer* pRenderer;
	//[position of content].place of vector eg begin
	std::vector<Content> prime_contents;
};

