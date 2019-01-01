#include "stdafx.h"
#include <iostream>
#include <cstdio>
#pragma once
class CSDLSetup
{
public:
	CSDLSetup();
	~CSDLSetup();

	void createWindow();
	void createRenderer();

	SDL_Window* getWindow() { return pWindow; }
	SDL_Renderer* getRenderer() { return pRenderer; }

	void clearWindow() { pWindow = NULL; }
	void clearRenderer() { pRenderer = NULL; }

	bool init();
private:
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
	bool InitSuccess = true;

	//Screen dimensions
	const int SCREEN_WIDTH = 960;
	const int SCREEN_HEIGHT = 720;


};

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#pragma once
class CSDLSetup
{
public:
	CSDLSetup();
	~CSDLSetup();

	bool createWindow();
	bool createRenderer();

	SDL_Window* getWindow() { return pWindow; }
	SDL_Renderer* getRenderer() { return pRenderer; }

	void clearWindow() { pWindow = NULL; }
	void clearRenderer() { pRenderer = NULL; }

	bool init();
	void endSDL();
private:
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
	bool InitSuccess = true;

	//Screen dimensions
	const int SCREEN_WIDTH = 960;
	const int SCREEN_HEIGHT = 720;


};

