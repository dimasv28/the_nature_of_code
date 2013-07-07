#include "Oscillator.h"

Oscillator::Oscillator()  {
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	angle = new PVector(0, 0);
	velocity = new PVector( (float)(rand() % 10 - 5) / 100, (float)(rand() % 10 - 5) / 100 );
	amplitude = new PVector(rand() % (int)size.width/2, rand() % (int)size.height/2);

	circle = CCSprite::create("circle.png");
	circle->setScale(0.5);
	addChild(circle);

	line = CCSprite::create("line.png");
	line->setScale(0.67);
	line->setAnchorPoint( ccp(0, 0) );
	line->setPosition( ccp(0, 0) );
	addChild(line);
}

void Oscillator::oscillate() {
	angle->add(velocity);
}

void Oscillator::display() {
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	float x = sin(angle->x)*amplitude->x;
	float y = sin(angle->y)*amplitude->y;
 
	circle->setPosition( ccp(x, y) );
	line->setScaleX( sqrt(x*x + y*y) / line->getContentSize().width );
	line->setRotation( - atan2(y, x) * 180 / M_PI );
}