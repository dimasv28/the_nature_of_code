#ifndef __EXAMPLE_1_2__
#define __EXAMPLE_1_2__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "DebugDraw.h"
#include "PVector.h"

using namespace cocos2d;

class Example_1_2 : public cocos2d::CCLayer
{
protected:
	PVector *location;
	PVector *velocity;
	DebugDraw *circle;

public:
	virtual bool init(); 
    static CCScene* scene();

	void goMainMenu(CCObject* pSender);
	void draw();
	void moveCircle(float dt);

	CREATE_FUNC(Example_1_2);
};

#endif  __EXAMPLE_1_2__