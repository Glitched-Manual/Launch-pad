#include "stdafx.h"
#include "SDLSetup.h"
#include "Content.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#pragma once
class CTexture
{
public:
	//store texture within object

	CTexture(CSDL_Setup* passed_setup, Content* passed_content);
	~CTexture();
		
	//pass content data
	void AddTexture();
	void SetTextureID();
	std::string* GetTextureID();
	
	void LoadContentTexture();
	void LoadContentTextureByID();
	
	SDL_Texture* GetTexture() { return texture; } //failed render within this class

	SDL_Renderer* GetRenderer() { return pRenderer; }

	//use stage to add to stages texture array

	//render method

	void render(int x, int y,int w = NULL,int h= NULL, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void RenderTextureByID(std::string passed_string);

private:
	std::string* textureID;
	//changed to none-pointer
	CSDL_Setup* csdl_setup ;
	Content* texture_content;
	SDL_Renderer* pRenderer;
	SDL_Texture* texture;
	SDL_Rect* texture_rect;
};

