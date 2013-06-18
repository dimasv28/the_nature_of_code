#include "Example_1_2.h"

Example_1_2* Example_1_2::create()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	Example_1_2 *ex = new Example_1_2();
	ex->location  = new PVector(50,50);
	ex->velocity = new PVector(1,1);

	//schedule( schedule_selector(HelloWorld::moveCircle), 0.0 );

	return ex;
}

void Example_1_2::moveCircle(float dt)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	location->add(velocity);

	if ((location->x > size.width) || (location->x < 0)) {
		velocity->x = velocity->x * -1;
	}
	if ((location->y > size.height) || (location->y < 0)) {
		velocity->y = velocity->y * -1;
	}
 
	draw();
}

void Example_1_2::draw()
{
    ccDrawColor4F(1.0f, 0.0f, 0.0f, 1.0f);
	//ccDrawLine(ccp(center->x,center->y),ccp(mouse->x,mouse->y));
}