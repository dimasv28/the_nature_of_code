#ifndef __BOB__
#define __BOB__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "PVector.h"

using namespace cocos2d;

class Bob : public CCLayer {
protected:
	PVector *location;
	PVector *velocity;
	PVector *acceleration;
	float mass;
	float damping;

	// For mouse interaction
	PVector *dragOffset;
	bool dragging;

	CCSprite *circle;

public:
	Bob(float m, float x , float y);
	void update();
	void display();
	void applyForce(PVector *force);

	PVector *getLocation() { return location; };
	PVector *getVelocity() { return velocity; };
	void setLocation(PVector *l) { location->x = l->x; location->y = l->y; };
	void setVelocity(PVector *v) { velocity->x = v->x; velocity->y = v->y; };

	// The methods below are for mouse interaction
	void clicked(PVector *mouse);
	void stopDragging();
	void drag(PVector *mouse);
};

#endif