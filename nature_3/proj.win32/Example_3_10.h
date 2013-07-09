#ifndef __EXAMPLE_3_10__
#define __EXAMPLE_3_10__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "Pendulum.h"

using namespace cocos2d;

class Example_3_10 : public cocos2d::CCLayer
{
protected:
	Pendulum *pendulum;
	PVector *mouse;
	CCLabelTTF *exLabel;
	
public:
	virtual bool init(); 
    static CCScene* scene();

	void goMainMenu(CCObject* pSender);
	void moveCircle(float dt);
	void ccTouchesMoved(CCSet* touches, CCEvent* event);

	CREATE_FUNC(Example_3_10);
};

#endif