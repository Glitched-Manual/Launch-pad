#include "Main.h"



int main(int argc, char* args[])
{
	CMain* cmain = new CMain(960, 720);
	
	Prime_Scene pScene(cmain->GetSetup());

	

	//std::vector<Content>::iterator *count = &pScene.GetSceneContents()->begin();

	//std::cout << pScene.GetSceneContents()[0].begin()->GetContentPath() << std::endl; [0] is useless
	//std::cout << pScene.GetSceneContents()->begin()->GetContentPath() << std::endl;

	//std::cout << cmain->GetMainStage()->GetCurrentScene()->GetSceneContents()->begin()->GetContentPath() << std::endl; //failed

	//cmain->SoftwareLoop();

	delete cmain;

	std::cin.get();

	return 0;
}