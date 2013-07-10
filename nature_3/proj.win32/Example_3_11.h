#ifndef __EXAMPLE_3_11__
#define __EXAMPLE_3_11__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "Bob.h"
#include "Spring.h"

using namespace cocos2d;

class Example_3_11 : public cocos2d::CCLayer
{
protected:
	Bob *bob;
	Spring *spring;
	PVector *mouse;
	CCLabelTTF *exLabel;
	
public:
	virtual bool init(); 
    static CCScene* scene();

	void goMainMenu(CCObject* pSender);
	void moveCircle(float dt);
	void ccTouchesMoved(CCSet* touches, CCEvent* event);
	void ccTouchesBegan(CCSet* touches, CCEvent* event);
	void ccTouchesEnded(CCSet* touches, CCEvent* event);

	CREATE_FUNC(Example_3_11);
};

#endif