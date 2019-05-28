#include "Content.h"
#include <ctype.h>
#include <stdio.h>
#include <locale>
#include <string>

Content::Content()
{	
}

Content::~Content()
{
}

void Content::SetContentType(char passed_type) {


	try {
		passed_type = tolower(passed_type);

		if ((passed_type == 'i') |( passed_type == 't'))
		{

			*contentType = "texture";

		}
		else if ((passed_type == 's'))
		{
			*contentType = "sfx";

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

void Content::SetContentType(std::string passed_type)
{
	try {
		std::locale loc;

		for (std::string::size_type i = 0; i < passed_type.length(); ++i)
			passed_type[i] = std::tolower(passed_type[i], loc);

		if ((passed_type == "image" )| (passed_type == "texture"))
		{
			*contentType = "texture";
		}
		else if ((passed_type == "music") | (passed_type == "song")) //gave wrong typename for loading music
		{
			*contentType = "music";
		}
		else if ((passed_type == "sfx") | (passed_type == "soundeffect"))
		{
			*contentType = "sfx";
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
	*contentPath = "";
	*contentID = "";
	*contentType = "";
	ClearContentRect();
}

void Content::SetContentRect(int passed_x, int passed_y, int passed_w, int passed_h)
{
	contentRect->x = passed_x;
	contentRect->y = passed_y;
	contentRect->w = passed_w;
	contentRect->h = passed_h;
}

void Content::SetContentRect(std::string passed_string_rect)
{
	if (passed_string_rect == "NULL" | passed_string_rect == "null")
	{
		SetContentRect(0, 0, 0, 0);
	}
	else
	{
		// filter rect string and set sdlRect for content

		std::string temp_value;

		for (unsigned int i = 0; i <= passed_string_rect.length(); i++)
		{
			if (passed_string_rect[i] == 'x')
			{
				temp_value = "";
				while (passed_string_rect[i] != ';')
				{
					if (isdigit(passed_string_rect[i]))
					{
						temp_value += passed_string_rect[i];

					}
					++i;
				}
				//contentRect.x = atoi(temp_value);
				contentRect->x = stoi(temp_value);
			}
			else if (passed_string_rect[i] == 'y')
			{
				temp_value = "";
				while (passed_string_rect[i] != ';')
				{
					if (isdigit(passed_string_rect[i]))
					{
						temp_value += passed_string_rect[i];
					}
					i++;

				}
				//contentRect.y = atoi(temp_value);
				contentRect->y = stoi(temp_value);
				//std::cout << "all is good " << temp_value << std::endl;

			}
			else if (passed_string_rect[i] == 'w')
			{
				temp_value = "";
				while (passed_string_rect[i] != ';')
				{
					if (isdigit(passed_string_rect[i]))
					{
						temp_value += passed_string_rect[i];
					}
					i++;
				}
				//contentRect.w = atoi(temp_value);
				contentRect->w = stoi(temp_value);
				//std::cout << "all is good " << temp_value << std::endl;
			}
			else if (passed_string_rect[i] == 'h')
			{
				temp_value = "";
				while (passed_string_rect[i] != ';')
				{
					if (isdigit(passed_string_rect[i]))
					{
						temp_value += passed_string_rect[i];
					}
					i++;
				}
				//contentRect.x = atoi(temp_value);
				contentRect->h = stoi(temp_value);
				//std::cout << "all is good " << temp_value << std::endl;
			}
		}

		// convent string value to int values for SDLRect
	}
	
}
	void Content::ClearContentRect()
	{
		SetContentRect(0, 0, 0, 0);
	}