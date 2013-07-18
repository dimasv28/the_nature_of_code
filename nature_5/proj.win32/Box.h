#ifndef __BOX__
#define __BOX__

#include "cocos2d.h"
#include "Box2D/Box2D.h"

#define PTM_RATIO 32.0

using namespace cocos2d;

class Box : public CCLayer {
protected:
	CCSprite *rect;
	b2Body *b;
	float w,h;
public:
	Box(b2World *world, CCPoint *mouse);
	void display();
};

#endif // __BOX__