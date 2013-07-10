#ifndef __SPRING__
#define __SPRING__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "PVector.h"
#include "Bob.h"

using namespace cocos2d;

class Spring : public CCLayer {
protected:
	PVector *anchor;
	float len;
	float k;
	CCSprite *line;
public:
	Spring(float x, float y, int l);
	void connect(Bob *b);	// Calculate spring force
	void constrainLength(Bob *b, float minlen, float maxlen);
	void display(Bob *b);
};

#endif