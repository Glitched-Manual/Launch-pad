#include "Stage.h"



Stage::Stage(CSDL_Setup* passed_setup)
{
	csdl_setup = passed_setup;
	pMainEvent = csdl_setup->getMainEvent();
	pRenderer = csdl_setup->getRenderer();

	LoadSceneBySceneName("prime_Scene");
	AmountOfImages = 0;
}


Stage::~Stage()
{
}

void Stage::LoadSceneContents()
{

	//stage_contents = *current_scene->GetSceneContents();

}

void Stage::LoadSceneBySceneName(std::string passed_scene_name)
{
	//pass text as arguement

	if (passed_scene_name == "prime_Scene")
	{
		

		current_scene = new Prime_Scene(csdl_setup);

		//risky use try catch
		SetContentsFromScene();
	}

}

//getTexture obj
void Stage::SetContentsFromScene()
{
	//risky use try catch

	stage_contents = *current_scene->GetSceneContents();
	/*
	if (stage_contents != *current_scene->GetSceneContents())
	{
		std::cout << "Failed to load current Scene contents" << std::endl;

	}
	*/
}
//make bool in scene to create texture if not already done
void Stage::CreateTextures()
{
	std::cout << stage_contents[0].GetContentType() << std::endl;
	
	if (stage_contents[0].GetContentType() == "texture") {
		//GetSceneContents()->begin()->GetContentPath()
		//use get content position to add to ->begin ex: begin +2
		//used *stage_contents
		Content content_arg = stage_contents[0];

		CTexture temp_ctexture(csdl_setup, content_arg);

		stage_textures.push_back(temp_ctexture);

		std::cout << "Texture created" << std::endl;

		AmountOfImages++;
	}
	if (stage_contents[1].GetContentType() == "texture") {
		//GetSceneContents()->begin()->GetContentPath()
		//use get content position to add to ->begin ex: begin +2
		//used *stage_contents
		Content content_arg = stage_contents[1];

		CTexture temp_ctexture(csdl_setup, content_arg);

		stage_textures.push_back(temp_ctexture);

		std::cout << "Texture created" << std::endl;
		AmountOfImages++;
	}
}

void Stage::RenderScene() 
{
	//maybe call a scene method to render stuff
	try {
		if (stage_textures[0].GetTextureID() > "")
		{
			//check it texture exists

			//reder by address
			CTexture rendered_texture =  *GetTextureObject(0);
			rendered_texture.render(20, 20);
		}
		if (stage_textures[1].GetTextureID() > "")
		{
			//check it texture exists

			//reder by address
			CTexture rendered_texture = *GetTextureObject(1);
			rendered_texture.render(200, 20);
		}

	}
	catch (...) 
	{


	}
	
}

void Stage::DisplayTextureCount() 
{

	//for loop to search all of contents

	//loop vector begin to end
	if (stage_textures[0].GetTextureCount() != TextureObjectTracker)
	{

		std::cout << "stage_textures contains " << stage_textures[0].GetTextureCount() << " object(s)" << std::endl;



		TextureObjectTracker = stage_textures[0].GetTextureCount();
	}

}


void Stage::DisplayContentCount() 
{

	//for loop to search all of contents

	//loop vector begin to end
	if (stage_contents[0].GetContentCount() != ContentObjectTracker)
	{

		std::cout << "stage_contents contains " << stage_contents[0].GetContentCount() << " object(s)" << std::endl;



		ContentObjectTracker = stage_contents[0].GetContentCount();
	}

}


void Stage::TestContent()
{
	DisplayContentCount();
	DisplayTextureCount();
}

CTexture* Stage::GetTextureObject(int passed_slot)
{

	//only allows images to be called?
	if (passed_slot < AmountOfImages)
	{ 
		return &stage_textures[passed_slot];


	}

}