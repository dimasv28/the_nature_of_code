#ifndef __MOVER__
#define __MOVER__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "DebugDraw.h"
#include "PVector.h"

using namespace cocos2d;

class Mover : public cocos2d::CCLayer {
protected:
	PVector *location;
	PVector *velocity;
	DebugDraw *circle;

public:

	Mover();
	void update();
	void display();
	void checkEdges();
};

#endif  __MOVER__