#include "Stage.h"



Stage::Stage(CSDL_Setup* passed_setup, Database* passed_database)
{
	csdl_setup = passed_setup;
	StageDatabase = passed_database;
	stage_audio = new CAudio; // start fresh
	pMainEvent = csdl_setup->getMainEvent();
	pRenderer = csdl_setup->getRenderer();

	stage_contents = new std::vector<Content*>;
	stage_textures = new std::vector<CTexture*>;
	LoadSceneBySceneName("prime_Scene");
	std::cout << "PrimeScene Loaded" << std::endl;
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

	stage_contents = current_scene->GetSceneContents();
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
	std::cout << "CreateTextures Start" << std::endl;
	Content* create_temp = new Content;
	//std::cout << stage_contents[0].GetContentType() << std::endl;
   if (!(stage_contents->empty()))
	{
	   //changed from contentcount to size() way better
		for (unsigned int x = 0; x < stage_contents->size(); x++) 
		{  // crash cause found
			
			if (*stage_contents->at(x)->GetContentType() == "texture") {
				//GetSceneContents()->begin()->GetContentPath()
				//use get content position to add to ->begin ex: begin +2
				//used *stage_contents
				Content* content_arg = stage_contents->at(x);
				std::cout << "Texture found" << std::endl;
				CTexture* temp_ctexture = new CTexture(csdl_setup, content_arg);

				stage_textures->push_back(temp_ctexture);

				std::cout << "Texture created" << std::endl;

				
			}			
			else {

				std::cout << "Not a texture" << std::endl;
			}
			
		}
		
	}
   std::cout << "CreateTextures End" << std::endl;
   delete create_temp;
}

void Stage::CreateAudio()
{
	if ((!stage_contents->empty()))
	{
		for (unsigned int x = 0; x < stage_contents->size(); x++) 
		{
			Content* content_temp = stage_contents->at(x);
			if ((*content_temp->GetContentType() == "music") | (*content_temp->GetContentType() == "sfx")) //forgot to change type to "music" from "audio"
			{
				stage_audio->LoadAudio(content_temp);
				printf("Stage::LoadAudio Called\n");
			}
			else {
				printf("non audio file found\n");
			}
			delete content_temp;
		}
	}
	else
	{
		printf("Stage::CreateAudio error : stage_contents is empty\n");
	}
}

void Stage::RenderScene() 
{
	if (!(stage_textures->empty())) 
	{

		for (unsigned int i = 0; i < stage_textures->size(); i++)
		{
			//maybe call a scene method to render stuff
			try {
				if (*stage_textures->at(i)->GetTextureID() != "")
				{
					//check it texture exists
					for (unsigned int it = 0; it < stage_contents->size(); it++)
					{
					//render by address
						if (*stage_contents->at(i)->GetContentID() == *stage_textures->at(i)->GetTextureID())
						{
							CTexture rendered_texture = *GetTextureObject(it);
							rendered_texture.render(stage_contents->at(i)->GetContentRect()->x, stage_contents->at(i)->GetContentRect()->y, stage_contents->at(it)->GetContentRect()->w, stage_contents->at(it)->GetContentRect()->h);
						}
				    }
				}
				

			}
			catch (...)
			{


			}
		}
	}
}


//delete this use size() from vector




CTexture* Stage::GetTextureObject(unsigned int passed_slot)
{
	if (passed_slot >= stage_textures->size())
	{

		passed_slot = passed_slot % stage_textures->size();

	}
	//only allows images to be called?
	if (passed_slot < stage_textures->size())
	{ 

		return stage_textures->at(passed_slot);
		
	}


}