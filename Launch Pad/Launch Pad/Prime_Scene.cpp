#include "Prime_Scene.h"



Prime_Scene::Prime_Scene(CSDL_Setup* passed_setup)
{
	csdl_setup = passed_setup;
	pMainEvent = csdl_setup->getMainEvent();
	pRenderer = csdl_setup->getRenderer();

	std::cout << "Prime_Scene obj created" << std::endl;
	SetContentValuesByID("manual");
	SetContentValuesByID("glass");

}


Prime_Scene::~Prime_Scene()
{
}

void Prime_Scene::SetContentValues()
{

}


void Prime_Scene::SetContentValuesByID(std::string passed_ID)
{

	if (passed_ID == "manual") {

		LoadManualImageContent();

	}

	if(passed_ID == "glass")
	{
		LoadGlassImageContent();
	}

}

void Prime_Scene::AddContents(Content passed_Content)
{

	//needs work
		
	prime_contents.push_back(passed_Content);
	   
}
/*
Content Prime_Scene::GetContentByID(std::string passed_string)
{   // int value for changing iteration
	int iter = 0;
	for (std::vector<Content>::iterator content_iterator = prime_contents.begin(); content_iterator != prime_contents.end(); content_iterator++)
	{   //filter for disired content
		if (prime_contents[iter].GetContentID() == passed_string)
		{
			return prime_contents[iter];

		}
		iter++;		
	}

}
*/
void Prime_Scene::clearTempContent()
{
	//temp_content.clearContent();

}

void Prime_Scene::LoadManualImageContent()
{
	Content temp_content;

	temp_content.SetContentID("manual-img");
	temp_content.SetContentPath("Debug/resources/images/solo.jpg");
	temp_content.SetContentType('t');
	temp_content.SetContentRect(0, 0, 100, 100);
	prime_contents.push_back(temp_content);

	std::cout << "Manual content pushed to prime contents" << std::endl;
	
}

void Prime_Scene::LoadGlassImageContent()
{
	Content temp_content;

	temp_content.SetContentID("glass-img");
	temp_content.SetContentPath("Debug/resources/images/glass.jpg");
	temp_content.SetContentType('t');
	temp_content.SetContentRect(20, 20, 20, 20);
	prime_contents.push_back(temp_content);

	std::cout << "Glass content pushed to prime contents" << std::endl;

}