#include "Stage.h"

#ifndef MAIN_H
#define MAIN_H

class CMain
{
public:
	CMain(int passed_ScreenWidth, int passed_ScreenHeight);
	~CMain();

	CSDL_Setup* GetSetup() { return csdl_setup; }
	Stage* GetMainStage() { return main_stage; }
	SDL_Event* GetMainEvent(){ return pMainEvent; }
	Database* GetMainDatabase() { return mainDatabase; }
	void SoftwareLoop();
	//add getmouse position method
private:
	//definitions of CSDL_SETUP and SDL_EVENT to be passed
	CSDL_Setup* csdl_setup;
	SDL_Event* pMainEvent;
	Stage* main_stage;
	SDL_Renderer* pRenderer;
	Database* mainDatabase;
	//Screen dimensions
	int ScreenWidth;
	int ScreenHeight;

	bool quit;


	int MouseX;
	int MouseY;

};
#endif //MAIN_H
