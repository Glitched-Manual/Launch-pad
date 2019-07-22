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
	
	char* gameControllerMapping;
	gameControllerMapping = SDL_GameControllerMapping(csdl_setup->GetGameController());
	std::cout << "Controller mapping is " << gameControllerMapping << std::endl;

	while (!quit && GetMainEvent()->type != SDL_QUIT)
	{

		csdl_setup->Start();

		//main_stage->TestContent();

		main_stage->RenderScene();


		//render scene and add code for actions

		//SDL_GetMouseState(&MouseX, &MouseY);
	
		//event check()
		while (SDL_PollEvent(GetMainEvent()) != 0)
		{
			if ((GetMainEvent()->key.keysym.sym == 'k') & (buttonReleased)) {
				buttonReleased = false;
				std::cout << "buttonPressed" << std::endl;
				if (!(main_stage->GetStageAudio()->GetMusicList().empty()))
				{  //
					main_stage->GetStageAudio()->PlayMusicByID(main_stage->GetStageAudio()->GetMusicList()[0].music_id);

					std::cout << GetMainEvent()->key.keysym.sym << std::endl;
				}


			}
			//SDL_GameController events
			else if (GetMainEvent()->type == SDL_CONTROLLERBUTTONDOWN)
			{
				//std::cout << "Game controller button "<< GetMainEvent()->cbutton.button << " was pressed" << std::endl;

				 std::cout << "Game controller button " << SDL_GameControllerGetButton(csdl_setup->GetGameController(),*csdl_setup->GetGameControllerButton()) << " was pressed" << std::endl;
				 std::cout << "Game controller Button test 2 " << *csdl_setup->GetGameControllerButton() << " was pressed" << std::endl;
				 std::cout << "Game controller button test 3 " << GetMainEvent()->cbutton.button << " was pressed" << std::endl;
				 std::cout << "Game controller button test 4 " << SDL_CONTROLLER_BUTTON_A << " was pressed" << std::endl;
				 if (GetMainEvent()->type == SDL_CONTROLLER_BUTTON_A)
				 {
					// std::cout << " \"A\" was pressed!" << std::endl;
				 }
				 				 
				 else if (GetMainEvent()->cbutton.button == SDL_CONTROLLER_BUTTON_A)
				 {
					 std::cout << " \"B\" was pressed!" << std::endl;
				 }
				 else if (GetMainEvent()->cbutton.button == SDL_CONTROLLER_BUTTON_B)
				 {
					 std::cout << " \"A\" was pressed!" << std::endl;
				 }
				 else if (GetMainEvent()->cbutton.button == SDL_CONTROLLER_BUTTON_X)
				 {
					 std::cout << " \"Y\" was pressed!" << std::endl;
				 }
				 else if (GetMainEvent()->cbutton.button == SDL_CONTROLLER_BUTTON_Y)
				 {
					 std::cout << " \"X\" was pressed!" << std::endl;
				 }
				 else if (GetMainEvent()->cbutton.button == SDL_CONTROLLER_AXIS_LEFTX)
				 {
					 std::cout << " \"AXIS_LEFTX\" was pressed!" << std::endl;
				 }
				 else if (GetMainEvent()->cbutton.button == SDL_CONTROLLER_AXIS_LEFTY)
				 {
					 std::cout << " \"AXIS_LEFTX\" was pressed!" << std::endl;
				 }
				 else if (GetMainEvent()->cbutton.button == SDL_CONTROLLER_AXIS_RIGHTX)
				 {
					 std::cout << " \"AXIS_LEFTX\" was pressed!" << std::endl;
				 }
				 else if (GetMainEvent()->cbutton.button == SDL_CONTROLLER_AXIS_RIGHTY)
				 {
					 std::cout << " \"AXIS_LEFTX\" was pressed!" << std::endl;
				 }
				 else if (GetMainEvent()->cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_UP)
				 {
					 std::cout << " \"DPAD_UP\" was pressed!" << std::endl;
				 }
				 else if (GetMainEvent()->cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_DOWN)
				 {
					 std::cout << " \"DPAD_DOW\" was pressed!" << std::endl;
				 }
				 else if (GetMainEvent()->cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_LEFT)
				 {
					 std::cout << " \"DPAD_LEFT\" was pressed!" << std::endl;
				 }
				 else if (GetMainEvent()->cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_RIGHT)
				 {
					 std::cout << " \"DPAD_RIGHT\" was pressed!" << std::endl;
				 }
			}
						// used SDL_KEYUP when SDL_KEYDOWN was needed playback paused an started super fast
			else if ((GetMainEvent()->type == SDL_KEYDOWN) & (buttonReleased == false))
			{
				buttonReleased = true;
				std::cout << "buttonReleased" << std::endl;
			}
			else 
			{
				std::cout << GetMainEvent()->key.keysym.sym << " Pressed" << std::endl;
				
			}
		}
		/*
			switch (GetMainEvent()->key.keysym.sym)
			{
			case 'k':
				buttonReleased = false;
				std::cout << "buttonPressed" << std::endl;
				main_stage->GetStageAudio()->PlayMusicByID("freeze-mus");
				std::cout << GetMainEvent()->key.keysym.sym << std::endl;
				break;
			default:
			}
		*/

		//Stage->DrawBack();


		//Stage->DrawFront();
		//Stage->Update();

		//std::cout << GetMainEvent()->type << std::endl;
		csdl_setup->Finish();
	}

	csdl_setup->endSDL();

}