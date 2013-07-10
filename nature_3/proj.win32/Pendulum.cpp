#include "Pendulum.h"

Pendulum::Pendulum(PVector *origin_, float r_) {
	origin = new PVector(origin_);
	location = new PVector();
	r = r_;
	angle = M_PI/2;
	aVelocity = 0.0;
	aAcceleration = 0.0;
	damping = 0.995;

	line = CCSprite::create("line.png");
	line->setScaleX( r / line->getContentSize().width );
	line->setAnchorPoint( ccp(0, 0) );
	line->setPosition( ccp(origin->x, origin->y) );
	addChild(line);

	circle = CCSprite::create("circle.png");
	circle->setScale(0.8);
	addChild(circle);
}

void Pendulum::update() {
	float gravity = 0.4;
	aAcceleration = (-1 * gravity / r) * sin(angle);
	aVelocity += aAcceleration;
	angle += aVelocity;
	aVelocity *= damping;
}

void Pendulum::display() {
	location->x = r*sin(angle);
	location->y = r*cos(angle);
	location = PVector::sub(origin, location);

	line->setRotation( (angle * 180 / M_PI) + 90 );
	circle->setPosition( ccp(location->x, location->y) );
}