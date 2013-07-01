#ifndef __LIQUID__
#define __LIQUID__

#include "cocos2d.h"
#include "Box2D/Box2D.h"

using namespace cocos2d;

class Liquid {
protected:
	float x,y,w,h;
	float c;

public:
	Liquid(float x_, float y_, float w_, float h_, float c_) {
		x = x_;
		y = y_;
		w = w_;
		h = h_;
		c = c_;
	};

	CCPoint getPosition() { return ccp(x,y); };
	CCSize getSize() { return CCSizeMake(w,h); };
	float getCoef() { return c; };
};

#endif __LIQUID__