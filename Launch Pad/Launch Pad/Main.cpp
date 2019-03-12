#include "Main.h"



CMain::CMain(int passed_ScreenWidth, int passed_ScreenHeight)
{
	ScreenWidth = passed_ScreenWidth;
	ScreenHeight = passed_ScreenHeight;
	quit = false;
	csdl_setup = new CSDL_Setup(&quit, ScreenWidth, ScreenHeight);
	pMainEvent = csdl_setup->getMainEvent();
	pRenderer = csdl_setup->getRenderer();
	mainDatabase = new Database("databases/LaunchPad.db");
	main_stage = new Stage(GetSetup(), GetMainDatabase());
}


CMain::~CMain()
{
	mainDatabase->close();
}

int Content::contentCount = -2;
int CTexture::textureCount = 0;

void CMain::SoftwareLoop()
{
	

	csdl_setup->init();

	bool quit = false;
	bool buttonReleased = true;
	/*
	if (GetMainEvent()->key.keysym.scancode != SDL_GetScancodeFromKey(GetMainEvent()->key.keysym.sym))
		printf("Physical %s key acting as %s key",
			SDL_GetScancodeName(GetMainEvent()->key.keysym.scancode),
			SDL_GetKeyName(GetMainEvent()->key.keysym.sym));
			*/
	std::cout << GetMainEvent()->key.type << std::endl;

	//setup scene?

	GetMainStage()->CreateTextures(); 
	GetMainStage()->CreateAudio();
	while (!quit && GetMainEvent()->type != SDL_QUIT) {

		csdl_setup->Start();
		
		//main_stage->TestContent();

		main_stage->RenderScene();


		//render scene and add code for actions
							   			
		//SDL_GetMouseState(&MouseX, &MouseY);

		//event check()
		if ((GetMainEvent()->type == 768)&(buttonReleased)) {
			buttonReleased = false;
			std::cout << "buttonPressed" << std::endl;
			main_stage->GetStageAudio()->PlayMusicByID("freeze-mus");
			std::cout << GetMainEvent()->type << std::endl;
		}
		if ((GetMainEvent()->type == SDL_KEYUP)&(buttonReleased == false))
		{
			buttonReleased = true;
			std::cout << "buttonReleased" << std::endl;
		}
		//Stage->DrawBack();


		//Stage->DrawFront();
		//Stage->Update();
		
		//std::cout << GetMainEvent()->type << std::endl;
		csdl_setup->Finish();
	}

	csdl_setup->endSDL();

}