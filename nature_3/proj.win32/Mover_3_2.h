#ifndef __MOVER_3_2__
#define __MOVER_3_2__

#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "PVector.h"
#include "Liquid.h"

using namespace cocos2d;

class Mover_3_2 : public CCLayer {
protected:
	PVector *location;
	PVector *velocity;
	PVector *acceleration;
	float topspeed;
	float mass;
	float G;
	float angle;
	float aVelocity;
	float aAcceleration;

	CCSprite *rect;

public:
	Mover_3_2(float m, float x , float y);
	void update(PVector *mouse);
	void display();
	void checkEdges();
	void applyForce(PVector *force);

	PVector *getLocation() { return location; };
	PVector *getVelocity() { return velocity; };
	float getMass() { return mass; };
	void setVelocity(PVector *v) { velocity->x = v->x; velocity->y = v->y; };

	boolean isInside(Liquid *l);
	void drag(Liquid *l);
	PVector* attract(Mover_3_2 *m);
};

#endif  __MOVER_3_2__