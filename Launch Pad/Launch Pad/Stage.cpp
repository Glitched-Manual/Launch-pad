#include "Stage.h"



Stage::Stage(CSDL_Setup* passed_setup, Database* passed_database)
{
	csdl_setup = passed_setup;
	StageDatabase = passed_database;
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
		

		current_scene = new Prime_Scene(csdl_setup, StageDatabase);

		//risky use try catch
		//check if empty
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
	Content* create_temp = new Content;
	//std::cout << stage_contents[0].GetContentType() << std::endl;
   if (!(stage_contents.empty()))
	{
	   //changed from contentcount to size() way better
		for (int x = 0; x < stage_contents.size(); x++) 
		{
			if (stage_contents[x].GetContentType() == "texture") {
				//GetSceneContents()->begin()->GetContentPath()
				//use get content position to add to ->begin ex: begin +2
				//used *stage_contents
				Content content_arg = stage_contents[x];

				CTexture temp_ctexture(csdl_setup, content_arg);

				stage_textures.push_back(temp_ctexture);

				std::cout << "Texture created" << std::endl;

				AmountOfImages++;
			}
			else {


			}
		}
		/*if (stage_contents[1].GetContentType() == "texture") {
			//GetSceneContents()->begin()->GetContentPath()
			//use get content position to add to ->begin ex: begin +2
			//used *stage_contents
			Content content_arg = stage_contents[1];

			CTexture temp_ctexture(csdl_setup, content_arg);

			stage_textures.push_back(temp_ctexture);

			std::cout << "Texture created" << std::endl;
			AmountOfImages++;
		}

		else {

			std::cout << "unknown type" << std::endl;
		}
		*/
		
	}
   delete create_temp;
}

void Stage::RenderScene() 
{
	if (!(stage_textures.empty())) 
	{

		for (int i = 0; i < stage_textures.size(); i++)
		{
			//maybe call a scene method to render stuff
			try {
				if (stage_textures[i].GetTextureID() > "")
				{
					//check it texture exists
					for (int it = 0; it < stage_contents.size(); it++) 
					{
					//reder by address
						if (stage_contents[it].GetContentID() == stage_textures[i].GetTextureID()) 
						{
							CTexture rendered_texture = *GetTextureObject(it);
							rendered_texture.render(stage_contents[it].GetContentRect().x, stage_contents[it].GetContentRect().y);
						}
				    }
				}
				/*if (stage_textures[1].GetTextureID() > "")
				{
					//check it texture exists

					//reder by address
					CTexture rendered_texture = *GetTextureObject(1);
					rendered_texture.render(200, 20);
				}*/

			}
			catch (...)
			{


			}
		}
	}
}
//delete this
void Stage::DisplayTextureCount()
{

	//for loop to search all of contents
	if (!(stage_contents.empty())) {
	//loop vector begin to end
	if (stage_textures[0].GetTextureCount() != TextureObjectTracker)
	{

		std::cout << "stage_textures contains " << stage_textures[0].GetTextureCount() << " object(s)" << std::endl;



		TextureObjectTracker = stage_textures[0].GetTextureCount();
	}
}
}

//delete this use size() from vector
void Stage::DisplayContentCount() 
{

	//for loop to search all of contents

	//loop vector begin to end
	if (!(stage_contents.empty())) {
		if (stage_contents[0].GetContentCount() != ContentObjectTracker)
		{

			std::cout << "stage_contents contains " << stage_contents[0].GetContentCount() << " object(s)" << std::endl;



			ContentObjectTracker = stage_contents[0].GetContentCount();
		}
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
	if (passed_slot < stage_textures.size())
	{ 
		return &stage_textures[passed_slot];


	}

}