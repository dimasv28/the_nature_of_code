#ifndef __PENDULUM__
#define __PENDULUM__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "PVector.h"

using namespace cocos2d;

class Pendulum : public CCLayer {
protected:
	PVector *location;		// Location of bob
	PVector *origin;			// Location of arm origin
	float r;				// Length of arm
	float angle;			// Pendulum arm angle
	float aVelocity;		// Angular velocity
	float aAcceleration;	// Angular acceleration
	float damping;			// Arbitrary damping amount
	CCSprite *line;
	CCSprite *circle;
public:
	Pendulum(PVector *origin_, float r_);
	void update();
	void display();
};

#endif