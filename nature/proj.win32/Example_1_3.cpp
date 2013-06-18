#include "Example_1_3.h"

Example_1_3* Example_1_3::create()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	Example_1_3 *ex = new Example_1_3();
	ex->mouse  = new PVector(50,50);
	ex->center = new PVector(size.width/2,size.height/2);

	return ex;
}

void Example_1_3::draw()
{
    ccDrawColor4F(1.0f, 0.0f, 0.0f, 1.0f);
	ccDrawLine(ccp(center->x,center->y),ccp(mouse->x,mouse->y));
}