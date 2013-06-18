#ifndef __EXAMPLE_1_3__
#define __EXAMPLE_1_3__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "PVector.h"

using namespace cocos2d;

class Example_1_3 : public cocos2d::CCLayer
{
protected:
	PVector *mouse;
	PVector *center;

public:
	virtual bool init(); 
    static CCScene* scene();

	void goMainMenu(CCObject* pSender);
 
	virtual void draw();
	void ccTouchesMoved(CCSet* touches, CCEvent* event);

	CREATE_FUNC(Example_1_3);
};

#endif  __EXAMPLE_1_3__