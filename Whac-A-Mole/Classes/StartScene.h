#include "cocos2d.h"

#include "Box2D/Box2D.h"

#include "SimpleAudioEngine.h"

using namespace cocos2d;

class StartScene : CCLayer
{
private:
	int screenWidth;
	int screenHeight;
	CCMenu *startMenu;
	CCLabelTTF *GameName;
	CCSprite *mainBg;

public:
	virtual bool init();
	//virtual void registerWithTouchDispatcher(void);
	//virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);

	void beginNewGame(CCObject* pSender);
	void continueGame(CCObject* pSender);
	void quit(CCObject* pSender);
	void showMenu();
	//void quitGame(CCObject* pSender);
	static CCScene *scene();
	CREATE_FUNC(StartScene);
};