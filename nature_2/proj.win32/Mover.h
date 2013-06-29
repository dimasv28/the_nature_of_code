#ifndef __MOVER__
#define __MOVER__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "PVector.h"
#include "Liquid.h"

using namespace cocos2d;

class Mover : public CCLayer {
protected:
	PVector *location;
	PVector *velocity;
	PVector *acceleration;
	float topspeed;
	float mass;

	CCSprite *circle;

public:
	Mover(float m, float x , float y);
	void update(PVector *mouse);
	void display();
	void checkEdges();
	void applyForce(PVector *force);

	PVector *getLocation() { return location; };
	PVector *getVelocity() { return velocity; };
	float getMass() { return mass; };

	boolean isInside(Liquid *l);
	void drag(Liquid *l);
};

#endif  __MOVER__