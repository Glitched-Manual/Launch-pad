#include "stdafx.h"
#include "Content.h"
#include "SDLSetup.h"
#include <vector>

#pragma once

#ifndef SCENE_H
#define SCENE_H
class Scene
{
public:
	Scene();
	~Scene();
	//render from Scene
	// make various scene object or make scene virual

	
	virtual Content GetContentByID(std::string passed_string);

	virtual void AddContents(Content passed_Content) = 0;

	virtual std::vector<Content>* GetSceneContents() = 0;
private:
	Content content_manager;
	std::vector<Content> contents;
	
	//Create Sprites and Audio base off getContent return values

	//Sprites
	//Audio
};
#endif //"SCENE_H"
