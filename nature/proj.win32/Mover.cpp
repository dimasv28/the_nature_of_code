#include "Mover.h"
#include "Math.h"

Mover::Mover()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	location = new PVector(rand() % (int)(size.width), rand() % (int)(size.height));
    velocity = new PVector(rand() % (-2) + 2, rand() % (-2) + 2);

	circle = DebugDraw::create();
	addChild(circle);
}

void Mover::update()
{
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