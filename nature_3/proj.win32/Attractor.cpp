#include "Attractor.h"

Attractor::Attractor() {
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	location = new PVector(size.width/2, size.height/2);
	mass = 20;
	G = 1;
	circle = CCSprite::create("circle.png");
	circle->setScale(mass/20);
	addChild(circle);
}

void Attractor::display() {
	circle->setPosition(ccp(location->x, location->y));
}

void Attractor::update(PVector *mouse) {
	location = new PVector(mouse->x, mouse->y);
}

PVector* Attractor::attract(Mover_3_2 *m) {
	PVector *force = PVector::sub(location, m->getLocation());
	float distance = force->mag();
	distance = constrain(distance,5,25);

	force->normalize();
	float strength = (G * mass * m->getMass()) / (distance * distance);
	force->mult(strength);

	return force;
}