#include "SDLSetup.h"
#include "CoreScene.h"
#include "Texture.h"
//#include "CTexture.h"
#include <algorithm>
#include <vector>
#include <iterator>
#include "Database.h"
#pragma once
class Stage
{
public:
	Stage(CSDL_Setup* passed_setup);
	~Stage();

	// texture load textures audio loads audio
	void LoadSceneBySceneName(std::string passed_scene_name);

	void LoadSceneContents();

	void SetContentsFromScene();

	CTexture* GetTextureObject(int slot);

	Scene* GetCurrentScene() { return current_scene; }
		
	void CreateTextures();
	void RenderScene();
	void TestContent();
	void DisplayTextureCount();
	void DisplayContentCount();
	//void count() { loop_iter++; }

private:
	

	
	int TextureObjectTracker;
	int ContentObjectTracker;
	int AmountOfImages;
	std::vector<Content> stage_contents;
	std::vector<CTexture> stage_textures;
	//int loop_iter;
	Scene* current_scene;
	CSDL_Setup* csdl_setup;
	SDL_Renderer* pRenderer;
	SDL_Event* pMainEvent;
	//Database* StageDatabase; //not sure it to keep here or not
};

