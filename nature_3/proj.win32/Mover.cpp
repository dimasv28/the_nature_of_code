#include "Mover.h"

Mover::Mover(float m, float x , float y) {
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	int rx = rand() % 2 + 1; // equal initialization of velocity and aVelocity
	int ry = rand() % 2 + 1;

	location = new PVector(x, y);
    velocity = new PVector(rx, ry);
	acceleration = new PVector(0,0);
	topspeed = 6;
	mass = m;
	G = 0.4;
	angle = 0;
	aVelocity = rx;
	aAcceleration = 0;

	circle = CCSprite::create("rect.png");
	circle->setScale(mass/6);
	addChild(circle);
}

void Mover::update(PVector *mouse) {
	velocity->add(acceleration);
    location->add(velocity);

	aAcceleration = acceleration->x;
	aVelocity += aAcceleration;
	aVelocity = constrain(aVelocity,-10,10);
	angle += aVelocity;

    acceleration->mult(0);
}

void Mover::display() {
	circle->setPosition(ccp(location->x, location->y));
	circle->setRotation(angle);
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

PVector* Mover::attract(Mover *m) {
	PVector *force = PVector::sub(location, m->getLocation());
	float distance = force->mag();
	distance = constrain(distance,5,25);

	force->normalize();
	float strength = (G * mass * m->getMass()) / (distance * distance);
	force->mult(strength);

	return force;
}