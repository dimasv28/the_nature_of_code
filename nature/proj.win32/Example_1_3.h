#ifndef __EXAMPLE_1_3__
#define __EXAMPLE_1_3__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "DebugDraw.h"
#include "PVector.h"

using namespace cocos2d;

class Example_1_3 : public cocos2d::CCLayer
{
protected:
	PVector *mouse;
	PVector *center;
	CCNode *centerPoint;
	DebugDraw *line;
	DebugDraw *rect;

public:
	virtual bool init(); 
    static CCScene* scene();

	void goMainMenu(CCObject* pSender);
	void ccTouchesMoved(CCSet* touches, CCEvent* event);

	void drawLine();
	void drawRect(float m);

	void example_1_4_func();
	void example_1_5_func();

	CREATE_FUNC(Example_1_3);
};

#endif  __EXAMPLE_1_3__