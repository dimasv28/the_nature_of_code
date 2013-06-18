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

public:
	virtual void draw();
    static Example_1_3* create();
 
	void setMouse(float x, float y) { mouse->x = x; mouse->y = y; };
};

#endif  __EXAMPLE_1_3__