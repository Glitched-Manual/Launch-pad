// filter rect string


#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cctype>

int main()
{

std::string string_rect = "x = 20; y = 20; w = 100; h= 100;";
std::string temp_value;
int nums[4];
for(int i = 0; i <= string_rect.length();i++)
{
	if(string_rect[i] == 'x')
	{
		temp_value = "";
		while(string_rect[i] != ';')
		{
			if(isdigit(string_rect[i]))
			{
			temp_value += string_rect[i];
			
			}
			++i;
		}
		//contentRect.x = atoi(temp_value);
		nums[0] = stoi(temp_value);
	}
	else if(string_rect[i] == 'y')
	{
		temp_value = "";
		while(string_rect[i] != ';')
		{
			if(isdigit(string_rect[i]))
			{
			temp_value += string_rect[i];
			}
			i++;
			std::cout << "all is good " << temp_value << std::endl;
		}
		//contentRect.y = atoi(temp_value);
		nums[1] = stoi(temp_value);
		std::cout << "all is good " << temp_value << std::endl;
		
		}
	else if(string_rect[i] == 'w')
	{
		temp_value = "";
		while(string_rect[i] != ';')
		{
			if(isdigit(string_rect[i]))
			{
			temp_value += string_rect[i];
			}
			i++;
		}
		//contentRect.w = atoi(temp_value);
		nums[2] = stoi(temp_value);
		std::cout << "all is good " << temp_value << std::endl;
	}
	else if(string_rect[i] == 'h')
	{
		temp_value = "";
		while(string_rect[i] != ';')
		{
			if(isdigit(string_rect[i]))
			{
			temp_value += string_rect[i];
			}
			i++;
		}
		//contentRect.x = atoi(temp_value);
		nums[3] = stoi(temp_value);
		std::cout << "all is good " << temp_value << std::endl;
	}
	else
	{
		//std::cout << "error: unwanted character found : " << std::endl;
	}
	
		
}


int count = 0;
for( auto a : nums){
printf("nums[%d] = %d \n",count,a);
count++;
}

return 0;
}
/*

    contentRect.x = passed_x;

	contentRect.y = passed_y;

	contentRect.w = passed_w;
	contentRect.h = passed_h;


	temp_content->SetContentID("manual-img");
	temp_content->SetContentPath("Debug/resources/images/solo.jpg");
	temp_content->SetContentType('t');
	temp_content->SetContentRect(0, 0, 100, 100);
	prime_contents.push_back(*temp_content);
*/