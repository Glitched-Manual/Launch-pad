#include "Texture.h"


//(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h) 

//use content object get all info from content object except the passed renderer
CTexture::CTexture(CSDL_Setup* passed_setup,Content* passed_content)
{

	csdl_setup = passed_setup;

	//create texture from content data
	texture_content = passed_content;
    //
	pRenderer = csdl_setup->getRenderer();
	texture_rect = texture_content->GetContentRect();
	SetTextureID();
	LoadContentTexture();
	
}






CTexture::~CTexture()
{

}

void CTexture::AddTexture()
{
	//get content from passed_content make texture add to texture vector
}

std::string* CTexture::GetTextureID()
{
	return textureID;
}


void CTexture::LoadContentTexture() {

	texture = IMG_LoadTexture(GetRenderer(), texture_content->GetContentPath()->c_str());

	if (texture == NULL) 
	{

		std::cout << "\nError: " << SDL_GetError() << std::endl;

	}

}

void CTexture::LoadContentTextureByID(){



}

void CTexture::SetTextureID()
{

	*textureID = *texture_content->GetContentID();

}

void CTexture::render(int x, int y, int w, int h, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	SDL_Rect renderQuad;
	//Set rendering space and render to screen
	//get width and Hieght for context
	if ((w == NULL) | (h == NULL)) 
	{
		renderQuad = { x, y, 100, 100 };
	}
	else
	{
	    renderQuad = { x, y, w, h };
	}
	//clip may be used for animating
	//Set clip rendering dimensions
if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	//clip and center crashing code with unreadable values
	//Render to screen

	//pass texture
	//SDL_RenderCopyEx(GetRenderer(), GetTexture(), clip, &renderQuad, angle, center, flip); //exception thrown here
	SDL_RenderCopy(GetRenderer(), GetTexture(), clip, &renderQuad);
}

void CTexture::RenderTextureByID(std::string passed_string)
{
	if (passed_string == "")
	{

	}

}