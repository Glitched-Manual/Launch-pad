#include "Scene.h"



Scene::Scene()
{
}


Scene::~Scene()
{
}
/*
void Scene::AddContents(Content passed_Content)
{

	//needs work
	std::vector<Content*>::iterator contentIterator = contents.end();

	int a = std::distance(contents.begin(), contentIterator);

	try {
		
		
	}
	catch (...) {

	}

	std::cout << "the value of a is " << a << std::endl;

	*contents[a] = passed_Content;

	
		
}
*/

Content Scene::GetContentByID(std::string passed_string)

{   // int value for changing iteration

	//contents.reserve(1);
	int iter = 0;
	for (std::vector<Content>::iterator content_iterator = contents.begin(); content_iterator != contents.end(); content_iterator++)
	{   //filter for disired content


		if (contents[iter].GetContentID() == passed_string)
		{
			return contents[iter];

		}
		iter++;


	}

}
/*

for ( int i=0 ; i<some_variable ; i++ )
{
	Custom obj;
	obj.metric = computation1();
	obj.nX= computation2();
	obj.nY= computation3();

	MyWonderfulVector.push_back( obj );
}
*/