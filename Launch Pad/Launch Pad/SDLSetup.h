#include "stdafx.h"
#include <iostream>
#include <cstdio>
#pragma once
class CSDL_Setup
{
public:
	CSDL_Setup(bool* quit, int passed_ScreenWidth,int ScreenHeight);
	~CSDL_Setup();

	bool createWindow();
	bool createRenderer();

	SDL_Window* getWindow() { return pWindow; }
	SDL_Renderer* getRenderer() { return pRenderer; }
	SDL_Event* getMainEvent() { return pMainEvent; }

	void clearWindow() { pWindow = NULL; }
	void clearRenderer() { pRenderer = NULL; }

	bool init();

	void Start();
	void Finish();

	void endSDL();
private:
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
	SDL_Event* pMainEvent;
	bool InitSuccess = true;

	//Screen dimensions
	
	 int SCREEN_WIDTH;
	 int SCREEN_HEIGHT;


};

