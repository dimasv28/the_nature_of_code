#ifndef __MOVER__
#define __MOVER__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "DebugDraw.h"
#include "PVector.h"
#include "Example_1_7.h"

using namespace cocos2d;
class Example_1_7;

class Mover : public cocos2d::CCLayer {
protected:
	PVector *location;
	PVector *velocity;
	PVector *acceleration;
	float topspeed;

	DebugDraw *circle;

public:
	Mover();
	void update(PVector *mouse);
	void display();
	void checkEdges();
};

#endif  __MOVER__