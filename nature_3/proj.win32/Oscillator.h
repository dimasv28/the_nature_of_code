#ifndef __OSCILLATOR__
#define __OSCILLATOR__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "PVector.h"

using namespace cocos2d;

class Oscillator : public CCLayer {
protected: 
	PVector *angle;
	PVector *velocity;
	PVector *amplitude;
	CCSprite *circle;
	CCSprite *line;

public:
	Oscillator();
 
	void oscillate(); 
	void display();
};

#endif