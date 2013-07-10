#include "Bob.h"

Bob::Bob(float m, float x , float y) {
	location = new PVector(x,y);
	velocity = new PVector();
	acceleration = new PVector();
	dragOffset = new PVector();
	dragging = false;
	mass = m;
	damping = 0.99;

	circle = CCSprite::create("circle.png");
	circle->setScale(mass/6);
	circle->setPosition( ccp(x, y) );
	addChild(circle);
}

void Bob::update() { 
	velocity->add(acceleration);
	velocity->mult(damping);
	location->add(velocity);
	acceleration->mult(0);
}

void Bob::applyForce(PVector *force) {
	PVector *f = new PVector(force);
	f->div(mass);
	acceleration->add(f);
 }

void Bob::display() {
	circle->setPosition( ccp(location->x, location->y) );
	if (dragging) {
		//circle->setOpacity(1.5);
	}
	else {
		//circle->setOpacity(1);
	}
}

void Bob::clicked(PVector *mouse) {
	float d = PVector::sub(mouse, location)->mag();
	if (d < (circle->getContentSize().width * circle->getScaleX() / 2) ) { // d < circle radius (with scale)
		dragging = true;
		dragOffset->x = location->x - mouse->x;
		dragOffset->y = location->y - mouse->y;
	}
}

void Bob::stopDragging() {
	dragging = false;
}

void Bob::drag(PVector *mouse) {
	if (dragging) {
		location->x = mouse->x + dragOffset->x;
		location->y = mouse->y + dragOffset->y;
	}
}