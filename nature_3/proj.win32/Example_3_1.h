#ifndef __EXAMPLE_3_1__
#define __EXAMPLE_3_1__

#include "cocos2d.h"
#include "Box2D/Box2D.h"

using namespace cocos2d;

class Example_3_1 : public CCLayer {
protected:
	CCNode *centerPoint;
	CCSprite *circle;
	CCSprite *circle_2;
	CCSprite *line;
	float angle;
	float aVelocity;
	float aAcceleration;
	CCLabelTTF *exLabel;
	
public:
	virtual bool init(); 
    static CCScene* scene();

	void goMainMenu(CCObject* pSender);
	void moveCircle(float dt);

	CREATE_FUNC(Example_3_1);
};

#endif __EXAMPLE_3_1__