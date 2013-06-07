#include "cocos2d.h"

using namespace cocos2d;

class LevelSelectScene:CCLayer
{
private:
	wchar_t *currdir;

public:
    virtual bool init();

	static CCScene *scene();
	CREATE_FUNC(LevelSelectScene);
};