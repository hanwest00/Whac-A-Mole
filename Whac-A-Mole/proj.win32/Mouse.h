#include "cocos2d.h"

using namespace cocos2d;

class Mouse : public CCNode
{
protected:
	CCSprite *mSprite;
public:
	CCPoint Start;

public:
	Mouse(CCPoint start,CCTexture2D context);
	Mouse(CCPoint start,CCArray *animFrames);
	Mouse(CCPoint start,CCAnimate *Animate);
		 
	virtual void Move(CCAction *action);
	virtual void Attact(CCAction *action);
	virtual void Bit(CCAction *action);
	virtual void Die(CCAction *action);
	virtual void Sound(const char* soundFile);

};