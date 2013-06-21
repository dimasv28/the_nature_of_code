#include "Mover.h"
#include "Example_1_7.h"

Mover::Mover()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	location = new PVector(rand() % (int)(size.width), rand() % (int)(size.height));
    velocity = new PVector(0, 0);
	acceleration = new PVector(-0.001,0.01);
	topspeed = 6;

	circle = DebugDraw::create();
	addChild(circle);
}

void Mover::update(PVector *mouse)
{
	//Example 1.10: Accelerating towards the mouse
	PVector *dir = PVector::sub(mouse,location);
	dir->normalize();
    dir->mult(0.3);
	acceleration = dir;

	//Example 1.9: Motion 101 (velocity and random acceleration)
	//acceleration->random2D();
	//acceleration->mult(0.3);

	//Example 1.8: Motion 101 (velocity and constant acceleration)
	velocity->add(acceleration);
	velocity->limit(topspeed);
	location->add(velocity);
}

void Mover::display()
{
	circle->clear();
	float r = 30;
	for(int alfa=0; alfa<360; alfa++)
	{
		circle->appendPoint(ccp(location->x + r*sin(alfa*M_PI/180), location->y + r*cos(alfa*M_PI/180)),125,255,0);
	}
}

void Mover::checkEdges()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	if (location->x > size.width) {
		location->x = 0;
	} else if (location->x < 0) {
		location->x = size.width;
	}
 
	if (location->y > size.height) {
		location->y = 0;
	} else if (location->y < 0) {
		location->y = size.height;
	}
}