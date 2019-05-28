#pragma once
#include "SDLSetup.h"
#include "CoreScene.h"
#include "Texture.h"
#include <algorithm>
#include <vector>
#include <iterator>
#include "Database.h"
#include "Audio.h"

#ifndef STAGE_H
#define STAGE_H
class Stage
{
public:
	Stage(CSDL_Setup* passed_setup,Database* passed_database);
	~Stage();

	// texture load textures audio loads audio
	void LoadSceneBySceneName(std::string passed_scene_name);

	void LoadSceneContents();

	void SetContentsFromScene();

	CTexture* GetTextureObject(unsigned int slot);

	Scene* GetCurrentScene() { return current_scene; }
	CAudio* GetStageAudio() { return stage_audio; }
	std::vector<Content*>* GetStageContents() { return stage_contents; }
	std::vector<CTexture*>* GetStageTextures() { return stage_textures; }

	void CreateTextures();
	void CreateAudio();
	void RenderScene();
	
private:
	

	
	int TextureObjectTracker;
	int ContentObjectTracker;
	int AmountOfImages;
	std::vector<Content*>* stage_contents;
	std::vector<CTexture*>* stage_textures;
	CAudio* stage_audio;
	Scene* current_scene;
	CSDL_Setup* csdl_setup;
	SDL_Renderer* pRenderer;
	SDL_Event* pMainEvent;
	Database* StageDatabase; //not sure it to keep here or not
};

#endif // STAGE_H