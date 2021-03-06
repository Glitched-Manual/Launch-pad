#include "SDLSetup.h"

CSDL_Setup::CSDL_Setup(bool* quit, int passed_ScreenWidth, int passd_ScreenHeight)
{
	//set screen dimensions

	SCREEN_WIDTH = passed_ScreenWidth;
	SCREEN_HEIGHT = passd_ScreenHeight;
	//second init main_event
	
	pMainEvent = NULL;

	pMainEvent = new SDL_Event();

}

CSDL_Setup::~CSDL_Setup()
{
}

bool CSDL_Setup::createWindow()
{
	pWindow = NULL;
	pWindow = SDL_CreateWindow("Launch Pad", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (this->getWindow() == NULL)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	return true;

}
bool CSDL_Setup::createRenderer()
{
	pRenderer = NULL;

	pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (this->getRenderer() == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	return true;
}

bool CSDL_Setup::LoadGameController()
{
	csdl_GameController = NULL;
	//Load joystick
	csdl_GameController = SDL_GameControllerOpen(0);
	if (csdl_GameController == NULL)
	{
		printf("Warning: Unable to open game controller! SDL Error: %s\n", SDL_GetError());
		return false;
	}
	else 
	{
		if(SDL_IsGameController(0))
		{
			csdl_GameControllerButton = new SDL_GameControllerButton;
			std::cout << "The controller was reconized" << std::endl;
		}
		else 
		{
			printf("LoadGameController Warning: Controller was not reconized! SDL Error: %s\n", SDL_GetError());
		}
	}
	return true;
}

bool CSDL_Setup::init()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		InitSuccess = false;
	}
	else
	{

		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");

			InitSuccess = false;
		}

		//Create window
		
		if (!this->createWindow())
		{
			InitSuccess = false;
		}
		else
		{
	    // create renderer
			if (!this->createRenderer()) 
			{
				InitSuccess = false;
			}
			else
			{

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					InitSuccess = false;
				}

				
				//Initialize SDL_mixer
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
					InitSuccess = false;
				}

				//Initialize SDL_ttf
				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					InitSuccess = false;
				}
				//Check for joysticks
				if (SDL_NumJoysticks() < 1)
				{
					printf("Warning: No joysticks connected!\n");
				}
				else
				{
					if (LoadGameController())
					{

					}
					else
					{
						printf("SDLSetup Warning: Unable to Load game controller! SDL Error: %s\n", SDL_GetError());
					}
				}
			}
		}
	}
	return InitSuccess;
}

void CSDL_Setup::Start()
{
	
	SDL_RenderClear(pRenderer);
}

void CSDL_Setup::Finish()
{
	
	SDL_RenderPresent(getRenderer()); //break point triggered here
}


void CSDL_Setup::endSDL()
{

	//Close game controller
	if (csdl_GameController != NULL)
	{
		SDL_GameControllerClose(csdl_GameController);
		csdl_GameController = NULL;
	}
	//Quit SDL subsystems
	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

}
