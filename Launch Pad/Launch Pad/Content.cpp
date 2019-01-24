#include "Content.h"
#include <ctype.h>
#include <stdio.h>


Content::Content()
{
	contentCount++;
}


Content::~Content()
{
}

void Content::SetContentType(char passed_type) {


	try {
		passed_type = tolower(passed_type);

		if (passed_type == 'i' | passed_type == 't')
		{

			contentType = "texture";

		}
		else if (passed_type == 'a' | passed_type == 's')
		{
			contentType = "audio";

		}

		else
		{
			printf("error: unknown content type");
		}
	}
	catch (...) {
		printf("error: Incorrect value for content type found");
	}
}

void Content::clearContent() 
{	
	contentPath = "";
	contentID = "";
	contentType = "";
	this->ClearContentRect();

}

void Content::SetContentRect(int passed_x, int passed_y, int passed_w, int passed_h)
{

	contentRect.x = passed_x;

	contentRect.y = passed_y;

	contentRect.w = passed_w;
	contentRect.h = passed_h;
}

void Content::ClearContentRect()
{
	this->SetContentRect(0, 0, 0, 0);
}