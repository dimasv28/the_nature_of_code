#ifndef __ATTRACTOR__
#define __ATTRACTOR__

#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "PVector.h"
#include "Mover.h"

using namespace cocos2d;

class Attractor : public CCLayer {
protected:
	PVector *location;
	float mass;
	float G;

	CCSprite *circle;

public:
	Attractor();
	void display();
	PVector *attract(Mover *m);
	void update(PVector *mouse);

	float getMass() { return mass; };
};

#endif  __ATTRACTOR__