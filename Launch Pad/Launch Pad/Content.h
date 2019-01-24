#include <iostream>
#include <string>
#include "SDLSetup.h"
//#include "stdafx.h"

#pragma once
class Content
{
public:
	Content();
	~Content();

	static int contentCount;
	//setters
	void SetContentID(std::string newIDValue) { contentID = newIDValue; }
	void SetContentPath(std::string passed_Path) { contentPath = passed_Path; }
	void SetContentType(char passed_type);
	void SetContentRect(int passed_x,int passed_y,int passed_w,int passed_h);
	//getters
	
	std::string GetContentID() { return contentID; }
	std::string GetContentPath() { return contentPath; }
	std::string GetContentType() { return contentType; }
	SDL_Rect GetContentRect() { return contentRect; }
	int	GetContentCount() { return contentCount; }
	//
	void clearContent();
	void ClearContentRect();
private:

	std::string contentPath;
	std::string contentID;
	std::string contentType;
	SDL_Rect contentRect;
	

};

