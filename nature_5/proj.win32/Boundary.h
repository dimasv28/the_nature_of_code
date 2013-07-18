#ifndef __BOUNDARY__
#define __BOUNDARY__

#include "cocos2d.h"
#include "Box2D/Box2D.h"

#define PTM_RATIO 32.0

using namespace cocos2d;

class Boundary : public CCLayer {
protected:
	CCSprite *rect;
	b2Body *b;
	float w,h;
public:
	Boundary(b2World *_world, float x_,float y_, float w_, float h_);
	void display();
};

#endif // __BOUNDARY__