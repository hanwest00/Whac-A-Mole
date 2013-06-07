#include "StartScene.h"
#include "GameScene.h"
#include "LevelSelectScene.h"
#include "CSArmature.h"

using namespace cs;

CCScene* StartScene::scene()
{
	CCScene* scene = NULL;
	do{
		scene = CCScene::create();
		CC_BREAK_IF(!scene);

		StartScene *startLayer = StartScene::create();
		CC_BREAK_IF(!startLayer);

		scene->addChild(startLayer);
	}
	while(0);
	return scene;
}

bool StartScene::init()
{
	bool retB = false;
	do{
		screenWidth = CCDirector::sharedDirector()->getWinSize().width;
		screenHeight = CCDirector::sharedDirector()->getWinSize().height;

		mainBg = CCSprite::create("feild_bg.png",CCRect(0,0,screenWidth,screenHeight));
		CC_BREAK_IF(!mainBg);
		mainBg->setAnchorPoint(ccp(0,0));
		mainBg->setPosition(ccp(0,0));
		this->addChild(mainBg,0);
		CCTexture2D *titleTx2d = CCTextureCache::sharedTextureCache()->addImage("startGameText.png");
		CCSprite *title = CCSprite::createWithTexture(titleTx2d,CCRect(0,0,600,250));
		CC_BREAK_IF(!title);
		CCSpriteFrame *spFrm = CCSpriteFrame::createWithTexture(titleTx2d,CCRect(0,0,600,250));
		CCSpriteFrame *spFrm1 = CCSpriteFrame::createWithTexture(titleTx2d,CCRect(0,250,600,250));
		CCArray *aniArr = CCArray::create();
		CC_BREAK_IF(!aniArr);
		aniArr->addObject(spFrm);
		aniArr->addObject(spFrm1);
		CCAnimation *ani = CCAnimation::createWithSpriteFrames(aniArr,0.1);
		CCAnimate *anit = CCAnimate::create(ani);

		this->addChild(title,1);
		CCRotateTo *ccr = CCRotateTo::create(0.7,1800.0f);
		CCMoveTo *ccm = CCMoveTo::create(0.5,ccp(screenWidth / 2,screenHeight / 2 - 80));
		CCMoveBy *ccm2 = CCMoveBy::create(0.5,ccp(0,110));
		CCScaleTo *scla = CCScaleTo::create(0.5,0.2);

		CCSequence *ccsq = CCSequence::create(CCDelayTime::create(1),ccm2,scla,scla->create(0.2,100.0f),CCHide::create(),anit,scla->create(0.1,1),CCShow::create(),ccm2,CCCallFunc::create(this,callfunc_selector(StartScene::showMenu)),NULL);
		title->runAction(ccr);
		title->runAction(ccm);
		title->runAction(ccsq);
		
		CCTexture2D *startText = CCTextureCache::sharedTextureCache()->addImage("start_btn_text.png");
		CCTexture2D *btnBg = CCTextureCache::sharedTextureCache()->addImage("start_btn_bg.png");
		CCMenuItemSprite *startItem = CCMenuItemSprite::create(CCSprite::createWithTexture(startText,CCRect(0,0,241,71)),NULL,this,menu_selector(StartScene::beginNewGame));
		CCMenuItemSprite *continueItem = CCMenuItemSprite::create(CCSprite::createWithTexture(startText,CCRect(0,71,241,71)),NULL,this,menu_selector(StartScene::beginNewGame));
		CCMenuItemSprite *optioItem = CCMenuItemSprite::create(CCSprite::createWithTexture(startText,CCRect(0,213,241,71)),NULL,this,menu_selector(StartScene::beginNewGame));
		CCMenuItemSprite *quitItem = CCMenuItemSprite::create(CCSprite::createWithTexture(startText,CCRect(0,142,241,71)),NULL,this,menu_selector(StartScene::quit));
		
		quitItem->setPositionY(0);
		optioItem->setPositionY(71);
		continueItem->setPositionY(142);
		startItem->setPositionY(213);
		startMenu = CCMenu::create();
		startMenu->addChild(startItem,0);
		startMenu->addChild(continueItem,0);
		startMenu->addChild(quitItem,0);
		startMenu->addChild(optioItem,0);
		startMenu->setPosition(ccp(screenWidth / 2,screenHeight / 2 - 250));
		startMenu->setVisible(false);
		this->addChild(startMenu,1);

		retB = true;
	}
	while(0);

	return retB;
}

void StartScene::showMenu()
{
	startMenu->setVisible(true);
	startMenu->runAction(CCFadeIn::create(1));
}

void StartScene::beginNewGame(CCObject* pSender)
{
	GameScene *start = GameScene::create();
	CCDirector::sharedDirector()->runWithScene(start->scene());
}

void  StartScene::continueGame(CCObject *pSender)
{
	LevelSelectScene *lvl = LevelSelectScene::create();
	CCDirector::sharedDirector()->runWithScene(lvl->scene());
}

void StartScene::quit(CCObject* pSender)
{
	CCDirector::sharedDirector()->end();
}