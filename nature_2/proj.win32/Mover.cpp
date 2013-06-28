#include "Mover.h"

Mover::Mover(float m, float x , float y) {
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	location = new PVector(x, y);
    velocity = new PVector(0,0);
	acceleration = new PVector(0,0);
	topspeed = 6;
	mass = m;

	circle = DebugDraw::create();
	addChild(circle);
}

void Mover::update(PVector *mouse) {
	velocity->add(acceleration);
    location->add(velocity);

    acceleration->mult(0);
}

void Mover::display() {
	circle->clear();
	float r = 5*mass;
	for(int alfa=0; alfa<360; alfa++) {
		circle->appendPoint(ccp(location->x + r*sin(alfa*M_PI/180), location->y + r*cos(alfa*M_PI/180)),125,255,0);
	}
}

void Mover::checkEdges() {
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	if (location->x > size.width) {
		location->x = size.width;
		velocity->x *= -1;
	} else if (location->x < 0) {
		velocity->x *= -1;
		location->x = 0;
	}
	if (location->y > size.height) {
		velocity->y *= -1;
		location->y = size.height;
	} else if (location->y <= 0) {
		velocity->y *= -1;
		location->y = 0;
	}
}

void Mover::applyForce(PVector *force) {
	PVector *f = PVector::div(force,mass);				// Newton's second law
	acceleration->add(f);
}

boolean Mover::isInside(Liquid *l) {
	if (location->x > l->getPosition().x
		&& location->x < (l->getPosition().x + l->getSize().width)
		&& location->y > l->getPosition().y
		&& location->y < (l->getPosition().y + l->getSize().height) ) {
		return true;
	} else {
		return false;
	}
}

void Mover::drag(Liquid *l) {
	float speed = velocity->mag();
	float dragMagnitude = l->getCoef() * speed * speed;
 
	PVector *drag = new PVector(velocity->x, velocity->y);
	drag->mult(-1);
	drag->normalize();
	drag->mult(dragMagnitude);

	applyForce(drag);
}