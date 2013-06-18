#ifndef __EXAMPLE_1_2__
#define __EXAMPLE_1_2__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "PVector.h"

using namespace cocos2d;

class Example_1_2 : public cocos2d::CCLayer
{
protected:
	PVector *location;
	PVector *velocity;

public:
	virtual void draw();
    static Example_1_2* create();

	void moveCircle(float dt);
};

#endif  __EXAMPLE_1_2__