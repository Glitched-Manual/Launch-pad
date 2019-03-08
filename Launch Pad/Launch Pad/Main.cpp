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


	

	//setup scene?

	GetMainStage()->CreateTextures(); 
   
	while (!quit && pMainEvent->type != SDL_QUIT) {
		csdl_setup->Start();
		
		//main_stage->TestContent();

		main_stage->RenderScene();


		//render scene and add code for actions
							   			
		//SDL_GetMouseState(&MouseX, &MouseY);

		//event check()

		//Stage->DrawBack();


		//Stage->DrawFront();
		//Stage->Update();
		if (pMainEvent->type == 'k') {
			main_stage->GetStageAudio()->PlayMusicByID("test");
		}
		
		csdl_setup->Finish();
	}

	csdl_setup->endSDL();

}