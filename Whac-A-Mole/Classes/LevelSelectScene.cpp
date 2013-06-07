#include "LevelSelectScene.h"

CCScene *LevelSelectScene::scene()
{
	CCScene *scene = NULL;
	do
	{
		scene = CCScene::create();
		CC_BREAK_IF(scene);

		LevelSelectScene *layer = LevelSelectScene::create();
		CC_BREAK_IF(layer);

		scene->addChild(layer);
	}while(0);

	return scene;
}

bool LevelSelectScene::init()
{
	currdir = new wchar_t();
	_wgetcwd(currdir,MAX_PATH);
	LPWIN32_FIND_DATA fileFind;
	FindFirstFile(currdir,fileFind);
	FILE *dir = fopen((char *)currdir,"w+");
	
	return true;
}



