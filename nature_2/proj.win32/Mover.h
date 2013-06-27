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
	PVector *acceleration;
	float topspeed;
	float mass;

	DebugDraw *circle;

public:
	Mover(float m, float x , float y);
	void update(PVector *mouse);
	void display();
	void checkEdges();
	void applyForce(PVector *force);

	PVector *getVelocity() { return velocity; };
	float getMass() { return mass; };
};

#endif  __MOVER__